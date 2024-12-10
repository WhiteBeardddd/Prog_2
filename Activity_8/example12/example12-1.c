
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Structure to store contact information
typedef struct Contact
{
    char name[MAX_NAME_LENGTH];   // Contact's name
    char phone[MAX_PHONE_LENGTH]; // Contact's phone number
    struct Contact *next;         // Pointer to the next contact in the list
} Contact;

// Function to create a new contact
// Parameters:
// - name: The name of the contact
// - phone: The phone number of the contact
// Returns: A pointer to the newly created contact
Contact *createContact(char *name, char *phone)
{
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}

// Function to add a contact to the beginning of the contact list
// Parameters:
// - head: A pointer to the head of the contact list
// - name: The name of the contact
// - phone: The phone number of the contact
void addContact(Contact **head, char *name, char *phone)
{
    Contact *newContact = createContact(name, phone);
    newContact->next = *head;
    *head = newContact;
}

// Function to print all contacts in the contact list
// Parameters:
// - head: A pointer to the head of the contact list
void printContacts(Contact *head)
{
    Contact *current = head;
    while (current != NULL)
    {
        printf("Name: %s, Phone: %s\n", current->name, current->phone);
        current = current->next;
    }
}

// Function to save all contacts to a file
// Parameters:
// - head: A pointer to the head of the contact list
// - filename: The name of the file to save the contacts to
void saveContactsToFile(Contact *head, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Failed to open file");
        return;
    }
    Contact *current = head;
    while (current != NULL)
    {
        fprintf(file, "%s,%s\n", current->name, current->phone);
        current = current->next;
    }
    fclose(file);
}

// Function to load contacts from a file and add them to the contact list
// Parameters:
// - head: A pointer to the head of the contact list
// - filename: The name of the file to load the contacts from
void loadContactsFromFile(Contact **head, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        return;
    }
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    while (fscanf(file, "%49[^,],%14[^\n]\n", name, phone) != EOF)
    {
        addContact(head, name, phone);
    }
    fclose(file);
}

// Function to free all contacts in the contact list
// Parameters:
// - head: A pointer to the head of the contact list
void freeContacts(Contact *head)
{
    Contact *current = head;
    while (current != NULL)
    {
        Contact *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
// Loads contacts from a file, adds new contacts, prints the contact list,
// saves the contacts to a file, and frees the contact list
int main()
{
    Contact *phonebook = NULL;
    loadContactsFromFile(&phonebook, "phonebook.txt");

    addContact(&phonebook, "Alice", "123-456-7890");
    addContact(&phonebook, "Bob", "987-654-3210");

    printContacts(phonebook);

    saveContactsToFile(phonebook, "phonebook.txt");

    freeContacts(phonebook);
    return 0;
}