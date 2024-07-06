#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct DV {
    string Name;
    int BirthYear, YearIn;
};

DV* readFile(const string &filename, int *n) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "file open\n";
    }
    file >> *n; 
    file.ignore();
    DV* dv = new DV[*n];
    for (int i = 0; i < *n; i++) {
        getline(file, dv[i].Name);
        file >> dv[i].BirthYear >> dv[i].YearIn;
        file.ignore();
    }
    file.close();
    return dv;
}

void print(DV* dv, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Dang vien " << i + 1 << ": " << dv[i].Name << " " << dv[i].BirthYear << " " << dv[i].YearIn << endl;
    }
}

void bubble_sort(DV* dv, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dv[j].YearIn > dv[j + 1].YearIn) {
                swap(dv[j], dv[j + 1]);
            }
        }
    }
}

void sx(DV* dv, int n) {
    bubble_sort(dv, n);
    for (int i = 0; i < n; i++) {
        cout << dv[i].Name << " " << dv[i].BirthYear << " " << dv[i].YearIn << endl;
    }
}

void year_20(DV* dv, int n) {
    int current_year = 2024;
    for (int i = 0; i < n; i++) {
        if ((current_year - dv[i].YearIn) >= 20) {
            cout << dv[i].Name << " " << dv[i].BirthYear << " " << dv[i].YearIn << endl;
        }
    }
}

int main() {
    int n;
    string file = "input2.txt";
    DV* dv = readFile(file, &n);
    print(dv, n);
    sx(dv, n);
    cout << endl;
    year_20(dv, n);

    delete []dv;
    return 0;
}