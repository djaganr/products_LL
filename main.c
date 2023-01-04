#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;
    char name[100];
    double price;
    struct node *next; //link to next lement in linked list
};

// List all Products
void printProducts(struct node *head){
    struct node * current = head;

    while (current != NULL){
        printf("%d, %s, %lf \n", current->id, current->name, current->price);
        current = current->next;
    }
}


void findProduct(struct node *head, char name[100]){
    struct node * current = head;

    while (current != NULL){
        
        if (current->name == name){
            printf("%s", name);
        }
        current = current->next;
    }
}

// Add product 
void addingProduct(struct node *head, char name[100], double price ){
    struct node * current = head;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = (struct node *)malloc(sizeof(struct node));
    current->next->id = current->id+1;
    strcpy(current->next->name, name);
    current->next->price = price;
}

// Delete product by id
void deleteProduct(struct node *head, int id ){
    struct node * current = head;
    struct node * temp_node = NULL;

    while (current != NULL){
        if (current->next->id == id){
            break;
        }
        current = current->next;
    }

    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);

    printProducts(head);
}

// Update product
void updateProduct(struct node *head,int id ,char name[100], double price ){
    struct node * current = head;

    while (current != NULL){
        if(current->id == id){
            break;
        }
        current = current->next;
    }

    strcpy(current->name, name);
    current->price = price;
    
}



int main() {

    // allocate heap memory and returns a void pointer and now we typecast it to struct type 
    struct node *head = (struct node *)malloc(sizeof(struct node)); // header is a pointer which stores the address of first byte out of the allocated heap memory bytes
    head->id = 1;
    strcpy(head->name, "first item");
    head->price = 34.9;

    // adding a variable
    struct node *item1 = (struct node *)malloc(sizeof(struct node));
    head->next = item1;
    item1->id = 2;
    strcpy(item1->name, "second item");
    item1->price = 45.0;
    item1->next = NULL;

    

    char Decision = 'Y';
    int productId;
    char productName[100];
    double productPrice;

    


    printf("Add a Product?:");
    scanf(" %c", &Decision);
    if(Decision=='Y'){
        printf("Enter name:");
        scanf("%s", productName);
        printf("enter price:");
        scanf("%lf", &productPrice);
        addingProduct(head, productName, productPrice);
        Decision = 'N';
    }

    printf("Want to List all the products?:");
    scanf(" %c", &Decision);
    if(Decision=='Y'){
        printProducts(head);
        Decision = 'N';
    }
    

    printf("Want to search a product?:");
    scanf(" %c", &Decision);
    if(Decision=='Y'){
        printf("Enter name:");
        scanf("%s", productName);
        findProduct(head, productName);
        Decision = 'N';
    }


    printf("Want to delete a product?:");
    scanf(" %c", &Decision);
    if(Decision=='Y'){
        printf("Enter id:");
        scanf("%d", &productId);
        deleteProduct(head, productId);
        Decision = 'N';
    }
    
    printf("update a Product?:");
    scanf(" %c", &Decision);
    if(Decision=='Y'){
        printf("Enter id:");
        scanf("%d", &productId);
        printf("Enter name:");
        scanf("%s", productName);
        printf("enter price:");
        scanf("%lf", &productPrice);
        updateProduct(head, productId,  productName, productPrice);
        Decision = 'N';
    }


    printProducts(head);

    return 0;
}