#pragma once


class Material;
class Mesh
{
public:
	void Init(vector<Vertex>& vec,vector<uint32>& index);
	void Render();
	void SetTransform(Transform transform) { _transform = transform; }
	void SetMaterial(shared_ptr<Material> material) { _material = material; }

private:
	void CreateVertxBuffer(vector<Vertex>& vec);
	void CreateIndexBuffer(vector<uint32>& index);


private:
	ComPtr<ID3D12Resource>		_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	_vertexBufferView = {};
	uint32 _vertexCount = 0;


	ComPtr<ID3D12Resource>		_indexBuffer;
	D3D12_INDEX_BUFFER_VIEW	_indexBufferView = {};
	uint32 _indexCount = 0;

	Transform _transform = {};
	shared_ptr<Material> _material;
};

