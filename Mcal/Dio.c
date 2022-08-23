/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital input/output Driver
 *
 *      \details  The Driver Provide APIs to deal with DIO pins
 *                
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Mcu_Hw.h"
#include "BITMATH.h"
#include "Dio_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/*****************************/



/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)                                      
* \Description     : function shall return the value of the
*					 specified DIO channel.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId                      
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	
	Dio_LevelType Dio_LevelType_Return=-1;
	
	switch(ChannelId/8)
	{
		case 0:

		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTA_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);
		break;
		
		case 1:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTB_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);
		break;
		
		case 2:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTC_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);
		break;
		
		case 3:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTD_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);
		break;
		
		case 4:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTE_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);
		break;

		case 5:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTF_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);
		break;		
	
		
		default:
		break;
		
		return Dio_LevelType_Return ;
		
		
		
	}
	
	
	
	
	
	
	
}




/******************************************************************************
* \Syntax          : void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )                                      
* \Description     : Service to set a level of a channel.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId,
*					 Level                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	
	switch(ChannelId/8)
	{
		case 0:

		*(	(volatile uint32 *)	(GPIODATA_PORTA_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	Level;
		break;
		
		case 1:
		*(	(volatile uint32 *)	(GPIODATA_PORTB_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	Level;
		break;
		
		case 2:
		*(	(volatile uint32 *)	(GPIODATA_PORTC_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	Level;
		break;
		
		case 3:
		*(	(volatile uint32 *)	(GPIODATA_PORTD_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	Level;
		break;
		
		case 4:
		*(	(volatile uint32 *)	(GPIODATA_PORTE_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	Level;
		break;

		case 5:
			
		*(	(volatile uint32 *)	(GPIODATA_PORTF_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	Level;
		break;		
	
		
		default:
		break;
		
		
		
	}
	
	}
	
	
	
/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )                                      
* \Description     : Returns the level of all channels of that port.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId                      
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType
*******************************************************************************/

Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
	
	Dio_PortLevelType Dio_LevelType_Return=-1;
	
	switch(PortId)
	{
		case PORTA:

		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTA_BASE_ADDRESS + 0x3FC) );
		break;
		
		case PORTB:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTB_BASE_ADDRESS+ 0x3FC) );
		break;
		
		case PORTC:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTC_BASE_ADDRESS+ 0x3FC) );
		break;
		
		case PORTD:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTD_BASE_ADDRESS+ 0x3FC) );
		break;
		
		case PORTE:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTE_BASE_ADDRESS+ 0x3FC) );
		break;

		case PORTF:
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTF_BASE_ADDRESS+ 0x3FC) );
		break;		
	
		
		default:
		break;
		
		return Dio_LevelType_Return ;
		
		
		
	}
}
	
	
	
	
/******************************************************************************
* \Syntax          : void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )                                      
* \Description     : Service to set a value of the port.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId,Level                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level ) 
{
	
	
	switch(PortId)
	{
		case PORTA:

		*(	(volatile uint32 *)	(GPIODATA_PORTA_BASE_ADDRESS+ 0x3FC)	)=	Level;
		break;
		
		case PORTB:
		*(	(volatile uint32 *)	(GPIODATA_PORTB_BASE_ADDRESS+ 0x3FC)	)=	Level;
		break;
		
		case PORTC:
		*(	(volatile uint32 *)	(GPIODATA_PORTC_BASE_ADDRESS+ 0x3FC)	)=	Level;
		break;
		
		case PORTD:
		*(	(volatile uint32 *)	(GPIODATA_PORTD_BASE_ADDRESS)+ 0x3FC	)=	Level;
		break;
		
		case PORTE:
		*(	(volatile uint32 *)	(GPIODATA_PORTE_BASE_ADDRESS)+ 0x3FC )	=	Level;
		break;

		case PORTF:
		*(	(volatile uint32 *)	(GPIODATA_PORTF_BASE_ADDRESS)+ 0x3FC )	=	Level;
		break;		
	
		
		default:
		break;
		

		
	}
		
	}



/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId}                                      
* \Description     : Service to set a level of a channel.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId
*					                       
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/

Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	
	Dio_LevelType Dio_LevelType_Return=-1;

	switch(ChannelId/8)
	{
		case 0:

		*(	(volatile uint32 *)	(GPIODATA_PORTA_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	~(*(	(volatile uint32 *)	(GPIODATA_PORTA_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	))	;
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTA_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);

		break;
		
		case 1:

		*(	(volatile uint32 *)	(GPIODATA_PORTB_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	~(*(	(volatile uint32 *)	(GPIODATA_PORTB_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	))	;
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTB_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);

		break;
		
		case 2:

		*(	(volatile uint32 *)	(GPIODATA_PORTC_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	~(*(	(volatile uint32 *)	(GPIODATA_PORTC_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	))	;
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTC_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);

		break;
		
		case 3:

		*(	(volatile uint32 *)	(GPIODATA_PORTD_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	~(*(	(volatile uint32 *)	(GPIODATA_PORTD_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	))	;
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTD_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);

		break;
		
		case 4:

		*(	(volatile uint32 *)	(GPIODATA_PORTE_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	~(*(	(volatile uint32 *)	(GPIODATA_PORTE_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	))	;
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTF_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);

		break;
		
		case 5:

		*(	(volatile uint32 *)	(GPIODATA_PORTF_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	)	=	~(*(	(volatile uint32 *)	(GPIODATA_PORTF_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	))	;
		Dio_LevelType_Return = *(	(volatile uint32 *)	(GPIODATA_PORTF_BASE_ADDRESS+ (0x4<<	(ChannelId %8))	)	);

		break;
		

	
		
		default:
		break;
		
		
		return Dio_LevelType_Return;
		
	}
	
	
	
}

	
	
	
	

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
*********************************************************************************************************************/
