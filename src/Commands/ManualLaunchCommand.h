#ifndef ManualLaunchCommand_H
#define ManualLaunchCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class ManualLaunchCommand : public CommandBase {
public:
	ManualLaunchCommand(double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double launchPower;
};

#endif  // ManualLaunchCommand_H
