#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a Book
typedef struct
{
    char title[100];  // Declare a character array of size 100 to store the book's title
    char author[100]; // Declare a character array of size 100 to store the book's author
    int year;         // Declare an integer to store the book's publication year
    char isbn[20];    // Declare a character array of size 20 to store the book's ISBN
} Book;

// Function to create an array of books (returns the array)
Book *createBookList(int *size)
{
    *size = 0; // Initialize the size to 0
    // Dynamically allocate memory for up to 100 books
    Book *books = (Book *)malloc(100 * sizeof(Book));
    return books; // Return the pointer to the newly created array
}

// Function to add a book to the array (Create)
void addBook(Book *books, int *size, const char *title, const char *author, int year, const char *isbn)
{
    strcpy(books[*size].title, title);   // Copy the provided title into the title field of the book at the current size index
    strcpy(books[*size].author, author); // Copy the provided author into the author field of the book at the current size index
    books[*size].year = year;            // Assign the provided year to the year field of the book at the current size index
    strcpy(books[*size].isbn, isbn);     // Copy the provided ISBN into the ISBN field of the book at the current size index
    (*size)++;                           // Increment the size to indicate a new book has been added
}

// Function to read all books (Read)
void readBooks(Book *books, int size)
{
    for (int i = 0; i < size; i++)
    { // Iterate through all books
        printf("Book %d: Title = %s, Author = %s, Year = %d, ISBN = %s\n",
               i + 1, books[i].title, books[i].author, books[i].year, books[i].isbn); // Print the details of each book
    }
}

// Function to find a book by ISBN
int findBookByISBN(Book *books, int size, const char *isbn)
{
    for (int i = 0; i < size; i++)
    { // Iterate through all books
        if (strcmp(books[i].isbn, isbn) == 0)
        {             // Compare the provided ISBN with the ISBN of the current book
            return i; // Return the index of the book if found
        }
    }
    return -1; // Return -1 if the book is not found
}

// Function to update a book's details (Update)
void updateBook(Book *books, int size, const char *isbn, const char *newTitle, const char *newAuthor, int newYear)
{
    int index = findBookByISBN(books, size, isbn); // Find the index of the book with the specified ISBN
    if (index != -1)
    {                                           // If the book was found
        strcpy(books[index].title, newTitle);   // Update the title
        strcpy(books[index].author, newAuthor); // Update the author
        books[index].year = newYear;            // Update the year
        printf("Book with ISBN %s updated successfully.\n", isbn);
    }
    else
    {
        printf("Book with ISBN %s not found.\n", isbn);
    }
}

// Function to delete a book by ISBN (Delete)
void deleteBook(Book *books, int *size, const char *isbn)
{
    int index = findBookByISBN(books, *size, isbn); // Find the index of the book with the specified ISBN
    if (index != -1)
    { // If the book was found
        for (int i = index; i < *size - 1; i++)
        {                            // Iterate from the index to be deleted to the last element
            books[i] = books[i + 1]; // Shift elements to the left, overwriting the deleted element
        }
        (*size)--; // Reduce the size to indicate a book has been removed
        printf("Book with ISBN %s deleted successfully.\n", isbn);
    }
    else
    {
        printf("Book with ISBN %s not found.\n", isbn);
    }
}

int main()
{
    int size; // Variable to hold the current number of books

    // Create a dynamic array of books using the function
    Book *books = createBookList(&size);

    // Add books (Create)
    addBook(books, &size, "The Hobbit", "J.R.R. Tolkien", 1937, "9780345339683");
    addBook(books, &size, "The Catcher in the Rye", "J.D. Salinger", 1951, "9780316769488");
    addBook(books, &size, "Pride and Prejudice", "Jane Austen", 1813, "9781503290563");

    // Read all books (Read)
    printf("Books in the list:\n");
    readBooks(books, size);

    // Update a book's details (Update)
    updateBook(books, size, "9780316769488", "The Catcher in the Rye (Updated)", "J.D. Salinger", 1952);
    printf("\nAfter updating The Catcher in the Rye:\n");
    readBooks(books, size);

    // Delete a book by ISBN (Delete)
    deleteBook(books, &size, "9780345339683");
    printf("\nAfter deleting The Hobbit:\n");
    readBooks(books, size);

    // Free dynamically allocated memory
    free(books);

    return 0;
}