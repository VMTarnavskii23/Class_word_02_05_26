#include <iostream>
#include "library.h" 

int main() {
    Library myLib;
    myLib.name = "City Library";
    myLib.count = 3;
    myLib.books = new Book[3];

    myLib.books[0] = createBook("The Matrix", "Wachowski", 1999, 15.0);
    myLib.books[1] = createBook("Hamlet", "Shakespeare", 1603, 10.5);
    myLib.books[2] = createBook("Coding 101", "John Doe", 2023, 50.0);

    printLibrary(myLib);

    std::cout << "Avg Price: " << averageBookPrice(myLib) << "\n";

    Book old = oldestBookInLibrary(myLib);
    std::cout << "Oldest: " << old.title << "\n";

    delete[] myLib.books;
    std::cin.get(); // Keep window open
    return 0;
}