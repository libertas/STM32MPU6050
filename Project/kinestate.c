#include "kinestate.h"

struct kine_state get_kine_state(struct kine_state *now_state)
{
	struct kine_state result;
	
	result.ax = mpu6050_get_exact_data(ACCEL_XOUT_H) * ACCEL_RANGE / 65535;
	result.ay = mpu6050_get_exact_data(ACCEL_YOUT_H) * ACCEL_RANGE / 65535;
	
	return result;
}
