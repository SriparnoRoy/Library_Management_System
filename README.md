Library Management System in C++

## Overview

This project is a simple **Library Management System** built using C++. It allows users to manage a collection of books, including:

- Adding new books
- Displaying all books in the collection
- Searching for books by their ID

Book data (ID, name, author) is stored in a text file (`bookData.txt`) for persistence, ensuring that the information is saved between program runs. The system uses file handling to manage the book records efficiently and provides a menu-driven interface for user interaction.

## Features

- **Add a Book**: Allows users to enter the book's ID, name, and author's name, then stores the information in a text file.
- **Display All Books**: Reads all the book details from the text file and displays them in a formatted table.
- **Search for a Book by ID**: Lets users search for a book by its ID and shows the details if found.
- **Menu Interface**: Provides an easy-to-use interface where users can choose different actions.

## How It Works

1. **Adding a Book**: The user enters the book's ID, name, and author. This data is appended to `bookData.txt`.
2. **Displaying All Books**: The system reads all the book records from the file and displays them in a formatted way.
3. **Extracting a Book by ID**: The user inputs a book ID, and the system searches the file for a matching record. If found, the book's details are displayed.


## Sample Output

```
1-Show all books
2-Extract books
3-Add Books
4-Exit
Enter your choice: 3

Enter book ID: 101
Enter book name: C++ Programming
Enter book's author name: Bjarne Stroustrup
Book added successfully!
```

## Requirements

- C++ Compiler (e.g., GCC)
- Text editor for code editing (e.g., Visual Studio Code)

## Future Enhancements

- Add functionality to delete or update book records.
- Improve the search functionality by allowing search by book name or author.
- Add error handling for invalid input.

## License

This project is open-source and free to use.

---

Feel free to contribute by submitting issues or suggestions to improve the system!
