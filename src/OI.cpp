#include "OI.h"
#include "Commands/DriveStraight.h"

#include <WPILib.h>

OI::OI():
left(0),
right(1),
mechanism(2),
driveStraight(&left, 1)
{
	// Process operator interface input here.
	driveStraight.WhileHeld(new DriveStraight());
}
Joystick& OI::GetLeftStick() {
	return left;
}
Joystick& OI::GetRightStick() {
	return right;
}
Joystick& OI::GetMechanismStick() {
	return mechanism;
}
