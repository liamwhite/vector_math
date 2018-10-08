#define _GNU_SOURCE
#include <math.h>

typedef float float2 __attribute__((vector_size(8)));
typedef float float4 __attribute__((vector_size(16)));

static const float M_PI_180f = M_PI / 180.f;
static const float EPSILON   = 1e-6f;

// 4/3*tan(pi/8) = 4/3*(sqrt2-1)
#define magic 0.552284749831f

static float2 unit_circle[] = {
    { +1, +0 }, { +1, +magic }, { +magic, +1 }, { +0, +1 }, // Q0
    { +0, +1 }, { -magic, +1 }, { -1, +magic }, { -1, +0 }, // Q1
    { -1, +0 }, { -1, -magic }, { -magic, -1 }, { +0, -1 }, // Q2
    { +0, -1 }, { +magic, -1 }, { +1, -magic }, { +1, +0 }  // Q3
};

#undef magic

static float2 lerp(float2 p0, float2 p1, float t)
{
    return (p1 - p0)*t + p0;
}

static float2 normalize(float2 p)
{    
    return p / sqrtf(p[0]*p[0] + p[1]*p[1]);
}

static float max(float p0, float p1)
{
    return p0 > p1 ? p0 : p1;
}

static float min(float p0, float p1)
{
    return p0 < p1 ? p0 : p1;
}

static float2 max2(float2 p0, float2 p1)
{
    return (float2) { max(p0[0], p1[0]), max(p0[1], p1[1]) };
}

static float2 min2(float2 p0, float2 p1)
{
    return (float2) { min(p0[0], p1[0]), min(p0[1], p1[1]) };
}

static float2 sqrt2(float2 x)
{
    return (float2) {sqrtf(x[0]), sqrtf(x[1])};
}

static float2 abs2(float2 x)
{
    return (float2) { copysignf(x[0], 1), copysignf(x[1], 1) };
}
