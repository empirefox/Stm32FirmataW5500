#pragma once

#include <stdint.h>

// #include "stm32f4xx_hal_conf.h"
/** @addtogroup STM32F4xx_HAL_Examples
 * @{
 */

/** @defgroup HAL_MSP
 * @brief HAL MSP module.
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
 * @{
 */

/**
 * @brief  Initializes the HASH MSP.
 *        This function configures the hardware resources used in this example:
 *           - HASH's clock enable
 * @param  hhash: HASH handle pointer
 * @retval None
 */
// void HAL_HASH_MspInit(HASH_HandleTypeDef *hhash);
int init_mac_address(uint8_t* mac);
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
