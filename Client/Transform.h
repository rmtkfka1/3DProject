#pragma once
#include "Component.h"

class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

	void Update() override;
	// TODO : �°� Parent/Child ����

private:
	// TODO : World ��ġ ����

};

