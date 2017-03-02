#ifndef HoodCloseCommand_H
#define HoodCloseCommand_H

#include "../CommandBase.h"

class HoodCloseCommand : public CommandBase {
public:
	HoodCloseCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HoodCloseCommand_H
