#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

Point* readFile(const string &filename, int *n) {
    ifstream file(filename); 
    if (file.is_open()) {
        cout << "file open\n";
    }
    file >> *n;
    Point* points = new Point[*n];
    for (int i = 0; i < *n; i++) {
        file >> points[i].x >> points[i].y;
    } 
    file.close();
    return points;
}

void print(int n, Point* points) {
    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }
}

void distance(int n, Point* points) {
    double max = 0;
    double result = 0;
    int a, b;
    for (int i = 0; i < n; i++) {
        result = sqrt(pow(points[i].x, 2) + pow(points[i].y, 2));
        if (result > max) {
            max = result;
            a = points[i].x;
            b = points[i].y;
        }
    }
    cout << "Diem xa goc toa do nhat la: " << a << " " << b << " " << max << endl;
}

void third(int n, Point* points) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((points[i].x < 0) && (points[i].y < 0) && (points[j].x < 0) && (points[j].y)) {
                count++;
            }
        }
    }
    cout << "So doan thang nam o goc phan tu thu ba la: " << count << endl;
}
int main() {
    int n;
    string file;
    cout << "Nhap ten tep: ";
    cin >> file;
    Point* points = readFile(file, &n);
    print(n, points);
    distance(n, points);
    third(n, points);

    delete []points;
    return 0;
}