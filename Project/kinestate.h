#include "mpu6050.h"
#include <complex.h>


struct kine_state {
	double x, y;
	double vx, vy;
	double ax, ay;
};

struct kine_state get_kine_state(struct kine_state *now_state);
