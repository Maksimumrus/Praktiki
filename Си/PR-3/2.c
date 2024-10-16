#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* Create(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void Add(struct Node** head_ref, int new_data)
{
    struct Node* newNode = Create(new_data);
    if (*head_ref == NULL) 
    {
        *head_ref = newNode;
    } 
    else 
    {
        struct Node* tail = (*head_ref)->prev;
        tail->next = newNode;
        newNode->prev = tail;
    }
    newNode->next = *head_ref;
    (*head_ref)->prev = newNode;
}

void Delete(struct Node** head_ref, struct Node* delNode) 
{
    if (*head_ref == NULL || delNode == NULL || delNode == *head_ref || delNode->next == *head_ref) 
    {
        printf("Удаление невозможно. Убедитесь, что элемент находится в середине.\n");
        return;
    }
    struct Node* prevNode = delNode->prev;
    struct Node* nextNode = delNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    free(delNode);
}

void Print(struct Node* head)
 {
    if (head == NULL) return;
    
    struct Node* temp = head;
    do 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    struct Node* head = NULL;

    int el = 0;
    int n;

    printf("Введите кол-во элементов для добавления: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        Add(&head, i+1);
    }

    printf("Список: ");
    Print(head);

    struct Node* middleNode = head->next->next;
    Delete(&head, middleNode);

    printf("После удаления элемента 3: ");
    Print(head);

    return 0;
}
