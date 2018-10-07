static void subdiv_b3(float2 *restrict dest, float2 c0, float2 c1, float2 c2, float2 c3, float t)
{
    float2 p0, p1, p2, p3, p4, pT;

    // Compute point
    p0 = lerp(c0, c1, t);
    p1 = lerp(c1, c2, t);
    p2 = lerp(c2, c3, t);
    p3 = lerp(p0, p1, t);
    p4 = lerp(p1, p2, t);
    pT = lerp(p3, p4, t);

    dest[0] = c0;
    dest[1] = p0;
    dest[2] = p1;
    dest[3] = pT;
    dest[4] = pT;
    dest[5] = p2;
    dest[6] = p3;
    dest[7] = c3;
}

static void subdiv_half_b3(float2 *restrict dest, float2 c0, float2 c1, float2 c2, float2 c3)
{
    subdiv_b3(dest, c0, c1, c2, c3, 0.5);
}
