#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum to represent the status of a book
typedef enum {
    AVAILABLE,  // The book is available for borrowing
    BORROWED,   // The book is currently borrowed by someone
    OVERDUE     // The book has been borrowed for longer than the allowed period
} BookStatus;

// Enum to represent transaction types
typedef enum {
    BORROW,     // A book is being borrowed
    RETURN      // A book is being returned
} TransactionType;

// Structure to represent a book
typedef struct Book {
    int bookId;                  // Unique identifier for the book
    char title[100];             // Title of the book
    BookStatus status;           // Current status of the book (Available, Borrowed, Overdue)
    char borrowerName[50];       // Name of the borrower (empty if the book is available)
    int daysBorrowed;            // Number of days the book has been borrowed
    struct Book* next;           // Pointer to the next book in the linked list
} Book;

// Structure to represent a transaction
typedef struct Transaction {
    int transactionId;           // Unique identifier for the transaction
    int bookId;                  // ID of the book involved in the transaction
    char borrowerName[50];       // Name of the borrower involved in the transaction
    TransactionType type;        // Type of transaction (Borrow or Return)
    struct Transaction* next;    // Pointer to the next transaction in the linked list
} Transaction;

// Function prototypes
void addBook(Book** head, int id, char* title);
void borrowBook(Book* head, Transaction** tHead, int transactionId, int id, char* borrowerName, int days);
void returnBook(Book* head, Transaction** tHead, int transactionId, int id);
void markOverdue(Book* head);
void logTransaction(Transaction** head, int transactionId, int bookId, char* borrowerName, TransactionType type);
void displayOverdueBooks(Book* head);
void displayBorrowedBooks(Book* head);
void displayTransactions(Transaction* head);
void saveBooksToFile(Book* head, const char* filename);
void saveTransactionsToFile(Transaction* head, const char* filename);
void freeBooks(Book* head);
void freeTransactions(Transaction* head);

int main() {
    // Initialize the book and transaction lists as empty
    Book* bookList = NULL;
    Transaction* transactionList = NULL;

    // Add sample books to the library
    addBook(&bookList, 1, "The Great Gatsby");
    addBook(&bookList, 2, "1984");
    addBook(&bookList, 3, "To Kill a Mockingbird");
    addBook(&bookList, 4, "Game of Thrones");
    addBook(&bookList, 5, "A Song of Ice and Fire");

    // Borrow books and log transactions
    borrowBook(bookList, &transactionList, 1, 1, "Alice", 15); 
    borrowBook(bookList, &transactionList, 2, 2, "Bob", 35); 
    borrowBook(bookList, &transactionList, 3, 3, "Charlie", 40);

    // Mark books as overdue if borrowed for more than 30 days
    markOverdue(bookList);

    // Return a borrowed book and log the transaction
    returnBook(bookList, &transactionList, 4, 1); 

    // Borrow another book
    borrowBook(bookList, &transactionList, 5, 4, "David", 20);

    // Display the lists of overdue books, borrowed books, and all transactions
    displayOverdueBooks(bookList);
    displayBorrowedBooks(bookList);
    displayTransactions(transactionList);

    // Save book and transaction data to files
    saveBooksToFile(bookList, "books.txt");
    saveTransactionsToFile(transactionList, "transactions.txt");

    // Free all dynamically allocated memory
    freeBooks(bookList);
    freeTransactions(transactionList);

    return 0;
}

// Function to add a new book to the library
void addBook(Book** head, int id, char* title) {
    Book* newBook = (Book*)malloc(sizeof(Book));  // Allocate memory for a new book
    newBook->bookId = id;
    strcpy(newBook->title, title);
    newBook->status = AVAILABLE;                 // Set the status to available
    strcpy(newBook->borrowerName, "");           // Clear borrower name
    newBook->daysBorrowed = 0;                   // Reset days borrowed to 0
    newBook->next = *head;                       // Insert the book at the start of the list
    *head = newBook;
}

