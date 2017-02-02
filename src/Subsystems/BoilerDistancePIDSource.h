/*
 * BoilerDistancePIDSource.h
 *
*/

#ifndef SRC_SUBSYSTEMS_BOILERDISTANCEPIDSOURCE_H_
#define SRC_SUBSYSTEMS_BOILERDISTANCEPIDSOURCE_H_

#include <PIDSource.h>

class BoilerVisionCalculation;

class BoilerDistancePIDSource: public frc::PIDSource {
public:
	BoilerDistancePIDSource(BoilerVisionCalculation* boilerVisionCalculation);
	virtual ~BoilerDistancePIDSource();
	virtual double 	PIDGet ();

private:
	BoilerVisionCalculation* boilerVisionCalculation;
};

#endif /* SRC_SUBSYSTEMS_BOILERDISTANCEPIDSOURCE_H_ */
