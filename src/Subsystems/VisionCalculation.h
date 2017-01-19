#ifndef VisionCalculation_H
#define VisionCalculation_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class VisionCalculation : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<NetworkTable> networkTable;
	std::vector<double> xVals;
	std::vector<double> yVals;

public:
	VisionCalculation();
	~VisionCalculation();
	void InitDefaultCommand();
};

#endif  // VisionCalculation_H
