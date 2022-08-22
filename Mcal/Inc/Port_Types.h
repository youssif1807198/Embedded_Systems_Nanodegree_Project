/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

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
	Pin0_PortA=0,
	Pin1_PortA,
	Pin2_PortA,
	Pin3_PortA,
	Pin4_PortA,
	Pin5_PortA,
	Pin6_PortA,
	Pin7_PortA,
	
	Pin0_PortB,
	Pin1_PortB,
	Pin2_PortB,
	Pin3_PortB,
	Pin4_PortB,
	Pin5_PortB,
	Pin6_PortB,
	Pin7_PortB,

	Pin0_PortC,
	Pin1_PortC,
	Pin2_PortC,
	Pin3_PortC,
	Pin4_PortC,
	Pin5_PortC,
	Pin6_PortC,
	Pin7_PortC,

	Pin0_PortD,
	Pin1_PortD,
	Pin2_PortD,
	Pin3_PortD,
	Pin4_PortD,
	Pin5_PortD,
	Pin6_PortD,
	Pin7_PortD,

	Pin0_PortE,
	Pin1_PortE,
	Pin2_PortE,
	Pin3_PortE,
	Pin4_PortE,
	Pin5_PortE,
	Pin6_PortE,
	Pin7_PortE,
	
	Pin0_PortF,
	Pin1_PortF,
	Pin2_PortF,
	Pin3_PortF,
	Pin4_PortF,
	Pin5_PortF,
	Pin6_PortF,
	Pin7_PortF,
	
}Port_PinType;


typedef enum
{
	Pin_Input=0,
	Pin_Output=1
	
}Port_PinDirectionType;

typedef enum
{
	/*ALTERNATE FUNCTIONS FOR PIN_B*/
	DIO=16,
	INT=20,
	
	
	
	PB1_USB0VBUS_Analog=17,
	PB1_U1Tx=1,
	PB1_T2CCP1=7,
	
	
	PB2_I2C0SCL=3,
	PB2_T3CCP0=7,
	
	
	PB3_I2C0SDL=3,
	PB3_T3CCP1=7,

	
	
}Port_PinModeType;

typedef enum 
{
	Level_Low=0x00,
	Level_High=0xFF
	
}Port_PinLevelValue;

typedef enum
{
	Pull_Up=0,
	Pull_Down=1,
	Open_Drain=2
	
}Port_PinInternalAttachType;

typedef enum
{
	Current_2mA=0,
	Current_4mA=1,
	Current_8mA=2,	
	
}Port_PinOutputCurrentType;

typedef struct
{
	Port_PinType 				PinType ;
	Port_PinDirectionType 		PinDirectionType;
	Port_PinModeType 			PinModeType;
	Port_PinLevelValue			PinLevelValue;
	Port_PinInternalAttachType 	PinInternalAttachType;
	Port_PinOutputCurrentType	PinOutputCurrentType;
	
	
}Port_ConfigType;

 
#endif  

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
