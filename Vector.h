#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Temp;
void AutoTest();
class Vector0;

class Vector {
protected:
	double* v;
	int n;
	string filename;
public:
	virtual int output(const string filename) = 0;

	void Setfile(const string s){
		filename = s; 
	};
	const string Getfile() {
		return filename;
	};
	void Setn(int m){ 
		Clean(); 
		n = m; 
		v = new double[n];
	}

	Vector(){ 
		SetZero(); 
	}
	~Vector(){ 
		Clean();
	}

	void Clean();
	void SetZero();
	void CopyOnly(const Vector& b);
	Vector(const Vector& b);
	Vector(const double* b, int n);
	void print();
	int length()const;
	double* vector()const;
	Vector& operator=(const Vector& b);
	double& operator[](int i) const;
	double operator*(const Vector& b);
	Temp operator[](int i);

	friend class Temp;
	friend Vector0 operator+(const Vector& a, const Vector& b);
	friend Vector0 operator-(const Vector& a, const Vector& b);
};

