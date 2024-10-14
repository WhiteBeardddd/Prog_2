#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100 // Define a constant for the maximum number of books

// Define a struct for a Book
typedef struct
{
    char title[100];  // Declare a character array of size 100 to store the book's title
    char author[100]; // Declare a character array of size 100 to store the book's author
    int year;         // Declare an integer to store the book's publication year
    char isbn[20];    // Declare a character array of size 20 to store the book's ISBN
} Book;

// Function to create a book (Add to the array)
void createBook(Book books[], int *size, const char *title, const char *author, int year, const char *isbn)
{
    strcpy(books[*size].title, title);   // Copy the provided title into the title field of the book at the current size index
    strcpy(books[*size].author, author); // Copy the provided author into the author field of the book at the current size index
    books[*size].year = year;            // Assign the provided year to the year field of the book at the current size index
    strcpy(books[*size].isbn, isbn);     // Copy the provided ISBN into the ISBN field of the book at the current size index
    (*size)++;                           // Increment the size to indicate a new book has been added
}

// Function to read all books (Display the array)
void readBooks(Book books[], int size)
{
    for (int i = 0; i < size; i++)
    { // Iterate through all books
        printf("Book %d: Title = %s, Author = %s, Year = %d, ISBN = %s\n",
               i + 1, books[i].title, books[i].author, books[i].year, books[i].isbn); // Print the details of each book
    }
}

// Function to find a book by ISBN (Search)
int findBookByISBN(Book books[], int size, const char *isbn)
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

// Function to update a book's details by ISBN
void updateBookByISBN(Book books[], int size, const char *isbn, const char *newTitle, const char *newAuthor, int newYear)
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

// Function to delete a book by ISBN
void deleteBookByISBN(Book books[], int *size, const char *isbn)
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
    Book books[MAX_BOOKS]; // Create an array to store up to 100 books
    int size = 0;          // Initialize the current number of books to 0

    // Create books (Add)
    createBook(books, &size, "The Great Gatsby", "F. Scott Fitzgerald", 1925, "9780743273565");
    createBook(books, &size, "To Kill a Mockingbird", "Harper Lee", 1960, "9780060935467");
    createBook(books, &size, "1984", "George Orwell", 1949, "9780451524935");

    // Read all books (Display)
    printf("After Adding Books:\n");
    readBooks(books, size);

    // Update a book by ISBN (Update)
    updateBookByISBN(books, size, "9780060935467", "To Kill a Mockingbird (Updated)", "Harper Lee", 1961);
    printf("\nAfter Updating To Kill a Mockingbird:\n");
    readBooks(books, size);

    // Delete a book by ISBN (Delete)
    deleteBookByISBN(books, &size, "9780451524935");
    printf("\nAfter Deleting 1984:\n");
    readBooks(books, size);

    // Attempt to delete a book that doesn't exist
    deleteBookByISBN(books, &size, "9789999999999");

    return 0;
}