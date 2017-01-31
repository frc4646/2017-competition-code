#ifndef DriveUntilDistance_H
#define DriveUntilDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveUntilDistance : public CommandBase {
public:
	DriveUntilDistance(double power, double distance);
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

#endif  // DriveUntilDistance_H
