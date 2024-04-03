#pragma once
#include "ConstantBuffer.h"
#include "ConstantBufferTable.h"
#include "TableDescriptorHeap.h"

class Core
{

public:
	

	void Init(const WindowInfo& info);
	void Update();
	void Render();

	void RenderBegin();
	void RenderEnd();
	void FlushResourceCommandQueue();

	const WindowInfo& GetWindowInfo() { return _info; }
	ComPtr<ID3D12RootSignature> GetRootSignature() { return _rootSignature; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }
	ComPtr<ID3D12GraphicsCommandList> GetCmdList() { return _cmdList; }
	ComPtr<ID3D12CommandQueue> GetCmdQueue() { return _cmdQueue; }
	ComPtr<ID3D12GraphicsCommandList> GetTextureCmdList() { return _cmdListTexture; }

	shared_ptr<TableDescriptorHeap> GetTableDescriptorHeap() { return _tableDescriptorHeap; }
	shared_ptr<ConstantBufferTable> GetConstantBufferTable(CONSTANT_BUFFER_TYPE type) { return _constantBufferTable[static_cast<uint8>(type)]; }


private:
	

	void ResizeWIndow();
	void WaitSync();
	void ShowFps();

	void CreateDevice();
	void CreateCommandQueueAndList();


	void CreateSwapChain();
	void CreateRTVBuffer();
	void CreateDepthBuffer();
	void CreateRootSignature();

	void CreateConstantBuffer(CBV_REGISTER reg, uint32 bufferSize , uint32 count);

private:
	D3D12_VIEWPORT _viewport;
	D3D12_RECT _scissorRect;

	WindowInfo _info;

	ComPtr<ID3D12Device> _device;
	ComPtr<IDXGIFactory4> _dxgi;
	ComPtr<ID3D12Debug>	 _debugController;

	ComPtr<ID3D12CommandQueue> _cmdQueue;

	ComPtr<ID3D12GraphicsCommandList> _cmdList;
	ComPtr<ID3D12GraphicsCommandList> _cmdListTexture;

	ComPtr<ID3D12CommandAllocator> _cmdMemory;
	ComPtr<ID3D12CommandAllocator> _cmdMemoryTexutre;

	ComPtr<ID3D12Fence>					_fence;
	uint32								_fenceValue = 0;
	HANDLE								_fenceEvent = INVALID_HANDLE_VALUE;


	ComPtr<IDXGISwapChain> _swapChain;
	array<ComPtr<ID3D12Resource>, SWAP_CHAIN_BUFFER_COUNT> _rtvBuffer;
	ComPtr<ID3D12DescriptorHeap> _rtvHeap;
	array< D3D12_CPU_DESCRIPTOR_HANDLE,2> _rtvHandle;

	ComPtr<ID3D12Resource> _dsvBuffer;
	ComPtr<ID3D12DescriptorHeap> _dsvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE _dsvHandle = {};
	DXGI_FORMAT _dsvFormat = DXGI_FORMAT_D32_FLOAT;


	uint8 _backBufferIndex = 0;

	ComPtr<ID3D12RootSignature> _rootSignature;
	D3D12_STATIC_SAMPLER_DESC _samplerDesc;



	//shared_ptr<ConstantBuffer> _constantBuffer;
	//shared_ptr<ConstantBufferTable> _constantBufferTable;
	vector<shared_ptr<ConstantBufferTable>> _constantBufferTable;
	shared_ptr<TableDescriptorHeap> _tableDescriptorHeap;



};

