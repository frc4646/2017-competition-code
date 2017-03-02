#ifndef SendUltrasonic_H
#define SendUltrasonic_H

#include "../CommandBase.h"

class SendUltrasonic : public CommandBase {
public:
	SendUltrasonic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SendUltrasonic_H
