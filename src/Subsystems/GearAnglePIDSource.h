/*
 * GearAnglePIDSource.h
 *
*/

#ifndef SRC_SUBSYSTEMS_GEARANGLEPIDSOURCE_H_
#define SRC_SUBSYSTEMS_GEARANGLEPIDSOURCE_H_

#include <PIDSource.h>

class GearVisionCalculation;

class GearAnglePIDSource: public frc::PIDSource {
public:
	GearAnglePIDSource(GearVisionCalculation* gearVisionCalculation);
	virtual ~GearAnglePIDSource();
	virtual double 	PIDGet ();

private:
	GearVisionCalculation* gearVisionCalculation;
};

#endif /* SRC_SUBSYSTEMS_GearANGLEPIDSOURCE_H_ */
