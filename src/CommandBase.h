#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/GearVisionCalculation.h"
#include "Subsystems/BoilerVisionCalculation.h"
#include "Subsystems/Climber.h"
#include "Subsystems/FuelIntakeRoller.h"
#include "Subsystems/UltrasonicSensor.h"
#include "Subsystems/RadioShackUltrasonic.h"
#include "Subsystems/GearPneumatic.h"
#include "Subsystems/Indexer.h"
#include "Subsystems/LauncherPID.h"
#include "Subsystems/LauncherHood.h"
#include "Subsystems/PressureSensor.h"
/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static void init();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<ExampleSubsystem> exampleSubsystem;
	static std::unique_ptr<OI> oi;

	static std::unique_ptr<DriveTrain> drivetrain;
	static std::unique_ptr<GearVisionCalculation> gearvisioncalculation;
	static std::unique_ptr<BoilerVisionCalculation> boilervisioncalculation;
	static std::unique_ptr<Climber> climber;
	static std::unique_ptr<FuelIntakeRoller> roller;
	static std::unique_ptr<UltrasonicSensor> frontusensor;
	static std::unique_ptr<RadioShackUltrasonic> backusensor;
	static std::unique_ptr<GearPneumatic> gearpneumatic;
	static std::unique_ptr<Indexer> indexer;
	static std::unique_ptr<LauncherPID> launcher;
	static std::unique_ptr<LauncherHood> launcherhood;
	static std::unique_ptr<PressureSensor> psensor;
};

#endif  // COMMAND_BASE_H
