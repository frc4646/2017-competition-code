#ifndef DriveUntilFarFront_H
#define DriveUntilFarFront_H

#include "../CommandBase.h"

class DriveUntilFarFront : public CommandBase {
public:
	DriveUntilFarFront(double power, double distance);
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

#endif  // DriveUntilFarFront_H
