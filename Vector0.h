#pragma once
#include "Vector.h"

class Vector0 : public Vector {
public:
	using Vector::operator=;
	Vector0() {}
	~Vector0() {}
	Vector0(const Vector& b) : Vector(b) {}
	Vector0(const double* b, int n) :Vector(b, n) {}
	friend Vector0 operator+(const Vector& a, const Vector& b);
	friend Vector0 operator-(const Vector& a, const Vector& b);
	int output(const string FileName) override;
};


