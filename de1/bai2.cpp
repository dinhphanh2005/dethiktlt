#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Library {
    string name;
    string author;
    int year;
};

Library* read_library(const string &filename, int *n) {
    ifstream file(filename);  
    if (file.is_open()) {
        cout << "File has been opened successfully!\n";
    }
    file >> *n;
    file.ignore();
    Library* library = new Library[*n];
    for (int i = 0; i < *n; i++) {
        getline(file, library[i].name);  
        getline(file, library[i].author);
        file >> library[i].year;
        file.ignore();
    }
    file.close();
    return library;
}

void print_library(Library* library, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Sach " << i + 1 << ": " << library[i].name << " " << library[i].author << " " << library[i].year << endl;;
    }
}

void findBook(Library* library, int n) {
    string book;
    cout << "Input book you want to find: ";
    getline(cin, book);
    book.erase(book.begin(), find_if(book.begin(), book.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    book.erase(find_if(book.rbegin(), book.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), book.end());
    transform(book.begin(), book.end(), book.begin(), ::tolower);
    bool found = false;
    for (int i = 0; i < n; i++) {
        string name = library[i].name;
        name.erase(name.begin(), find_if(name.begin(), name.end(), [](unsigned char ch) {
            return !isspace(ch);
        }));
        name.erase(find_if(name.rbegin(), name.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), name.end());
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (book == name) {
            cout << library[i].name << " " << library[i].author << " " << library[i].year << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "There is no book has name like that in library\n";
    }
}

void bubble_sort(Library* books, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (books[j].year > books[j + 1].year) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

void year_small(Library *library, int n, const string &output_filename) {
    Library* book_before_2000 = new Library[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (library[i].year < 2000) {
            book_before_2000[count++] = library[i];
        }
    }
    bubble_sort(book_before_2000, count);
    ofstream output(output_filename);
    for (int i = 0; i < count; i++) {
        output << book_before_2000[i].name << " " << book_before_2000[i].author << " " << book_before_2000[i].year << endl;
    }
    output.close();
    delete[] book_before_2000;
}

int main() {
    string filename = "bai2.txt";
    string output_filename = "outputbai2.txt";
    int n;
    Library* library = read_library(filename, &n);
    print_library(library, n);
    findBook(library, n);
    year_small(library, n, output_filename);

    delete[] library;
    return 0;
}