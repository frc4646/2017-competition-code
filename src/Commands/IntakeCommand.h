#ifndef IntakeCommand_H
#define IntakeCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeCommand : public CommandBase {
public:
	IntakeCommand(double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double rollerPower;
};

#endif  // IntakeCommand_H
