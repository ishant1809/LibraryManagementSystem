#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100

typedef struct {
    int id;
    char title[MAX_TITLE];
    int available;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &library[book_count].id);
    printf("Enter book title: ");
    scanf(" %[^\n]s", library[book_count].title);
    library[book_count].available = 1;
    book_count++;
    printf("Book added successfully.\n");
}

void listBooks() {
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d, Title: %s, Available: %s\n", library[i].id, library[i].title, library[i].available ? "Yes" : "No");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Book\n2. List Books\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
