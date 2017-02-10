#ifndef DriveUntilCloseBack_H
#define DriveUntilCloseBack_H

#include "../CommandBase.h"

class DriveUntilCloseBack : public CommandBase {
public:
	DriveUntilCloseBack(double power, double distance);
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

#endif  // DriveUntilCloseBack_H
