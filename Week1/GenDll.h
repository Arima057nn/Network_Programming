#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account
{
  char name[30];
  char pass[30];
  int act;
  int countLogin;
} Account;

typedef Account element;

typedef struct Node
{
  element data;
  struct Node *next;
  struct Node *prev;
} node;
void displayNodeSearch(node *p);
void displayNode(node *p);
element inputNode();
void initialize(node **root, node **cur, node **tail);
node *makeNewNode(element e);
void traversingList(node *root, node *cur, node *tail);
void writeFile(FILE *fptr, node *root);
void traversingList2(node *root, node *cur, node *tail);
void insertAtHead(element A, node **root, node **cur, node **tail);
void insertAtTail(element A, node **root, node **cur, node **tail);
void insertBeforeCurrent(element A, node **root, node **cur, node **tail);
void insertAfterCurrent(element A, node **root, node **cur, node **tail);
void insertAtPosition(element A, int n, node **root, node **cur, node **tail);
void deleteFirstElement(node **root, node **cur, node **tail);
void deleteLastElement(node **root, node **cur, node **tail);
void deleteCurrentElement(node **root, node **cur, node **tail);
void deleteAtPosition(int n, node **root, node **cur, node **tail);
void Reverse_List(node **root, node **cur, node **tail);
int searchRegister(char S[], node *root);
node *searchingLogin(node *root, int *k, node *cur, node *tail);
node *searching(char S[], node *root, int *k);
void freeList(node **root, node **cur, node **tail);
