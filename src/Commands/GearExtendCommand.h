#ifndef GearExtendCommand_H
#define GearExtendCommand_H

#include "../CommandBase.h"

class GearExtendCommand : public CommandBase {
public:
	GearExtendCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GearExtendCommand_H
