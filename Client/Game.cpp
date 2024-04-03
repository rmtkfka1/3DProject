#include "pch.h"
#include "Game.h"
#include "Core.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"

void Game::Init(const WindowInfo& info)
{
	_windowInfo = info;

	core->Init(info);

	_mesh = make_shared<Mesh>();
	vector<Vertex> vec(4);
	vec[0].pos = Vec3(-0.5f, 0.5f, 0.5f);
	vec[0].color = Vec4(1.f, 0.f, 0.f, 1.f);
	vec[0].uv = Vec2(0.0f, 0.0f);

	vec[1].pos = Vec3(0.5f, 0.5f, 0.5f);
	vec[1].color = Vec4(0.f, 1.f, 0.f, 1.f);
	vec[1].uv = Vec2(1.0f, 0.0f);

	vec[2].pos = Vec3(0.5f, -0.5f, 0.5f);
	vec[2].color = Vec4(0.f, 0.f, 1.f, 1.f);
	vec[2].uv = Vec2(1.0f, 1.0f);

	vec[3].pos = Vec3(-0.5f, -0.5f, 0.5f);
	vec[3].color = Vec4(0.f, 1.f, 0.f, 1.f);
	vec[3].uv = Vec2(0.0f, 1.0f);

	vector<uint32> index{ 0,1,2,0,2,3 };

	_mesh->Init(vec, index);



	shared_ptr<Shader> shader = make_shared<Shader>();
	shader->Init(L"..\\Resource\\Shader\\Default.hlsl");

	shared_ptr<Texture> texture = make_shared<Texture>();
	texture->Init(L"..\\Resource\\Texture\\ghost.png");

	shared_ptr<Material> material = make_shared<Material>();
	material->SetShader(shader);
	//material->SetFloat(0, 0.4f);
	//material->SetFloat(1, 0.2f);
	//material->SetFloat(2, 0.3f);
	material->SetTexture(0, texture);
	
	_mesh->SetMaterial(material);

	TimeManager::GetInstance()->Init();
	KeyManager::GetInstance()->Init(_windowInfo.hwnd);

	t1.offset = Vec4(0.0f, 0.0f, 0.0f, 0.0f);



}

void Game::Update()
{

	core->Update();

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::D))
	{
		t1.offset.x += 1.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::A))
	{
		t1.offset.x -= 1.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::W))
	{
		t1.offset.y += 1.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::S))
	{
		t1.offset.y -= 1.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::UP))
	{
		t1.offset.z += 1.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->GetButton(KEY_TYPE::DOWN))
	{
		t1.offset.z -= 1.0f * TimeManager::GetInstance()->GetDeltaTime();
	}
}

void Game::Render()
{

	core->RenderBegin();


	{
		_mesh->SetTransform(t1);
		_mesh->Render();
	}


	core->RenderEnd();

}
