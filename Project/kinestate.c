#include "kinestate.h"

struct kine_state get_kine_state(struct kine_state *now_state)
{
	struct kine_state result;
	double ax, ay, az;
	
	ax = mpu6050_get_exact_data(ACCEL_XOUT_H);
	ay = mpu6050_get_exact_data(ACCEL_YOUT_H);
	az = mpu6050_get_exact_data(ACCEL_ZOUT_H);

	/*
	result.ax = ax * ACCEL_RANGE / 32767;
	result.ay = ay * ACCEL_RANGE / 32767;
	result.az = az * ACCEL_RANGE / 32767;
	*/
	
	result.ax = int2double(ax);
	result.ay = int2double(ay);
	result.az = int2double(az);

	return result;
}
