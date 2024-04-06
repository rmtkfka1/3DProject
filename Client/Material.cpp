#include "pch.h"
#include "Material.h"
#include "Core.h"
#include "Texture.h"
#include "Shader.h"
Material::Material():Object(OBJECT_TYPE::MATERIAL)
{
}
Material::~Material()
{
}
void Material::PushData()
{

	core->GetConstantBufferTable(CONSTANT_BUFFER_TYPE::MATERIAL)->PushData(&_materialParams, sizeof(_materialParams));

	for (int i = 0; i < _textures.size(); ++i)
	{
		if(_textures[i]==nullptr)
		{
			continue;
		}

		SRV_REGISTER reg = SRV_REGISTER(static_cast<uint8>(SRV_REGISTER::t0) + i);
		core->GetTableDescriptorHeap()->SetSRV(_textures[i]->GetCpuHandle(), reg);
	}


	_shader->SetPipelineState();

}
