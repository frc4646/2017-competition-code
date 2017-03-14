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

#include <WPILib.h>

OI::OI():
left(0),
right(1),
mechanism(2),
autoGearDrop(&left, 1),
boilerDistance(&left, 2),
boilerAngle(&right, 2),
driveStraight(&right, 1),
hoodArc(&mechanism, 5),
hoodKey(&mechanism, 3),
shoot(&mechanism, 1),
climb(&mechanism, 2),
intakeOn(&mechanism, 9),
intakeOff(&mechanism, 10),
indexerOn(&mechanism, 7),
indexerOff(&mechanism, 8),
extendGear(&mechanism, 6),
retractGear(&mechanism, 4)

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
	shoot.WhileHeld(new ManualLaunchCommand(.78));
//	shoot.WhenPressed(new SpinUp(0.5));
//	shoot.WhenReleased(new ManualLaunchCommand(0));
	hoodArc.WhenPressed(new HoodFarCommand());
	hoodKey.WhenPressed(new HoodCloseCommand());

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
