#include "Vector1.h"

int Vector1::output(const string filename) {
	ofstream fout(filename, ios_base::app);
	for (int i = 0; i < n; ++i) {
		fout << v[i] << '\n';
	}
	fout << '\n';
	fout.close();
	return 0;
}
