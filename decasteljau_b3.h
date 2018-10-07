static float4 decasteljau_b3(float2 c0, float2 c1, float2 c2, float2 c3, float t)
{
    float2 p0, p1, p2;

    // Compute point
    p0 = lerp(c0, c1, t);
    p1 = lerp(c1, c2, t);
    p2 = lerp(c2, c3, t);
    p0 = lerp(p0, p1, t);
    p1 = lerp(p1, p2, t);
    p2 = lerp(p0, p1, t);

    // Compute tangent at point
    p1 = normalize(p1 - p0);

    return (float4) { p2[0], p2[1], -p1[1], p1[0] };
}
