#include <stdio.h>
#include <stdlib.h>

int** readFile(const char* filename, int* n, int* m) {
    FILE* file; 
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File could not open\n");
    }
    fscanf(file, "%d %d", n, m);
    int** array = (int**) malloc(*n * sizeof(int*));
    for (int i = 0; i < *n; i++) {
        array[i] = (int*) malloc(*m * sizeof(int));
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(file, "%d", &array[i][j]);
        }
    }
    fclose(file);
    return array;
}

void print(int** array, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void write(const char* filename, int** array, int n, int m) {
    FILE* file; 
    file = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", array[i][j]);
        }
        fprintf(file, "\n");
    }
}

int main() {
    int n, m;
    char filename[100];
    scanf("%s", filename);
    int** array = readFile(filename, &n, &m);
    print(array, n, m);
    const char file[100] = "output1.txt";
    write(file, array, n, m);

    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}