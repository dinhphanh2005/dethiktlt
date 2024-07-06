#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} Point;

Point* read_file(const char* filename, int* n) {
    FILE* file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Couldn't open file\n");
    }
    fscanf(file, "%d", n);
    Point* points = (Point*) malloc(*n * sizeof(Point));
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%f %f", &points[i].x, &points[i].y);
    }
    fclose(file);
    return points;
}

void print(Point* point, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f %.2f\n", point[i].x, point[i].y);
    }
}

float distance(Point p) {
    return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

void inside(Point* points, int n, float radius) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (distance(points[i]) < radius) {
            count++;
        }
    }
    printf("Inside: %d\n", count);
}

void outside(Point* points, int n, float radius) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (distance(points[i]) > radius) {
            count++;
        }
    }
    printf("Outside: %d\n", count);
}

void symmetry(Point* points, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((fabs(points[i].x) == fabs(points[j].x)) && (fabs(points[i].y) == fabs(points[j].y))) {
                printf("%f %f %f %f\n", points[i].x, points[i].y, points[j].x, points[j].y);
            }
        }
    }
    if ((fabs(points[n - 1].x) == fabs(points[0].x)) && (fabs(points[n - 1].y) == fabs(points[0].y))) {
        printf("%f %f %f %f\n", points[n - 1].x, points[0].y, points[n - 1].x, points[0].y);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    int n;
    Point* points = read_file(filename, &n);
    print(points, n);
    float radius = 5;
    inside(points, n, radius);
    outside(points, n, radius);
    symmetry(points, n);

    free(points);
    return 0;
}