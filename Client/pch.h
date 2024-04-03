#pragma once

#define _HAS_STD_BYTE 0

#include <windows.h>
#include <tchar.h>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;



/////////////////////////////////////
///         다이렉트             ////
/////////////////////////////////////

#include "d3dx12.h"
#include "SimpleMath.h"
#include <d3d12.h>
#include <wrl.h>
#include <d3dcompiler.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
#include <dxgi1_4.h>

using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace Microsoft::WRL;

#include <DirectXTex/DirectXTex.h>
#include <DirectXTex/DirectXTex.inl>

// 각종 lib
#pragma comment(lib, "d3d12")
#pragma comment(lib, "dxgi")
#pragma comment(lib, "dxguid")
#pragma comment(lib, "d3dcompiler")

#ifdef _DEBUG
#pragma comment(lib, "DirectXTex\\DirectXTex_debug.lib")
#else
#pragma comment(lib, "DirectXTex\\DirectXTex.lib")
#endif

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;
using Vec2 = DirectX::SimpleMath::Vector2;
using Vec3 = DirectX::SimpleMath::Vector3;
using Vec4 = DirectX::SimpleMath::Vector4;
using Matrix = DirectX::SimpleMath::Matrix;



struct Vertex
{
	Vec3 pos;
	Vec4 color;
	Vec2 uv;
};

struct WindowInfo
{
	int width;
	int height;
	HWND hwnd;
};

struct TransformMatirx
{
	Vec4 offset;
};




enum class CBV_REGISTER 
{
	b0,
	b1,
	b2,
	b3,
	b4,

	END
};

enum class SRV_REGISTER 
{
	t0 =static_cast<uint32>(CBV_REGISTER::END),
	t1,
	t2,
	t3,
	t4,
	END
};

enum
{
	MATERIAL_INT_COUNT = 5,
	MATERIAL_FLOAT_COUNT = 5,
	MATERIAL_TEXTURE_COUNT = 5
};

struct MaterialParam
{
	void SetInt(uint8 index, int32 value) { intParams[index] = value; }
	void SetFloat(uint8 index, float value) { floatParams[index] = value; }

	array<int32, MATERIAL_INT_COUNT> intParams;
	array<float, MATERIAL_FLOAT_COUNT> floatParams;
};

enum
{
	SWAP_CHAIN_BUFFER_COUNT = 2,
	CBV_REGISTER_COUNT = CBV_REGISTER::END,
	SRV_REGISTER_COUNT = static_cast<uint32>(SRV_REGISTER::END) - CBV_REGISTER_COUNT,
	REGISTER_COUNT = CBV_REGISTER_COUNT+ SRV_REGISTER_COUNT,

};

#include "KeyManager.h"
#include "Time.h"



extern unique_ptr<class Core> core;

#define DEVICE core->GetDevice()
#define CMD_LIST core->GetCmdList()