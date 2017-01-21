#ifndef GearVisionCalculation_H
#define GearVisionCalculation_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class GearVisionCalculation : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<NetworkTable> networkTable;
	std::vector<double> xVals;
	float goalX;

public:
	GearVisionCalculation();
	~GearVisionCalculation();
	void InitDefaultCommand();
	float GoalAngle();
};

#endif  // GearVisionCalculation_H
