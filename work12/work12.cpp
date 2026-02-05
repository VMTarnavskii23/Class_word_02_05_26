#include <iostream>
#include "library.h"
using namespace std;
int main() {
    Library lib;    lib.name = "Gradska Biblioteka";
    lib.count = 3;
    lib.books = new Book[3];

    lib.books[0] = createBook("Pod Igoto", "Ivan Vazov", 1894, 25.50);
    lib.books[1] = createBook("Tutun", "Dimitar Dimov", 1951, 15.00);
    lib.books[2] = createBook("Bai Ganyo", "Aleko Konstantinov", 1895, 12.99);

    printLibrary(lib);
    double avg = averageBookPrice(lib);
    cout << "Sredna cena na knigite: " << avg << endl;

    Book oldest = oldestBookInLibrary(lib);
    cout << "Nai-starata kniga e: " << oldest.title << endl;

    delete[] lib.books;

    int wait;
    cin >> wait;
    
}