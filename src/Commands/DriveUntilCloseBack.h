#ifndef DriveUntilCloseBack_H
#define DriveUntilCloseBack_H

#include "../CommandBase.h"

class DriveUntilCloseBack : public CommandBase {
public:
	DriveUntilCloseBack();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveUntilCloseBack_H
