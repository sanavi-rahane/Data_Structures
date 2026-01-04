#include<iostream>
using namespace std;
template< class T >
struct DoublyLLLnode
{
    T data;
    struct DoublyLLLnode<T> *next;
    struct DoublyLLLnode<T> *prev;
};
template <class T>
class DoublyLLL
{
    private:
        struct DoublyLLLnode<T> *first;
        int iCount ;
    public:

    DoublyLLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no,int pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int pos);
    void Display();
    
    int Count();

};
template<class T>
    DoublyLLL<T>:: DoublyLLL()
    {
        this->first = NULL;
        this->iCount = 0;
    }

template<class T>
    void DoublyLLL<T> :: InsertFirst(T no)
    {
        struct DoublyLLLnode<T> *newn;
        newn = new struct DoublyLLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        this->iCount++;
    }
template<class T>
    void  DoublyLLL<T> :: Display()
    {
        struct DoublyLLLnode<T> *temp = NULL;
        temp = first;
        cout<<"\nNULL->";
        while (temp!= NULL)
        {
            cout<<"| "<<temp->data<<"| ->";
            temp = temp->next;
        }
        cout<<"NULL\n";
        
    }
template<class T>
    int DoublyLLL<T> :: Count()
    {
        return iCount;
    }
template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    struct DoublyLLLnode<T> *newn = NULL;
    struct DoublyLLLnode<T> *temp = NULL;

    newn = new struct DoublyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;

}
template<class T>
void DoublyLLL<T>  :: InsertAtPos(T no,int pos)
{
    struct DoublyLLLnode<T> *newn = NULL;
    newn = new struct DoublyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    int iCnt = 0;

    struct DoublyLLLnode<T> *temp = NULL;
    
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invlaid Position : \n";
        return;
    }

    if(pos == 1)
    {
       this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = first;
        for(iCnt = 1;iCnt <pos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        this->iCount++;
    }
}
template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    this->iCount--;
}
template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    struct DoublyLLLnode<T> *temp = NULL;
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        
    }
    this->iCount--;
}
template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    struct DoublyLLLnode<T> *temp = NULL;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position : \n";
        return;
    }

    if(pos == 1)
    {
       this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = first;
        for(iCnt = 1;iCnt <pos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        this->iCount--;
    }
    
}
int main()
{
   
    DoublyLLL<int> obj;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout<<"Element : "<<obj.Count();

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    cout<<"Element : "<<obj.Count();

    obj.InsertAtPos(105,5);
    obj.Display();
    cout<<"Element : "<<obj.Count();

    obj.DeleteFirst();
    obj.Display();
    cout<<"Element : "<<obj.Count();

    obj.DeleteLast();
    obj.Display();
    cout<<"Element : "<<obj.Count();

    obj.DeleteAtPos(3);
    obj.Display();
    cout<<"Element : "<<obj.Count();

    return 0;
}