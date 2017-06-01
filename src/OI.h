#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	OI();
	Joystick& GetGamepad();
	Joystick& GetLeftStick();
	Joystick& GetRightStick();
	Joystick& GetMechanismStick();


private:
	Joystick gamepad;
	Joystick left;
	Joystick right;
	Joystick mechanism;
	JoystickButton autoGearDrop;
	JoystickButton boilerDistance;
	JoystickButton boilerAngle;
	JoystickButton driveStraight;
	JoystickButton hoodArc;
	JoystickButton hoodKey;
	JoystickButton shoot;
	JoystickButton climb;
	JoystickButton intakeOn;
	JoystickButton intakeOff;
	JoystickButton indexerOn;
	JoystickButton indexerOff;
	JoystickButton extendGear;
	JoystickButton retractGear;
	//JoystickButton turn90;
};

#endif  // OI_H
