#pragma once

#include "MonoBehaviour.h"

class TestCameraScript : public MonoBeHaviour
{
public:
	TestCameraScript();
	virtual ~TestCameraScript();

	virtual void LateUpdate() override;

private:
	float		_speed = 100.f;
};

