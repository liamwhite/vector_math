static void circle_b3(float2 *restrict dest, float2 center, float radius)
{
    for (int i = 0; i < 16; ++i)
        dest[i] = unit_circle[i]*radius + center;
}

static void ellipse_b3(float2 *restrict dest, float2 center, float2 radius, float angle)
{
    float trans_1[6];
    float trans_2[6];

    // Construct matrix
    scale(trans_1, radius[0], radius[1]);
    rotate(trans_2, angle * M_PI_180f);
    combine(trans_1, trans_1, trans_2);
    translate(trans_2, center[0], center[1]);
    combine(trans_1, trans_1, trans_2);

    // Convert unit circle to ellipse
    for (int i = 0; i < 16; ++i)
        dest[i] = transform_point(trans_1, unit_circle[i]);
}
