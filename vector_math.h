#ifndef _SEEN_VECTOR_MATH_H
#define _SEEN_VECTOR_MATH_H

#include "defs.h"

// Return a AABB around the cubic bezier specified by control points c{0,3}.
static float4 bbox_b3(float2 c0, float2 c1, float2 c2, float2 c3);

// Construct a circle with four cubic bezier curves, centered at center
// with radius radius.
static void circle_b3(float2 *restrict dest, float2 center, float radius);

// Construct an ellipse with four cubic bezier curves, centered at center
// with rays radius and rotated by angle degrees.
static void ellipse_b3(float2 *restrict dest, float2 center, float2 radius, float angle);

// Return the point and normal on the cubic bezier at time t. 
static float4 decasteljau_b3(float2 c0, float2 c1, float2 c2, float2 c3, float t);

// Return whether a cubic bezier is has no length (boolean).
static int degentest(float2 c0, float2 c1, float2 c2, float2 c3);

// Construct an affine matrix with values a,b,c,d,e,f,0,0,1.
static void matrix(float *restrict dest, float a, float b, float c, float d, float e, float f);

// Construct an affine matrix representing a rotation around the origin by
// a degrees.
static void rotate(float *restrict dest, float a);

// Construct an affine matrix representing a translation by (x,y).
static void translate(float *restrict dest, float x, float y);

// Construct an affine matrix representing a scale by (x,y).
static void scale(float *restrict dest, float x, float y);

// Construct an affine matrix representing an x-axis skew by a degrees.
static void skew_x(float *restrict dest, float a);

// Construct an affine matrix representing a y-axis skew by a degrees.
static void skew_y(float *restrict dest, float a);

// Construct an affine matrix representing the dot product of m1 and m2.
// dest and m1 may alias.
static void combine(float *dest, float *m1, float *restrict m2);

// Construct an affine matrix representing a rotation by a degrees around a
// point (x,y).
static void rotate_around(float *restrict dest, float a, float x, float y);

// Return the point offset by width from a combined point and normal vector.
static float2 offset(float4 pnt, float width);

// Construct two cubic beziers by splitting the bezier in c{0,3} at time t.
static void subdiv_b3(float2 *restrict dest, float2 c0, float2 c1, float2 c2, float2 c3, float t);

// Construct two cubic beziers by splitting the bezier in c{0,3} at time 0.5. 
static void subdiv_half_b3(float2 *restrict dest, float2 c0, float2 c1, float2 c2, float2 c3);

// Return whether this cubic bezier is not almost linear (boolean).
static int subdivtest(float2 c0, float2 c1, float2 c2, float2 c3);

// Return the dot product of m and pt.
static float2 transform_point(float *restrict m, float2 pt);

#include "bbox_b3.h"
#include "circle_b3.h"
#include "decasteljau_b3.h"
#include "degentest.h"
#include "matrix.h"
#include "offset.h"
#include "subdiv_b3.h"
#include "subdivtest.h"
#include "transform_point.h"

#endif // _SEEN_VECTOR_MATH_H
