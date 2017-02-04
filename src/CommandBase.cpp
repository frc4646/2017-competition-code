#include "CommandBase.h"
#include <Commands/Scheduler.h>
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/GearVisionCalculation.h"
#include "Subsystems/BoilerVisionCalculation.h"
#include "Subsystems/Climber.h"
#include "Subsystems/FuelIntakeRoller.h"
#include "Subsystems/UltrasonicSensor.h"
#include "Subsystems/FuelIntakeArms.h"
#include "Subsystems/GearPneumatic.h"
#include "Subsystems/Indexer.h"
#include "Subsystems/LauncherPID.h"


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
std::unique_ptr<DriveTrain> CommandBase::drivetrain = NULL;

std::unique_ptr<GearVisionCalculation> CommandBase::gearvisioncalculation = NULL;

std::unique_ptr<BoilerVisionCalculation> CommandBase::boilervisioncalculation = NULL;

std::unique_ptr<Climber> CommandBase::climber = NULL;

std::unique_ptr<FuelIntakeRoller> CommandBase::roller = NULL;

std::unique_ptr<UltrasonicSensor> CommandBase::frontusensor = NULL;

std::unique_ptr<UltrasonicSensor> CommandBase::backusensor = NULL;

std::unique_ptr<FuelIntakeArms> CommandBase::arms = NULL;

std::unique_ptr<GearPneumatic> CommandBase::gearpneumatic = NULL;

std::unique_ptr<LauncherPID> CommandBase::launcher = NULL;

std::unique_ptr<Indexer> CommandBase::indexer = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init()
{
	exampleSubsystem.reset(new ExampleSubsystem());

	drivetrain.reset(new DriveTrain(M9,M0));

	gearvisioncalculation.reset(new GearVisionCalculation());

	boilervisioncalculation.reset(new BoilerVisionCalculation());

	climber.reset(new Climber(M5));

	roller.reset(new FuelIntakeRoller(M4));

	arms.reset(new FuelIntakeArms(S0, S1));

	frontusensor.reset(new UltrasonicSensor(A0));
	backusensor.reset(new UltrasonicSensor(A1));

	gearpneumatic.reset(new GearPneumatic(S2, S3));

	indexer.reset(new Indexer(M6));

	launcher.reset(new LauncherPID(M7, D1));

	oi.reset(new OI());
	SmartDashboard::PutData(backusensor.get());


}
