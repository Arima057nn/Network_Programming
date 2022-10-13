#include "GenDll.h"

int main()
{
    FILE *ptr = fopen("account.txt", "r");
    FILE *fptr;
    Account acc[2];
    int k, logIn = 0;
    node *head, *cur, *tail, *p, *q;
    initialize(&head, &cur, &tail);
    char S[30], accLogin[30] = "*****";
    while (fscanf(ptr, "%s%s%d%*c", acc[0].name, acc[0].pass, &acc[0].act) == 3)
    {
        insertAtTail(acc[0], &head, &cur, &tail);
    }
    int choose;
    while (1)
    {
        printf("\nUSER MANAGEMENT PROGRAM\n"
               "-----------------------------------\n"
               "1. Register\n"
               "2. Sign in\n"
               "3. Search\n"
               "4. Sign out\n"
               "--->Your choice (1-4, other to quit): ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            k = 0;
            printf("\n== Register ==\n");
            printf("Input Account Name: ");
            scanf("%s%*c", acc[1].name);

            if (searchRegister(acc[1].name, head) == 1)
            {
                printf("-- Account already exists\n");
            }
            else
            {
                printf("Input Password: ");
                scanf("%s%*c", acc[1].pass);
                acc[1].act = 1;
                insertAtTail(acc[1], &head, &cur, &tail);
                printf("-- Successful registration\n");
                fptr = fopen("account.txt", "a+");
                fprintf(fptr, "%s %s %d\n", acc[1].name, acc[1].pass, acc[1].act);
                fclose(fptr);
            }

            break;
        case 2:
            k = 0;
            printf("\n== Login ==\n");
            p = searchingLogin(head, &k, cur, tail);
            if (k == 1)
            {
                p->data.countLogin += 1;
                if (p->data.countLogin <= 3 && p->data.act == 1)
                {
                    printf("-- Password is incorrect\n");
                }
                else
                {
                    p->data.act = 0;
                    p->data.countLogin = 0;
                    printf("-- Account is blocked\n");
                    fptr = fopen("account.txt", "w+");
                    writeFile(fptr, head);
                    fclose(fptr);
                }
            }
            else if (k == 2)
            {

                printf("-- Hello %s\n", p->data.name);
                logIn = 1;
                p->data.countLogin = 0;
                strcpy(accLogin, p->data.name);
            }
            else
                printf("Cannot find account\n");

            break;
        case 3:
            k = 0;
            printf("\n== Search ==\n");

            printf("Input Account Name: ");
            scanf("%s%*c", S);
            p = searching(S, head, &k);

            if (p != NULL && k == 1)
            {
                displayNodeSearch(p);
            }
            else
            {
                printf("-- Cannot find account\n");
            }

            break;
        case 4:
            k = 0;
            if (logIn == 1)
            {
                printf("Account Name: ");
                scanf("%s%*c", S);
                searching(S, head, &k);

                if (strcmp(S, accLogin) == 0)
                {
                    printf("-- Goodbye %s\n", S);
                    logIn == 0;
                    stpcpy(accLogin, "*****");
                }
                else
                {
                    if (k == 1)
                        printf("-- Account is not sign in\n");
                    else
                        printf("-- Cannot find account\n");
                }
            }
            else
                printf("-- Account is not sign in\n");
            break;
        case 5:
            printf("\nAccount online: %s\n", accLogin);
            traversingList(head, cur, tail);
            break;
        default:
            fclose(ptr);

            freeList(&head, &cur, &tail);
            exit(0);
            break;
        }
    }
}
