#include<iostream>
using namespace std;

// Structure to store book information
struct Book {
    int bookId;
    float price;
    int pages;

    // Function to assign user-defined values to the book
    void assignValues(int id, float p, int pg) {
        bookId = id;
        price = p;
        pages = pg;
    }

    // Function to display the record of the most costly book
    void displayMostCostly(const Book& other) {
        if (other.price > price) {
            cout << "Most Costly Book Record:\n";
            cout << "Book ID: " << other.bookId << endl;
            cout << "Price: $" << other.price << endl;
            cout << "Pages: " << other.pages << endl;
        } else {
            cout << "Most Costly Book Record:\n";
            cout << "Book ID: " << bookId << endl;
            cout << "Price: $" << price << endl;
            cout << "Pages: " << pages << endl;
        }
    }
};

int main() {
    Book book1, book2;
    book1.assignValues(1, 25.99, 300);
    book2.assignValues(2, 19.95, 250);

    // Display the record of the most costly book
    book1.displayMostCostly(book2);

    return 0;
}
