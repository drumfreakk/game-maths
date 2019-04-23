#ifndef GAME_MATHS_GEOMETRY3D_H
#define GAME_MATHS_GEOMETRY3D_H

#include "vectors.h"
#include "matrices.h"

typedef vec3 Point;

typedef struct Line {
	Point start;
	Point end;
	inline Line() {}
	inline Line(const Point& s, const Point& e)
		: start(s), end(e)
	{ }
} Line;

float Length(const Line& line);
float LengthSq(const Line& line);

typedef struct Ray {
	Point origin;
	vec3 direction;
	inline Ray()
		: direction(0.0f, 0.0f, 1.0f) {}
	inline Ray(const Point& o, const vec3& d)
		: origin(o), direction(d) {
		NormalizeDirection();
	}
	inline void NormalizeDirection() {
		Normalize(direction);
	}
} Ray;

Ray FromPoints(const Point& from, const Point& to);

typedef struct Sphere {
	Point position;
	float radius;
	inline Sphere()
		: radius(1.0f)
	{ }
	inline Sphere(const Point& p, float r)
		: position(p), radius(r)
	{ }
} Sphere;

typedef struct AABB {
	Point position;
	vec3 size;
	inline AABB()
		: size(1, 1, 1)
	{ }
	inline AABB(const Point& o, const vec3& s)
		: position(o), size(s)
	{ }
} AABB;

vec3 GetMin(const AABB& aabb);
vec3 GetMax(const AABB& aabb);
AABB FromMinMax(const vec3& min, const vec3& max);

typedef struct OBB {
	Point position;
	vec3 size;
	mat3 orientation;
	inline OBB()
		: size(1, 1, 1)
	{ }
	inline OBB(const Point& p, const vec3& s)
		: position(p), size(s)
	{ }
	inline OBB(const Point& p, const vec3& s, const mat3& o)
		: position(p), size(s), orientation(o)
	{ }
} OBB;

typedef struct Plane {
	vec3 normal;
	float distance;
	inline Plane()
		: normal(1, 0, 0)
	{ }
	inline Plane(const vec3& n, float d)
		: normal(n), distance(d)
	{ }
} Plane;

float PlaneEquation(const Point& pt, const Plane& plane);

typedef struct Triangle {
	union {
		struct {
			Point a;
			Point b;
			Point c;
		};
		Point points[3];
		float values[9];
	};
	inline Triangle(){ }
	inline Triangle(const Point& p1, const Point& p2, const Point& p3)
		: a(p1), b(p2), c(p3)
	{ }
} Triangle;


#endif
