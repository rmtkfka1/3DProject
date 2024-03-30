#pragma once

class Core;
class Mesh;
class Shader;

class Game
{


public:

	void Init(const WindowInfo& info);
	void Update();
	void Render();

private:

	WindowInfo _windowInfo;
	shared_ptr<Mesh> _mesh;
	shared_ptr<Shader> _shader;


};

