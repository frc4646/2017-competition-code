#ifndef SetDriveCommand_H
#define SetDriveCommand_H

#include "../CommandBase.h"

class SetDriveCommand : public CommandBase {
public:
	SetDriveCommand(double power, double curve);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double p;
	double c;
};

#endif  // SetDriveCommand_H
