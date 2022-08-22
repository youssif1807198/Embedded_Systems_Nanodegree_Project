/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "BITMATH.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/*linking time configurations*/
extern uint8 INT_PRIORITY[138];
extern uint8 INT_EN[138];
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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	
	

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
	
	#if PRIGROUP_bxxx
	
	APINT=0xFA05||(0x0 <<8 );

	
	#elif PRIGROUP_bxx_y
	APINT=0xFA05||(0x5 <<8 );
	
	#elif PRIGROUP_bx_yy
	APINT=0xFA05||(0x6<<8 );
	
	
	#elif PRIGROUP_b_yyy
	APINT=0xFA05||(0x7 <<8 );
	
	
	#else
	APINT=0xFA05||(0x0 <<8 );
	#endif
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
	

	volatile PRIx_BF* PRIx;
	PRIx=(uint32*)(PRI_BASE_ADDR);

	
	for(uint8 i=0;i<=138;i++)
	{
		if(INT_PRIORITY[i]!=0)
		{
			switch(i%4)
			{
				
			case 0:	(PRIx+	(i/4)	)->INTA=INT_PRIORITY[i];
			break;
			
			case 1:	(PRIx+	(i/4)	)->INTB=INT_PRIORITY[i];
			break;
			
			case 2:	(PRIx+	(i/4)	)->INTC=INT_PRIORITY[i];
			break;
			
			case 3:	(PRIx+	(i/4)	)->INTD=INT_PRIORITY[i];
			break;
			
			default:
			break;

			}			
			
		}		
		
	}
	
			volatile PRIx_BF* SYS_PRI_1;
			volatile PRIx_BF* SYS_PRI_2;
			volatile PRIx_BF* SYS_PRI_3;


	
	#if	MEM_PRI		!= 0

		SYS_PRI_1=(uint32*)(SYS_PRI_1_ADDR);
	//0xE000ED18;
	//SYS_PRI_1_ADDR;
		SYS_PRI_1->INTA=MEM_PRI;
	
	#endif

	#if	BUS_PRI		!= 0
	
	  SYS_PRI_1=(uint32*)(SYS_PRI_1_ADDR);
		SYS_PRI_1->INTB=BUS_PRI;
	
	#endif
	
	#if	USAGE_PRI	!= 0
	
	  SYS_PRI_1=(uint32*)(SYS_PRI_1_ADDR);
		SYS_PRI_1->INTC=USAGE_PRI;
	
	#endif
	
	#if	SVC_PRI		!= 0
	
		SYS_PRI_2=(uint32*)(SYS_PRI_2_ADDR);
		SYS_PRI_2->INTD=SVC_PRI;
	
	#endif
	
	#if	DEBUG_PRI	!= 0
	
		SYS_PRI_3=(uint32*)(SYS_PRI_3_ADDR);
		SYS_PRI_3->INTA=DEBUG_PRI;
	
	#endif
	
	#if	PENDSV_PRI	!= 0
	
		SYS_PRI_3=(uint32*)(SYS_PRI_3_ADDR);
		SYS_PRI_3->INTC=PENDSV_PRI;
	
	#endif
	
	#if	TICK_PRI	!= 0	
	
		SYS_PRI_3=(uint32*)(SYS_PRI_3_ADDR);
		SYS_PRI_3->INTD=TICK_PRI;
	
	#endif	



	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
	for( i=0;i<138;i++)
	{
		if(INT_EN[i]!=0)
		{
			/*enable interrupts*/
			switch(i/32)
			{
			
			case 0:SET_BIT(EN0,i%32);
			break;
			
			case 1:SET_BIT(EN1,i%32);
			break;			
			
			case 2:SET_BIT(EN2,i%32);
			break;			
			
			case 3:SET_BIT(EN3,i%32);
			break;			
			
			case 4:SET_BIT(EN4,i%32);
			break;

			default:
			break;	
			
			}
		}
			
		
	}
	
	#if MEM
	SET_BIT(SYS_CTRL,16);
	#else
	CLEAR_BIT(SYS_CTRL,16);
	#endif
	
	#if BUS
	SET_BIT(SYS_CTRL,17);
	#else
	CLEAR_BIT(SYS_CTRL,17);
	#endif
	
	#if USAGE
	SET_BIT(SYS_CTRL,18);
	#else
	CLEAR_BIT(SYS_CTRL,18);
	#endif
	
	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
