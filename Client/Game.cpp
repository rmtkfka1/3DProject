#include "pch.h"
#include "Game.h"
#include "Core.h"
#include "SceneManager.h"
#include "Scene.h"
void Game::Init(const WindowInfo& info)
{
	_windowInfo = info;

	core->Init(info);

	SceneManager::GetInstance()->LoadScene(L"test");


}

void Game::Update()
{
	core->Update();

}

void Game::Render()
{
	core->StartGame();
}
