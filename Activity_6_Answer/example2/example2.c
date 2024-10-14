#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
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
void createBook(Book *books, int *size)
{
    char title[MAX];
    char author[MAX];
    char isbn[MAX];
    int year;

    printf("\n");
    printf("Enter Book Title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Enter Book Author: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';
    
    printf("Enter Book ISBN: ");
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';

    printf("Enter Book year of Publication: ");
    scanf("%d", &year);
    

    printf("\n");
    strcpy(books[*size].title, title);   // Copy the provided title into the title field of the book at the current size index
    strcpy(books[*size].author, author); // Copy the provided author into the author field of the book at the current size index
    books[*size].year = year;            // Assign the provided year to the year field of the book at the current size index
    strcpy(books[*size].isbn, isbn);     // Copy the provided ISBN into the ISBN field of the book at the current size index
    (*size)++;                           // Increment the size to indicate a new book has been added
}

// Function to read all books (Display the array)
void readBooks(Book *books, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    { // Iterate through all books
        printf("Book %d: Title = %s, Author = %s, Year = %d, ISBN = %s\n",
               i + 1, books[i].title, books[i].author, books[i].year, books[i].isbn); // Print the details of each book
    }
    printf("\n");
}

// Function to find a book by ISBN (Search)
int findBookByISBN(Book *books, int size){
    char isbn[MAX];

    printf("Enter Book's ISBN to find: ");
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '0';

    for (int i = 0; i < size; i++)
    { // Iterate through all books
        if (strcmp(books[i].isbn, isbn) == 0)
        {             // Compare the provided ISBN with the ISBN of the current book
            return i;
        }else{
            printf("Book not Found\n\n");
            return; // Return -1 if the book is not found
        }
    }
}

// Function to update a book's details by ISBN
void updateBookByISBN(Book *books, int size)
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
void deleteBookByISBN(Book *books, int *size)
{
    int index = findBookByISBN(books, *size); // Find the index of the book with the specified ISBN
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
    int choice;

    do{
        printf("Library Management System: \n");
        printf("1. Add new Book\n");
        printf("2. Update Book\n");
        printf("3. Delete Book\n");
        printf("4. Display books\n");
        printf("5. Find Book by ISBN\n");
        printf("6. Exit Program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            createBook(books, &size);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            readBooks(books, size);
            break;
        case 5:
            findBookByISBN(books, size);
            break;
        case 6:
            printf("Exitting Program....");
            return 0;
        default:
            break;
        }
    }while(choice != 6);

    return 0;
}