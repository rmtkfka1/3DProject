#include "pch.h"
#include "Game.h"
#include "Core.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

void Game::Init(const WindowInfo& info)
{
	_windowInfo = info;

	core->Init(info);

	_mesh = make_shared<Mesh>();
	_shader = make_shared<Shader>();
	_texture = make_shared<Texture>();

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

	_mesh->Init(vec,index);

	_shader->Init(L"..\\Resource\\Shader\\Default.hlsl");
	_texture->Init(L"..\\Resource\\Texture\\ghost.png");

	TimeManager::GetInstance()->Init();
	KeyManager::GetInstance()->Init(_windowInfo.hwnd);

}

void Game::Update()
{

	core->Update();

}

void Game::Render()
{

	core->RenderBegin();

	_shader->SetPipelineState();

	_mesh->SetTexture(_texture);
	_mesh->Render();



	core->RenderEnd();

}
