#pragma once

class Core;
class Mesh;
class Shader;
class Texture;

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
	shared_ptr<Texture> _texture;

};

