#pragma once
#include "Vector.h"

class Vector1 : public Vector {
public:
	using Vector::operator=;
	Vector1() {}
	~Vector1() {}
	Vector1(const Vector& b) : Vector(b) {}
	Vector1(const double* b, int n) :Vector(b, n) {}
	int output(const string FileName) override;
};
