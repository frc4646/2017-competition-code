#ifndef DriveUntilCloseFront_H
#define DriveUntilCloseFront_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveUntilCloseFront : public CommandBase {
public:
	DriveUntilCloseFront(double power, double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double targetDistance;
	double drivePower;
	int confidence;

};

#endif  // DriveUntilCloseFront_H
