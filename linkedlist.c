#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node NODEPTR;
void listTraversal(NODEPTR *list)
{
    printf("\n");
    while (list != NULL)
    {
        printf("%d\t", list->info);
        list = list->next;
    }
    printf("\n\n");
}
void createList(NODEPTR **list)
{
    int element;
    NODEPTR *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("First elements of list: ");
    scanf("%d", &element);
    temp->info = element;
    temp->next = NULL;
    *list = temp;
    // return list;
}
void insert_Begin(NODEPTR **list, int element)
{
    NODEPTR *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (*list == NULL)
    {
        printf("List is Empty!!");
    }
    else
    {
        temp->info = element;
        temp->next = *list;
        *list = temp;
    }

    // return list;
}
void insert_Aftergiven(NODEPTR **list, int given, int element)
{
    NODEPTR *temp, *p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    p = *list;
    while (p->info != given && p != NULL)
    {
        p = p->next;
    }
    if (p == NULL)
        printf("Element cannot be inserted!!");
    else
    {
        temp->info = element;
        temp->next = p->next;
        p->next = temp;
    }
    // return list;
}
void insert_Beforegiven(NODEPTR **list, int given, int element)
{
    NODEPTR *prev, *q, *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    prev = q = *list;
    // insert before p
    if (*list == NULL)
    {
        temp->info = element;
        temp = *list;
        printf("List cannot be inserted!!");
    }
    if (q->info != given && q != NULL)
    {
        prev = q;
        q = q->next;
    }
    if (q->info == given)
    {
        temp->info = element;
        temp->next = prev->next;
        prev->next = temp;
    }
    // return list;
}
void insert_atEnd(NODEPTR **list, int element)
{
    NODEPTR *temp, *p, *prev;
    p = *list;
    while (p != NULL)
    {
        prev = p;
        p = p->next;
    }
    temp = malloc(sizeof(struct Node));
    temp->info = element;
    temp->next = prev->next;
    prev->next = temp;
}
void delete_begin(NODEPTR **list)
{
    NODEPTR *temp;
    if (list == NULL)
    {
        printf("Cannot be deleted!!");
    }
    temp = *list;
    *list = temp->next;
    free(temp);
}
void delete_afterGiven(NODEPTR **list, int given)
{
    NODEPTR *p, *q;
    // p = q = *list;
    if (*list != NULL)
    {
        p = *list;
        while (p->info != given && p->next != NULL)
        {
            p = p->next;
        }
        if (p->info == given)
        {
            p->next = p->next->next;
        }
    }
    else
        printf("Cannot be deleted!! ");
}
void delete_beforeGiven(NODEPTR **list, int given)
{
    NODEPTR *p, *q, *r;
    q = *list;
    if (*list == NULL)
    {
        printf("Cannot be deleted!!");
    }
    else if (q->next->info == given)
    {
        printf("%d", q->next->info);
        *list = q->next;
    }
    else
    {
        p = q = *list;
        do
        {
            r = p;
            p = q;
            q = q->next;
        } while (list != NULL && q->info != given);
        if (q->info == given)
        {
            r->next = q;
            free(p);
        }
    }
}
void delete_end(NODEPTR **list)
{
    NODEPTR *temp, *p;
    p = temp = *list;
    if (list != NULL)
    {
        if (p->next == NULL)
        {
            *list = NULL;
        }
        do
        {
            p = temp;
            temp = temp->next;
        } while (temp->next!=NULL);
        if (temp->next == NULL)
        {
            p->next = temp->next;
            free(temp);
        }
    }
    else
    {
        printf("Cannot be deleted!!");
    }
}
void menu()
{
    printf("Enter : 1  To create a list.\n");
    printf("Enter : 2  To insert at the beginning of the list.\n");
    printf("Enter : 3  To insert after a given element of the list.\n");
    printf("Enter : 4  To insert before a given element of the list.\n");
    printf("Enter : 5  To insert at the end of the list.\n");
    printf("Enter : 6  To Delete at the beginning of the list.\n");
    printf("Enter : 7  To Delete after a given element of the list.\n");
    printf("Enter : 8  To Delete before a given element of the list.\n");
    printf("Enter : 9  To Delete at the end of the list.\n");
    printf("Enter : 10  To EXIT\n");
    printf("Enter your Choice\n");
}
int main()
{
    int ne1, ele1, ele2, ele3, ele4, ele5, ele6, giv1, giv2, giv3, giv4;
    int ch = 0;
    NODEPTR *list;
    list = (struct Node *)malloc(sizeof(struct Node));
    list = NULL;
    while (1)
    {
        menu();
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createList(&list);
            listTraversal(list);
            break;
        case 2:
            printf("Enter no of elements to enter at the beginning: ");
            scanf("%d", &ne1);
            for (int i = 0; i < ne1; i++)
            {
                printf("Enter element to enter at the beginning: ");
                scanf("%d", &ele1);
                insert_Begin(&list, ele1);
            }
            listTraversal(list);
            break;
        case 3:
            printf("Enter the element after which to insert: ");
            scanf("%d", &giv1);
            printf("Enter the elements to be entered: ");
            scanf("%d", &ele2);
            insert_Aftergiven(&list, giv1, ele2);
            listTraversal(list);
            break;
        case 4:
            printf("Enter the element before which to insert: ");
            scanf("%d", &giv2);
            printf("Enter the elements to be entered: ");
            scanf("%d", &ele3);
            insert_Beforegiven(&list, giv2, ele3);
            listTraversal(list);
            break;
        case 5:
            printf("Enter the elements to be entered at the end of the list: ");
            scanf("%d", &ele4);
            insert_atEnd(&list, ele4);
            listTraversal(list);
            break;
        case 6:
            printf("To Delete at the beginning of the list: ");
            delete_begin(&list);
            listTraversal(list);
            break;
        case 7:
            printf("Enter the element after which to DELETE: ");
            scanf("%d", &giv3);
            delete_afterGiven(&list, giv3);
            listTraversal(list);
            break;
        case 8:
            printf("Enter the element before which to DELETE: ");
            scanf("%d", &giv4);
            delete_beforeGiven(&list, giv4);
            listTraversal(list);
            break;
        case 9:
            printf("DELETED the end of the list.\n");
            delete_end(&list);
            listTraversal(list);
            break;
        case 10:
            return 0;
            break;
        default:
            printf("INCORRECT OPTION!!!\n TRY AGAIN\n");
            break;
        }
    }
    return 0;
}