#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/GearVisionCalculation.h"
#include "Subsystems/Climber.h"
#include "Subsystems/FuelIntakeRoller.h"
#include "Subsystems/UltrasonicSensor.h"
#include "Subsystems/FuelIntakeArms.h"


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
	static std::unique_ptr<Climber> climber;
	static std::unique_ptr<FuelIntakeRoller> roller;
	static std::unique_ptr<UltrasonicSensor> usensor;
	static std::unique_ptr<FuelIntakeArms> arms;
};

#endif  // COMMAND_BASE_H
