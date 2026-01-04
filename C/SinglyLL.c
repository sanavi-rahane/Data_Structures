#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
void Display(PNODE first)
{
    printf("\n");
    while (first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
    
}
int Count(PNODE first)
{
    int iCount = 0;
    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}
void Insertfirst(PPNODE first,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
    
}
void InsertLast(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        
    }
}
void InsertAtPos(PPNODE first,int no,int pos)
{
    int iSize = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    iSize = Count(*first);

    if(pos < 1 || pos > iSize+1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        Insertfirst(first,no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;
        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp =temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}
void DeleteFirst(PPNODE first)
{
    PNODE target = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else{
        target = *first;
        *first = (*first)->next;
        free(target);
    }

}
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next->next = NULL;
    }
}
void DeleteAtPos(PPNODE first,int pos)
{
    int iSize = 0;
    int iCnt = 0;
    
    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp =temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}


int main()
{
    PNODE head = NULL;
    Insertfirst(&head,30);
    Insertfirst(&head,20);
    Insertfirst(&head,10);
    Insertfirst(&head,5);

    Display(head);
    printf("Number of Element : %d",Count(head));

    InsertLast(&head,40);
    Display(head);
    printf("Number of Element : %d",Count(head));

    InsertAtPos(&head,78,3);
    Display(head);
    printf("Number of Element : %d",Count(head));

    DeleteFirst(&head);
    Display(head);
    printf("\nNumber of Element : %d",Count(head));

    DeleteLast(&head);
    Display(head);
    printf("\nNumber of Element : %d",Count(head));

    DeleteAtPos(&head,5);
   
    Display(head);
    printf("\nNumber of Element : %d",Count(head));

    return 0;
}