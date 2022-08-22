
//#include "IntCtrl.h"
//#include "IntCtrl_Types.h"
//#include "Dio.h"
//#include "Dio_Types.h"
#include "Port.h"
#include "Port_Types.h"
#include "Mcu_Hw.h"


extern Port_ConfigType ConfigType[3];

int main(void)
{



	ConfigType[0].PinDirectionType=Pin_Output;
	ConfigType[0].PinInternalAttachType=Open_Drain;
	ConfigType[0].PinType=Pin0_PortA;
	ConfigType[0].PinLevelValue=Level_High;
	ConfigType[0].PinOutputCurrentType=Current_8mA;
	ConfigType[0].PinModeType=DIO;
	
	ConfigType[1].PinDirectionType=Pin_Output;
	ConfigType[1].PinInternalAttachType=Open_Drain;
	ConfigType[1].PinType=Pin1_PortB;
	ConfigType[1].PinLevelValue=Level_High;
	ConfigType[1].PinOutputCurrentType=Current_8mA;
	ConfigType[1].PinModeType=DIO;
	
	ConfigType[2].PinDirectionType=Pin_Output;
	ConfigType[2].PinInternalAttachType=Open_Drain;
	ConfigType[2].PinType=Pin5_PortC;
	ConfigType[2].PinLevelValue=Level_High;
	ConfigType[2].PinOutputCurrentType=Current_8mA;
	ConfigType[2].PinModeType=DIO;
	
	Port_Init((const Port_ConfigType *)&ConfigType[0]);
//					*(	(volatile uint32 *)(GPIODATA_PORTC_BASE_ADDRESS+(0x4<<	(1%8))	)	)=0xFF;

//	Dio_WriteChannel( CH_PC2, LEVEL_HIGH);


while(1);
return 0;
}
