
cbuffer TEST_B0 : register(b0)
{
    float4 offset3;
};

cbuffer TEST_B0 : register(b1)
{
    float4 offset4;
};

cbuffer TEST_B1 : register(b5)
{
    float4 offset1;
};

cbuffer TEST_B2 : register(b6)
{
    float4 offset2;
};


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
    output.pos += offset1;
    output.pos += offset3;
    
    output.color = input.color;
    output.color += offset2;
    output.color += offset4;
    
    
    return output;
    
}

float4 PS_Main(VS_OUT input):SV_Target
{
    return input.color;

}