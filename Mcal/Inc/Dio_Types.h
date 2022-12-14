/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

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

	CH_PA0=0,
	CH_PA1,
	CH_PA2,
	CH_PA3,
	CH_PA4,
	CH_PA5,
	CH_PA6,
	CH_PA7,
	
	CH_PB0,
	CH_PB1,
	CH_PB2,
	CH_PB3,
	CH_PB4,
	CH_PB5,
	CH_PB6,
	CH_PB7,
	
	CH_PC0,
	CH_PC1,
	CH_PC2,
	CH_PC3,
	CH_PC4,
	CH_PC5,
	CH_PC6,
	CH_PC7,
	
	CH_PD0,
	CH_PD1,
	CH_PD2,
	CH_PD3,
	CH_PD4,
	CH_PD5,
	CH_PD6,
	CH_PD7,
	
	CH_PE0,
	CH_PE1,
	CH_PE2,
	CH_PE3,
	CH_PE4,
	CH_PE5,
	CH_PE6,
	CH_PE7,
	
	CH_PF0,
	CH_PF1,
	CH_PF2,
	CH_PF3,
	CH_PF4,
	CH_PF5,
	CH_PF6,
	CH_PF7




	
}Dio_ChannelType;


typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
	
}Dio_PortType;


typedef enum
{
	LEVEL_LOW		=0x00,
	LEVEL_HIGH	=0xFF
	
	
}Dio_LevelType;


typedef  uint8	Dio_PortLevelType;





 
#endif  

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
