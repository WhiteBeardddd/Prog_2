#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FICTION,
    NON_FICTION,
    MYSTERY,
    BIOGRAPHY,
    SCIENCE_FICTION
} Genre;

typedef struct Book {
    int id;
    char title[50];
    Genre genre;
    struct Book* next;
} Book;

Book* createBook(int id, const char* title, Genre genre) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newBook->id = id;
    strncpy(newBook->title, title, 50);
    newBook->genre = genre;
    newBook->next = NULL;
    return newBook;
}

void addBook(Book** head, int id, const char* title, Genre genre) {
    Book* newBook = createBook(id, title, genre);
    newBook->next = *head;
    *head = newBook;
}

void deleteBook(Book** head, int id) {
    Book* temp = *head;
    Book* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book with Book No: %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void displayBooks(Book* head) {
    Book* temp = head;
    while (temp != NULL) {
        printf("Book No: %d\nTitle: %s\nGenre: %d\n\n", temp->id, temp->title, temp->genre);
        temp = temp->next;
    }
}

void saveToFile(Book* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file!\n");
        return;
    }

    Book* temp = head;
    while (temp != NULL) {
        fprintf(file, "%d,%s,%d\n", temp->id, temp->title, temp->genre);
        temp = temp->next;
    }

    fclose(file);
}

void loadFromFile(Book** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file!\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int id;
        char title[50];
        int genre;
        sscanf(line, "%d,%49[^,],%d", &id, title, &genre);
        addBook(head, id, title, (Genre)genre);
    }

    fclose(file);
}

int main() {
    Book* library = NULL;

    addBook(&library, 1, "Game of Thrones", FICTION);
    addBook(&library, 2, "Mathemathics in the Modern World", NON_FICTION);
    addBook(&library, 3, "Mysterious Beast", MYSTERY);
    addBook(&library, 4, "Japanese in the Philippines", BIOGRAPHY);
    addBook(&library, 5, "Predator", SCIENCE_FICTION);

    printf("~~~~~~~~~USC-LRC~~~~~~~~~\n");
    printf("~~~~~Book Collection~~~~~\n");
    displayBooks(library);

    saveToFile(library, "library_records.txt");

    printf("Deleting book with ID 3.\n\n");
    deleteBook(&library, 3);

    printf("Books in the Collection after deletion:\n");
    displayBooks(library);

    printf("Reconstructing the list from the file:\n\n");
    Book* reconstructedLibrary = NULL;
    loadFromFile(&reconstructedLibrary, "library_records.txt");

    printf("Books in the reconstructed library:\n");
    displayBooks(reconstructedLibrary);

    return 0;
}
