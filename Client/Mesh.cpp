#include "pch.h"
#include "Mesh.h"
#include "Core.h"


void Mesh::Init(vector<Vertex>& vec, vector<uint32>& index)
{
	CreateVertxBuffer(vec);
	CreateIndexBuffer(index);

<<<<<<< HEAD

	_transform.offset = Vec4(30.0f, 30.0f, 30.0f, 0.0f);

=======
>>>>>>> parent of be4d8ea (ìƒìˆ˜ë²„í¼ë·° ì´ìš©)
}

void Mesh::Render()
{
	CORE->GetCmdList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	CORE->GetCmdList()->IASetVertexBuffers(0, 1, &_vertexBufferView); // Slot: (0~15)
	CORE->GetCmdList()->IASetIndexBuffer(&_indexBufferView);
<<<<<<< HEAD

	////CORE->GetConstantBuffer()->PushData(0, &_transform, sizeof(_transform));
	//CORE->GetConstantBuffer()->PushData(1, &_transform, sizeof(_transform));
	CORE->GetConstantBuffer()->PushCvData(3, &_transform, sizeof(_transform));
=======
>>>>>>> parent of be4d8ea (ìƒìˆ˜ë²„í¼ë·° ì´ìš©)
	CORE->GetCmdList()->DrawIndexedInstanced(_indexCount, 1, 0, 0,0);
}

void Mesh::CreateVertxBuffer(vector<Vertex>& vec)
{
	_vertexCount = static_cast<uint32>(vec.size());
	uint32 bufferSize = _vertexCount * sizeof(Vertex);

	D3D12_HEAP_PROPERTIES heapProperty = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	D3D12_RESOURCE_DESC desc = CD3DX12_RESOURCE_DESC::Buffer(bufferSize);

	CORE->GetDevice()->CreateCommittedResource(
		&heapProperty,
		D3D12_HEAP_FLAG_NONE,
		&desc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&_vertexBuffer));

	// Copy the triangle data to the vertex buffer.
	void* vertexDataBuffer = nullptr;
	CD3DX12_RANGE readRange(0, 0); // We do not intend to read from this resource on the CPU.
	_vertexBuffer->Map(0, &readRange, &vertexDataBuffer);
	::memcpy(vertexDataBuffer, &vec[0], bufferSize);
	_vertexBuffer->Unmap(0, nullptr);

	// Initialize the vertex buffer view.
	_vertexBufferView.BufferLocation = _vertexBuffer->GetGPUVirtualAddress();
	_vertexBufferView.StrideInBytes = sizeof(Vertex); // Á¤Á¡ 1°³ Å©±â
	_vertexBufferView.SizeInBytes = bufferSize; // ¹öÆÛÀÇ Å©±â	

}

void Mesh::CreateIndexBuffer(vector<uint32>& buffer)
{
	_indexCount = static_cast<uint32>(buffer.size());
	uint32 bufferSize = _indexCount * sizeof(uint32);

	D3D12_HEAP_PROPERTIES heapProperty = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	D3D12_RESOURCE_DESC desc = CD3DX12_RESOURCE_DESC::Buffer(bufferSize);

	CORE->GetDevice()->CreateCommittedResource(
		&heapProperty,
		D3D12_HEAP_FLAG_NONE,
		&desc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&_indexBuffer));
	
	void* indexDataBuffer = nullptr;
	CD3DX12_RANGE readRange(0, 0); // We do not intend to read from this resource on the CPU.
	_indexBuffer->Map(0, &readRange, &indexDataBuffer);
	::memcpy(indexDataBuffer, buffer.data(), bufferSize);
	_indexBuffer->Unmap(0, nullptr);

	_indexBufferView.BufferLocation = _indexBuffer->GetGPUVirtualAddress();
	_indexBufferView.Format = DXGI_FORMAT_R32_UINT;
	_indexBufferView.SizeInBytes = bufferSize;


}

