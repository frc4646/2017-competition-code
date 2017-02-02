#ifndef BoilerDistance_H
#define BoilerDistance_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/NullPIDOutput.h"
#include <Subsystems/BoilerDistancePIDSource.h>

class BoilerDistance : public CommandBase {
public:
	BoilerDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float distancePower;
	int confidence;
	NullPIDOutput po;
	BoilerDistancePIDSource ps;
	PIDController pc;
};

#endif  // BoilerDistance_H
