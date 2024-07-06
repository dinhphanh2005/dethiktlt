#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

struct NV {
    string Name;
    double Salary;
    int MCV;
};

NV* input(int n) {
    NV* employee = new NV[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhan vien " << i + 1 << ": ";
        getline(cin, employee[i].Name);
        cin >> employee[i].Salary;
        cin >> employee[i].MCV;
        cin.ignore();
    }
    return employee;
}

void writeFile(const string &filename, int n, NV* employee) {
    ofstream file(filename); 
    file << "So nhan vien: " << n << endl;
    for (int i = 0; i < n; i++) {
        file << "Nhan vien " << i + 1 << ": " << employee[i].Name << " " << employee[i].Salary << " " << employee[i].MCV << endl;
    }
}

void bubble_sort(NV* employee, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employee[j].Salary < employee[j + 1].Salary) {
                swap(employee[j], employee[j + 1]);
            }
        }
    } 
}

void print(NV* employee, int n) {
    bubble_sort(employee, n);
    for (int i = 0; i < n; i++) {
        cout << employee[i].Name << " " << employee[i].Salary << " " << employee[i].MCV << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;
    cin.ignore();
    NV* employee = input(n);
    string file = "output2.txt";
    writeFile(file, n, employee);
    print(employee, n);

    delete []employee;
    return 0;
}