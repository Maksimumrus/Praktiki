#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
    char name[100];
    char author[100];
    int year;
};

struct Node
{
    struct Book* book;
    struct Node* next;
};

struct Book* Create_Book (const char *name, const char *author, int year)
{
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strncpy(newBook->name, name, sizeof(newBook->name));
    strncpy(newBook->author, author, sizeof(newBook->author));
    newBook->year = year;
    return newBook;
};

struct Node* Create_Node (struct Book* book)
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->book = book;
    new->next = NULL;
    return new;
};

void Add_Node(struct Node** head, struct Node *new)
{
    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void Print_Books(struct Node *head) 
{
    struct Node *current = head;
    while (current != NULL) 
    {
        printf("Название: %s, Автор: %s, Год выпуска: %d\n", current->book->name, current->book->author, current->book->year);
        current = current->next;
    }
}

int main()
{
    setlocale (LC_ALL, "RUS");

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    Add_Node(&list1, Create_Node(Create_Book("Название1", "Автор1", 2000)));
    Add_Node(&list1, Create_Node(Create_Book("Название2", "Автор2", 2001)));

    Add_Node(&list2, Create_Node(Create_Book("Название3", "Автор3", 2002)));
    Add_Node(&list2, Create_Node(Create_Book("Название4", "Автор4", 2003)));

    list1->next->next = list2;

    printf("Книги:\n");
    Print_Books(list1);

    struct Node *current = list1;
    while (current != NULL) 
    {
        struct Node *temp = current;
        current = current->next;
        free(temp->book);
        free(temp);
    }
}