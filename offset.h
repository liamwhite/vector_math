static float2 offset(float4 pnt, float width)
{
    float2 point = (float2) { pnt[0], pnt[1] };
    float2 tang  = (float2) { pnt[2], pnt[3] };

    return tang*width + point;
}
