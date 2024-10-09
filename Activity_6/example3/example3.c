#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[100];
    char author[100];
    int year;
    char isbn[20];
} Book;

Book *createBookList(int *size)
{
    *size = 0;
    Book *books = (Book *)malloc(100 * sizeof(Book));
    return books;
}

void addBook(Book *books, int *size)
{
    if (*size >= 100)
    {
        printf("The book list is full. Can't add more books.\n");
        return;
    }

    char title[100];
    char author[100];
    int year;
    char isbn[20];

    printf("Enter book title: ");
    getchar();
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Enter author: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    printf("Enter publication year: ");
    scanf("%d", &year);

    printf("Enter ISBN: ");
    getchar();
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';

    strcpy(books[*size].title, title);
    strcpy(books[*size].author, author);
    books[*size].year = year;
    strcpy(books[*size].isbn, isbn);
    (*size)++;
}

void readBooks(Book *books, int size)
{
    if (size == 0)
    {
        printf("No books available.\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("Book %d: Title = %s, Author = %s, Year = %d, ISBN = %s\n",
               i + 1, books[i].title, books[i].author, books[i].year, books[i].isbn);
    }
}

int findBookByISBN(Book *books, int size, char *isbn)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            return i;
        }
    }
    return -1;
}

void updateBook(Book *books, int size)
{
    char isbn[20];
    printf("Enter the ISBN of the book to update: ");
    getchar();
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';

    int index = findBookByISBN(books, size, isbn);
    if (index != -1)
    {
        char newTitle[100];
        char newAuthor[100];
        int newYear;

        printf("Enter new title: ");
        fgets(newTitle, sizeof(newTitle), stdin);
        newTitle[strcspn(newTitle, "\n")] = '\0';

        printf("Enter new author: ");
        fgets(newAuthor, sizeof(newAuthor), stdin);
        newAuthor[strcspn(newAuthor, "\n")] = '\0';

        printf("Enter new publication year: ");
        scanf("%d", &newYear);

        strcpy(books[index].title, newTitle);
        strcpy(books[index].author, newAuthor);
        books[index].year = newYear;

        printf("Book with ISBN %s updated successfully.\n", isbn);
    }
    else
    {
        printf("Book with ISBN %s not found.\n", isbn);
    }
}

void deleteBook(Book *books, int *size)
{
    char isbn[20];
    printf("Enter the ISBN of the book to delete: ");
    getchar();
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';

    int index = findBookByISBN(books, *size, isbn);
    if (index != -1)
    {
        for (int i = index; i < *size - 1; i++)
        {
            books[i] = books[i + 1];
        }
        (*size)--;
        printf("Book with ISBN %s deleted successfully.\n", isbn);
    }
    else
    {
        printf("Book with ISBN %s not found.\n", isbn);
    }
}

int main()
{
    int size;
    Book *books = createBookList(&size);
    int choice;

    do
    {
        printf("\nBook Management Menu:\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Update a book by ISBN\n");
        printf("4. Delete a book by ISBN\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook(books, &size);
            break;
        case 2:
            readBooks(books, size);
            break;
        case 3:
            updateBook(books, size);
            break;
        case 4:
            deleteBook(books, &size);
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    free(books);
    return 0;
}

