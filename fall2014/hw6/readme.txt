#ifndef __CIRCULAR_BUFFER
#define __CIRCULAR_BUFFER

/* Implement a circularbuffer library with the following API interface */

/**< Circular Buffer Types */
typedef unsigned char INT8U;
typedef INT8U KeyType ;
typedef struct {  
    INT8U writePointer ; /**< write pointer */  
    INT8U readPointer ;  /**< read pointer */  
    INT8U size;         /**< size of circular buffer */
    INT8U mask;         /**< bit Mask of circular buffer size*/   
    KeyType keys[0];    /**< Element of ciruclar buffer */
} CircularBuffer ; 

inline int CircularBufferIsFull(CircularBuffer* que)
{ }
inline int CircularBufferIsEmpty(CircularBuffer* que)
{ }
inline int CircularBufferEnque(CircularBuffer* que, KeyType k)
{ }
inline int CircularBufferDeque(CircularBuffer* que, KeyType* pK)
{ }
inline int CircularBufferPrint(CircularBuffer* que)
{ }

#endif
