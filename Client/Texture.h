#pragma once


class Texture
{

public:
	void Init(const wstring& path);
	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle() { return _handle; }

	void CreateTexture(const wstring& path);
	void CreateView();

private:
	ScratchImage _image;
	ComPtr<ID3D12Resource> _tex2D;

	ComPtr<ID3D12DescriptorHeap> _heap;
	D3D12_CPU_DESCRIPTOR_HANDLE _handle;


};