// Function to borrow a book and log the transaction
void borrowBook(Book* head, Transaction** tHead, int transactionId, int id, char* borrowerName, int days) {
    while (head) {
        if (head->bookId == id && head->status == AVAILABLE) {
            head->status = BORROWED;             // Update the book's status to borrowed
            strcpy(head->borrowerName, borrowerName);
            head->daysBorrowed = days;
            logTransaction(tHead, transactionId, id, borrowerName, BORROW);  // Log the borrow transaction
            break;
        }
        head = head->next;
    }
}

// Function to return a borrowed book and log the transaction
void returnBook(Book* head, Transaction** tHead, int transactionId, int id) {
    while (head) {
        if (head->bookId == id && head->status == BORROWED) {
            head->status = AVAILABLE;           // Update the book's status to available
            logTransaction(tHead, transactionId, id, head->borrowerName, RETURN); // Log the return transaction
            strcpy(head->borrowerName, "");     // Clear borrower name
            head->daysBorrowed = 0;             // Reset days borrowed to 0
            break;
        }
        head = head->next;
    }
}

// Function to mark books as overdue
void markOverdue(Book* head) {
    while (head) {
        if (head->status == BORROWED && head->daysBorrowed > 30) {
            head->status = OVERDUE;             // Update the book's status to overdue
        }
        head = head->next;
    }
}

// Function to log a transaction in the transaction list
void logTransaction(Transaction** head, int transactionId, int bookId, char* borrowerName, TransactionType type) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction)); // Allocate memory for a new transaction
    newTransaction->transactionId = transactionId;
    newTransaction->bookId = bookId;
    strcpy(newTransaction->borrowerName, borrowerName);
    newTransaction->type = type;
    newTransaction->next = *head;              // Insert the transaction at the start of the list
    *head = newTransaction;
}

// Display Functions for Book Statuses//
void displayOverdueBooks(Book* head) {
    printf("\nOverdue Books:\n");
    while (head) {
        if (head->status == OVERDUE) {
            printf("Book ID: %d\n, Title: %s, Borrower: %s\n, Days Borrowed: %d\n",
                   head->bookId, head->title, head->borrowerName, head->daysBorrowed);
        }
        head = head->next;
    }
}

void displayBorrowedBooks(Book* head) {
    printf("\nBorrowed Books:\n");
    while (head) {
        if (head->status == BORROWED) {
            printf("Book ID: %d\n Title: %s, Borrower: %s\n, Days Borrowed: %d\n",
                   head->bookId, head->title, head->borrowerName, head->daysBorrowed);
        }
        head = head->next;
    }
}

void displayTransactions(Transaction* head) {
    printf("\nTransactions:\n");
    while (head) {
        printf("Transaction ID: %d\n Book ID: %d Borrower: %s\n Action: %s\n",
               head->transactionId, head->bookId, head->borrowerName,
               head->type == BORROW ? "BORROW" : "RETURN");
        head = head->next;
    }
}
// Save Books to File Function //
void saveBooksToFile(Book* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    while (head) {
        fprintf(file, "Book ID: %d\n Title: %s Status = %d\n Borrower's Name %s\n Borrow Date: %d\n",
                head->bookId, head->title, head->status, head->borrowerName, head->daysBorrowed);
        head = head->next;
    }
    fclose(file);
}
// Save Books to File Function //

// Save Transactions Record to File//
void saveTransactionsToFile(Transaction* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    while (head) {
        fprintf(file, "Transaction ID: %d\n Book ID: %d Borrower's Name: %s\n Action: %d\n",
                head->transactionId, head->bookId, head->borrowerName, head->type);
        head = head->next;
    }
    fclose(file);
}
// Save Transactions Record to File//

// Free Functions //
void freeBooks(Book* head) {
    while (head) {
        Book* temp = head;
        head = head->next;
        free(temp);
    }
}

void freeTransactions(Transaction* head) {
    while (head) {
        Transaction* temp = head;
        head = head->next;
        free(temp);
    }
}
// Free Functions //