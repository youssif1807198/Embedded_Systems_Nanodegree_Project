/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Led.c
 *        \brief  LED Functions
 *
 *      \details  The Driver Provide APIs to deal with LED
 *                
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

#include "IntCtrl.h"
#include "IntCtrl_Types.h"

#include "Dio.h"
#include "Dio_Types.h"

#include "Port.h"
#include "Port_Types.h"


/* #include "Gpt.h"
#include "Gpt_Types.h" */

#include "SysTick.h"

#include "BITMATH.h"
#include "Led.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static void (*ptr_LedOn)(void);
static void (*ptr_LedOff)(void );




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/*****************************/
extern Port_ConfigType ConfigType[3];




/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void Func_Callback_LedOn(void);
static void Func_Callback_LedOff(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

static void Func_Callback_LedOn(void)
{
	Dio_WriteChannel( CH_PA0, LEVEL_HIGH);
	Dio_WriteChannel( CH_PA1, LEVEL_HIGH);
	Dio_WriteChannel( CH_PA2, LEVEL_HIGH);
	
}

static void Func_Callback_LedOff(void)
{
		Dio_WriteChannel( CH_PA0, LEVEL_LOW);
		Dio_WriteChannel( CH_PA1, LEVEL_LOW);
		Dio_WriteChannel( CH_PA2, LEVEL_LOW);
	
}





/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




void Led_Init (void)
{
	/*FILLING LINKING CONFIGURATION FOR PORT TYPE*/
	ConfigType[0].PinDirectionType=Pin_Output;
	ConfigType[0].PinInternalAttachType=Pull_Up;
	ConfigType[0].PinType=Pin0_PortA;
	ConfigType[0].PinLevelValue=Level_High;
	ConfigType[0].PinOutputCurrentType=Current_8mA;
	ConfigType[0].PinModeType=DIO;
	
	ConfigType[1].PinDirectionType=Pin_Output;
	ConfigType[1].PinInternalAttachType=Pull_Up;
	ConfigType[1].PinType=Pin1_PortA;
	ConfigType[1].PinLevelValue=Level_High;
	ConfigType[1].PinOutputCurrentType=Current_8mA;
	ConfigType[1].PinModeType=DIO;
	
	ConfigType[2].PinDirectionType=Pin_Output;
	ConfigType[2].PinInternalAttachType=Pull_Up;
	ConfigType[2].PinType=Pin2_PortA;
	ConfigType[2].PinLevelValue=Level_High;
	ConfigType[2].PinOutputCurrentType=Current_8mA;
	ConfigType[2].PinModeType=DIO;	
	
	Port_Init((const Port_ConfigType *)&ConfigType[0]);
	IntCrtl_Init();
	SysTick_Init();
	
	ptr_LedOn=Func_Callback_LedOn;
	ptr_LedOff=Func_Callback_LedOff;
	
	Systick_EnableNotification(ptr_LedOn,ptr_LedOff);

	
	
	
	
}


void Led_Toggle(uint8 ON_Time_Sec,uint8 OFF_Time_Sec)
{
	
	StartTimer(ON_Time_Sec,OFF_Time_Sec);
	
	
}












	
	
	
	

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
*********************************************************************************************************************/
