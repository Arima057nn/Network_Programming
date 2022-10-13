#include "GenDll.h"

void displayNode(node *p)
{
    if (p == NULL)
        printf("Error Pointer");
    else
        printf("%-20s %-20s %-20d %-20d\n", p->data.name, p->data.pass, p->data.act, p->data.countLogin);
}

void displayNodeSearch(node *p)
{

    if (p == NULL)
    {
        printf("Error Pointer");
    }
    else
    {
        if (p->data.act == 1)
            printf("Account is %-20s\n", "active");
        else
            printf("Account is %-20s\n", "blocked");
    }
}

Account inputNode()
{
    Account new;
    printf("Name: ");
    scanf("%s%*c", new.name);
    printf("Password: ");
    scanf("%s%*c", new.pass);
    new.act = 1;
    new.countLogin = 0;
    return new;
}

Account inputNodeLogin()
{
    Account new;
    printf("Name: ");
    scanf("%s%*c", new.name);
    printf("Password: ");
    scanf("%s%*c", new.pass);
    new.act = 1;
    return new;
}

void initialize(node **root, node **cur, node **tail)
{
    *root = NULL;
    *tail = NULL;
    *cur = NULL;
}
node *makeNewNode(element e)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = e;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void traversingList(node *root, node *cur, node *tail)
{
    node *p = root;
    if (root == NULL)
    {
        printf("Error Pointer");
        return;
    }
    printf("%-20s %-20s %-20s %-20s\n", "Account Name", "password", "status", "countLogin");

    while (p != NULL)
    {
        displayNode(p);
        p = p->next;
    }
}

void writeFile(FILE *fptr, node *root)
{
    node *p = root;
    if (root == NULL)
        return;
    while (p != NULL)
    {
        fprintf(fptr, "%s %s %d\n", p->data.name, p->data.pass, p->data.act);
        p = p->next;
    }
}
void traversingList2(node *root, node *cur, node *tail)
{
    node *p = tail;
    if (tail == NULL)
    {
        printf("Error Pointer");
        return;
    }
    while (p != NULL)
    {
        // displayNode(p);
        p = p->prev;
    }
}
void insertAtHead(element A, node **root, node **cur, node **tail)
{
    node *new = makeNewNode(A);
    if (*root == NULL)
    {
        *root = new;
        *cur = *root;
        *tail = new;
    }
    else
    {
        (*root)->prev = new;
        new->next = *root;
        new->prev = NULL;
        *root = new;
        *cur = *root;
    }
    return;
}
void insertAtTail(element A, node **root, node **cur, node **tail)
{
    node *new = makeNewNode(A);
    if (*root == NULL)
    {
        insertAtHead(A, root, cur, tail);
        return;
    }
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    *cur = new;
    return;
}
void insertBeforeCurrent(element A, node **root, node **cur, node **tail)
{
    node *new = makeNewNode(A);
    if (*root == NULL || *cur == *root)
    {
        insertAtHead(A, root, cur, tail);
        return;
    }
    else if (*cur == NULL)
    {
        printf("Current is NULL!\n");
        return;
    }
    else
    {
        new->next = *cur;
        new->prev = (*cur)->prev;
        (*cur)->prev->next = new;
        (*cur)->prev = new;
        *cur = new;
    }
    return;
}
void insertAfterCurrent(element A, node **root, node **cur, node **tail)
{
    node *new = makeNewNode(A);
    if (*root == NULL || *cur == *tail)
    {
        insertAtTail(A, root, cur, tail);
        return;
    }
    else if (*cur == NULL)
    {
        printf("Current is NULL!\n");
        return;
    }
    else
    {
        new->next = (*cur)->next;
        new->prev = *cur;
        (*cur)->next->prev = new;
        (*cur)->next = new;
        *cur = new;
    }
}
void insertAtPosition(element A, int n, node **root, node **cur, node **tail)
{
    node *new = makeNewNode(A);
    *cur = *root;
    if (n < 0)
    {
        printf("n must be >=0!\n");
        return;
    }
    if (n == 0)
    {
        insertAtHead(A, root, cur, tail);
        return;
    }
    for (int i = 1; i < n; i++)
    {
        *cur = (*cur)->next;
        if (*cur == NULL)
        {
            printf("n must be<=%d\n", i);
            return;
        }
    }
    insertAfterCurrent(A, root, cur, tail);
    return;
}

void deleteFirstElement(node **root, node **cur, node **tail)
{
    node *p = *root;
    if (*root == NULL)
    {
        printf("root is NULL\n");
        return;
    }
    *root = (*root)->next;
    (*root)->prev = NULL;
    *cur = *root;
    free(p);
    return;
}
void deleteLastElement(node **root, node **cur, node **tail)
{
    node *p = *tail;
    if (*tail == NULL)
    {
        printf("tail is NULL\n");
        return;
    }
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    *cur = *tail;
    free(p);
    return;
}
void deleteCurrentElement(node **root, node **cur, node **tail)
{
    node *p = *cur;
    if (*cur == NULL)
    {
        printf("cur is NULL\n");
        return;
    }
    if (*cur == *root)
    {
        deleteFirstElement(root, cur, tail);
        return;
    }
    if (*cur == *tail)
    {
        deleteLastElement(root, cur, tail);
        return;
    }
    (*cur)->prev->next = (*cur)->next;
    (*cur)->next->prev = (*cur)->prev;
    *cur = (*cur)->next;
    free(p);
    return;
}
void deleteAtPosition(int n, node **root, node **cur, node **tail)
{
    *cur = *root;
    if (n < 0)
    {
        printf("n must be >=0!\n");
        return;
    }
    if (n == 0)
    {
        deleteFirstElement(root, cur, tail);
        return;
    }
    for (int i = 1; i < n; i++)
    {
        *cur = (*cur)->next;
        if (*cur == NULL)
        {
            printf("n must be<=%d\n", i);
            return;
        }
    }
    deleteCurrentElement(root, cur, tail);
    return;
}
void Reverse_List(node **root, node **cur, node **tail)
{
    node *p = *cur = NULL;
    *tail = *root;
    while (*root != NULL)
    {
        *cur = *root;
        *root = (*root)->next;
        (*cur)->next = p;
        (*cur)->prev = *root;
        p = *cur;
    }
    *root = *cur;
    return;
}

int searchRegister(char S[], node *root)
{
    node *p;
    int i = 0;
    for (p = root; p != NULL; p = p->next)
    {
        if (strcmp(p->data.name, S) == 0)
        {
            i = 1;
            return 1;
        }
    }
    if (i == 0)
        return 0;
}

node *searchingLogin(node *root, int *k, node *cur, node *tail)
{
    node *p;
    int i = 0;
    char S[30];
    element A[0];
    printf("Account Name: ");
    scanf("%s%*c", S);
    for (p = root; p != NULL; p = p->next)
    {
        i++;
        if (strcmp(S, p->data.name) == 0)
        {
            *k = 1;
            if (p->data.act == 0)
            {
                return p;
            }
            printf("Password: ");
            scanf("%s%*c", S);
            if (strcmp(S, p->data.pass) == 0)
            {
                *k = 2;
                return p;
            }
            else
            {

                return p;
            }
        }
    }
    return p;
}

node *searching(char S[], node *root, int *k)
{
    node *p;
    for (p = root; p != NULL; p = p->next)
    {
        if (strcmp(S, p->data.name) == 0)
        {
            *k = 1;
            return p;
        }
    }
    return p;
}

void freeList(node **root, node **cur, node **tail)
{
    node *p = *root;
    while (p != NULL)
    {
        *root = (*root)->next;
        free(p);
        p = *root;
    }
    return;
}
