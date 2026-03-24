#pragma once
#include "Defines.h"

#include <cstdlib>
#include <cmath>

#ifndef GRID_CUBE_VERTS_DEFINED
#define GRID_CUBE_VERTS_DEFINED

Float4 gridVerts[44];
Float4WithColor cubeVertsUV[36];
Star starField[3000];
LitVertex stoneVerts[1457];
unsigned int stoneIndices[2532];
constexpr int GROUND_SEGMENTS = 64;
Float4WithColor groundVerts[GROUND_SEGMENTS + 2];

#endif // GRID_CUBE_VERTS_DEFINED


void InitializeGridVerts()
{
    int index = 0;
    for (int i = 0; i <= 10; ++i)
    {
        float t = -0.5f + i * (1.0f / 10.0f);
        gridVerts[index++] = { -0.5f, 0.0f, t, 1.0f };
        gridVerts[index++] = { 0.5f, 0.0f, t, 1.0f };
        gridVerts[index++] = { t, 0.0f, -0.5f, 1.0f };
        gridVerts[index++] = { t, 0.0f,  0.5f, 1.0f };
    }
}

void InitializeCubeVerts()
{
    int i = 0;
    float s = 0.25f;

    // Front
    cubeVertsUV[i++] = { { -s, -s, -s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { {  s, -s, -s, 1.0f }, 0, 1.0f, 1.0f };
    cubeVertsUV[i++] = { {  s,  s, -s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { { -s, -s, -s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { {  s,  s, -s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { { -s,  s, -s, 1.0f }, 0, 0.0f, 0.0f };

    // Back
    cubeVertsUV[i++] = { {  s, -s,  s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { { -s, -s,  s, 1.0f }, 0, 1.0f, 1.0f };
    cubeVertsUV[i++] = { { -s,  s,  s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { {  s, -s,  s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { { -s,  s,  s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { {  s,  s,  s, 1.0f }, 0, 0.0f, 0.0f };

    // Left
    cubeVertsUV[i++] = { { -s, -s,  s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { { -s, -s, -s, 1.0f }, 0, 1.0f, 1.0f };
    cubeVertsUV[i++] = { { -s,  s, -s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { { -s, -s,  s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { { -s,  s, -s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { { -s,  s,  s, 1.0f }, 0, 0.0f, 0.0f };

    // Right
    cubeVertsUV[i++] = { {  s, -s, -s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { {  s, -s,  s, 1.0f }, 0, 1.0f, 1.0f };
    cubeVertsUV[i++] = { {  s,  s,  s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { {  s, -s, -s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { {  s,  s,  s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { {  s,  s, -s, 1.0f }, 0, 0.0f, 0.0f };

    // Top
    cubeVertsUV[i++] = { { -s,  s, -s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { {  s,  s, -s, 1.0f }, 0, 1.0f, 1.0f };
    cubeVertsUV[i++] = { {  s,  s,  s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { { -s,  s, -s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { {  s,  s,  s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { { -s,  s,  s, 1.0f }, 0, 0.0f, 0.0f };

    // Bottom
    cubeVertsUV[i++] = { { -s, -s,  s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { {  s, -s,  s, 1.0f }, 0, 1.0f, 1.0f };
    cubeVertsUV[i++] = { {  s, -s, -s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { { -s, -s,  s, 1.0f }, 0, 0.0f, 1.0f };
    cubeVertsUV[i++] = { {  s, -s, -s, 1.0f }, 0, 1.0f, 0.0f };
    cubeVertsUV[i++] = { { -s, -s, -s, 1.0f }, 0, 0.0f, 0.0f };
}

float RandomRange(float min, float max)
{
    return min + ((rand() / (float)RAND_MAX) * (max - min));
}

void InitializeStars()
{
    for (int i = 0; i < 3000; ++i)
    {
        float x = RandomRange(-1.0f, 1.0f);
        float y = RandomRange(-1.0f, 1.0f);
        float z = RandomRange(-1.0f, 1.0f);
        float len = std::sqrt(x * x + y * y + z * z);
        if (len == 0.0f) len = 1.0f;

        x /= len;
        y /= len;
        z /= len;

        // Move stars to 5–20 units away from the camera (within visible range)
        float dist = RandomRange(5.0f, 9.5f); // ensure they're inside the 10.0 far plane
        starField[i].position = { x * dist, y * dist, z * dist, 1.0f };
    }
}

void InitializeStonehengeData()
{
    // === Step 1: Initialize positions, UVs, zero normals ===
    for (int i = 0; i < 1457; ++i)
    {
        const OBJ_VERT& vert = StoneHenge_data[i];

        LitVertex v;
        v.pos = { vert.pos[0] * 0.1f, vert.pos[1] * 0.1f, vert.pos[2] * 0.1f, 1.0f }; // scaled pos
        v.normal = { 0.0f, 0.0f, 0.0f, 0.0f }; // will accumulate from faces
        v.u = vert.uvw[0];
        v.v = vert.uvw[1];
        v.color = 0; // to be set in vertex shader

        stoneVerts[i] = v;
    }

    // === Step 2: Copy indices ===
    for (int i = 0; i < 2532; ++i)
    {
        stoneIndices[i] = StoneHenge_indicies[i];
    }

    // === Step 3: Compute face normals and accumulate into vertex normals ===
    for (int i = 0; i < 2532; i += 3)
    {
        int i0 = stoneIndices[i + 0];
        int i1 = stoneIndices[i + 1];
        int i2 = stoneIndices[i + 2];

        Float4 p0 = stoneVerts[i0].pos;
        Float4 p1 = stoneVerts[i1].pos;
        Float4 p2 = stoneVerts[i2].pos;

        // Edges
        Float4 edge1 = { p1.x - p0.x, p1.y - p0.y, p1.z - p0.z, 0.0f };
        Float4 edge2 = { p2.x - p0.x, p2.y - p0.y, p2.z - p0.z, 0.0f };

        // Face normal (not normalized yet)
        Float4 faceNormal = CrossProduct(edge1, edge2);

        // Accumulate to each vertex
        stoneVerts[i0].normal.x += faceNormal.x;
        stoneVerts[i0].normal.y += faceNormal.y;
        stoneVerts[i0].normal.z += faceNormal.z;

        stoneVerts[i1].normal.x += faceNormal.x;
        stoneVerts[i1].normal.y += faceNormal.y;
        stoneVerts[i1].normal.z += faceNormal.z;

        stoneVerts[i2].normal.x += faceNormal.x;
        stoneVerts[i2].normal.y += faceNormal.y;
        stoneVerts[i2].normal.z += faceNormal.z;
    }

    // === Step 4: Normalize all vertex normals ===
    for (int i = 0; i < 1457; ++i)
    {
        stoneVerts[i].normal = NormalizeVec3(stoneVerts[i].normal);
    }
}


