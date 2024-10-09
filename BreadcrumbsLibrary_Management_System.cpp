#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Library
{
    string id, name, author, search;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
} obj;

void displayMenu()
{
    cout << "1-Show all books" << endl;
    cout << "2-Extract books" << endl;
    cout << "3-Add Books" << endl;
    cout << "4-Exit" << endl;
}

int main()
{
    char choice;
    bool isRunning = true;

    while (isRunning)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
            obj.showAll();
            break;
        case '2':
            obj.extractBook();
            break;
        case '3':
            obj.addBook();
            break;
        case '4':
            isRunning = false;
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!!" << endl;
        }
    }
    return 0;
}
void Library::addBook()
{
    cout << "\nEnter book ID: ";
    getline(cin, id);
    cout << "Enter book name: ";
    getline(cin, name);
    cout << "Enter book's autor name: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    file << id << "*" << name << "*" << author << endl;
    file.close();
    cout << "Book added successfully!" << endl;
}

void Library::showAll()
{
    file.open("bookData.txt", ios::in);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "\n\t\t Book ID \t\t Book Name \t\t Author's Name" << endl;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n'))
    {
        cout << "\t\t" << id << "\t\t" << name << "\t\t" << author << endl;
    }
    file.close();
}

void Library::extractBook()
{
    cout << "Enter book id to searcg: ";
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n'))
    {
        if (search == id)
        {
            cout << "\n Book found!!" << endl;
            cout << "Book ID: " << id << "\n Book name: " << name << "\n Author" << author << endl;

            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book With ID" << search << "not found!!" << endl;
    }
    file.close();
}
