#ifndef DoNothingAuto_H
#define DoNothingAuto_H

#include "../CommandBase.h"

class DoNothingAuto : public CommandBase {
public:
	DoNothingAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DoNothingAuto_H
