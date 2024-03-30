#include "pch.h"
#include "Game.h"
#include "Core.h"
#include "Mesh.h"
#include "Shader.h"
void Game::Init(const WindowInfo& info)
{
	_windowInfo = info;

	CORE->Init(info);

	_mesh = make_shared<Mesh>();
	_shader = make_shared<Shader>();

	vector<Vertex> vec(3);
	vec[0].pos = Vec3(0.f, 0.5f, 0.5f);
	vec[0].color = Vec4(1.f, 0.f, 0.f, 1.f);
	vec[1].pos = Vec3(0.5f, -0.5f, 0.5f);
	vec[1].color = Vec4(0.f, 1.0f, 0.f, 1.f);
	vec[2].pos = Vec3(-0.5f, -0.5f, 0.5f);
	vec[2].color = Vec4(0.f, 0.f, 1.f, 1.f);


	_mesh->Init(vec);
	_shader->Init(L"..\\Resource\\Default.hlsl");

}

void Game::Update()
{




}

void Game::Render()
{

	CORE->RenderBegin();

	_shader->SetPipelineState();
	_mesh->Render();

	CORE->RenderEnd();

}