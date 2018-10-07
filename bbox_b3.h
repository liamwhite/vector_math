static float4 bbox_b3(float2 c0, float2 c1, float2 c2, float2 c3)
{
    float2 p0, p1;

    p0 = max2(c0, c1);
    p0 = max2(p0, c2);
    p0 = max2(p0, c3);
    p1 = min2(c0, c1);
    p1 = min2(p1, c2);
    p1 = min2(p1, c3);

    return (float4) { p0[0], p0[1], p1[0], p1[1] };
}
