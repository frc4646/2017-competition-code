#ifndef ArmRetractCommand_H
#define ArmRetractCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmRetractCommand : public CommandBase {
public:
	ArmRetractCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmRetractCommand_H
