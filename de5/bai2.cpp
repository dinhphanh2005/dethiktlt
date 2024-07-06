#include <iostream>
#include <string>
#include <fstream>
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

void print(NV* employee, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhan vien " << i + 1 << ": " << employee[i].Name << " " << employee[i].Salary << " " << employee[i].MCV << endl;
    }
}

void writeFile(const string &filename, int n, NV* employee) {
    ofstream file(filename); 
    file << "So nhan vien: " << n << endl;
    for (int i = 0; i < n; i++) {
        file << "Nhan vien " << i + 1 << ": " << employee[i].Name << " " << employee[i].Salary << " " << employee[i].MCV << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;
    cin.ignore();
    NV* employee = input(n);
    print(employee, n);
    string file = "output2.txt";
    writeFile(file, n, employee);

    delete []employee;
    return 0;
}