#include <iostream>
#include <string>
#include "library.h"
using namespace std;

int main() {
    Library lib;

    cout << "Vavedete ime na bibliotekata: ";
    getline(cin, lib.name);

    cout << "Kolko knigi shte vavedete: ";
    cin >> lib.count;

    lib.books = new Book[lib.count];

    for (int i = 0; i < lib.count; i++) {
        string t, a;
        int y;
        double p;

        cout << endl << "Kniga " << i + 1 << endl;

        cout << "Zaglavie: ";
        cin.ignore();
        getline(cin, t);

        cout << "Avtor: ";
        getline(cin, a);

        cout << "Godina: ";
        cin >> y;

        cout << "Cena: ";
        cin >> p;

        lib.books[i] = createBook(t, a, y, p);
    }

    printLibrary(lib);

    if (lib.count > 0) {
        cout << "Sredna cena: " << averageBookPrice(lib) << " lv." << endl;
        Book old = oldestBookInLibrary(lib);
        cout << "Nai-stara kniga: " << old.title << " (" << old.year << ")" << endl;
    }

    delete[] lib.books;

    

    
}