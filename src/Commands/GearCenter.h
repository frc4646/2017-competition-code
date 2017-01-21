#ifndef GearCenter_H
#define GearCenter_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/NullPIDOutput.h"
#include "Subsystems/GearAnglePIDSource.h"

class GearCenter : public CommandBase {
public:
	GearCenter();
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
	GearAnglePIDSource ps;
	PIDController pc;
};

#endif  // GearCenter_H
