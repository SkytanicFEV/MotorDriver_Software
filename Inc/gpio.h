/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define VOLTAGE_PHASE_U_Pin GPIO_PIN_0
#define VOLTAGE_PHASE_U_GPIO_Port GPIOA
#define VOLTAGE_PHASE_V_Pin GPIO_PIN_1
#define VOLTAGE_PHASE_V_GPIO_Port GPIOA
#define VOLTAGE_PHASE_W_Pin GPIO_PIN_2
#define VOLTAGE_PHASE_W_GPIO_Port GPIOA
#define CURRENT_PHASE_U_Pin GPIO_PIN_3
#define CURRENT_PHASE_U_GPIO_Port GPIOA
#define CURRENT_PHASE_V_Pin GPIO_PIN_4
#define CURRENT_PHASE_V_GPIO_Port GPIOA
#define CURRENT_PHASE_W_Pin GPIO_PIN_5
#define CURRENT_PHASE_W_GPIO_Port GPIOA
#define THROTTLE_Pin GPIO_PIN_6
#define THROTTLE_GPIO_Port GPIOA
#define PWM_PHASE_W_LOW_Pin GPIO_PIN_0
#define PWM_PHASE_W_LOW_GPIO_Port GPIOB
#define HALL_PHASE_U_Pin GPIO_PIN_12
#define HALL_PHASE_U_GPIO_Port GPIOB
#define HALL_PHASE_V_Pin GPIO_PIN_13
#define HALL_PHASE_V_GPIO_Port GPIOB
#define HALL_PHASE_W_Pin GPIO_PIN_14
#define HALL_PHASE_W_GPIO_Port GPIOB
#define PWM_PHASE_U_LOW_Pin GPIO_PIN_6
#define PWM_PHASE_U_LOW_GPIO_Port GPIOC
#define PWM_PHASE_V_LOW_Pin GPIO_PIN_7
#define PWM_PHASE_V_LOW_GPIO_Port GPIOC
#define PWM_PHASE_U_HIGH_Pin GPIO_PIN_8
#define PWM_PHASE_U_HIGH_GPIO_Port GPIOA
#define PWM_PHASE_V_HIGH_Pin GPIO_PIN_9
#define PWM_PHASE_V_HIGH_GPIO_Port GPIOA
#define PWM_PHASE_W_HIGH_Pin GPIO_PIN_10
#define PWM_PHASE_W_HIGH_GPIO_Port GPIOA


void MX_GPIO_Init(void);


#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
