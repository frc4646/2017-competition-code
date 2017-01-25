#ifndef ArmExtendCommand_H
#define ArmExtendCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmExtendCommand : public CommandBase {
public:
	ArmExtendCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmExtendCommand_H
