#include<iostream>
using namespace std;
template< class T >
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};
template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> *first;
        struct DoublyCLLnode<T> *last;
        int iCount ;
    public:

    DoublyCLL();
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
    DoublyCLL<T>:: DoublyCLL()
    {
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

template<class T>
    void DoublyCLL<T> :: InsertFirst(T no)
    {
        struct DoublyCLLnode<T> *newn;
        newn = new struct DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        last->next = first;
        first->prev = last;

        this->iCount++;
    }
template<class T>
    void  DoublyCLL<T> :: Display()
    {
        struct DoublyCLLnode<T> *temp = NULL;
        temp = first;
        cout<<"\n<=>";
        do
        {
            cout<<"|"<<temp->data<<"| <=>";
            temp = temp->next;
        } while (temp != first);
        cout<<"\n";
        
        
    }
template<class T>
    int DoublyCLL<T> :: Count()
    {
        return iCount;
    }
template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> *newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    this->iCount++;

}
template<class T>
void DoublyCLL<T>  :: InsertAtPos(T no,int pos)
{
    struct DoublyCLLnode<T> *newn = NULL;
    newn = new struct DoublyCLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    int iCnt = 0;

    struct DoublyCLLnode<T> *temp = NULL;
    
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
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
       delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        
    }
    last->next = first;
    first->prev = last;
    this->iCount--;
}
template<class T>
void DoublyCLL<T> :: DeleteLast()
{
   
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
       last = last->prev;
       delete last->next;
    }
    last->next = first;
    first->prev = last;
    this->iCount--;
}
template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    struct DoublyCLLnode<T> *temp = NULL;
    
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
   
    DoublyCLL<int> obj;
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