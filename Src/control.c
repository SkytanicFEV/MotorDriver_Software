/*
 * control.c
 *
 *  Created on: Dec 5, 2019
 *      Author: alex
 */

#include "main.h"


/**
  * @brief Function to update a specific phase waveform
  * @param phase to update
  * @retval none
  */
void UpdateWaveform(phase_t phase)
{
	switch(phase)
	{
	case phase_U:
	    // Check to see if waveform U is running
	    if(waveformU_state == waveform_running)
	    {
	        // Increment the waveform count
	        waveformU_switchCount++;
	        // Check to see if there have been enough counts to switch output polarity
	        if(waveformU_switchCount >= waveform_maxSwitches)
	        {
	        	// If the low side is open, indicate that it should be closing and open the high side
	        	if(phaseU_low_state == switchOpen)
	        	{
	        		// Update low side state
	        		phaseU_low_state = switchClosing;

	        		// Update high side state
	        		phaseU_high_state = switchOpen;
	        		// Update high side duty cycle
	        		TIM1->CCR1 = 0;
	        	}
	        	// else turn it off, and update the states of low and high side
	        	else if(phaseU_low_state == switchClosed)
	        	{
	        		// Update low side state
	        		phaseU_low_state = switchOpen;
	        		// Update low side duty cycle
	        		TIM3->CCR1 = 0;

	        		// Update high side state
	        		phaseU_high_state = switchClosing;
	        	}

	        	// Reset the switch count
	        	waveformU_switchCount = 0;
	        	// Enter deadtime
	        	waveformU_state = waveform_deadTime;
	        }
	    }
	    else if(waveformU_state == waveform_deadTime)
	    {
	        // Increment the waveform count
	        waveformU_switchCount++;
	        // Check to see if there have been enough counts to end the deadtime
	        if(waveformU_switchCount >= WAVEFORM_DEADTIME)
	        {
	        	// If the low side is closing, then turn on the FET
	        	if(phaseU_low_state == switchClosing)
	        	{
	        		TIM3->CCR1 = TIM_PERIOD;
	        		phaseU_low_state = switchClosed;
	        	}
	        	// If the high side is closing, then turn on the high side FET
	        	if(phaseU_high_state == switchClosing)
	        	{
	        		TIM1->CCR1 = TIM_PERIOD / 2;
	        		phaseU_high_state = switchClosed;
	        	}
	        	// Reset switch count
	        	waveformU_switchCount = 0;
	        	// Update waveform state
	        	waveformU_state = waveform_running;
	        }
	    }
		return;
	case phase_V:
	    // Check to see if waveform is running
	    if(waveformV_state == waveform_running)
	    {
	        // Increment the waveform count
	        waveformV_switchCount++;
	        // Check to see if there have been enough counts to switch output polarity
	        if(waveformV_switchCount >= waveform_maxSwitches)
	        {
	        	// If the low side is open, indicate that it should be closing and open the high side
	        	if(phaseV_low_state == switchOpen)
	        	{
	        		// Update low side state
	        		phaseV_low_state = switchClosing;

	        		// Update high side state
	        		phaseV_high_state = switchOpen;
	        		// Update high side duty cycle
	        		TIM1->CCR2 = 0;
	        	}
	        	// else turn it off, and update the states of low and high side
	        	else if(phaseV_low_state == switchClosed)
	        	{
	        		// Update low side state
	        		phaseV_low_state = switchOpen;
	        		// Update low side duty cycle
	        		TIM3->CCR2 = 0;

	        		// Update high side state
	        		phaseV_high_state = switchClosing;
	        	}

	        	// Reset the switch count
	        	waveformV_switchCount = 0;
	        	// Enter deadtime
	        	waveformV_state = waveform_deadTime;
	        }
	    }
	    else if(waveformV_state == waveform_deadTime)
	    {
	        // Increment the waveform count
	        waveformV_switchCount++;
	        // Check to see if there have been enough counts to end the deadtime
	        if(waveformV_switchCount >= WAVEFORM_DEADTIME)
	        {
	        	// If the low side is closing, then turn on the FET
	        	if(phaseV_low_state == switchClosing)
	        	{
	        		TIM3->CCR2 = TIM_PERIOD;
	        		phaseV_low_state = switchClosed;
	        	}
	        	// If the high side is closing, then turn on the high side FET
	        	if(phaseV_high_state == switchClosing)
	        	{
	        		TIM1->CCR2 = TIM_PERIOD / 2;
	        		phaseV_high_state = switchClosed;
	        	}
	        	// Reset switch count
	        	waveformV_switchCount = 0;
	        	// Update waveform state
	        	waveformV_state = waveform_running;
	        }
	    }
		return;
	case phase_W:
		return;
	default:
		return;
	}
}


/**
  * @brief Use the fast sin algorithm to calculate sin(x)
  * @param x = input to sin(x)
  * @retval floating point value of result
  */
float fast_sin(float x)
{
	// If a value outside of -Pi - Pi is given, correct it
	if(x < -(PI))
	{
		x += TWO_PI;
	}
	else if(x > PI)
	{
		x -= TWO_PI;
	}

	// Compute the approximation of sine
	float sine;
	// Compute the brunt of the calculation using sin(x) ~ (4/pi)x +- (4/(pi^2))x^2
	if(x < 0)
	{
		sine = (FOUR_OVER_PI * x) + (FOUR_OVER_PI2 * x * x);
	}
	else
	{
		sine = (FOUR_OVER_PI * x) - (FOUR_OVER_PI2 * x * x);
	}
	// Make the calculation more accurate by = .225 * (+-(sine)^2 - sine) + sine
    if (sine < 0)
    {
        sine = SINE_ACCURACY_CONSTANT * (sine * -1 * sine - sine) + sine;
    }
    else
    {
        sine = SINE_ACCURACY_CONSTANT * (sine * sine - sine) + sine;
    }
    // Return the calculated value
    return sine;
}


