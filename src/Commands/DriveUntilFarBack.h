#ifndef DriveUntilFarBack_H
#define DriveUntilFarBack_H

#include "../CommandBase.h"

class DriveUntilFarBack : public CommandBase {
public:
	DriveUntilFarBack();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveUntilFarBack_H
