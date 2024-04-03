#pragma once

class Core;
class Mesh;
class Shader;
class Texture;
class GameObject;

class Game
{


public:

	void Init(const WindowInfo& info);
	void Update();
	void Render();

private:

	WindowInfo _windowInfo;

	shared_ptr<GameObject> _gameObject;

	TransformParam t1;

};

