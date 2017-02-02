#ifndef BoilerVisionCalculation_H
#define BoilerVisionCalculation_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class BoilerVisionCalculation : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<NetworkTable> networkTable;
	std::vector<double> xVals;
	std::vector<double> distVals;
	float goalX;
	float goalHeight;

public:
	BoilerVisionCalculation();
	~BoilerVisionCalculation();
	void InitDefaultCommand();
	float GoalAngle();
	float GoalDistance();
};

#endif  // BoilerVisionCalculation_H
