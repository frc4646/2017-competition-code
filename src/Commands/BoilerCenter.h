#ifndef BoilerCenter_H
#define BoilerCenter_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/NullPIDOutput.h"
#include <Subsystems/BoilerAnglePIDSource.h>

class BoilerCenter : public CommandBase {
public:
	BoilerCenter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float turning;
	float robotTurn;
	int confidence;
	NullPIDOutput po;
	BoilerAnglePIDSource ps;
	PIDController pc;
};

#endif  // BoilerCenter_H
