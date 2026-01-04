#include<iostream>
using namespace std;
template< class T >
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T> *next;
};
template <class T>
class SinglyLLL
{
    private:
        struct SinglyLLLnode<T> *first;
        int iCount ;
    public:

    SinglyLLL();
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
    SinglyLLL<T>:: SinglyLLL()
    {
        this->first = NULL;
        this->iCount = 0;
    }

template<class T>
    void SinglyLLL<T> :: InsertFirst(T no)
    {
        struct SinglyLLLnode<T> *newn;
        newn = new struct SinglyLLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        this->iCount++;
    }
template<class T>
    void  SinglyLLL<T> :: Display()
    {
        struct SinglyLLLnode<T> *temp = NULL;
        temp = first;
        cout<<"\n";
        while (temp!= NULL)
        {
            cout<<"| "<<temp->data<<"| ->";
            temp = temp->next;
        }
        cout<<"NULL\n";
        
    }
template<class T>
    int SinglyLLL<T> :: Count()
    {
        return iCount;
    }
template<class M>
void SinglyLLL<M> :: InsertLast(M no)
{
    struct SinglyLLLnode<M> *newn = NULL;
    newn = new struct SinglyLLLnode<M>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        struct SinglyLLLnode<M> *temp;
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newn;
    }
    this->iCount++;

}
template<class T>
void SinglyLLL<T>  :: InsertAtPos(T no,int pos)
{
    struct SinglyLLLnode<T> *newn = NULL;
    newn = new struct SinglyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    int iCnt = 0;

    struct SinglyLLLnode<T> *temp = NULL;
    
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
        temp->next = newn;
        this->iCount++;
    }
}
template<class T>
void SinglyLLL<T> :: DeleteFirst()
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
        struct SinglyLLLnode<T> *temp = NULL;
        temp = first;
        first = first->next;
        delete temp;
    }
    this->iCount--;
}
template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    struct SinglyLLLnode<T> *temp = NULL;
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
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    struct SinglyLLLnode<T> *temp = NULL;
    struct SinglyLLLnode<T> *target = NULL;
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invlaid Position : \n";
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
        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
    
}
int main()
{
   
    SinglyLLL<int> obj;
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