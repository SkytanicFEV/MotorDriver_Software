/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

// Enum for phases
typedef enum
{
	phase_U = 0,
	phase_V,
	phase_W,
}phase_t;
// Enum describing switch state
typedef enum
{
	switchOff = 0,
	switchOn,
	switchClosing,
}switchState_t;

// Enum describing the waveform state
typedef enum
{
	waveform_stopped = 0,
	waveform_running,
	waveform_deadTime,
}waveformState_t;

/* Private defines -----------------------------------------------------------*/
// If using the motor driver in single phase mode uncomment this
#define SINGLE_PHASE_MODE

/* USER CODE BEGIN Private defines */
// Frequency of the processor in KHz
#define PROC_FREQ_KHZ					40000U

// Desired frequency of the timers in KHz
#define DESIRED_TIM_FREQ_KHZ		50U

// Waveform defines
#define WAVEFORM_FREQ_HZ				50U
#define WAVEFORM_MAX_COUNT				(uint32_t) ((DESIRED_TIM_FREQ_KHZ * 1000) / WAVEFORM_FREQ_HZ)

// Pre-calculated values of PI for Sine function
#define PI 								(3.14159265)								// Value of Pi
#define TWO_PI							(6.28318531)								// 2 * Pi
#define PI_OVER_TWO						(1.57079632)								// Pi / 2
#define FOUR_OVER_PI					(1.27323954)								// 4 / Pi
#define FOUR_OVER_PI2					(.405284735)								// 4 / (Pi^2)

// Sine calculation constants
#define SINE_ACCURACY_CONSTANT			(.225)										// Constant used when increasing accuracy of sine

// Amount of dead time in between waveform polarities in ticks of TIM3
#define WAVEFORM_DEADTIME				1U

#define NUM_ADC_CHANNEL					7U

#define THROTTLE_MAX_VALUE				(uint16_t) 4095

// Global waveform variables
uint16_t waveform_frequency;
uint32_t waveformU_switchCount;
uint32_t waveformV_switchCount;
uint32_t waveformW_switchCount;
uint32_t waveform_maxSwitches;

// Create a lookup table for sine values
float sine_lookup[WAVEFORM_MAX_COUNT];

// Switch state variables
switchState_t phaseU_low_state;
switchState_t phaseW_low_state;
switchState_t phaseV_low_state;

switchState_t phaseU_high_state;
switchState_t phaseW_high_state;
switchState_t phaseV_high_state;

// Waveform state variables
waveformState_t waveformU_state;
waveformState_t waveformV_state;
waveformState_t waveformW_state;

// ADC buffer
uint32_t adc_buffer[NUM_ADC_CHANNEL];

// Throttle variables
uint16_t throttleValue;

// Max value of output waveform
uint16_t waveformAmplitude;


/**
  * @brief Function to update a specific phase waveform
  * @param phase to update
  * @retval none
  */
void UpdateWaveform(phase_t phase);

/**
  * @brief Use the fast sin algorithm to calculate sin(x)
  * @param x = input to sin(x)
  * @retval floating point value of result
  */
float fast_sin(float x);

/**
  * @brief Creates a lookup table for the sine wave
  * @param none
  * @retval none
  */
void Create_SineTable(void);

void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
