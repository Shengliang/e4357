/*
 * sudo apt-get install openssl
 * sudo apt-get install libssl-dev
 * gcc -Wall hmac_strcmp.c -lssl -lcrypto
 *
 * Reference:
 * https://www.openssl.org/docs/crypto/hmac.html
 * http://etutorials.org/Programming/secure+programming/Chapter+6.+Hashes+and+Message+Authentication/6.10+Using+HMAC/
 * http://www.jokecamp.com/blog/examples-of-creating-base64-hashes-using-hmac-sha256-in-different-languages/
 * http://linux.die.net/man/3/evp_sha256
 * http://stackoverflow.com/questions/22269408/linking-challenges-with-gcc-and-crypto-libraries
 */

#include<openssl/hmac.h>
#include<stdint.h>
#include<string.h>

#define dprint if(0) print

/* 
 * - assume is '\0' terminate 
 * - assume max string length is 256KB 
 */
#define MAX_LEN (256*1024)
unsigned int get_len(void *msg)
{
	unsigned int n = 0;
	while (n < MAX_LEN && *((char*)msg++)) n++;
	return n;
}


/*
 * man hmac | openssl sha512
 */
uint32_t priv_key[] = {
0xfc370b7e,
0x41a5ba66,
0xd4811801,
0xc2ca851c,

0x506dff4d,
0x5e4361b1,
0x5f767ba4,
0x0880f304,

0x917ac446,
0x31d84191,
0x02461bfd,
0x5a3e4246,

0xf4631b85,
0x41db2203,
0xf4f0effa,
0x040e487e
};

/*
 * input: msg, len
 * output: hval, plen
 */
int get_hmac(void *msg, unsigned int len, void *hval, unsigned int *plen)
{
	int rc = 0;
	HMAC_CTX ctxObj;
	HMAC_CTX *ctx = &ctxObj;

	(void) HMAC_CTX_init(ctx);

	rc = HMAC_Init_ex(ctx, priv_key, sizeof(priv_key), EVP_sha512(), NULL);
	if (rc == 0) return -1;

	rc = HMAC_Update(ctx, (unsigned char*)msg, len);
	if (rc == 0) return -1;

	rc = HMAC_Final(ctx,  (unsigned char*)hval, plen);
	if (rc == 0) return -1;

	(void) HMAC_CTX_cleanup(ctx);
	return 0;
}

/*
 * Print hash value
 */
void print(void *hval, int len)
{
	int i;
        for(i = 0; i < len; i++)
		printf("%02x", ((unsigned char*)hval)[i]);
        printf("\n");
}

#if 0
/*
 * Compare k,s that are NULL terminated string
 */
int mystrcmp(const char *k, const char *s)
{
   int d = 0;

   while ( (*k || *s) && 0 == (d = *k++ - *s++) );

   return d;
}
#endif

/*
 * HMAC strcmp
 *    - finished in about 1.3 second for any string inputs
 */
int hmac_strcmp(void *msg1, void *msg2, int *result, int loop)
{
	unsigned char hval1[64];
	unsigned char hval2[64];
	unsigned int len1;
	unsigned int len2;
	int cnt;
	int rc = 0;

	len1 = get_len(msg1);
	len2 = get_len(msg2);

	cnt=0;
	while (cnt++ < loop) {
		rc |= get_hmac(msg1, len1, hval1, &len1);
		msg1 = hval1;
		rc |= get_hmac(msg2, len2, hval2, &len2);
		msg2 = hval2;
		dprint(hval1, len1);
		dprint(hval2, len2);
	}
	*result = strncmp((const char*)hval1, (const char*)hval2, 64);
	return rc;
}

int main(int argc, char* argv[])
{
	int rc, result;
	if (argc == 3) {
		rc = hmac_strcmp(argv[1], argv[2], &result, MAX_LEN);
		if (rc) printf("Got Error in HMAC function calls:%X\n", rc);
		if (result) printf("Not Equal:%d\n", result);
		else printf("Equal\n");
	}
	return rc;
}
