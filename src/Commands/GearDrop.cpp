#include <Commands/GearDrop.h>
#include "Commands/GearCenter.h"
#include "Commands/GearExtendCommand.h"
#include "Commands/SetDriveCommand.h"
#include "Commands/GearRetractCommand.h"
#include "Commands/DriveUntilCloseBack.h"
GearDrop::GearDrop() {
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
	AddSequential(new GearCenter());
	AddSequential(new GearCenter());
	AddSequential(new DriveUntilCloseBack(0.3,20));
	AddSequential(new GearExtendCommand());
	AddSequential((new SetDriveCommand(-0.5, 0)),0.5);
	AddSequential((new SetDriveCommand(0, 0)),0.2);
	AddSequential(new GearRetractCommand());

}
