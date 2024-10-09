#include <iostream>   // Includes the input/output stream library.
#include <fstream>    // Includes the file stream library for file handling.
#include <string>     // Includes the string library.
using namespace std;  // Standard namespace declaration for using common functions without 'std::'.

class Library        // Define a class named 'Library'.
{
    string id, name, author, search;  // Declare private string variables to store book details and search query.
    fstream file;                     // Declare a file stream object for file operations.

public:              // Access specifier to make these functions accessible from outside the class.
    void addBook();  // Function to add a book to the file.
    void showAll();  // Function to display all books.
    void extractBook();  // Function to search and extract a book's details by its ID.
} obj;               // Create an instance 'obj' of the class 'Library'.

void displayMenu()    // Function to display the menu options.
{
    cout << "1-Show all books" << endl;   // Display option 1 for showing all books.
    cout << "2-Extract books" << endl;    // Display option 2 for extracting book details.
    cout << "3-Add Books" << endl;        // Display option 3 for adding a new book.
    cout << "4-Exit" << endl;             // Display option 4 for exiting the program.
}

int main()             // Main function that runs the program.
{
    char choice;        // Variable to store the user's choice.
    bool isRunning = true;  // Boolean flag to keep the program running in a loop.

    while (isRunning)  // Loop until 'isRunning' becomes false.
    {
        displayMenu();      // Call the function to display the menu.
        cout << "Enter your choice: ";  // Ask the user to enter their choice.
        cin >> choice;      // Store the user input in 'choice'.
        cin.ignore();       // Clear the input buffer.

        switch (choice)     // Switch statement to handle different cases based on user input.
        {
        case '1':           // If choice is '1', show all books.
            obj.showAll();
            break;
        case '2':           // If choice is '2', extract a book's details.
            obj.extractBook();
            break;
        case '3':           // If choice is '3', add a new book.
            obj.addBook();
            break;
        case '4':           // If choice is '4', exit the loop.
            isRunning = false;
            cout << "Exiting..." << endl;
            break;
        default:            // If input is invalid, display an error message.
            cout << "Invalid choice!!" << endl;
        }
    }
    return 0;  // End the program.
}

void Library::addBook()  // Define the 'addBook' function to add a book to the file.
{
    cout << "\nEnter book ID: ";   // Prompt the user to enter the book's ID.
    getline(cin, id);              // Store the ID in the 'id' variable.
    cout << "Enter book name: ";   // Prompt the user to enter the book's name.
    getline(cin, name);            // Store the name in the 'name' variable.
    cout << "Enter book's author name: ";  // Prompt the user to enter the author's name.
    getline(cin, author);          // Store the author name in the 'author' variable.

    file.open("bookData.txt", ios::out | ios::app);  // Open 'bookData.txt' in append mode.
    if (!file)    // If the file fails to open, display an error message.
    {
        cout << "Error opening file!" << endl;
        return;
    }
    file << id << "*" << name << "*" << author << endl;  // Write the book's details into the file.
    file.close();    // Close the file.
    cout << "Book added successfully!" << endl;  // Display success message.
}

void Library::showAll()  // Define the 'showAll' function to display all books.
{
    file.open("bookData.txt", ios::in);  // Open 'bookData.txt' in read mode.
    if (!file)    // If the file fails to open, display an error message.
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "\n\t\t Book ID \t\t Book Name \t\t Author's Name" << endl;  // Display table headers.
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n'))  // Read each book's details from the file.
    {
        cout << "\t\t" << id << "\t\t" << name << "\t\t" << author << endl;  // Display the details of the book.
    }
    file.close();  // Close the file.
}

void Library::extractBook()  // Define the 'extractBook' function to search for a book by its ID.
{
    cout << "Enter book id to search: ";  // Prompt the user to enter the book's ID to search for.
    getline(cin, search);  // Store the search ID in the 'search' variable.

    file.open("bookData.txt", ios::in);  // Open 'bookData.txt' in read mode.
    if (!file)    // If the file fails to open, display an error message.
    {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;  // Boolean flag to track if the book is found.
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n'))  // Read each book's details from the file.
    {
        if (search == id)  // If the book's ID matches the search ID.
        {
            cout << "\n Book found!!" << endl;  // Display success message.
            cout << "Book ID: " << id << "\n Book name: " << name << "\n Author: " << author << endl;  // Display the book's details.

            found = true;  // Set the flag to true as the book is found.
            break;  // Exit the loop since the book is found.
        }
    }
    if (!found)  // If the book is not found, display an error message.
    {
        cout << "Book with ID " << search << " not found!!" << endl;
    }
    file.close();  // Close the file.
}
