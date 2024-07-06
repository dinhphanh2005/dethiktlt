#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct SV {
    string Name;
    string Country;
    char HL;
};

SV* readFile(const string &filename, int *n) {
    ifstream file(filename); 
    if (file.is_open()) {
        cout << "file open\n";
    }
    file >> *n;
    file.ignore();
    SV* sv = new SV[*n];
    for (int i = 0; i < *n; i++) {
        getline(file, sv[i].Name);
        getline(file, sv[i].Country);
        file >> sv[i].HL;
        file.ignore();
    }
    file.close();
    return sv;
}

void print(int n, SV* sv) {
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << ": " << sv[i].Name << " " << sv[i].Country << " " << sv[i].HL << endl;
    }
}

void thong_ke(SV* sv, int n) {
    int count_a = 0, count_b = 0, count_c = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].HL == 'A' || sv[i].HL == 'a') {
            count_a++;
        }
        if (sv[i].HL == 'B' || sv[i].HL == 'b') {
            count_b++;
        }
        if (sv[i].HL == 'C' || sv[i].HL == 'c') {
            count_c++;
        }
    }
    cout << "Hoc luc A: " << count_a << endl;
    cout << "Hoc luc B: " << count_b << endl;
    cout << "Hoc luc C: " << count_c << endl;
}

void find(SV* sv, int n) {
    string student;
    cout << "Nhap ten sinh vien: ";
    getline(cin, student);
    student.erase(student.begin(), find_if(student.begin(), student.end(), [](unsigned char c) {
        return !isspace(c);
    }));
    student.erase(find_if(student.rbegin(), student.rend(), [](unsigned char c) {
        return !isspace(c);
    }).base(), student.end());
    transform(student.begin(), student.end(), student.begin(), ::tolower);
    bool found = false;
    for (int i = 0; i < n; i++) {
        string name = sv[i].Name;
        name.erase(name.begin(), find_if(name.begin(), name.end(), [](unsigned char c) {
            return !isspace(c);
        }));
        name.erase(find_if(name.rbegin(), name.rend(), [](unsigned char c) {
            return !isspace(c);
        }).base(), name.end());
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (name == student) {
            cout << sv[i].Name << " " << sv[i].Country << " " << sv[i].HL << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "khong co sinh vien nay\n";
    }
}

int main() {
    int n; 
    string file = "input2.txt";
    SV* sv = readFile(file, &n);
    print(n, sv);
    thong_ke(sv, n);
    find(sv, n);

    delete []sv;
    return 0;
}