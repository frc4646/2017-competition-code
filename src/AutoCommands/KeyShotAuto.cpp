#include "KeyShotAuto.h"
#include <Commands/DriveStraightTime.h>
#include <Commands/TurnForAngle.h>
#include <Commands/ManualLaunchCommand.h>
#include <Commands/Index.h>

KeyShotAuto::KeyShotAuto() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

//	AddSequential(new DriveStraightTime(0.75), 0.5);
//	AddSequential(new TurnForAngle(0.75, -125));
//	AddSequential(new DriveStraightTime(0.75), 0.5);
	AddSequential(new ManualLaunchCommand(0.78), 0.5);
	AddParallel(new Index(0.75));
	AddSequential(new ManualLaunchCommand(0.78), 10);

	AddParallel(new Index(0));
	AddSequential(new DriveStraightTime(-.75), .25);
	AddSequential(new TurnForAngle(.75, 45), 1);
	AddSequential(new DriveStraightTime(-.75), 1.5);

}
