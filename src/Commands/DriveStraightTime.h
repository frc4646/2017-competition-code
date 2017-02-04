#ifndef DriveStraightTime_H
#define DriveStraightTime_H

#include "../CommandBase.h"

class DriveStraightTime : public CommandBase {
public:
	DriveStraightTime(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double CommandSpeed;
};

#endif  // DriveStraightTime_H
