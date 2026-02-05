#include "library.h"
Book createBook(const string& title, const string& author, int year, double price) {
    Book b;
    b.title = title;
    b.author = author;
    b.year = year;
    b.price = price;
    return b;
}

void printBook(const Book& book) {
    cout << "Zaglavie: " << book.title << endl;
    cout << "Avtor:    " << book.author << endl;
    cout << "Godina:   " << book.year << endl;
    cout << "Cena:     " << book.price << " lv." << endl;
    cout << "--------------------" << endl;
}

void printLibrary(const Library& library) {
    cout << endl << "Biblioteka: " << library.name << endl;
    cout << "Broi knigi: " << library.count << endl << endl;
    for (int i = 0; i < library.count; i++) {
        printBook(library.books[i]);
    }
}

double averageBookPrice(const Library& library) {
    double sum = 0;
    for (int i = 0; i < library.count; i++) {
        sum = sum + library.books[i].price;
    }
    return sum / library.count;
}

Book oldestBookInLibrary(const Library& library) {
    Book old = library.books[0];
    for (int i = 1; i < library.count; i++) {
        if (library.books[i].year < old.year) {
            old = library.books[i];
        }
    }
    return old;
}