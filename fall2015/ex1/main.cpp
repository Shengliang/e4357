extern "C" {

typedef unsigned int uint32_t;
//PTB22 = (1 << GPIO_PORT_SHIFT | 22)

#define PORT_LED1 1
#define PIN_LED1 22
#define PTB_BASE                                 (0x400FF040u)
#define SET_OFFSET    0x4
#define CLEAR_OFFSET  0x8
#define DIR_OFFSET    0x14


#define SIM_BASE                                 (0x40047000u)
#define HW_SIM_SCGC5_ADDR(x)     ((x) + 0x1038U)
/*!
 * @name Register SIM_SCGC5, field PORTB[10] (RW)
 *
 * This bit controls the clock gate to the Port B module.
 *
 * Values:
 * - 0 - Clock disabled
 * - 1 - Clock enabled
 */
#define BP_SIM_SCGC5_PORTB   (10U)         /*!< Bit position for SIM_SCGC5_PORTB. */
#define BM_SIM_SCGC5_PORTB   (0x00000400U) /*!< Bit mask for SIM_SCGC5_PORTB. */
#define BS_SIM_SCGC5_PORTB   (1U)         
/**
 * @brief Macro to access a single bit of a 32-bit peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_ACCESS32(Reg,Bit) (*((uint32_t volatile*)(0x42000000u + (32u*((uint32_t)(Reg) - (uint32_t)0x40000000u)) + (4u*((uint32_t)(Bit))))))


/*! @brief Set the PORTB field to a new value. */
#define BW_SIM_SCGC5_PORTB(x, v) (BITBAND_ACCESS32(HW_SIM_SCGC5_ADDR(x), BP_SIM_SCGC5_PORTB) = (v))



#define PORTB_BASE                               (0x4004A000u)

#define BP_PORT_PCRn_MUX     (8U)          /*!< Bit position for PORT_PCRn_MUX. */
#define BM_PORT_PCRn_MUX     (0x00000700U) /*!< Bit mask for PORT_PCRn_MUX. */
#define BS_PORT_PCRn_MUX     (3U)          /*!< Bit field size in bits for PORT_PCRn_MUX. */

/*! @brief Format value for bitfield PORT_PCRn_MUX. */
#define BF_PORT_PCRn_MUX(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_MUX) & BM_PORT_PCRn_MUX)

#define HW_PORT_PCRn_WR(addr, n, v) \
        (*((uint32_t*)(addr + (0x4U *(n)))) = (v))

/*! @brief Set the MUX field to a new value. */
#define BW_PORT_PCRn_MUX(x, n, v) (HW_PORT_PCRn_WR(x, n, BF_PORT_PCRn_MUX(v)))

#define HW_PORT_PCRn_ADDR(x, n)  ((x) + 0x0U + (0x4U * (n)))

#define BP_PORT_PCRn_PE      (1U)          /*!< Bit position for PORT_PCRn_PE. */
#define BM_PORT_PCRn_PE      (0x00000002U) /*!< Bit mask for PORT_PCRn_PE. */
#define BS_PORT_PCRn_PE      (1U)          /*!< Bit field size in bits for PORT_PCRn_PE. */

/*! @brief Read current value of the PORT_PCRn_PE field. */
#define BR_PORT_PCRn_PE(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PE))

/*! @brief Format value for bitfield PORT_PCRn_PE. */
#define BF_PORT_PCRn_PE(v)   ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_PE) & BM_PORT_PCRn_PE)

/*! @brief Set the PE field to a new value. */
#define BW_PORT_PCRn_PE(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PE) = (v))


#define BP_PORT_PCRn_PS      (0U)          /*!< Bit position for PORT_PCRn_PS. */
#define BM_PORT_PCRn_PS      (0x00000001U) /*!< Bit mask for PORT_PCRn_PS. */
#define BS_PORT_PCRn_PS      (1U)          /*!< Bit field size in bits for PORT_PCRn_PS. */

/*! @brief Read current value of the PORT_PCRn_PS field. */
#define BR_PORT_PCRn_PS(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PS))

/*! @brief Format value for bitfield PORT_PCRn_PS. */
#define BF_PORT_PCRn_PS(v)   ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_PS) & BM_PORT_PCRn_PS)

/*! @brief Set the PS field to a new value. */
#define BW_PORT_PCRn_PS(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PS) = (v))

int main(void);

//void Reset_Handler(void) { main(); }

void set_output(void) {
   volatile unsigned int * pdirection =
      (volatile unsigned int*) (PTB_BASE+DIR_OFFSET);
 
    BW_SIM_SCGC5_PORTB(SIM_BASE, 1);

    //PORT_HAL_SetMuxMode 1 /*GPIO*/
    BW_PORT_PCRn_MUX(PORTB_BASE, PIN_LED1, 1 /*mux*/);

    //mode: PullNone
    BW_PORT_PCRn_PE(PORTB_BASE, PIN_LED1, 0);

    //pullmode pulldown
    BW_PORT_PCRn_PS(PORTB_BASE, PIN_LED1, 0/*pull down*/);

    *pdirection = 1U << PIN_LED1;
}

inline void turn_on_led1(void) {
   volatile unsigned int * pclear =
            (volatile unsigned int*) (PTB_BASE+CLEAR_OFFSET);
   *pclear = 1U << PIN_LED1;
}

inline void clr_led(void) {
  volatile unsigned int * pset =
     (volatile unsigned int*) (PTB_BASE+SET_OFFSET);
  *pset = 1U << PIN_LED1;
}

/* call by Reset_Handler: 0x50 */
void SystemInit(void) { }

/* call by Reset_Handler: 0x54 */
void _start() { main(); }

uint32_t  mysleep(int n)
{
  int i,j, s=0;
  for(i=0; i< n; i++)
     for(j=0; j< 1000; j++)
         s++;
  return s;
}

int main(void)
{
    set_output();
    while (1) {
       turn_on_led1();
       mysleep(1000);
       clr_led();
       mysleep(1000);
    }
}

}
