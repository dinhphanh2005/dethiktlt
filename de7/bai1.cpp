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

void print(Point* points, int n) {
    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }
}

double distance(Point &point) {
    return sqrt(pow(point.x, 2) + pow(point.y, 2));
}

void further(Point* points, int n) {
    double max = 0;
    for (int i = 0; i < n; i++) {
        double distances = distance(points[i]);
        if (distances > max) {
            max = distances;
        }
    }
    for (int i = 0; i < n; i++) {
        if (distance(points[i]) == max) {
            cout << "Diem co khoang cach lon nhat la: " << points[i].x << " " << points[i].y << endl;
        }
    }
}

void cut(Point* points, int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].x > 0 && points[i].y > 0) {
                if ((points[j].x > 0 && points[j].y < 0) || (points[j].x < 0 && points[j].y < 0)) {
                    count++;
                }
            }
            if (points[i].x < 0 && points[i].y > 0) {
                if ((points[j].x > 0 && points[j].y < 0) || (points[j].x < 0 && points[j].y < 0)) {
                    count++;
                }
            }
        }
    }
    cout << "so doan thang cat truc hoanh la: " << count << endl;
}

int main() {
    int n;
    string file; 
    cout << "nhap ten tep: ";
    cin >> file;
    Point* points = readFile(file, &n);
    print(points, n);
    further(points, n);
    cut(points, n);

    delete []points;
    return 0;
}