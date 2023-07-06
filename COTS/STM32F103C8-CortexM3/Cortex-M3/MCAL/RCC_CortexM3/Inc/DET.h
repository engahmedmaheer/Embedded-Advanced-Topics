/*
 * DET.h
 *
 *  Created on: Apr 14, 2023
 *      Author: AhmedMaher
 */

#ifndef DET_H_
#define DET_H_



typedef enum {
				DET_RCCModuleID,

}DET_module_ID_E;

typedef enum {

				DET_RCC_VoidSetClkStatues,
				DET_RCC_VoidSetSysClk,
				DET_RCC_VoidHSEConfig,
				DET_RCC_voidEnablePeripheralBus,
}DET_function_ID_E;

typedef enum {
			DET_busId,
			DET_peripheralId,
			DET_clocktype,
			DET_MAX_AHB_ID,
			DET_MAX_APB1_ID,
			DET_MAX_APB2_ID,
}DET_error_ID_E;

void DET_ReportError(DET_module_ID_E   module_ID   ,
					 DET_function_ID_E function_ID ,
					 DET_error_ID_E    error_ID  );


#endif /* DET_H_ */
