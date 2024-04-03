#pragma once
#include "Component.h"

class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

	void Update() override;
	// TODO : 온갖 Parent/Child 관계

private:
	// TODO : World 위치 관련

};

