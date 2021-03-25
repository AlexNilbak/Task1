#include "Vector0.h"

int Vector0::output(const string filename) {
	ofstream fout(filename, ios_base::app);
	for (int i = 0; i < n; ++i) {
		fout << v[i] << ' ';
	}
	fout << '\n';
	fout.close();
	return 0;
}

Vector0 operator+(const Vector& a, const Vector& b) {
	if (a.n > b.n) {
		double* d = new double[a.n];
		for (int i = b.n - 1; i < a.n; i++) {
			d[i] = a.v[i];
		}
		for (int i = 0; i < b.n; i++) {
			d[i] = a.v[i] + b.v[i];
		}
		Vector0 res(d, a.n);
		delete[] d;
		return res;
	}
	if (a.n < b.n) {
		double* d = new double[b.n];
		for (int i = a.n - 1; i < b.n; i++) {
			d[i] = b.v[i];
		}
		for (int i = 0; i < b.n; i++) {
			d[i] = a.v[i] + b.v[i];
		}
		Vector0 res(d, a.n);
		delete[] d;
		return res;
	}
	if (a.n == b.n) {
		double* d = new double[a.n];
		for (int i = 0; i < a.n; i++) {
			d[i] = a.v[i] + b[i];
		}
		Vector0 res(d, a.n);
		delete[] d;
		return res;
	}
}

Vector0 operator-(const Vector& a, const Vector& b) {
	if (a.n > b.n) {
		double* d = new double[a.n];
		for (int i = b.n - 1; i < a.n; i++) {
			d[i] = a.v[i];
		}
		for (int i = 0; i < b.n; i++) {
			d[i] = a.v[i] - b.v[i];
		}
		Vector0 res(d, a.n);
		delete[] d;
		return res;
	}
	if (a.n < b.n) {
		double* d = new double[b.n];
		for (int i = a.n - 1; i < b.n; i++) {
			d[i] = (-1)*b.v[i];
		}
		for (int i = 0; i < b.n; i++) {
			d[i] = a.v[i] - b.v[i];
		}
		Vector0 res(d, a.n);
		delete[] d;
		return res;
	}
	if (a.n == b.n) {
		double* d = new double[a.n];
		for (int i = 0; i < a.n; i++) {
			d[i] = a.v[i] - b[i];
		}
		Vector0 res(d, a.n);
		delete[] d;
		return res;
	}
}
