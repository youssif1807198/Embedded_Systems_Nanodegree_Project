/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  port Driver
 *
 *      \details  The Driver Provide port init function
 *                
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Mcu_Hw.h"
#include "BITMATH.h"
#include "Port_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern Port_ConfigType ConfigType[3];

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
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)                                      
* \Description     : function shall return the value of the
*					 specified DIO channel.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Port_Init(const Port_ConfigType* ConfigPtr)
{
	for(int i=0 ;i<=2;i++)
	{
		

		switch(ConfigPtr[i].PinType/8)
		{
			/*PORTA*/
			case 0:
			
			/*Activate clock for each port it shall not included in this driver but we do it as we havent wrriten MCU DRVIER*/
				SYSCTL_RCGCGPIO_R |=0x01;
				while ((SYSCTL_PRGPIO_R&0x01)==0);
				
			/*TODO:COMMIT CONTROL*/
			*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOLOCK_Offest))= 0x4C4F434B;
			*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOCR_Offest))= 1U;
			
			if(ConfigPtr[i].PinModeType==DIO)
			{
				/*TODO:MODE CONTROL*/
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO:Data CONTROL*/
				if(ConfigPtr[i].PinDirectionType==Pin_Output)
				{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);
			
				}
				else
				{
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);	
					
				}
				
			/*DIGITAL ENABLE*/
			
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO: WRITE PIN LEVEL VALUE*/
					
				*(	(volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+(0x4<<	(ConfigPtr[i].PinType%8))	)	)=ConfigPtr[i].PinLevelValue;
					
					
				

	
				
				
				
			}
			else if(ConfigPtr[i].PinModeType==INT)
			{
				
			/*set interrupt in the masked interrupt*/

				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOIM_Offest))	, ConfigPtr[i].PinType%8);
				
				
			}
			else
			{
				/*TODO:MODE CONTROL*/
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOPCTL_Offest))=ConfigPtr[i].PinModeType<<(4*ConfigPtr[i].PinType%8);

				CLEAR_BIT(*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
	
				
	
			}
			
			/*Pad control*/
			if(ConfigPtr[i].PinInternalAttachType==Pull_Up)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOPUR_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinInternalAttachType==Pull_Down)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOPDR_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinInternalAttachType==Open_Drain)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIOODR_Offest))	, ConfigPtr[i].PinType%8);
				
			}


			if(ConfigPtr[i].PinOutputCurrentType==Current_2mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIODR2R_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_4mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIODR4R_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_8mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTA_BASE_ADDRESS+GPIODR8R_Offest))	, ConfigPtr[i].PinType%8);
				
			}			
			
			
			
			
			break;
			
			
			/*PORTB*/
			case 1:
			
			/*Activate clock for each port it shall not included in this driver but we do it as we havent wrriten MCU DRVIER*/
				SYSCTL_RCGCGPIO_R |=0x02;
				while ((SYSCTL_PRGPIO_R&0x02)==0);
				
			/*TODO:COMMIT CONTROL*/
			*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOLOCK_Offest))= 0x4C4F434B;
			*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOCR_Offest))= 1U;
			
			if(ConfigPtr[i].PinModeType==DIO)
			{
				/*TODO:MODE CONTROL*/
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO:Data CONTROL*/
				if(ConfigPtr[i].PinDirectionType==Pin_Output)
				{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);
			
				}
				else
				{
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);	
					
				}
				
			/*DIGITAL ENABLE*/
			
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO: WRITE PIN LEVEL VALUE*/
					
				*(	(volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+(0x4<<	(ConfigPtr[i].PinType%8))	)	)=ConfigPtr[i].PinLevelValue;
					
					
				

	
				
				
				
			}
			else if(ConfigPtr[i].PinModeType==INT)
			{
				
			/*set interrupt in the masked interrupt*/

				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOIM_Offest))	, ConfigPtr[i].PinType%8);
				
				
			}
			else
			{
				/*TODO:MODE CONTROL*/
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOPCTL_Offest))=ConfigPtr[i].PinModeType<<(4*ConfigPtr[i].PinType%8);

				CLEAR_BIT(*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
	
				
	
			}
			
			/*Pad control*/
			if(ConfigPtr[i].PinInternalAttachType==Pull_Up)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOPUR_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinInternalAttachType==Pull_Down)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOPDR_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinInternalAttachType==Open_Drain)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIOODR_Offest))	, ConfigPtr[i].PinType%8);
				
			}


			if(ConfigPtr[i].PinOutputCurrentType==Current_2mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIODR2R_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_4mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIODR4R_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_8mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTB_BASE_ADDRESS+GPIODR8R_Offest))	, ConfigPtr[i].PinType%8);
				
			}			
			
			
			
			
			break;			
			

			/*PORTC*/
			
			case 2:
			
			/*Activate clock for each port it shall not included in this driver but we do it as we havent wrriten MCU DRVIER*/
				SYSCTL_RCGCGPIO_R |=0x04;
				while ((SYSCTL_PRGPIO_R&0x04)==0);
				
			/*TODO:COMMIT CONTROL*/
			*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOLOCK_Offest))= 0x4C4F434B;
			*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOCR_Offest))= 1U;
			
			if(ConfigPtr[i].PinModeType==DIO)
			{
				/*TODO:MODE CONTROL*/
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO:Data CONTROL*/
				if(ConfigPtr[i].PinDirectionType==Pin_Output)
				{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);
			
				}
				else
				{
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);	
					
				}
				
			/*DIGITAL ENABLE*/
			
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO: WRITE PIN LEVEL VALUE*/
					
				*(	(volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+(0x4<<	(ConfigPtr[i].PinType%8))	)	)=ConfigPtr[i].PinLevelValue;
					
					
				

	
				
				
				
			}
			else if(ConfigPtr[i].PinModeType==INT)
			{
				
			/*set interrupt in the masked interrupt*/

				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOIM_Offest))	, ConfigPtr[i].PinType%8);
				
				
			}
			else
			{
				/*TODO:MODE CONTROL*/
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOPCTL_Offest))=ConfigPtr[i].PinModeType<<(4*ConfigPtr[i].PinType%8);

				CLEAR_BIT(*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
	
				
	
			}
			
			/*Pad control*/
			if(ConfigPtr[i].PinInternalAttachType==Pull_Up)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOPUR_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinInternalAttachType==Pull_Down)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOPDR_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinInternalAttachType==Open_Drain)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIOODR_Offest))	, ConfigPtr[i].PinType%8);
				
			}


			if(ConfigPtr[i].PinOutputCurrentType==Current_2mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIODR2R_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_4mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIODR4R_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_8mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+GPIODR8R_Offest))	, ConfigPtr[i].PinType%8);
				
			}			
			
			
			
			
			break;						
			


			/*PORTD*/
			case 3:
			
			/*Activate clock for each port it shall not included in this driver but we do it as we havent wrriten MCU DRVIER*/
				SYSCTL_RCGCGPIO_R |=0x08;
				while ((SYSCTL_PRGPIO_R&0x08)==0);
				
			/*TODO:COMMIT CONTROL*/
			*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOLOCK_Offest))= 0x4C4F434B;
			*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOCR_Offest))= 1U;
			
			if(ConfigPtr[i].PinModeType==DIO)
			{
				/*TODO:MODE CONTROL*/
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO:Data CONTROL*/
				if(ConfigPtr[i].PinDirectionType==Pin_Output)
				{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);
			
				}
				else
				{
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);	
					
				}
				
			/*DIGITAL ENABLE*/
			
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO: WRITE PIN LEVEL VALUE*/
					
				*(	(volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+(0x4<<	(ConfigPtr[i].PinType%8))	)	)=ConfigPtr[i].PinLevelValue;
					
					
				

	
				
				
				
			}
			else if(ConfigPtr[i].PinModeType==INT)
			{
				
			/*set interrupt in the masked interrupt*/

				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOIM_Offest))	, ConfigPtr[i].PinType%8);
				
				
			}
			else
			{
				/*TODO:MODE CONTROL*/
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOPCTL_Offest))=ConfigPtr[i].PinModeType<<(4*ConfigPtr[i].PinType%8);

				CLEAR_BIT(*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
	
				
	
			}
			
			/*Pad control*/
			if(ConfigPtr[i].PinInternalAttachType==Pull_Up)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOPUR_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinInternalAttachType==Pull_Down)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOPDR_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinInternalAttachType==Open_Drain)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIOODR_Offest))	, ConfigPtr[i].PinType%8);
				
			}


			if(ConfigPtr[i].PinOutputCurrentType==Current_2mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIODR2R_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_4mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIODR4R_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_8mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTD_BASE_ADDRESS+GPIODR8R_Offest))	, ConfigPtr[i].PinType%8);
				
			}			
			
			
			
			
			break;	



			/*PORTE*/
			case 4:
			
			/*Activate clock for each port it shall not included in this driver but we do it as we havent wrriten MCU DRVIER*/
				SYSCTL_RCGCGPIO_R |=16U;
				while ((SYSCTL_PRGPIO_R&16U)==0);
				
			/*TODO:COMMIT CONTROL*/
			*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOLOCK_Offest))= 0x4C4F434B;
			*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOCR_Offest))= 1U;
			
			if(ConfigPtr[i].PinModeType==DIO)
			{
				/*TODO:MODE CONTROL*/
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO:Data CONTROL*/
				if(ConfigPtr[i].PinDirectionType==Pin_Output)
				{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);
			
				}
				else
				{
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);	
					
				}
				
			/*DIGITAL ENABLE*/
			
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO: WRITE PIN LEVEL VALUE*/
					
				*(	(volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+(0x4<<	(ConfigPtr[i].PinType%8))	)	)=ConfigPtr[i].PinLevelValue;
					
					
				

	
				
				
				
			}
			else if(ConfigPtr[i].PinModeType==INT)
			{
				
			/*set interrupt in the masked interrupt*/

				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOIM_Offest))	, ConfigPtr[i].PinType%8);
				
				
			}
			else
			{
				/*TODO:MODE CONTROL*/
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOPCTL_Offest))=ConfigPtr[i].PinModeType<<(4*ConfigPtr[i].PinType%8);

				CLEAR_BIT(*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
	
				
	
			}
			
			/*Pad control*/
			if(ConfigPtr[i].PinInternalAttachType==Pull_Up)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOPUR_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinInternalAttachType==Pull_Down)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOPDR_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinInternalAttachType==Open_Drain)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIOODR_Offest))	, ConfigPtr[i].PinType%8);
				
			}


			if(ConfigPtr[i].PinOutputCurrentType==Current_2mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIODR2R_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_4mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIODR4R_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_8mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTE_BASE_ADDRESS+GPIODR8R_Offest))	, ConfigPtr[i].PinType%8);
				
			}			
			
			
			
			
			break;

			/*PORTF*/
			case 5:
			
			/*Activate clock for each port it shall not included in this driver but we do it as we havent wrriten MCU DRVIER*/
				SYSCTL_RCGCGPIO_R |=32U;
				while ((SYSCTL_PRGPIO_R&32U)==0);
				
			/*TODO:COMMIT CONTROL*/
			*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOLOCK_Offest))= 0x4C4F434B;
			*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOCR_Offest))= 1U;
			
			if(ConfigPtr[i].PinModeType==DIO)
			{
				/*TODO:MODE CONTROL*/
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO:Data CONTROL*/
				if(ConfigPtr[i].PinDirectionType==Pin_Output)
				{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);
			
				}
				else
				{
				CLEAR_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIODIR_Offest))	, ConfigPtr[i].PinType%8);	
					
				}
				
			/*DIGITAL ENABLE*/
			
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
				
				/*TODO: WRITE PIN LEVEL VALUE*/
					
				*(	(volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+(0x4<<	(ConfigPtr[i].PinType%8))	)	)=ConfigPtr[i].PinLevelValue;
					
					
				

	
				
				
				
			}
			else if(ConfigPtr[i].PinModeType==INT)
			{
				
			/*set interrupt in the masked interrupt*/

				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOIM_Offest))	, ConfigPtr[i].PinType%8);
				
				
			}
			else
			{
				/*TODO:MODE CONTROL*/
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOAFSEL_Offest))	, ConfigPtr[i].PinType%8);
				
				*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOPCTL_Offest))=ConfigPtr[i].PinModeType<<(4*ConfigPtr[i].PinType%8);

				CLEAR_BIT(*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIODEN_Offest))	, ConfigPtr[i].PinType%8);
	
				
	
			}
			
			/*Pad control*/
			if(ConfigPtr[i].PinInternalAttachType==Pull_Up)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOPUR_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinInternalAttachType==Pull_Down)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOPDR_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinInternalAttachType==Open_Drain)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIOODR_Offest))	, ConfigPtr[i].PinType%8);
				
			}


			if(ConfigPtr[i].PinOutputCurrentType==Current_2mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIODR2R_Offest))	, ConfigPtr[i].PinType%8);

			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_4mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIODR4R_Offest))	, ConfigPtr[i].PinType%8);
	
			}
			else if(ConfigPtr[i].PinOutputCurrentType==Current_8mA)
			{
				SET_BIT(	*((volatile uint32 *)(GPIODATA_PORTF_BASE_ADDRESS+GPIODR8R_Offest))	, ConfigPtr[i].PinType%8);
				
			}			
			
			
			
			
			break;				
			
			
		}
		 
		
		
					
			
			
		}
		 
		
		
		
		
		
		
		
		
	}
	
	






/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
