#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

Point* readFile(const string &filename, int* n) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "File open\n";
    }
    file >> *n;
    Point* points = new Point[*n];
    for (int i = 0; i < *n; i++) {
        file >> points[i].x >> points[i].y;
    }
    file.close();
    return points;
}

void print(Point* points, int n) {
    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }
}

double distance(Point &points) {
    return sqrt(pow(points.x, 2) + pow(points.y, 2));
}

void inside(Point* points, int n, int radius) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double distances = distance(points[i]);
        if (distances < radius) {
            count++;
        }
    }
    cout << "co " << count << " nam trong duong tron\n";
}

void outside(Point* points, int n, int radius) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double distances = distance(points[i]);
        if (distances > radius) {
            count++;
        }
    }
    cout << "co " << count << " nam ngoai duong tron\n";
}

void distance_inside(Point* points, int n, int radius) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance1 = distance(points[i]);
            double distance2 = distance(points[j]);
            if ((distance1 < radius) && (distance2 < radius)) {
                count++;
            }
        }
    }
    cout << "co " << count << " doan nam trong duong tron\n";
}

int main() {
    int n;
    string file;
    cout << "Nhap ten tep: ";
    cin >> file;
    Point* points = readFile(file, &n);
    print(points, n);
    int radius = 5;
    inside(points, n, radius);
    outside(points, n, radius);
    distance_inside(points, n, radius);

    delete []points;
    return 0;
}