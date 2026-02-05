#include "library.h"
#include <iostream>

// Turn off precompiled headers requirement just in case
// (Visual Studio sometimes complains if this isn't the first include)

Book createBook(const std::string& title, const std::string& author, int year, double price) {
    Book newBook;
    newBook.title = title;
    newBook.author = author;
    newBook.year = year;
    newBook.price = price;
    return newBook;
}

void printBook(const Book& book) {
    std::cout << "Title:  " << book.title << "\n"
        << "Author: " << book.author << "\n"
        << "Year:   " << book.year << "\n"
        << "Price:  $" << book.price << "\n"
        << "-------------------------\n";
}

void printLibrary(const Library& library) {
    std::cout << "Library: " << library.name << "\n";
    std::cout << "Total Books: " << library.count << "\n\n";

    for (int i = 0; i < library.count; ++i) {
        printBook(library.books[i]);
    }
}

double averageBookPrice(const Library& library) {
    if (library.count == 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < library.count; ++i) {
        sum += library.books[i].price;
    }
    return sum / library.count;
}

Book oldestBookInLibrary(const Library& library) {
    if (library.count == 0) return createBook("N/A", "N/A", 0, 0);
    int oldestIndex = 0;
    for (int i = 1; i < library.count; ++i) {
        if (library.books[i].year < library.books[oldestIndex].year) {
            oldestIndex = i;
        }
    }
    return library.books[oldestIndex];
}