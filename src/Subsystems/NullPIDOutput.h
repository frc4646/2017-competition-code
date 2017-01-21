/*
 * NullPIDOutput.h
 *
 */

#ifndef SRC_SUBSYSTEMS_NULLPIDOUTPUT_H_
#define SRC_SUBSYSTEMS_NULLPIDOUTPUT_H_

#include <PIDOutput.h>

class NullPIDOutput: public PIDOutput {
public:
	NullPIDOutput();
	virtual ~NullPIDOutput();
	virtual void 	PIDWrite (double output);
};

#endif /* SRC_SUBSYSTEMS_NULLPIDOUTPUT_H_ */
