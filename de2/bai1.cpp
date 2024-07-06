#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void readfile(const string &filename, int *n, int *m, int*** array) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "File open successful\n";
    }
    file >> *n >> *m;
    *array = new int*[*n];
    for (int i = 0; i < *n; i++) {
        (*array)[i] = new int[*m];
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            file >> (*array)[i][j];
        }
    }
    file.close();
}

void print(int n, int m, int** array) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int total(int n, int m, int** array) {
    int sum = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += array[i][j];
        }
    }
    double tbc = (double)sum / (n * m);
    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] > tbc) {
                sum1 += array[i][j];
            }
        }
    }
    return sum1;
}

void negative(int n, int m, int** array) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] < 0) {
                
            }
        }
    }
}

int main() {
    int n, m;
    string filename;
    cin >> filename;
    int** array;
    readfile(filename, &n, &m, &array);
    print(n, m, array);
    int sum = total(n, m, array);
    cout << sum << endl;
    negative(n, m, array);
    
    for (int i = 0; i < n; i++) {
            delete[] array[i];
    }
    delete[] array;

    return 0;
}