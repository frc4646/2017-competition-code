#ifndef HoodFarCommand_H
#define HoodFarCommand_H

#include "../CommandBase.h"

class HoodFarCommand : public CommandBase {
public:
	HoodFarCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HoodFarCommand_H
