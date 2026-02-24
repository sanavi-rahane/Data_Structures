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
    int iChoice = 0;
    int iNo = 0;
    int Position = 0;

    printf("1.Insert First\n2.Inser tLast\n3.Insert At Position\n4.Delete First\n4.Delete Last\n5.Delete At Position\n6.Display Linked List\n7.Total Count of Nodes\n8.Exit");
    
    while (1)
    {    
        printf("Enter Your Choice : \n");
        scanf("%d",&iChoice);
 
        switch (iChoice)
        {
        case 1 :
            printf("Enter Number to Insert at First : \n");
            scanf("%d",&iNo);
            Insertfirst(&head,iNo);
            printf("Number Inserted Succesfully! \n");
            break;
        case 2 :
            printf("Enter Number to Insert at Last : \n");
            scanf("%d",&iNo);
            InsertLast(&head,iNo);
            printf("Number Inserted Succesfully! \n");
            break;
        case 3 :
            printf("Enter Number to Insert at Position : \n");
            scanf("%d",&iNo);
            printf("Enter Position where you want to insert number :\n");
            scanf("%d",Position);
            InsertAtPos(&head,iNo,Position);
            printf("Number Inserted Succesfully! \n");
            break;
        case 4 :
            
            DeleteFirst(&head);
            printf("first Node Deleted Succesfully! \n");
            break;
        case 5 :
        
            DeleteLast(&head);
            printf("last Node Deleted Succesfully! \n");
            break;
        case 6 :
            printf("Enter Position of node : \n");
            scanf("%d",&Position);
            DeleteAtPos(&head,Position);
            printf("Node Deleted Succesfully! \n");
            break;
        case 7 :
            Display(head);
            break;
        case 8 :
            printf("Number of Element : %d",Count(head));
            break;
        case 9 :
        exit(0);
            break;
        
        default:
            printf("Please Enter Valid Choice \n");
            break;
        }
    }

}