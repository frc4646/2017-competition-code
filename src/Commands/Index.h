#ifndef Index_H
#define Index_H

#include "../CommandBase.h"
#include "WPILib.h"

class Index : public CommandBase {
public:
	Index(double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double indexPower;
};

#endif  // Index_H
