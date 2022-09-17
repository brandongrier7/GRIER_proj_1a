#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define BUFFERSIZE 128
 
/* Function to delete a node in a Doubly Linked List.
   parameters: head reference, pointer to node to be deleted
   returns: nothing
   side effects: deletes the node passed in */

void deleteNode(student_t** head_ref, student_t* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
}

/* Function to all nodes with the same last name in the Doubly Linked List 
    params: head_reference, lastname
   returns: nothing
   side effects: deletes all nodes with same last name as one passed in */
void deleteAllNodes(student_t** head_ref, char *last)
{
    if ((*head_ref) == NULL)
        return;
    student_t* current = *head_ref;
    student_t* next= (*head_ref)->next;
    while (current != NULL) {
        if (strcmp(current->lastName,last) == 0) {
            next = current->next;
            deleteNode(head_ref, current);
            current = next;
        }
        else
            current = current->next;
    }
}

/* Function to insert a node at the beginning of the Doubly Linked List 
    params: head_reference, lastname, first name, ID, year, expexted grad year
   returns: printed doubly linked list */
void push(student_t** head_ref, char* new_last, char* new_first, long new_id, char* new_year, int new_grad)
{
    student_t* new_node = (student_t*)malloc(sizeof(student_t));
    new_node->lastName = new_last;
    new_node->firstName = new_first;
    new_node->studentID = new_id;
    new_node->studentYear = new_year;
    new_node->expectGrad = new_grad;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
 
/* Function to print nodes in a given doubly linked list
   params: node
   returns: nothing
   side effects: printed doubly linked list from beginning to last*/
void printList(student_t* node)
{
    while (node != NULL) {
        printf("%s\n", node->lastName);
        printf("%s\n", node->firstName);
        printf("%ld\n", node->studentID);
        printf("%s\n", node->studentYear);
        printf("%d\n", node->expectGrad);
        node = node->next;
    }
}

/* Function to print nodes in a given doubly linked list
   params: node
   returns: nothing
   side effects: printed doubly linked list from end to beginning */
void printListEnd(student_t* node)
{
    while (node != NULL) {
        printf("%d\n", node->expectGrad);
        printf("%s\n", node->studentYear);
        printf("%ld\n", node->studentID);
        printf("%s\n", node->firstName);
        printf("%s\n", node->lastName);
        node = node->next;
    }
}

 
/* Driver program to test above functions*/
int main()
{
    int a;
    int x;
    char *p;
    char b[BUFFERSIZE];
    char c[BUFFERSIZE];
    char e[BUFFERSIZE];
    char g[BUFFERSIZE];
    student_t* head = (student_t*)malloc(sizeof(student_t));
    while(1){
    printf("Press 1 to add a student\n");
    printf("Press 2 to delete a student\n");
    printf("Press 3 to print all students beginning to end\n");
    printf("Press 4 to print all students end to beginning\n");
    printf("Press 5 to exit\n");
    scanf("%d",&a);
    getchar();
    switch(a){
        case 1:
            printf("\nType Last Name:");
            fgets(b, BUFFERSIZE, stdin);
            head->lastName = (char *) malloc(BUFFERSIZE);
            printf("\nType First Name:");
            fgets(c, BUFFERSIZE, stdin);
            head->firstName = (char *) malloc(BUFFERSIZE);
            long d;
            printf("\nType Student ID:");
            scanf("\n%ld",&d);
            getchar();
            printf("\nType Student Year:");
            fgets(e, BUFFERSIZE, stdin);
            head->studentYear = (char *) malloc(BUFFERSIZE);
            int f;
            printf("\nType Expected Graduation Year:");
            scanf("\n%d",&f);
            getchar();
            while ((x = getchar()) != EOF && x != '\n') ;
            push(&head, b, c, d, e, f);
            printf("student added\n");
            break;
        case 2:
            printf("Type Last Name:");
            scanf("\n%s",g);
            deleteAllNodes(&head,g);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            printListEnd(head);
            break;
        case 5:
            free(head);
            exit(1);
            break;
    }
}
}
