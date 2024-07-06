#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Olympic {
    string Name;
    double Point;
    string SchoolName;
};

Olympic* readFile(const string &filename, int *n) {
    ifstream file(filename);  
    if (file.is_open()) {
        cout << "File open\n";
    }
    file >> *n;
    file.ignore();
    Olympic* data = new Olympic[*n];
    for (int i = 0; i < *n; i++) {
        getline(file, data[i].Name);
        file >> data[i].Point;
        file.ignore();
        getline(file, data[i].SchoolName);
    }
    file.close(); 
    return data;
}

void print(Olympic* data, int n) {
    for (int i = 0; i < n; i++) {
        cout << "sinh vien " << i + 1 << ": " << data[i].Name << " " << data[i].Point << " " << data[i].SchoolName << endl;
    }
}

double total(Olympic* data, int n) {
    double sum_a = 0, sum_b = 0, sum_c = 0, sum_d = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].SchoolName == "A") {
            sum_a += data[i].Point;
        }
        if (data[i].SchoolName == "B") {
            sum_b += data[i].Point;
        }
        if (data[i].SchoolName == "C") {
            sum_c += data[i].Point;
        }
        if (data[i].SchoolName == "D") {
            sum_d += data[i].Point;
        }
    }    
    if ((sum_a > sum_b) && (sum_a > sum_c) && (sum_a > sum_d)) {
        return sum_a;
    } else if ((sum_b > sum_c) && (sum_b > sum_d) && (sum_b > sum_a)) {
        return sum_b;
    } else if ((sum_c > sum_d) && (sum_c > sum_a) && (sum_c > sum_b)) {
        return sum_c;
    } else {
        return sum_d;
    }
}

void max_point(const string &filename, Olympic* data, int n) {
    double max = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].Point > max) {
            max = data[i].Point;
        }
    }
    int count = 0;
    Olympic* data2 = new Olympic[n];
    for (int i = 0; i < n; i++) {
        if (data[i].Point == max) {
            data2[count++] = data[i];
        }
    }
    for (int i = 0; i < count; i++) {
        cout << "Danh sach thi sinh dat diem cao: " << data2[i].Name << " " << data2[i].Point << " " << data2[i].SchoolName << endl;
    }
    ofstream file(filename);
    for (int i = 0; i < count; i++) {
        file << "Danh sach thi sinh dat diem cao: " << data2[i].Name << " " << data2[i].Point << " " << data2[i].SchoolName << endl;
    }
}

int main() {
    int n;
    string filename;
    cin >> filename;
    Olympic* data = readFile(filename, &n);
    print(data, n);
    double max = total(data, n);
    cout << max << endl;
    string file = "output2.txt";
    max_point(file, data, n);

    delete []data;
    return 0;
}