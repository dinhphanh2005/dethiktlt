#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Olympic {
    string name;
    double point;
    string schoolName;
};

Olympic* readFile(const string &filename, int* n) {
    ifstream file(filename); 
    if (file.is_open()) {
        cout << "file open\n";
    }
    file >> *n;
    file.ignore();
    Olympic* ts = new Olympic[*n];
    for (int i = 0; i < *n; i++) {
        getline(file, ts[i].name);
        file >> ts[i].point;
        file.ignore();
        getline(file, ts[i].schoolName);
    }
    file.close();
    return ts;
}

void print(Olympic* ts, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thi sinh " << i + 1 << ": " << ts[i].name << " " << ts[i].point << " " << ts[i].schoolName << endl;
    }
}

void max_school(Olympic* ts, int n) {
    double sum_a = 0, sum_b = 0, sum_c = 0, sum_d = 0;
    for (int i = 0; i < n; i++) {
        if (ts[i].schoolName == "A" || ts[i].schoolName == "a") {
            sum_a += ts[i].point;
        } 
        if (ts[i].schoolName == "B" || ts[i].schoolName == "b") {
            sum_b += ts[i].point;
        } 
        if (ts[i].schoolName == "C" || ts[i].schoolName == "c") {
            sum_c += ts[i].point;
        } 
        if (ts[i].schoolName == "D" || ts[i].schoolName == "d") {
            sum_d += ts[i].point;
        } 
    }
    if ((sum_a > sum_b) && (sum_a > sum_c) && (sum_a > sum_d)) {
        cout << "Truong A co diem so cao nhat: " << sum_a << endl;
    }
    if ((sum_b > sum_a) && (sum_b > sum_c) && (sum_b > sum_d)) {
        cout << "Truong B co diem so cao nhat: " << sum_b << endl;
    }
    if ((sum_c > sum_a) && (sum_c > sum_b) && (sum_c > sum_d)) {
        cout << "Truong C co diem so cao nhat: " << sum_c << endl;
    }
    if ((sum_d > sum_a) && (sum_d > sum_b) && (sum_d > sum_c)) {
        cout << "Truong D co diem so cao nhat: " << sum_d << endl;
    }
}

void max_point(Olympic* ts, int n) {
    double max = 0;
    for (int i = 0; i < n; i++) {
        if (ts[i].point > max) {
            max = ts[i].point;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ts[i].point == max) {
            cout << "Thi sinh co diem cao la: " << ts[i].name << " " << ts[i].point << " " << ts[i].schoolName << endl;
        }
    }
}

int main() {
    int n; 
    string file = "input2.txt";
    Olympic* ts = readFile(file, &n);
    print(ts, n);
    max_school(ts, n);
    max_point(ts, n);

    delete []ts;
    return 0;
}