#include "OI.h"
#include "Commands/DriveStraight.h"
#include "Commands/TurnForAngle.h"
#include "Commands/GearDrop.h"
#include "Commands/GearCenter.h"
#include "Commands/ClimbRope.h"
#include "Commands/IntakeCommand.h"
#include "Commands/BoilerCenter.h"
#include "Commands/BoilerDistance.h"
#include "Commands/Index.h"
#include "Commands/GearExtendCommand.h"
#include "Commands/GearRetractCommand.h"
#include "Commands/ManualLaunchCommand.h"
#include "Commands/HoodFarCommand.h"
#include "Commands/HoodCloseCommand.h"
#include "Commands/DriveUntilCloseBack.h"
#include "Commands/SpinUp.h"
#include "Commands/DriveStraightGamepad.h"
#include "Commands/GyroCurve.h"

#include <WPILib.h>

OI::OI():
gamepad(0),
left(1),
right(2),
mechanism(3),
autoGearDrop(&left, 1),
boilerDistance(&left, 2),
boilerAngle(&right, 2),
driveStraight(&right, 1),
hoodArc(&mechanism, 5),
hoodKey(&mechanism, 3),
shoot(&mechanism, 1),
intakeOn(&mechanism, 9),
intakeOff(&mechanism, 10),
indexerOn(&mechanism, 7),
indexerOff(&mechanism, 8),
driveStraightGamepad(&gamepad, 1),
extendGear(&gamepad, 2),
retractGear(&gamepad, 3),
shootGamepad(&gamepad, 4),
indexGamepad(&gamepad, 5),
outdexGamepad(&gamepad, 6),
climb(&gamepad, 7)

//turn90(&left, 2)
{
	// Process operator interface input here.
	driveStraight.WhileHeld(new DriveStraight());
	//climb.WhenPressed(new DriveUntilCloseBack(0.3,6));
	climb.WhileHeld(new ClimbRope());
	intakeOn.WhileHeld(new IntakeCommand(1));
	intakeOff.WhileHeld(new IntakeCommand(-0.5));
	boilerAngle.WhileHeld(new BoilerCenter());
	boilerDistance.WhileHeld(new BoilerDistance());
	indexerOn.WhileHeld(new Index(0.75));
	indexerOff.WhileHeld(new Index(-0.75));
	extendGear.WhileHeld(new GearExtendCommand());
	retractGear.WhileHeld(new GearRetractCommand());
//	shoot.WhileHeld(new ManualLaunchCommand(.78));
	shoot.WhenPressed(new ManualLaunchCommand(1));
	shoot.WhenReleased(new ManualLaunchCommand(0));
	hoodArc.WhenPressed(new HoodFarCommand());
	hoodKey.WhenPressed(new HoodCloseCommand());
	driveStraightGamepad.WhileHeld(new DriveStraightGamepad());
	curveGamepad.WhileHeld(new GyroCurve());
	shootGamepad.WhenPressed(new SpinUp(1));
	shootGamepad.WhenReleased(new ManualLaunchCommand(0));
	indexGamepad.WhileHeld(new Index(0.75));
	outdexGamepad.WhileHeld(new Index(-0.75));

	//turn90.WhenPressed(new TurnForAngle(0.5,90));
}
Joystick& OI::GetGamepad() {
	return gamepad;
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

