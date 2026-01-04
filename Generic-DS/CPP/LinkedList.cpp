#include<iostream>
using namespace std;


//structures


template<class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode *next;
};

template <class T>
struct DoublyLLLnode
{
    T data;
    struct DoublyLLLnode *next;
    struct DoublyLLLnode *prev;
};

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode *next;
};

template<class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode *next;
    struct DoublyCLLnode *prev;
};

//Classes


template <class T>
class SinglyLLL
{
    private:
        struct SinglyLLLnode<T> *first;
        int iCount;
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
class DoublyLLL
{
    private:
        struct DoublyLLLnode<T> *first;
        int iCount;
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
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> *first;
        int iCount;
    public:
        SinglyCLL();
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
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> *first;
        int iCount;
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

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    this->first = NULL;
    this->iCount = 0;
}
template <class T>
void SinglyLLL<T> :: Display()
{
    struct SinglyLLLnode<T> *temp = NULL;
    temp = this->first;
    cout<<"\n";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}
template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    struct SinglyLLLnode<T> *newn = NULL;
    newn = new SinglyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->iCount++;
}
template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    struct SinglyLLLnode<T> *newn = NULL;
    struct SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        
    }
    this->iCount++;
}
template <class T>
void SinglyLLL<T> :: InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    struct SinglyLLLnode<T> *newn = NULL;
    struct SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"\nInvlaid Position \n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = first;
        for(iCnt = 1;iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}
template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    struct SinglyLLLnode<T> *temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }
    this->iCount--;
}
template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    struct SinglyLLLnode<T> *temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        
    }
    this->iCount--;
}
template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
   
    struct SinglyLLLnode<T> *temp = NULL;
    struct SinglyLLLnode<T> *target = NULL;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"\nInvlaid Position \n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = first;
        for(iCnt = 1;iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}


template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    this->first = NULL;
    this->iCount = 0;
}
template<class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}
template <class T>
void SinglyCLL<T> :: InsertFirst(T no)
{

}
template <class T>
void SinglyCLL<T> :: InsertLast(T no)
{

}
template <class T>
void SinglyCLL<T> :: InsertAtPos(T no,int pos)
{

}
template <class T>
void SinglyCLL<T> :: DeleteFirst()
{

}
template <class T>
void SinglyCLL<T> :: DeleteLast()
{

}
template <class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{

}
int main()
{
    SinglyLLL<int> SinglyLLLObj;
    DoublyLLL<int> DoublyLLLObj;
    SinglyCLL<int> SinglyCLLObj;
    DoublyCLL<int> DoublyCLLObj;
    
cout<<"SinglyLLL : \n\n";
    SinglyLLLObj.InsertFirst(51);
    SinglyLLLObj.InsertFirst(21);
    SinglyLLLObj.InsertFirst(11);
    SinglyLLLObj.Display();
    cout<<"Element : "<<SinglyLLLObj.Count();

    SinglyLLLObj.InsertLast(101);
    SinglyLLLObj.InsertLast(111);
    SinglyLLLObj.InsertLast(121);
    SinglyLLLObj.Display();
    cout<<"Element : "<<SinglyLLLObj.Count();

    SinglyLLLObj.InsertAtPos(105,5);
    SinglyLLLObj.Display();
    cout<<"Element : "<<SinglyLLLObj.Count();

    SinglyLLLObj.DeleteFirst();
    SinglyLLLObj.Display();
    cout<<"Element : "<<SinglyLLLObj.Count();

    SinglyLLLObj.DeleteLast();
    SinglyLLLObj.Display();
    cout<<"Element : "<<SinglyLLLObj.Count();

    SinglyLLLObj.DeleteAtPos(3);
    SinglyLLLObj.Display();
    cout<<"Element : "<<SinglyLLLObj.Count();
    
    return 0;
}