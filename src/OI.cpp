#include "OI.h"
#include "Commands/DriveStraight.h"
#include "Commands/TurnForAngle.h"

#include <WPILib.h>

OI::OI():
left(0),
right(1),
mechanism(2),
driveStraight(&left, 1),
turn90(&left, 2)
{
	// Process operator interface input here.
	driveStraight.WhileHeld(new DriveStraight());
	turn90.WhenPressed(new TurnForAngle(0.5,90));
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
