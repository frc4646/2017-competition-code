#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/ExampleCommand.h"
#include "CommandBase.h"

#include <AutoCommands/DoNothingAuto.h>
#include <AutoCommands/BlueGearCenterAuto.h>
#include <AutoCommands/RedKeyShotAuto.h>
#include <AutoCommands/BlueKeyShotAuto.h>

class Robot: public frc::IterativeRobot {
public:
	enum AutoChoice {
		noAuto, gearDrop, keyShot
	};
	void RobotInit() override {
		CommandBase::init();

		chooser.AddDefault("Do Nothing", new AutoChoice(noAuto));
		chooser.AddObject("Gear Drop", new AutoChoice(gearDrop));
		chooser.AddObject("Key Shot", new AutoChoice(keyShot));
		Compressor *c = new Compressor(0);
		c->Start();

		frc::SmartDashboard::PutData("Auto Modes", &chooser);
		frc::SmartDashboard::PutData(frc::Scheduler::GetInstance());
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {

	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		DriverStation& ds = DriverStation::GetInstance();
		DriverStation::Alliance alliance = ds.GetAlliance();
		if(chooser.GetSelected())
		{
			switch(*chooser.GetSelected())
			{
			case noAuto:
				autonomousCommand.reset(new DoNothingAuto());
				break;
			case gearDrop:
				autonomousCommand.reset(new BlueGearCenterAuto());
				break;
			case keyShot:
				if(alliance == DriverStation::Alliance::kRed){
					autonomousCommand.reset(new RedKeyShotAuto());
				} else {
					autonomousCommand.reset (new BlueKeyShotAuto());
				}
				break;
			}
		}

		if (autonomousCommand.get() != nullptr) {
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
		frc::LiveWindow::GetInstance()->Run();
	}

private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<AutoChoice*> chooser;
};

START_ROBOT_CLASS(Robot)
