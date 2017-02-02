/*
 * BoilerAnglePIDSource.h
 *
*/

#ifndef SRC_SUBSYSTEMS_BOILERANGLEPIDSOURCE_H_
#define SRC_SUBSYSTEMS_BOILERANGLEPIDSOURCE_H_

#include <PIDSource.h>

class BoilerVisionCalculation;

class BoilerAnglePIDSource: public frc::PIDSource {
public:
	BoilerAnglePIDSource(BoilerVisionCalculation* boilerVisionCalculation);
	virtual ~BoilerAnglePIDSource();
	virtual double 	PIDGet ();

private:
	BoilerVisionCalculation* boilerVisionCalculation;
};

#endif /* SRC_SUBSYSTEMS_BOILERANGLEPIDSOURCE_H_ */
