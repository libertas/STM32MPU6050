#include "mpu6050.h"
#include "utils.h"
#include <complex.h>


struct kine_state {
	double x, y, z;
	double vx, vy, vz;
	double ax, ay, az;
};

struct kine_state get_kine_state(struct kine_state *now_state);
