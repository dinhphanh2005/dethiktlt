#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int** readFile(const string &filename, int *n, int *m) {
    ifstream file(filename); 
    if (file.is_open()) {
        cout << "file open\n";
    }
    file >> *n >> *m;
    if (*n != *m) {
        return NULL;
    }

    int** array = new int*[*n];
    for (int i = 0; i < *n; i++) {
        array[i] = new int[*m];
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            file >> array[i][j];
        }
    }
    file.close();
    return array;
}

void print(int n, int m, int** array) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void tbc(int n, int m, int** array) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j > m - 1) {
                sum += array[i][j];
                count++;
            }
        }
    }
    double result = sum / count;
    cout << result << endl;
}

void check(int n, int m, int** array) {
    bool checked = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i > j) && (array[i][j] == 0)) {
                checked = true;
            }
        }
    }
    if (checked) {
        cout << "la ma tran tam giac tren\n";
    } else {
        cout << "ko phai ma tran tam giac tren\n";
    }
}

void sparse(int** array, int n, int m) {
    bool sparse_matrix = false;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] == 0) {
                count++;
            }
        }
    }
    double percentage = (double)count / (n * m);
    if (percentage > 0.6) {
        sparse_matrix = true;
    }
    if (sparse_matrix) {
        cout << "Ma tran thua\n";
    } else {
        cout << "Ma tran ko thua\n";
    }
}

int main() {
    int n, m;
    string file;
    cout << "Nhap ten tep: ";
    cin >> file;
    int** array = readFile(file, &n, &m);
    print(n, m, array);
    tbc(n, m, array);
    check(n, m, array);
    sparse(array, n, m);

    for (int i = 0; i < n; i++) {
        delete []array[i];
    }
    delete []array;
    return 0;
}