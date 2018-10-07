static float2 transform_point(float *restrict m, float2 pt)
{
    pt[0] = pt[0] * m[0] + pt[1] * m[2] + m[4];
    pt[1] = pt[0] * m[1] + pt[1] * m[3] + m[5];

    return pt;
}
