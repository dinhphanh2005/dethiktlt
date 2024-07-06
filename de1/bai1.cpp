#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

struct Point {
    float x, y;
};

Point* readFile(const string &filename, int *n) {
    ifstream myFile(filename);  
    if (myFile.is_open()) {
        cout << "File has successfully open!\n";
    }
    myFile >> *n;
    Point* points = new Point[*n];
    for (int i = 0; i < *n; i++) {
        myFile >> points[i].x >> points[i].y;
    }
    myFile.close();
    return points;
}

void print_points(Point* points, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Diem " << i + 1  << ": "<< points[i].x << " " << points[i].y << endl;
    }
}

double distance(Point p) {
    return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

int count_inside(Point* points, int radius, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (distance(points[i]) <= radius) {
            count++;
        }
    }
    return count;
}

void symmetry(Point* points, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((abs(points[i].x) == abs(points[j].x)) && (abs(points[i].y) == abs(points[j].y))) {
                cout << "Symmetry: " << points[i].x << " " << points[i].y << " " << points[j].x << " " << points[j].y << endl;
            }
        }
    }
    if ((abs(points[n - 1].x) == abs(points[0].x)) && (abs(points[n - 1].y) == abs(points[0].y))) {
        cout << "Symmetry: " << points[n - 1].x << " " << points[n - 1].y << " " << points[0].x << " " << points[0].y << endl;
    }
}

int count_outside(Point* points, int radius, int n) {
    int count = 0; 
    for (int i = 0; i < n; i++) {
        if (distance(points[i]) > radius) {
            count++;
        }
    }
    return count;
}

int main() {
    string filename;  
    cout << "Enter filename: ";
    cin >> filename; 
    int n; 
    Point* points = readFile(filename, &n);
    print_points(points, n);
    int inside_circle = count_inside(points, 5, n);
    cout << "Points inside circle: " << inside_circle << endl;
    int outside_circle = count_outside(points, 5, n);
    cout << "Points outside circle: " << outside_circle << endl;
    symmetry(points, n);

    delete[] points;
    points = NULL;
    return 0;
}