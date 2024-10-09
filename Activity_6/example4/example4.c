#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    float price;
    int stock;
    char productCode[20];
} Product;

Product* createProductList(int *size) {
    *size = 0;
    Product *products = (Product*)malloc(100 * sizeof(Product));
    return products;
}

void addProduct(Product *products, int *size) {
    if (*size >= 100) {
        printf("Product list is full. Can't add more products.\n");
        return;
    }

    char name[100];
    float price;
    int stock;
    char productCode[20];

    printf("Enter Product Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove trailing newline

    printf("Enter Product Price: ");
    scanf("%f", &price);

    printf("Enter Product Stock: ");
    scanf("%d", &stock);
    getchar(); // Consume newline

    printf("Enter Product Code: ");
    fgets(productCode, sizeof(productCode), stdin);
    productCode[strcspn(productCode, "\n")] = '\0';  // Remove trailing newline

    strcpy(products[*size].name, name);
    products[*size].price = price;
    products[*size].stock = stock;
    strcpy(products[*size].productCode, productCode);
    (*size)++;
}

void readProducts(Product *products, int size) {
    if (size == 0) {
        printf("No products available.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("Product %d: Name = %s, Price = $%.2f, Stock = %d, Product Code = %s\n",
               i + 1, products[i].name, products[i].price, products[i].stock, products[i].productCode);
    }
}

int findProductByCode(Product *products, int size, char *productCode) {
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].productCode, productCode) == 0) {
            return i;
        }
    }
    return -1;
}

void updateProduct(Product *products, int size) {
    char productCode[20];
    char newName[100];
    float newPrice;
    int newStock;

    printf("Enter Product Code to update: ");
    fgets(productCode, sizeof(productCode), stdin);
    productCode[strcspn(productCode, "\n")] = '\0';

    int index = findProductByCode(products, size, productCode);
    if (index != -1) {
        printf("Enter New Name: ");
        fgets(newName, sizeof(newName), stdin);
        newName[strcspn(newName, "\n")] = '\0';

        printf("Enter New Price: ");
        scanf("%f", &newPrice);

        printf("Enter New Stock: ");
        scanf("%d", &newStock);
        getchar(); // Consume newline

        strcpy(products[index].name, newName);
        products[index].price = newPrice;
        products[index].stock = newStock;
        printf("Product with Code %s updated successfully.\n", productCode);
    } else {
        printf("Product with Code %s not found.\n", productCode);
    }
}

void deleteProduct(Product *products, int *size) {
    char productCode[20];

    printf("Enter Product Code to delete: ");
    fgets(productCode, sizeof(productCode), stdin);
    productCode[strcspn(productCode, "\n")] = '\0';

    int index = findProductByCode(products, *size, productCode);
    if (index != -1) {
        for (int i = index; i < *size - 1; i++) {
            products[i] = products[i + 1];
        }
        (*size)--;
        printf("Product with Code %s deleted successfully.\n", productCode);
    } else {
        printf("Product with Code %s not found.\n", productCode);
    }
}

int main() {
    int size;
    Product *products = createProductList(&size);
    int choice;

    do {
        printf("\nProduct Management System:\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Display Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addProduct(products, &size);
                break;
            case 2:
                updateProduct(products, size);
                break;
            case 3:
                deleteProduct(products, &size);
                break;
            case 4:
                readProducts(products, size);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    free(products);
    return 0;
}

