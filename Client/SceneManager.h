#pragma once

class Scene;


class SceneManager
{

public:

	static SceneManager* GetInstance()
	{
		static SceneManager instance;
		return &instance;
	}

public:
	void Update();
	void LoadScene(wstring sceneName);

public:
	shared_ptr<Scene> GetActiveScene() { return _activeScene; }

private:
	shared_ptr<Scene> LoadTestScene();

private:
	shared_ptr<Scene> _activeScene;
};

