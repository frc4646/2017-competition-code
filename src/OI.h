#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	OI();
	Joystick& GetLeftStick();
	Joystick& GetRightStick();
	Joystick& GetMechanismStick();

private:
	Joystick left;
	Joystick right;
	Joystick mechanism;
	JoystickButton driveStraight;
	JoystickButton turn90;
};

#endif  // OI_H
