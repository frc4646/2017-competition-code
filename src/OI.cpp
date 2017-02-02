#include "OI.h"
#include "Commands/DriveStraight.h"
#include "Commands/TurnForAngle.h"
#include "Commands/ArmExtendCommand.h"
#include "Commands/ArmRetractCommand.h"
#include "Commands/GearDrop.h"
#include "Commands/ClimbRope.h"
#include "Commands/IntakeCommand.h"
#include "Commands/BoilerCenter.h"
#include "Commands/BoilerDistance.h"

#include <WPILib.h>

OI::OI():
left(0),
right(1),
mechanism(2),
autoGearDrop(&left, 1),
boilerDistance(&left, 2),
boilerAngle(&right, 2),
driveStraight(&right, 1),
extendArms(&mechanism, 6),
retractArms(&mechanism, 4),
hoodArc(&mechanism, 5),
hoodKey(&mechanism, 3),
shoot(&mechanism, 1),
climb(&mechanism, 2),
intakeOn(&mechanism, 9),
intakeOff(&mechanism, 10),
indexerOn(&mechanism, 7),
indexerOff(&mechanism, 8),
extendGear(&mechanism, 11),
retractGear(&mechanism, 12)

//turn90(&left, 2)
{
	// Process operator interface input here.
	driveStraight.WhileHeld(new DriveStraight());
	extendArms.WhenPressed(new ArmExtendCommand());
	retractArms.WhenPressed(new ArmRetractCommand());
	autoGearDrop.WhenPressed(new GearDrop());
	climb.WhileHeld(new ClimbRope());
	intakeOn.WhenPressed(new IntakeCommand(0.5));
	intakeOff.WhenPressed(new IntakeCommand(0));
	boilerAngle.WhileHeld(new BoilerCenter());
	boilerDistance.WhileHeld(new BoilerDistance());
	//turn90.WhenPressed(new TurnForAngle(0.5,90));
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
