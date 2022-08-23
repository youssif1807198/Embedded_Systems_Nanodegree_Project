/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

//INTCTRL register
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

//APINT register
typedef struct
{
	uint32 VECTRESET 	:1;
	uint32 VECTCLRACT	:1;
	uint32 SYSRESREQ	:2;
	uint32				:5;
	uint32 PRIGROUP		:3;
	uint32				:4;
	uint32 VECTKEY		:16;
	
}APINT_BF;

typedef union 
{
    uint32 R;
    APINT_BF B;
	
}APINT_Tag;

/* typedef struct 
{
	uint32 PRI0;
	uint32 PRI1;
	uint32 PRI2;
	uint32 PRI3;
	uint32 PRI4;
	uint32 PRI5;
	uint32 PRI6;
	uint32 PRI7;
	uint32 PRI8;
	uint32 PRI9;
	uint32 PRI10;
	uint32 PRI11;
	uint32 PRI12;
	uint32 PRI13;
	uint32 PRI14;
	uint32 PRI15;
	uint32 PRI16;
	uint32 PRI17;
	uint32 PRI18;
	uint32 PRI19;
	uint32 PRI20;
	uint32 PRI21;
	uint32 PRI22;
	uint32 PRI23;
	uint32 PRI24;
	uint32 PRI25;
	uint32 PRI26;
	uint32 PRI27;
	uint32 PRI28;
	uint32 PRI29;
	uint32 PRI30;
	uint32 PRI31;
	uint32 PRI32;
	uint32 PRI33;
	uint32 PRI34;
	
	
}PRIx_reg; */

		typedef struct
	{
		uint32  		  :5;
		uint32	INTA	:3;
		uint32 			  :5;
		uint32	INTB	:3;
		uint32 			  :5;
		uint32	INTC	:3;
		uint32 			:5;
		uint32	INTD	:3;
		
	}PRIx_BF;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define PRI_BASE_ADDR						               CORTEXM4_PERI_BASE_ADDRESS+0x400

#define RCGCGPIO                                  *((volatile uint32*)(0x400FE000+0x608))


#define SYS_PRI_1_ADDR                         CORTEXM4_PERI_BASE_ADDRESS+0xD18
#define SYS_PRI_2_ADDR                         CORTEXM4_PERI_BASE_ADDRESS+0xD1C
#define SYS_PRI_3_ADDR                         CORTEXM4_PERI_BASE_ADDRESS+0xD20

#define EN0                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define EN1                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define EN2                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define EN3                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define EN4                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))

#define SYS_CTRL                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))

#define SYSCTL_RCGCTIMER_R       (*((volatile unsigned long *)0x400FE604))
#define SYSCTL_PRTIMER_R         (*((volatile unsigned long *)0x400FEA04))





#define GPIODATA_PORTA_BASE_ADDRESS				 0x40004000
#define GPIODATA_PORTB_BASE_ADDRESS				 0x40005000
#define GPIODATA_PORTC_BASE_ADDRESS				 0x40006000
#define GPIODATA_PORTD_BASE_ADDRESS				 0x40007000
#define GPIODATA_PORTE_BASE_ADDRESS				 0x40024000
#define GPIODATA_PORTF_BASE_ADDRESS				 0x40025000


#define GPIOLOCK_Offest 	0x520
#define	GPIOCR_Offest		0x524
#define	GPIOAFSEL_Offest	0x420
#define	GPIODIR_Offest		0x400
#define	GPIOPCTL_Offest		0x52C
#define	GPIODEN_Offest		0x51C
#define	GPIOPUR_Offest		0x510
#define	GPIOPDR_Offest		0x514
#define	GPIOODR_Offest		0x50C
#define	GPIODR2R_Offest		0x500
#define	GPIODR4R_Offest		0x504
#define	GPIODR8R_Offest		0x508
#define	GPIOIM_Offest		0x410


#define TIMER_0_BASE_ADDRESS				 0x40030000
#define TIMER_1_BASE_ADDRESS				 0x40031000
#define TIMER_2_BASE_ADDRESS				 0x40032000
#define TIMER_3_BASE_ADDRESS				 0x40033000
#define TIMER_4_BASE_ADDRESS				 0x40034000
#define TIMER_5_BASE_ADDRESS				 0x40035000




#define	GPTMTAMR_Offest			0x004
#define	GPTMCTL_Offest			0x00C
#define	GPTMCTL_Offest			0x000
#define	GPTMTAILR_Offest		0x028
#define	GPTMIMR_Offest			0x018

#define SYSTICK_STCTRL_R       		(*((volatile unsigned long *)0xE000E010))
#define SYSTICK_STRELOAD_R       	(*((volatile unsigned long *)0xE000E014))
#define SYSTICK_STCURRENT_R       	(*((volatile unsigned long *)0xE000E018))












/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
