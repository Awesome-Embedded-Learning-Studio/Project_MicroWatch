#ifndef STM32G4xx_HAL_CONF_H
#define STM32G4xx_HAL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* ── 启用所有 HAL 模块（链接时由 --gc-sections 自动裁剪）────────── */
#define HAL_MODULE_ENABLED
#define HAL_ADC_MODULE_ENABLED
#define HAL_COMP_MODULE_ENABLED
#define HAL_CORDIC_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_CRC_MODULE_ENABLED
#define HAL_CRYP_MODULE_ENABLED
#define HAL_DAC_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_FDCAN_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_FMAC_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_HRTIM_MODULE_ENABLED
#define HAL_IRDA_MODULE_ENABLED
#define HAL_IWDG_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#define HAL_I2S_MODULE_ENABLED
#define HAL_LPTIM_MODULE_ENABLED
#define HAL_NAND_MODULE_ENABLED
#define HAL_NOR_MODULE_ENABLED
#define HAL_OPAMP_MODULE_ENABLED
#define HAL_PCD_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_QSPI_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_RNG_MODULE_ENABLED
#define HAL_RTC_MODULE_ENABLED
#define HAL_SAI_MODULE_ENABLED
#define HAL_SMARTCARD_MODULE_ENABLED
#define HAL_SMBUS_MODULE_ENABLED
#define HAL_SPI_MODULE_ENABLED
#define HAL_SRAM_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_USART_MODULE_ENABLED
#define HAL_WWDG_MODULE_ENABLED

/* ── 时钟值（无外部晶振则只留 HSI）──────────────────────────────── */
#define HSE_VALUE 8000000UL
#define HSE_STARTUP_TIMEOUT 100U
#define HSI_VALUE 16000000UL
#define HSI48_VALUE 48000000UL
#define LSI_VALUE 32000UL
#define LSE_VALUE 32768UL
#define LSE_STARTUP_TIMEOUT 5000U
#define EXTERNAL_CLOCK_VALUE 12288000UL

/* ── 系统配置 ────────────────────────────────────────────────────── */
#define  VDD_VALUE                    (3300UL)
#define  TICK_INT_PRIORITY            (0x0FUL)
#define  USE_RTOS                     0U
#define  PREFETCH_ENABLE              0U
#define  INSTRUCTION_CACHE_ENABLE     1U
#define  DATA_CACHE_ENABLE            1U

/* ── HAL 通用超时 ────────────────────────────────────────────────── */
#define HAL_TIMEOUT_VALUE 0xFFFFFFFFU

/* ── 断言（调试期打开，发布时关闭）──────────────────────────────── */
/* #define USE_FULL_ASSERT 1U */

/* ── 包含所有 HAL 驱动头文件（固定写法，不要改）─────────────────── */
#ifdef HAL_RCC_MODULE_ENABLED
#include "stm32g4xx_hal_rcc.h"
#endif
#ifdef HAL_GPIO_MODULE_ENABLED
#include "stm32g4xx_hal_gpio.h"
#endif
#ifdef HAL_DMA_MODULE_ENABLED
#include "stm32g4xx_hal_dma.h"
#endif
#ifdef HAL_CORTEX_MODULE_ENABLED
#include "stm32g4xx_hal_cortex.h"
#endif
#ifdef HAL_ADC_MODULE_ENABLED
#include "stm32g4xx_hal_adc.h"
#endif
#ifdef HAL_COMP_MODULE_ENABLED
#include "stm32g4xx_hal_comp.h"
#endif
#ifdef HAL_CORDIC_MODULE_ENABLED
#include "stm32g4xx_hal_cordic.h"
#endif
#ifdef HAL_CRC_MODULE_ENABLED
#include "stm32g4xx_hal_crc.h"
#endif
#ifdef HAL_CRYP_MODULE_ENABLED
#include "stm32g4xx_hal_cryp.h"
#endif
#ifdef HAL_DAC_MODULE_ENABLED
#include "stm32g4xx_hal_dac.h"
#endif
#ifdef HAL_EXTI_MODULE_ENABLED
#include "stm32g4xx_hal_exti.h"
#endif
#ifdef HAL_FDCAN_MODULE_ENABLED
#include "stm32g4xx_hal_fdcan.h"
#endif
#ifdef HAL_FLASH_MODULE_ENABLED
#include "stm32g4xx_hal_flash.h"
#endif
#ifdef HAL_FMAC_MODULE_ENABLED
#include "stm32g4xx_hal_fmac.h"
#endif
#ifdef HAL_HRTIM_MODULE_ENABLED
#include "stm32g4xx_hal_hrtim.h"
#endif
#ifdef HAL_IRDA_MODULE_ENABLED
#include "stm32g4xx_hal_irda.h"
#endif
#ifdef HAL_IWDG_MODULE_ENABLED
#include "stm32g4xx_hal_iwdg.h"
#endif
#ifdef HAL_I2C_MODULE_ENABLED
#include "stm32g4xx_hal_i2c.h"
#endif
#ifdef HAL_I2S_MODULE_ENABLED
#include "stm32g4xx_hal_i2s.h"
#endif
#ifdef HAL_LPTIM_MODULE_ENABLED
#include "stm32g4xx_hal_lptim.h"
#endif
#ifdef HAL_NAND_MODULE_ENABLED
#include "stm32g4xx_hal_nand.h"
#endif
#ifdef HAL_NOR_MODULE_ENABLED
#include "stm32g4xx_hal_nor.h"
#endif
#ifdef HAL_OPAMP_MODULE_ENABLED
#include "stm32g4xx_hal_opamp.h"
#endif
#ifdef HAL_PCD_MODULE_ENABLED
#include "stm32g4xx_hal_pcd.h"
#endif
#ifdef HAL_PWR_MODULE_ENABLED
#include "stm32g4xx_hal_pwr.h"
#endif
#ifdef HAL_QSPI_MODULE_ENABLED
#include "stm32g4xx_hal_qspi.h"
#endif
#ifdef HAL_RNG_MODULE_ENABLED
#include "stm32g4xx_hal_rng.h"
#endif
#ifdef HAL_RTC_MODULE_ENABLED
#include "stm32g4xx_hal_rtc.h"
#endif
#ifdef HAL_SAI_MODULE_ENABLED
#include "stm32g4xx_hal_sai.h"
#endif
#ifdef HAL_SMARTCARD_MODULE_ENABLED
#include "stm32g4xx_hal_smartcard.h"
#endif
#ifdef HAL_SMBUS_MODULE_ENABLED
#include "stm32g4xx_hal_smbus.h"
#endif
#ifdef HAL_SPI_MODULE_ENABLED
#include "stm32g4xx_hal_spi.h"
#endif
#ifdef HAL_SRAM_MODULE_ENABLED
#include "stm32g4xx_hal_sram.h"
#endif
#ifdef HAL_TIM_MODULE_ENABLED
#include "stm32g4xx_hal_tim.h"
#endif
#ifdef HAL_UART_MODULE_ENABLED
#include "stm32g4xx_hal_uart.h"
#endif
#ifdef HAL_USART_MODULE_ENABLED
#include "stm32g4xx_hal_usart.h"
#endif
#ifdef HAL_WWDG_MODULE_ENABLED
#include "stm32g4xx_hal_wwdg.h"
#endif

/* ── assert_param ────────────────────────────────────────────────── */
#ifdef USE_FULL_ASSERT
#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
void assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif

#ifdef __cplusplus
}
#endif

#endif /* STM32G4xx_HAL_CONF_H */
