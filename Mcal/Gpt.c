/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief  Digital input/output Driver
 *
 *      \details  The Driver Provide APIs to deal with Timer 
 *                
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt.h"
#include "Mcu_Hw.h"
#include "BITMATH.h"
#include "Gpt_Types.h"

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
* \Syntax          : void Gpt_Init( const Gpt_ConfigType* ConfigPtr )                                      
* \Description     : Initializes the GPT driver.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr )
{
	/*
	Gpt_ChannelType 	GptChannelId;
	Gpt_ValueType		GptChannelTickValueMax;
	Gpt_ModeType		ChannelMode;
	Gpt_PredefTimerType	PredefTimerType;
	GPT_TickFrequency 	GptChannelTickFrequency;
	void (*GptNotification)(void);
	
	
	*/
	
	/*TODO:enable timer clock*/
	
			/*Activate clock for each TIMER it shall not included in this driver but we do it as we havent wrriten MCU DRVIER*/
					SYSCTL_RCGCGPIO_R |=0x02;
				while ((SYSCTL_PRGPIO_R&0x01)==0);			
	SYSCTL_RCGCTIMER_R |=0x3F;
				while ((SYSCTL_PRTIMER_R&0x02)==0);	
				
				
				

	
	/*TODO:1.Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making any changes.*/
	
			CLEAR_BIT( *(	(uint32 *)(TIMER_0_BASE_ADDRESS+(0x1000	*	(ConfigPtr->GptChannelId))+	GPTMCTL_Offest))	,0) ;


	/*TODO:2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000.*/
	
		*(	(uint32 *)(TIMER_0_BASE_ADDRESS+(0x1000	*	(ConfigPtr->GptChannelId))+	GPTMCTL_Offest) ) =	0x00000000;
		
	
	/*TODO:3select mode	/*TODO:3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR) */

	if(ConfigPtr->ChannelMode == GPT_CH_MODE_CONTINOUS)
	{
		
		
				(*(	(uint32 *)(TIMER_0_BASE_ADDRESS+(0x1000	*	(ConfigPtr->GptChannelId))+	GPTMTAMR_Offest)	) )	|= (0x2) ;
		
	}
	else
	{
		
				(*(	(uint32 *)(TIMER_0_BASE_ADDRESS+(0x1000	*	(ConfigPtr->GptChannelId))+	GPTMTAMR_Offest)	) )	|= (0x1) ;
		
	}
	
	
	/*TODO:4. If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register (GPTMIMR)*/
	
				SET_BIT(*(	(uint32 *)(TIMER_0_BASE_ADDRESS+(0x1000	*	(ConfigPtr->GptChannelId))+	GPTMIMR_Offest))	,0) ;

	

	
		/*Configure predefined timer*/
		//use timer 5_A as predefined timer 
	
	/*TODO:1.Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making any changes.*/
	
			CLEAR_BIT(*(	(uint32 *)(TIMER_5_BASE_ADDRESS+GPTMCTL_Offest) )	,0) ;
			
			
			
	/*TODO:2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000.*/
	
		*(	(uint32 *)(TIMER_5_BASE_ADDRESS+ GPTMCTL_Offest	) )=	0x00000000;

		
	
			
	/*TODO:3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR) AS ONE SHOT MODE */
	
		(*(	(uint32 *)(TIMER_5_BASE_ADDRESS+GPTMTAMR_Offest)	) ) |= (0x2) ;

	
	

	
	/*TODO:4. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).*/
		*(	(uint32 *)(TIMER_5_BASE_ADDRESS+ GPTMTAILR_Offest	) )=	0x00000000;

	
	/*TODO:5. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.*/
	
		SET_BIT(*(	(uint32 *)(TIMER_5_BASE_ADDRESS+GPTMCTL_Offest) )	,0) ;

	
	
}	
	
	
	

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
*********************************************************************************************************************/
