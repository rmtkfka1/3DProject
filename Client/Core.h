#pragma once
#include "ConstantBuffer.h"
#include "ConstantBufferTable.h"
#include "TableDescriptorHeap.h"

class Core
{

public:
	
	static Core* GetInstance()
	{
		static Core mm;
		return &mm;
	}

	void Init(const WindowInfo& info);
	void RenderBegin();
	void RenderEnd();

	ComPtr<ID3D12RootSignature> GetRootSignature() { return _rootSignature; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }
	ComPtr<ID3D12GraphicsCommandList> GetCmdList() { return _cmdList; }
	shared_ptr<ConstantBuffer> GetConstantBuffer() { return _constantBuffer; }
	shared_ptr<ConstantBufferTable> GetConstantBufferTable() { return _constantBufferTable; }
	shared_ptr<TableDescriptorHeap> GetTableDescriptorHeap() { return _tableDescriptorHeap; }

private:
	Core() {};
	~Core() {};

	void ResizeWIndow();
	void WaitSync();

	//장치초기화
	void CreateDevice();
	void CreateCommandQueueAndList();
	void CreateSwapChain();
	void CreateRTVBuffer();
	void CreateRootSignature();


private:
	D3D12_VIEWPORT _viewport;
	D3D12_RECT _scissorRect;

	WindowInfo _info;

	ComPtr<ID3D12Device> _device;
	ComPtr<IDXGIFactory4> _dxgi;
	ComPtr<ID3D12Debug>	 _debugController;

	ComPtr<ID3D12CommandQueue> _cmdQueue;
	ComPtr<ID3D12GraphicsCommandList> _cmdList;
	ComPtr<ID3D12CommandAllocator> _cmdMemory;

	ComPtr<ID3D12Fence>					_fence;
	uint32								_fenceValue = 0;
	HANDLE								_fenceEvent = INVALID_HANDLE_VALUE;


	ComPtr<IDXGISwapChain> _swapChain;
	array<ComPtr<ID3D12Resource>, SWAP_CHAIN_BUFFER_COUNT> _rtvBuffer;
	ComPtr<ID3D12DescriptorHeap> _rtvHeap;
	array< D3D12_CPU_DESCRIPTOR_HANDLE,2> _rtvHandle;
	uint8 _backBufferIndex = 0;

	ComPtr<ID3D12RootSignature> _rootSignature;


	shared_ptr<ConstantBuffer> _constantBuffer;
	shared_ptr<ConstantBufferTable> _constantBufferTable;
	shared_ptr<TableDescriptorHeap> _tableDescriptorHeap;



};

