#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a Product
typedef struct
{
    char name[100];       // Declare a character array of size 100 to store the product's name
    float price;          // Declare a float to store the product's price
    int stock;            // Declare an integer to store the product's stock quantity
    char productCode[20]; // Declare a character array of size 20 to store the product's unique identifier
} Product;

// Function to create an array of products (returns the array)
Product *createProductList(int *size)
{
    *size = 0; // Initialize the size to 0
    // Dynamically allocate memory for up to 100 products
    Product *products = (Product *)malloc(100 * sizeof(Product));
    return products; // Return the pointer to the newly created array
}

// Function to add a product to the array (Create)
void addProduct(Product *products, int *size, const char *name, float price, int stock, const char *productCode)
{
    strcpy(products[*size].name, name);               // Copy the provided name into the name field of the product at the current size index
    products[*size].price = price;                    // Assign the provided price to the price field of the product at the current size index
    products[*size].stock = stock;                    // Assign the provided stock quantity to the stock field of the product at the current size index
    strcpy(products[*size].productCode, productCode); // Copy the provided product code into the productCode field of the product at the current size index
    (*size)++;                                        // Increment the size to indicate a new product has been added
}

// Function to display all products (Read)
void readProducts(Product *products, int size)
{
    for (int i = 0; i < size; i++)
    { // Iterate through all products
        printf("Product %d: Name = %s, Price = $%.2f, Stock = %d, Product Code = %s\n",
               i + 1, products[i].name, products[i].price, products[i].stock, products[i].productCode); // Print the details of each product
    }
}

// Function to find a product by product code
int findProductByCode(Product *products, int size, const char *productCode)
{
    for (int i = 0; i < size; i++)
    { // Iterate through all products
        if (strcmp(products[i].productCode, productCode) == 0)
        {             // Compare the provided product code with the product code of the current product
            return i; // Return the index of the product if found
        }
    }
    return -1; // Return -1 if the product is not found
}

// Function to update a product's details (Update)
void updateProduct(Product *products, int size, const char *productCode, const char *newName, float newPrice, int newStock)
{
    int index = findProductByCode(products, size, productCode); // Find the index of the product with the specified product code
    if (index != -1)
    {                                          // If the product was found
        strcpy(products[index].name, newName); // Update the name
        products[index].price = newPrice;      // Update the price
        products[index].stock = newStock;      // Update the stock quantity
        printf("Product with Code %s updated successfully.\n", productCode);
    }
    else
    {
        printf("Product with Code %s not found.\n", productCode);
    }
}

// Function to delete a product by product code (Delete)
void deleteProduct(Product *products, int *size, const char *productCode)
{
    int index = findProductByCode(products, *size, productCode); // Find the index of the product with the specified product code
    if (index != -1)
    { // If the product was found
        for (int i = index; i < *size - 1; i++)
        {                                  // Iterate from the index to be deleted to the last element
            products[i] = products[i + 1]; // Shift elements to the left, overwriting the deleted element
        }
        (*size)--; // Reduce the size to indicate a product has been removed
        printf("Product with Code %s deleted successfully.\n", productCode);
    }
    else
    {
        printf("Product with Code %s not found.\n", productCode);
    }
}

int main()
{
    int size; // Variable to hold the current number of products

    // Create a dynamic array of products using the function
    Product *products = createProductList(&size);

    // Add products (Create)
    addProduct(products, &size, "Laptop", 999.99, 50, "P1001");
    addProduct(products, &size, "Smartphone", 499.99, 100, "P1002");
    addProduct(products, &size, "Headphones", 29.99, 200, "P1003");

    // Read all products (Read)
    printf("Products in inventory:\n");
    readProducts(products, size);

    // Update a product's details (Update)
    updateProduct(products, size, "P1002", "Smartphone (Updated)", 549.99, 80);
    printf("\nAfter updating the Smartphone:\n");
    readProducts(products, size);

    // Delete a product by product code (Delete)
    deleteProduct(products, &size, "P1001");
    printf("\nAfter deleting the Laptop:\n");
    readProducts(products, size);

    // Free dynamically allocated memory
    free(products);

    return 0;
}