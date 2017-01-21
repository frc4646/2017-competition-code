#include "CommandBase.h"
#include <Commands/Scheduler.h>
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/GearVisionCalculation.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
//		std::make_unique<ExampleSubsystem>();
//std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
////
//std::unique_ptr<DriveTrain> CommandBase::drivetrain =
//		std::make_unique<DriveTrain>(M9,M1);

std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
		NULL;
std::unique_ptr<OI> CommandBase::oi = NULL;
//
std::unique_ptr<DriveTrain> CommandBase::drivetrain =
		NULL;
std::unique_ptr<GearVisionCalculation> CommandBase::gearvisioncalculation =
		NULL;


CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init()
{
	exampleSubsystem.reset(new ExampleSubsystem());

	drivetrain.reset(new DriveTrain(M9,M0));

	gearvisioncalculation.reset(new GearVisionCalculation());

	oi.reset(new OI());

}
