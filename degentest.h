static int degentest(float2 c0, float2 c1, float2 c2, float2 c3)
{
    float2 rmax, c_avg;

    c_avg = (c0 + c1 + c2 + c3)*0.25;

    rmax =      abs2(c0 - c_avg);
    rmax = max2(abs2(c1 - c_avg), rmax);
    rmax = max2(abs2(c2 - c_avg), rmax);
    rmax = max2(abs2(c3 - c_avg), rmax);

    return rmax[0] < EPSILON && rmax[1] < EPSILON;
}
