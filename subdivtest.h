static int subdivtest(float2 c0, float2 c1, float2 c2, float2 c3)
{
    float2 c_avg, c_sdv;
    float r;

    // Compute avg[x, y]
    c_avg = (c0 + c1 + c2 + c3)*0.25f;

    // Convert to residual
    c0 -= c_avg;
    c1 -= c_avg;
    c2 -= c_avg;
    c3 -= c_avg;

    // Compute sdv[x, y]
    c_sdv = sqrt2(c0*c0 + c1*c1 + c2*c2 + c3*c3)*0.5f;

    // Compute PMCC^2
    r  = (c0[0]*c0[1] + c1[0]*c1[1] + c2[0]*c2[1] + c3[0]*c3[1]);
    r /= (c_sdv[0]*c_sdv[1]*4);
    r *= r;

    // If r is +inf, the points were all on top of each other
    // and this does not need any further subdivision.
    return isfinite(r) && r < 0.97f;
}
