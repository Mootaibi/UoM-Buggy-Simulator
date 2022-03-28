#include "buggy.h"

//set
void buggy::set_DefaultS(int val) {
	defaultS = val;
}

//alg
void buggy::alg_Control(int speedVal) {
	
	start();
	while (1) {
		int val = LS.get - RS.get;
		
			if (val > 24) {
				FLS.attach(cb_FLS);
				do {
					speedCtrl.set_SetSpeedR(defaultS + val * constant, period);
					val = LS.get - RS.get;
				} while (val > 24);
				FLS.detach(cb_FLS);
			}

			else if (val < -24) {
				FRS.attach(cb_FRS);
				do {
					speedCtrl.set_SetSpeedL(defaultS + val * constant, period);
					val = LS.get - RS.get;
				} while (val < -24);
				FRS.detach(cb_FRS);
			}

			if (BLE) {
				alg_BLE();
			}
		}
	}
}
void buggy::alg_BLE(void) {
	//do a J-turn then return to alg_Control()
}

//cb
void buggy::cb_FRS(void) {
	//big left turn till FRS.read() = 0
}
void buggy::cb_FLS(void) {
	//big right turn till FLS.read() = 0
}
void buggy::cb_MS(void) {
	//get average speed and calc time needed to move 6 cm
	//set up a timeout interrupt (attached to cb_check) using calculated time
}
void buggy::cb_Check(void) {
	//if all interrupt sensors.read() = 0 && both analog sensors are below a threashold then stop
	//else, return to algorithm
}