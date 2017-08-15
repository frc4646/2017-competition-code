#ifndef GyroCurve_H
#define GyroCurve_H

#include "../CommandBase.h"

class GyroCurve : public CommandBase {
public:
	GyroCurve();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GyroCurve_H
