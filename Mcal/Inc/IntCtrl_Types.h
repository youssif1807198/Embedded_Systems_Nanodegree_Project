/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum
{
	
	/*Interrupts types*/
	
GPIO_PortA=0,
GPIO_PortB,
GPIO_PortC,
GPIO_PortD,
GPIO_PortE,
UART0,
UART1,
SSI0,
I2C0,
PWM0_Fault,
PWM0_Generator_0 ,
PWM0_Generator_1 ,
PWM0_Generator_2 ,
QEI0,
ADC0_Sequence_0, 
ADC0_Sequence_1,
ADC0_Sequence_2,
ADC0_Sequence_3,
WatchdogTimers,
Timer_0A,
Timer_0B,
Timer_1A,
Timer_1B,
Timer_2A,
Timer_2B,
Analog_Comparator_0,
Analog_Comparator_1,
SystemControl=28,
FlashMemoryControl_EEPROMControl,
GPIO_PortF,
UART2=33,
SSI1,
Timer_3A,
Timer_3B,
I2C1,
QEI1,
CAN0,
CAN1,
Hibernation_Module=43,
USB,
PWM_Generator,
μDMA_Software,
μDMA_Error,
ADC1_Sequence_0, 
ADC1_Sequence_1,
ADC1_Sequence_2,
ADC1_Sequence_3,
SSI2=57,
SSI3,
UART3,
UART4,
UART5,
UART6,
UART7,
I2C2=68,
I2C3,
Timer_4A_16_32_Bit,
Timer_4B_16_32_Bit,
Timer_5A_16_32_Bit=92,
Timer_5B_16_32_Bit,
Timer_0A_32_64_Bit,
Timer_0B_32_64_Bit,
Timer_1A_32_64_Bit,
Timer_1B_32_64_Bit,
Timer_2A_32_64_Bit,
Timer_2B_32_64_Bit,
Timer_3A_32_64_Bit,
Timer_3B_32_64_Bit,
Timer_4A_32_64_Bit,
Timer_4B_32_64_Bit,
Timer_5A_32_64_Bit,
Timer_5B_32_64_Bit,
System_Exception,
PWM1_Generator_0=134,
PWM1_Generator_1,
PWM1_Generator_2,
PWM1_Generator_3,
PWM1_Fault,

/*Exception Types*/

Reset=0,
NMI,               
HardFault, 
MemoryManagement, 
BusFault ,
UsageFault, 
Reserved=10,
SVCall,
DebugMonitor,
PendSV=14,
SysTick



}IntCtrl__InterruptType;




 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
