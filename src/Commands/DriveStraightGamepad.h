#ifndef DriveStraightGamepad_H
#define DriveStraightGamepad_H

#include "../CommandBase.h"

class DriveStraightGamepad : public CommandBase {
public:
	DriveStraightGamepad();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveStraightGamepad_H
