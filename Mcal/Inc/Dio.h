/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H
  
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);


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

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );

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

Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );



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

void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );

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

Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);
 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
