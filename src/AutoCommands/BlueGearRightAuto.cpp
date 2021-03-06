#include "BlueGearRightAuto.h"
#include <Commands/DriveUntilCloseBack.h>
#include <Commands/DriveUntilFarFront.h>
#include "Commands/TurnForAngle.h"
#include "Commands/GearDrop.h"
#include "Commands/DriveUntilFarBack.h"

BlueGearRightAuto::BlueGearRightAuto() {
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

	AddSequential(new DriveUntilFarFront(.75,75 ), 5);
	AddSequential(new TurnForAngle(.75, -45), 2); //Assuming Left=Negative
	AddSequential(new DriveUntilCloseBack(0.5, 4), 1);
	AddSequential(new DriveUntilCloseBack(0.3, 4), 5);
	AddSequential(new GearDrop(), 5);
	AddSequential(new DriveUntilFarBack(.5, 15));
}
