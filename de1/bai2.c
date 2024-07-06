#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[100];
    char author[100];
    int year;
} Library;

Library* readfile(const char* filename, int* n) {
    FILE* file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File could not open\n");
    }
    fscanf(file, "%d", n);
    Library* library = (Library*) malloc(*n * sizeof(Library));
    for (int i = 0; i < *n; i++) {
        fscanf(file, " %[^\n]", library[i].name);
        fscanf(file, " %[^\n]", library[i].author);
        fscanf(file, "%d", &library[i].year);
    }
    fclose(file);
    return library;
}

void print(Library* library, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %s %d\n", library[i].name, library[i].author, library[i].year);
    }
}

void find_book_by_name(Library* library, int n, const char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(library[i].name, name) == 0) {
            printf("Book found:\n");
            printf("Title: %s, Author: %s, Year: %d\n", library[i].name, library[i].author, library[i].year);
            return;
        }
    }
    printf("Book with title '%s' not found.\n", name);
}

int main() {
    const char* filename = "input2.txt";
    int n;
    Library* library = readfile(filename, &n);
    print(library, n);
    char name[100];
    scanf("%s", name);
    find_book_by_name(library, n, name);

    free(library);
    return 0;
}