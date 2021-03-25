#include "Vector.h"
#include "Temp.h"
#include "Vector0.h"
#include "Vector1.h"
using namespace std;


int main() {
    try {
        AutoTest();

        ifstream input("data.txt");
        if (!input.is_open()) {
            cout << "Cannot open the file" << endl;
            return 1;
        }
        char* str = new char[512];
        string s;
        int m;
        double d;
        int n = 0;
        while (!input.eof()) {
            input.getline(str, 512, '\n');
            n++;
        }
        input.seekg(0, ios_base::beg);

        Vector** arr;
        arr = new Vector * [n];
        for (int i = 0; i < n; ++i) {
            input >> m;
            if (m == 0) {
                arr[i] = new Vector0;
            }
            if (m == 1) {
                arr[i] = new Vector1;
            }
            input >> s;
            arr[i]->Setfile(s);
            input >> m;
            arr[i]->Setn(m);
            for (int j = 0; j < m; ++j) {
                input >> d;
                (*arr[i])[j] = d;
            }
        }
        for (int i = 0; i < n; ++i) {
            arr[i]->output(arr[i]->Getfile());
        }
        input.close();
        delete[] str;
        for (int i = 0; i < n; ++i) {
            delete arr[i];
        }
        delete[] arr;
        return 0;
    }
    catch (int err) {
        cout << "error" << err << endl;
    }
}
