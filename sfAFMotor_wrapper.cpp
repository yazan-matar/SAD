#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



#ifndef MATLAB_MEX_FILE

#define ARDUINO 100
#include <Arduino.h>
#include "AFMotor.h"
#include "AFMotor.cpp"
/* 
 * Definition of the Motor Objects
 */
	AF_DCMotor motor1(1);
	AF_DCMotor motor2(2);
	AF_DCMotor motor3(3);
	AF_DCMotor motor4(4);
#endif

#define u_width 1


/*
 * Output function: it sets the speed and direction of each motor based on the hardware signaling
 */
extern "C" void sfAFMotor_Outputs_wrapper(
			const uint8_T *DIR1,
			const uint8_T *PWM1,
			const uint8_T *DIR2,
			const uint8_T *PWM2,
			const uint8_T *DIR3,
			const uint8_T *PWM3,
			const uint8_T *DIR4,
			const uint8_T *PWM4)
{

#ifndef MATLAB_MEX_FILE

	motor1.setSpeed(PWM1[0]);
	motor1.run(DIR1[0]);

	motor2.setSpeed(PWM2[0]);
	motor2.run(DIR2[0]);

	motor3.setSpeed(PWM3[0]);
	motor3.run(DIR3[0]);

	motor4.setSpeed(PWM4[0]);
	motor4.run(DIR4[0]);

#endif
}


