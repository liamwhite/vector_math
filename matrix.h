#define _GNU_SOURCE
#include <math.h>

// Use a float[6]
// | a c e |
// | b d f |
// | 0 0 1 |

static void matrix(float *restrict dest, float a, float b, float c, float d, float e, float f)
{
    dest[0] = a; dest[1] = b;
    dest[2] = c; dest[3] = d;
    dest[4] = e; dest[5] = f;
}

static void rotate(float *restrict dest, float a)
{
    float sin_a, cos_a;

    // TODO: use vector sincos
    sincosf(a * M_PI_180f, &sin_a, &cos_a);

    dest[0] =  cos_a; dest[1] = sin_a;
    dest[2] = -sin_a; dest[3] = cos_a;
    dest[4] = 0;      dest[5] = 0;
}

static void translate(float *restrict dest, float x, float y)
{
    dest[0] = 1; dest[1] = 0;
    dest[2] = 0; dest[3] = 1;
    dest[4] = x; dest[5] = y;
}

static void scale(float *restrict dest, float x, float y)
{
    dest[0] = x; dest[1] = 0;
    dest[2] = 0; dest[3] = y;
    dest[4] = 0; dest[5] = 0;
}

static void skew_x(float *restrict dest, float a)
{
    a *= M_PI_180f;

    dest[0] = 1;       dest[1] = 0;
    dest[2] = tanf(a); dest[3] = 1;
    dest[4] = 0;       dest[5] = 0;
}

static void skew_y(float *restrict dest, float a)
{
    a *= M_PI_180f;

    dest[0] = 1; dest[1] = tanf(a);
    dest[2] = 0; dest[3] = 1;
    dest[4] = 0; dest[5] = 0;
}

// m1 and dest may alias
static void combine(float *dest, float *m1, float *restrict m2)
{
    dest[0] = m1[0] * m2[0] + m1[1] * m2[2];
    dest[1] = m1[0] * m2[1] + m1[1] * m2[3];
    dest[2] = m1[2] * m2[0] + m1[3] * m2[2];
    dest[3] = m1[2] * m2[1] + m1[3] * m2[3];
    dest[4] = m1[4] * m2[0] + m1[5] * m2[2];
    dest[5] = m1[4] * m2[1] + m1[5] * m2[3];
}

static void rotate_around(float *restrict dest, float a, float x, float y)
{
    float pos_translate[6];
    float rot[6];

    translate(dest, -x, -y);
    rotate(rot, a);
    combine(dest, dest, rot);

    translate(pos_translate, x,  y);
    combine(dest, dest, pos_translate);
}
