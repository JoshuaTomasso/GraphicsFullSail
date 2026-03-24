#pragma once
#include "MyMath.h"

void (*VertexShader)(Float4&);
void (*PixelShader)(unsigned int&);
Matrix4x4 SV_WorldMatrix;
Matrix4x4 SV_ViewMatrix;
Matrix4x4 SV_ProjectionMatrix;

// Directional light config
Float4 LightDir = NormalizeVec3({ -0.577f, -0.577f, 0.577f, 0.0f });
unsigned int LightColor = 0xFFC0C0F0;
float AmbientIntensity = 0.15f;

void VS_World(Float4& v)
{
    LitVertex& vert = *(LitVertex*)&v;

    // Transform position
    Float4 worldPos = MatrixVertexMultiply(vert.pos, SV_WorldMatrix);

    // Transform normal (only rotate, no translate)
    Float4 worldNormal = MatrixVertexMultiply(vert.normal, SV_WorldMatrix);
    worldNormal = NormalizeVec3(worldNormal);

    // Dot product for directional lighting
    float NdotL = DotProduct(worldNormal, LightDir);
    NdotL = Saturate(NdotL);

    // Final light ratio (diffuse + ambient)
    float lightingFactor = Saturate(NdotL + AmbientIntensity);

    // Apply lighting to texture color (color modulated)
    unsigned int litColor = ModulateColors(LightColor, (unsigned int)(lightingFactor * 255.0f) << 24 | 0xFFFFFF);
    vert.color = litColor;

    // Pass position through view/projection
    Float4 viewPos = MatrixVertexMultiply(worldPos, SV_ViewMatrix);
    v = MatrixVertexMultiply(viewPos, SV_ProjectionMatrix);

    // Homogenize
    if (v.w != 0.0f)
    {
        v.x /= v.w;
        v.y /= v.w;
        v.z /= v.w;
    }
    v.w = 1.0f;
}

void PS_White(unsigned int& color) { color = 0xFFFFFFFF; }
void PS_Red(unsigned int& color) { color = 0xFFFF0000; }
void PS_Green(unsigned int& color) { color = 0xFF00FF00; }
void PS_Blue(unsigned int& color) { color = 0xFF0000FF; }
