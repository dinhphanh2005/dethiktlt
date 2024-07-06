#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int** readFile(const string &filename, int* n, int* m) {
    ifstream file(filename); 
    if (file.is_open()) {
        cout << "File open\n";
    }
    file >> *n >> *m;
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

void print(int** array, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void tbc(int** array, int n, int m) {
    double sum = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            if ((array[i][j] % 2 == 0) && (array[i][j] % 3 == 1)) {
                sum += array[i][j];
            }
        }
    }
    double result = sum / (n * m);
    cout << result << endl;
}

void sum_row(int** array, int n, int m) {
    for (int i = 0; i < n; i++) {
        int sum = 0; 
        for (int j = 0; j < m; j++) {
            sum += array[i][j];
        }
        cout << sum << endl;
    }
}

void writeFile(const string &filename, int n, int m, int** array) {
    ofstream file(filename);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file << array[i][j] << " ";
        }
        file << endl;
    }
}

int main() {
    int n, m;
    string file;
    cout << "Nhap ten tep: ";
    cin >> file;
    int** array = readFile(file, &n, &m);
    print(array, n, m);
    tbc(array, n, m);
    sum_row(array, n, m);
    string filename = "output1.txt";
    writeFile(filename, n, m, array);

    for (int i = 0; i < n; i++) {
        delete []array[i];
    }
    delete []array;
    return 0;
}