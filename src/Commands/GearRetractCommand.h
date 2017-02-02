#ifndef GearRetractCommand_H
#define GearRetractCommand_H

#include "../CommandBase.h"

class GearRetractCommand : public CommandBase {
public:
	GearRetractCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GearRetractCommand_H
