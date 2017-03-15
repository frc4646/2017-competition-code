#include "BlueGearCenterAuto.h"
#include <Commands/DriveUntilCloseBack.h>
#include <Commands/DriveUntilFarBack.h>
#include "Commands/GearExtendCommand.h"
#include "Commands/GearRetractCommand.h"
#include "Commands/DriveStraightTime.h"
#include "Commands/GearDrop.h"

BlueGearCenterAuto::BlueGearCenterAuto() {
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
//AddSequential(new DriveUntilCloseBack(.75, 10));
//AddSequential(new GearDrop);
//AddSequential(new DriveUntilFarBack(.75,10));
	AddSequential(new DriveUntilCloseBack(0.3, 4), 5);
	AddSequential(new GearExtendCommand(), 0.75);
	AddSequential(new DriveStraightTime(0.5), 1);
	AddSequential(new GearRetractCommand(), 0.5);

}
