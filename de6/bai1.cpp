#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double** readFile(const string &filename, int* n, int* m) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "file open\n";
    }
    file >> *n >> *m;
    double** array = new double*[*n];
    for (int i = 0; i < *n; i++) {
        array[i] = new double[*m];
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            file >> array[i][j];
        }
    }
    file.close();
    return array;
}

void print(double** array, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void tbc_row(double** array, int n, int m) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 2 != 0) {
                if (array[i][j] > 0) {
                    sum += array[i][j];
                    count++;
                }
            }
        }
    }
    double result = sum / count;
    cout << result << endl;
}
 
void min_pos(double** array, int n, int m) {
    double max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    double min = max;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] > 0) {
                if (array[i][j] < min) {
                    min = array[i][j];
                }
            }
        }
    }
    cout << "Phan tu duong nho nhat la: " << min << endl;
}

int main() {
    int n, m;
    string file;
    cout << "nhap ten file: ";
    cin >> file;
    double** array = readFile(file, &n, &m);
    print(array, n, m);
    tbc_row(array, n, m);
    min_pos(array, n, m);

    for (int i = 0; i < n; i++) {
        delete []array[i];
    }
    delete []array;
    return 0;
}