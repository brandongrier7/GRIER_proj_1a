#ifndef MAIN_H
#define MAIN_H
#define BUFFERSIZE 128

typedef struct student {
  char *lastName;
  char *firstName;
  long studentID;
  char *studentYear;
  int expectGrad;
  struct student *next;
  struct student *prev;
} student_t;


void deleteNode(student_t** head_ref, student_t* del);

void deleteAllNodes(student_t** head_ref, char *last);

void printList(student_t* node);

void printListEnd(student_t* node);

void push(student_t** head_ref, char* new_last, char* new_first, long new_id, char* new_year, int new_grad);

#endif