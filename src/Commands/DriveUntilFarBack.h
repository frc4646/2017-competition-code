#ifndef DriveUntilFarBack_H
#define DriveUntilFarBack_H

#include "../CommandBase.h"

class DriveUntilFarBack : public CommandBase {
public:
	DriveUntilFarBack(double power, double distance);
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

#endif  // DriveUntilFarBack_H
