
<<<<<<< HEAD
cbuffer TEST_B1 : register(b0)
{
    float4 offset1;
};

cbuffer TEST_B2 : register(b1)
{
    float4 offset2;
};

cbuffer TEST_B3 : register(b2)
{
    float4 offset3;
};


=======
>>>>>>> parent of be4d8ea (상수버퍼뷰 이용)
struct VS_IN
{
    float3 pos : POSITION;
    float4 color : COLOR;
  
};

struct VS_OUT
{
    float4 pos : SV_Position;
    float4 color : COLOR;
};


VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output;
    
    output.pos = float4(input.pos, 1.0f);
<<<<<<< HEAD
    output.pos += offset3;
    
    output.color = input.color;
    output.color += offset3;
    
=======
    output.color = input.color;
  
>>>>>>> parent of be4d8ea (상수버퍼뷰 이용)
    return output;
    
}

float4 PS_Main(VS_OUT input):SV_Target
{
    return input.color;

}