#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vector.h"
#include "Temp.h"

class Temp;

void Vector::Clean() {
	delete[] v;
	SetZero();
}
void Vector::SetZero() {
	v = NULL;
	n = 0;
}

Vector::Vector(const Vector& b) {
	CopyOnly(b);
}

Vector& Vector::operator=(const Vector& b) {
	if (this != &b) {
		Clean();
		CopyOnly(b);
	}
	return *this;
}

Vector::Vector(const double* b, int n) {
	this->n = n;
	v = new double[n];
	for (int i = 0; i < n; i++) {
		v[i] = b[i];
	}
}

void Vector::CopyOnly(const Vector& b) {
	n = b.n;
	v = new double[n];
	for (int i = 0; i < n; i++) {
		v[i] = b[i];
	}
}

void Vector::print() {
	for (int i = 0; i < n; i++) {
		printf("%f ", v[i]);
	}
}

int Vector::length()const {
	return n;
}

double* Vector::vector()const {
	return v;
}

double& Vector::operator[](int i) const {
	if (i < 0 || i >= n) {
		printf("Incorrect index\n");
		throw 4;
	}
	return v[i];
}
double Vector::operator*(const Vector& b) {
	if (n != b.n) {
		printf("Incorrect length\n");
		throw 5;
	}
	else {
		double res = 0;
		for (int i = 0; i < n; i++) {
			res += v[i] * b[i];
		}
		return res;
	}
}

Temp Vector::operator[](int i) {
	if (i < 0) {
		throw  6;
	}
	return Temp(this, i);
}
