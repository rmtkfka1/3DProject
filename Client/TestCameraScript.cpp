#include "pch.h"
#include "TestCameraScript.h"
#include "Transform.h"
#include "Camera.h"
#include "GameObject.h"
#include "KeyManager.h"
#include "Time.h"

TestCameraScript::TestCameraScript()
{
}

TestCameraScript::~TestCameraScript()
{
}

void TestCameraScript::LateUpdate()
{
	Vec3 pos = GetTransform()->GetLocalPosition();

	if(KeyManager::GetInstance()->GetButton(KEY_TYPE::W))
		pos += GetTransform()->GetLook() * _speed * TimeManager::GetInstance()->GetDeltaTime();

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::S))
		pos -= GetTransform()->GetLook() * _speed * TimeManager::GetInstance()->GetDeltaTime();

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::A))
		pos -= GetTransform()->GetRight() * _speed * TimeManager::GetInstance()->GetDeltaTime();

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::D))
		pos += GetTransform()->GetRight() * _speed * TimeManager::GetInstance()->GetDeltaTime();

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::LEFT))
	{
		Vec3 rotation = GetTransform()->GetLocalRotation();
		rotation.y += TimeManager::GetInstance()->GetDeltaTime() * 5.0f;
		GetTransform()->SetLocalRotation(rotation);
	}

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::RIGHT))
	{
		Vec3 rotation = GetTransform()->GetLocalRotation();
		rotation.y -= TimeManager::GetInstance()->GetDeltaTime() * 5.0f;
		GetTransform()->SetLocalRotation(rotation);
	}


	GetTransform()->SetLocalPosition(pos);
}