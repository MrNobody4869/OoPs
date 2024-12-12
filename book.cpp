#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;

public:
    // Default constructor
    Publication() : title("Unknown"), price(0.0f) {}

    // Function to get data for Publication
    virtual void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;

        if (price < 0) {
            throw invalid_argument("Price cannot be negative.");
        }
    }

    // Function to display data of Publication
    virtual void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class Book
class Book : public Publication {
private:
    int pageCount;

public:
    // Default constructor
    Book() : pageCount(0) {}

    // Function to get data for Book
    void getData() override {
        Publication::getData();

        cout << "Enter page count: ";
        cin >> pageCount;

        if (pageCount < 0) {
            throw invalid_argument("Page count cannot be negative.");
        }
    }

    // Function to display data of Book
    void displayData() const override {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class Tape
class Tape : public Publication {
private:
    float playingTime;

public:
    // Default constructor
    Tape() : playingTime(0.0f) {}

    // Function to get data for Tape
    void getData() override {
        Publication::getData();

        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;

        if (playingTime < 0) {
            throw invalid_argument("Playing time cannot be negative.");
        }
    }

    // Function to display data of Tape
    void displayData() const override {
        Publication::displayData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for Book:\n";
    try {
        book.getData();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cout << "Resetting book data to zero values...\n";
        book = Book(); // Reset to default values
    }

    cout << "\nEnter details for Tape:\n";
    try {
        tape.getData();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cout << "Resetting tape data to zero values...\n";
        tape = Tape(); // Reset to default values
    }

    cout << "\nDetails of Book:\n";
    book.displayData();

    cout << "\nDetails of Tape:\n";
    tape.displayData();

    return 0;
}
