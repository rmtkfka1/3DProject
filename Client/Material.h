#pragma once
#include "Object.h"
class Shader;
class Texture;

class Material:public Object
{


public:
	Material();
	virtual ~Material();

	shared_ptr<Shader> GetShader() { return _shader; }

	void SetShader(shared_ptr<Shader> shader) { _shader = shader; }
	void SetInt(uint8 index, int32 value) { _materialParams.SetInt(index, value); }
	void SetFloat(uint8 index, float value) { _materialParams.SetFloat(index, value); }
	void SetTexture(uint8 index, shared_ptr<Texture> texture) { _textures[index] = texture; }

	void PushData();

private:
	shared_ptr<Shader> _shader;
	MaterialParam _materialParams;
	array<shared_ptr<Texture>, MATERIAL_TEXTURE_COUNT> _textures;
};

