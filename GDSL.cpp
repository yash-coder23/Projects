#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

         T Addition();
         int EvenCount();
         int OddCount();
         bool Search(T No);
         int SearchFirstOccurence(T No);
         int SearchLastOccurence(T No);
         void SumDigits();
         void SumFactors();
         bool ChkPerfect(T iNo);
         void Displayperfect();
         T MiddleElement();
         T MiddleElementX();
         bool CheckLoop();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

template <class T>
T SinglyLL<T> :: Addition()
{
      T iSum = 0;
     struct nodeSL<T> * temp = First;

    while(temp!=NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }
    return iSum;
}

template <class T>
int SinglyLL <T> :: EvenCount()
{
  int iCount = 0;
  struct nodeSL<T> * temp = First;

  while(temp!=NULL)
  {
    if((temp->data)%2==0)
    {
      iCount++;
    }
    temp= temp->next;
  }
  return iCount;
  
}
template <class T>
int SinglyLL <T>:: OddCount()
{
  int iCount = 0;
 struct nodeSL<T> * temp = First;

  while(temp!=NULL)
  {
    if((temp->data)%2==1)
    {
      iCount++;
    }
    temp= temp->next;
  }
  return iCount;
  
}

template <class T>
bool SinglyLL <T> :: Search(T No)
{
  bool bFlag = false;
 struct nodeSL<T> * temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      bFlag=true;
      break;
    }
    temp= temp->next;
  }
  return bFlag;
}

template <class T>
int SinglyLL <T> :: SearchFirstOccurence(T No)
{
  int iPos = -1;
  int iCount = 1;
 struct nodeSL<T> * temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      iPos=iCount;
      break;
    }
    iCount++;
    temp = temp->next;
  }
  return iPos;

} 

template <class T>
int SinglyLL <T> :: SearchLastOccurence(T No)
{
  int iPos = -1;
  int iCount = 1;

  struct nodeSL<T> *temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      iPos = iCount;

    }
    iCount++;
    temp = temp->next;
  }
  return iPos;
}

template <class T>
void SinglyLL <T>:: SumDigits()
{
  struct nodeSL<T> *temp = First;
  T Digit = 0;
  T No = 0;
  T Sum = 0;
  

  while (temp!=NULL)
  {
    No = temp->data;

    while (No!=0)
    {
     Digit = No % 10;
     Sum = Sum + Digit;
     No = No/10;
    }
    cout<<Sum<<"\n";
    Sum = 0;

    temp = temp->next; 
  }
  
}

template <class T>
void SinglyLL <T> :: SumFactors()
{
  int i = 0;
  T Sum = 0;
  T No = 0;

 struct nodeSL<T> * temp = First;

  while(temp!=NULL)
  {
    No = temp->data;

    for(i=1;i<=No;i++)
    {
      if(No%i==0)
      {
        Sum = Sum +i; 
      }
    }
    cout<<Sum<<endl;
    Sum = 0;

    temp = temp -> next;
  }
}

template <class T>
bool SinglyLL <T>:: ChkPerfect(T No)
{
  T Sum = 0;
  int i = 0;

  for(i=1;i<=No/2;i++);
  {
    if(No % i == 0)
    {
      Sum = Sum + i;
    }
  }
  if(Sum==No)
  {
      return true;
  }
  else
  {
     return false;
  }
}

template <class T>
void SinglyLL <T> :: Displayperfect()
{
  struct nodeSL<T>* temp = First;
  
  while(temp!=NULL)
  {
    if(ChkPerfect(temp->data)==true)
    {
      cout<<"Perfect Number from LL is"<<temp->data<<endl;
    }
    temp = temp -> next;
  }
}

template <class T>
T SinglyLL <T> :: MiddleElement()
{
   int iCnt = 0;
   int iPos = 0 , i =0;
  struct nodeSL<T> * temp = First;

   while(temp!=NULL)
   {
      iCnt++;
      temp = temp ->next;
   }
   iPos = iCnt / 2;
   for(i=1;i<=iPos;i++)
   {
    First = First->next;
   }
   return First->data;

}

template <class T>
T SinglyLL <T> :: MiddleElementX()
{
  struct nodeSL<T> * temp =First;
   struct nodeSL<T> * Teacher = temp;
   struct nodeSL<T> * Student = temp;

    while((Teacher != NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }
    return (Student->data);
}

template <class T>
bool SinglyLL <T>:: CheckLoop()
{
    struct nodeSL<T> * temp = First;
    struct nodeSL<T> *Teacher = temp;
   struct nodeSL<T> *Student = temp;
    bool bFlag = false;

    while((Teacher != NULL) && (Teacher->next != NULL))
    {
        Teacher = Teacher->next->next;

        if(Teacher == Student)
        {
            bFlag = true;
            break;
        }
        
        Student = Student->next;

        if(Teacher == Student)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        
       T Addition();
       int EvenCount();
       int OddCount();
       bool Search(T No);
       int SearchFirstOccurence(T No);
       int SearchLastOccurence(T No);
       void SumDigits();
       void SumFactors();
       bool ChkPerfect(T iNo);
       void Displayperfect();
       T MiddleElement();
       T MiddleElementX();
       bool CheckLoop();
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

template <class T>
T DoublyCL<T> :: Addition()
{
      T Sum = 0;
     struct nodeDC<T> * temp = First;

    while(temp!=NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }
    return Sum;
}

template <class T>
int DoublyCL <T> :: EvenCount()
{
  int iCount = 0;
  struct nodeDC<T> * temp = First;

  while(temp!=NULL)
  {
    if((temp->data)%2==0)
    {
      iCount++;
    }
    temp= temp->next;
  }
  return iCount;
  
}
template <class T>
int DoublyCL <T>:: OddCount()
{
  int iCount = 0;
 struct nodeDC<T> * temp = First;

  while(temp!=NULL)
  {
    if((temp->data)%2==1)
    {
      iCount++;
    }
    temp= temp->next;
  }
  return iCount;
  
}

template <class T>
bool DoublyCL <T> :: Search(T No)
{
  bool bFlag = false;
 struct nodeDC<T> * temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      bFlag=true;
      break;
    }
    temp= temp->next;
  }
  return bFlag;
}

template <class T>
int DoublyCL <T> :: SearchFirstOccurence(T No)
{
  int iPos = -1;
  int iCount = 1;
 struct nodeDC<T> * temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      iPos=iCount;
      break;
    }
    iCount++;
    temp = temp->next;
  }
  return iPos;

} 

template <class T>
int DoublyCL <T> :: SearchLastOccurence(T No)
{
  int iPos = -1;
  int iCount = 1;

  struct nodeDC<T> *temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      iPos = iCount;

    }
    iCount++;
    temp = temp->next;
  }
  return iPos;
}

template <class T>
void DoublyCL <T>:: SumDigits()
{
  struct nodeDC<T> *temp = First;
  T Digit = 0;
  T No = 0;
  T Sum = 0;
  

  while (temp!=NULL)
  {
    No = temp->data;

    while (No!=0)
    {
     Digit = No % 10;
     Sum = Sum + Digit;
     No = No/10;
    }
    cout<<Sum<<"\n";
   Sum = 0;

    temp = temp->next; 
  }
  
}

template <class T>
void DoublyCL <T> :: SumFactors()
{
   int i = 0;
   T Sum = 0 ;
   T No = 0;

 struct nodeDC<T> * temp = First;

  while(temp!=NULL)
  {
    No = temp->data;

    for(i=1;i<=No;i++)
    {
      if(No%i==0)
      {
        Sum = Sum +i; 
      }
    }
    cout<<Sum<<endl;
    Sum = 0;

    temp = temp -> next;
  }
}

template <class T>
bool DoublyCL <T>:: ChkPerfect(T No)
{
  T Sum = 0;
  int i = 0;

  for(i=1;i<=No/2;i++);
  {
    if(No % i == 0)
    {
      Sum = Sum + i;
    }
  }
  if(Sum==No)
  {
      return true;
  }
  else
  {
     return false;
  }
}

template <class T>
void DoublyCL <T> :: Displayperfect()
{
  struct nodeDC<T>* temp = First;
  
  while(temp!=NULL)
  {
    if(ChkPerfect(temp->data)==true)
    {
      cout<<"Perfect Number from LL is"<<temp->data<<endl;
    }
    temp = temp -> next;
  }
}

template <class T>
T DoublyCL <T> :: MiddleElement()
{
   int iCnt = 0;
   int iPos = 0 , i =0;
  struct nodeDC<T> * temp = First;

   while(temp!=NULL)
   {
      iCnt++;
      temp = temp ->next;
   }
   iPos = iCnt / 2;
   for(i=1;i<=iPos;i++)
   {
    First = First->next;
   }
   return First->data;

}

template <class T>
T DoublyCL <T> :: MiddleElementX()
{
  struct nodeDC<T> * temp =First;
   struct nodeDC<T> * Teacher = temp;
   struct nodeDC<T> * Student = temp;

    while((Teacher != NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }
    return (Student->data);
}

template <class T>
bool DoublyCL <T>:: CheckLoop()
{
    struct nodeDC<T> * temp = First;
    struct nodeDC<T> *Teacher = temp;
    struct nodeDC<T> *Student = temp;
    bool bFlag = false;

    while((Teacher != NULL) && (Teacher->next != NULL))
    {
        Teacher = Teacher->next->next;

        if(Teacher == Student)
        {
            bFlag = true;
            break;
        }
        
        Student = Student->next;

        if(Teacher == Student)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}


/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////

    
template<class T>
struct nodeDL
{
  T data;
  struct nodeDL *next;
  struct nodeDL *prev;
};

template<class T>
class DoublyLL
{
  private:
  struct nodeDL <T>* First;
  int iCount;

  public:
  DoublyLL();
  void Display();
  int Count();

  void InsertFirst(T No);
  void InsertLast(T No);
  void InsertAtPos(int Pos, T No);

  void DeleteFirst();
  void DeleteLast();
  void DeleteAtPos(int Pos);

   T Addition();
   int EvenCount();
   int OddCount();
   bool Search(T No);
   int SearchFirstOccurence(T No);
   int SearchLastOccurence(T No);
   void SumDigits();
  
  void SumFactors();
  bool ChkPerfect(T iNo);
  void Displayperfect();
  T MiddleElement();
  T MiddleElementX();
  bool CheckLoop();

};

template<class T>
DoublyLL <T> :: DoublyLL()
{
  First = NULL;
  iCount = 0;
}

template<class T>
void DoublyLL<T> :: Display()
{
  struct nodeDL <T>*  temp = First;
  cout<<" NULL";
  while(temp!=NULL)
  {
    cout<<"|<=>"<<temp->data<<"|<=>|";
    temp = temp ->next;
  }
  cout<<"NULL\n";
}

template<class T>
int DoublyLL<T>:: Count()
{
   return iCount;
}

template<class T>
void DoublyLL <T>:: InsertFirst(T No)
{
   struct nodeDL <T>*  newn = NULL;

  newn = new nodeDL<T>;

  newn->data=No;
  newn->next = NULL;
  newn->prev = NULL;

  if(First ==NULL)
  {
    First = newn;
  }
  else
  {
    newn->next=First;
    First->prev = newn;
    First= newn;
  }
  iCount++;

}

template<class T>
void DoublyLL <T> :: InsertLast(T No)
{
  struct nodeDL <T>*  newn = NULL;

  newn = new nodeDL<T>;

  newn->data=No;
  newn->next = NULL;
  newn->prev = NULL;

  if(First ==NULL)
  {
    First = newn;
  }
  else
  {
    struct nodeDL <T>* temp = NULL;
    temp =First;

    while(temp->next!=NULL)
    {
      temp = temp->next;
    }
    temp->next = newn;
    newn->prev= temp;
  }
  iCount++;
}

template<class T>
 void DoublyLL<T> :: InsertAtPos(int Pos, T No)
 {
  int i = 0;
  struct nodeDL <T>*  newn = NULL;
   struct nodeDL <T>* temp = NULL;

   if((Pos<1) && (Pos>iCount+1))
   {
    cout<<"Unable to insert at Position"<<endl;
    return;
   }
   else if(Pos==1)
   {
    InsertFirst(No);
   }
   else if(Pos==(iCount+1))
   {
    InsertLast(No);
   }
   else
   {
    temp = First;
    
    newn = new nodeDL<T>;
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;

    for(i=1;i<Pos-1;i++)
    {
      temp = temp->next;
    }
    newn->next = temp->next;
    temp->next->prev=newn;
    temp->next= newn;
    newn->prev= temp;

   }
   iCount++;
 }
  template <class T>
 void DoublyLL <T> :: DeleteFirst()
 {
   if(First==NULL)
   {
    return;
   }
   else if(First->next==NULL)
   {
    delete(First);
    First=NULL;
   }
   else
   {
    First = First->next;
    delete(First->prev);
    First->prev=NULL;
   }
   iCount--;
 }

template<class T>
 void DoublyLL <T> :: DeleteLast()
 {
     if(First==NULL)
   {
    return;
   }
   else if(First->next==NULL)
   {
    delete(First);
    First=NULL;
   }
   else
   {
     struct nodeDL <T>* temp = NULL;
     temp=First;

     while(temp->next->next!=NULL)
     {
      temp = temp->next;
     }
     delete(temp->next);
     temp->next=NULL;
     
   }
   iCount--;
 }

 template<class T>
 void DoublyLL <T>:: DeleteAtPos(int Pos)
 {
  if((Pos<1) && (Pos>iCount))
  {
    cout<<"Unable to delete at Position"<<endl;
    return;
  }
  else if(Pos==1)
  {
    DeleteFirst();
  }
  else if(Pos==iCount)
  {
    DeleteLast();
  }
  else
  {
    int i = 0;
    struct nodeDL <T>* temp = NULL;
    temp = First;
    for(i=1;i<Pos-1;i++)
    {
      temp = temp->next;
    }
    temp->next=temp->next->next;
    delete(temp->next->prev);
    temp->next->prev=temp;

  }
  iCount--;
 }

template <class T>
T DoublyLL<T> :: Addition()
{
      T Sum = 0;
     struct nodeDL<T> * temp = First;

    while(temp!=NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }
    return Sum;
}

template <class T>
int DoublyLL <T> :: EvenCount()
{
  int iCount = 0;
  struct nodeDL<T> * temp = First;

  while(temp!=NULL)
  {
    if((temp->data)%2==0)
    {
      iCount++;
    }
    temp= temp->next;
  }
  return iCount;
  
}
template <class T>
int DoublyLL <T>:: OddCount()
{
  int iCount = 0;
 struct nodeDL<T> * temp = First;

  while(temp!=NULL)
  {
    if((temp->data)%2==1)
    {
      iCount++;
    }
    temp= temp->next;
  }
  return iCount;
  
}

template <class T>
bool DoublyLL <T> :: Search(T No)
{
  bool bFlag = false;
 struct nodeDL<T> * temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      bFlag=true;
      break;
    }
    temp= temp->next;
  }
  return bFlag;
}

template <class T>
int DoublyLL <T> :: SearchFirstOccurence(T No)
{
  int iPos = -1;
  int iCount = 1;
 struct nodeDL<T> * temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      iPos=iCount;
      break;
    }
    iCount++;
    temp = temp->next;
  }
  return iPos;

} 

template <class T>
int DoublyLL <T> :: SearchLastOccurence(T No)
{
  int iPos = -1;
  int iCount = 1;

  struct nodeDL<T> *temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      iPos = iCount;

    }
    iCount++;
    temp = temp->next;
  }
  return iPos;
}

template <class T>
void DoublyLL <T>:: SumDigits()
{
  struct nodeDL<T> *temp = First;
  T Digit = 0;
  T No = 0;
  T Sum = 0;
  

  while (temp!=NULL)
  {
    No = temp->data;

    while (No!=0)
    {
     Digit = No % 10;
     Sum = Sum + Digit;
     No = No/10;
    }
    cout<<Sum<<"\n";
   Sum = 0;

    temp = temp->next; 
  }
  
}

template <class T>
void DoublyLL <T> :: SumFactors()
{
   int i = 0;
   T Sum = 0 ;
   T No = 0;

 struct nodeDL<T> * temp = First;

  while(temp!=NULL)
  {
    No = temp->data;

    for(i=1;i<=No;i++)
    {
      if(No%i==0)
      {
        Sum = Sum +i; 
      }
    }
    cout<<Sum<<endl;
    Sum = 0;

    temp = temp -> next;
  }
}

template <class T>
bool DoublyLL <T>:: ChkPerfect(T No)
{
  T Sum = 0;
  int i = 0;

  for(i=1;i<=No/2;i++);
  {
    if(No % i == 0)
    {
      Sum = Sum + i;
    }
  }
  if(Sum==No)
  {
      return true;
  }
  else
  {
     return false;
  }
}

template <class T>
void DoublyLL <T> :: Displayperfect()
{
  struct nodeDL<T>* temp = First;
  
  while(temp!=NULL)
  {
    if(ChkPerfect(temp->data)==true)
    {
      cout<<"Perfect Number from LL is"<<temp->data<<endl;
    }
    temp = temp -> next;
  }
}

template <class T>
T DoublyLL <T> :: MiddleElement()
{
   int iCnt = 0;
   int iPos = 0 , i =0;
  struct nodeDL<T> * temp = First;

   while(temp!=NULL)
   {
      iCnt++;
      temp = temp ->next;
   }
   iPos = iCnt / 2;
   for(i=1;i<=iPos;i++)
   {
    First = First->next;
   }
   return First->data;

}

template <class T>
T DoublyLL <T> :: MiddleElementX()
{
  struct nodeDL<T> * temp =First;
   struct nodeDL<T> * Teacher = temp;
   struct nodeDL<T> * Student = temp;

    while((Teacher != NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }
    return (Student->data);
}

template <class T>
bool DoublyLL <T>:: CheckLoop()
{
    struct nodeDL<T> * temp = First;
    struct nodeDL<T> *Teacher = temp;
    struct nodeDL<T> *Student = temp;
    bool bFlag = false;

    while((Teacher != NULL) && (Teacher->next != NULL))
    {
        Teacher = Teacher->next->next;

        if(Teacher == Student)
        {
            bFlag = true;
            break;
        }
        
        Student = Student->next;

        if(Teacher == Student)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

   
template<class T>
struct nodeSC
{
  T data;
  struct nodeSC* next;
};


template<class T>
class SinglyCL
{
  private:
  struct nodeSC<T>* First;
  struct nodeSC<T>* Last;
  int iCount;
 
 public:
  SinglyCL();
  void Display();
  int Count();

  void InsertFirst(T No);
  void InsertLast(T No);
  void InsertAtPos(int Pos, T No);

  void DeleteFirst();
  void DeleteLast();
  void DeleteAtPos(int Pos);

   T Addition();
  int EvenCount();
  int OddCount();
  bool Search(T No);
  int SearchFirstOccurence(T No);
  int SearchLastOccurence(T No);
  void SumDigits();
  void SumFactors();
  bool ChkPerfect(T iNo);
  void Displayperfect();
  T MiddleElement();
  T MiddleElementX();
  bool CheckLoop();

};
template<class T>
SinglyCL <T>:: SinglyCL()
{
  First = NULL;
  Last = NULL;
  iCount = 0;
}
template<class T>
void SinglyCL <T>:: Display()
{
 if((First==NULL)&&(Last==NULL))
 {
  cout<<"Linked list is empty"<<endl;
  return;
 }
 cout<<"<->";
 do
 {
  cout<<"|"<<First->data<<"|<->";
  First = First->next;
 } while(Last->next!=First);
 cout<<"\n";
 
}

template<class T>
int SinglyCL<T> :: Count()
{
  return iCount;
}

template<class T>
void SinglyCL <T> :: InsertFirst(T No)
{
  struct nodeSC<T>* newn = NULL;

  newn = new nodeSC<T>;
  newn->data = No;
  newn ->next= NULL;

  if((First== NULL)&&(Last==NULL))
  {
     First = newn;
     Last = newn;
     
  }
  else
  {
    newn->next = First;
    First = newn;
  }
  Last->next = First;

  iCount++;
}


template<class T>
void SinglyCL <T> :: InsertLast(T No)
{
  struct nodeSC <T>* newn = NULL;
  newn = new nodeSC<T>;

  newn->data=No;
  newn->next=NULL;

  if((First==NULL) && (Last==NULL))
  {
    First = newn;
    Last = newn;
    
  }
  else
  {
    Last->next= newn;
    Last= newn;
  }
  Last->next = First;

  iCount++;

}

template<class T>
void SinglyCL <T> :: InsertAtPos(int Pos, T No)
{
  
    struct nodeSC<T>* newn = newn;
    struct nodeSC<T>* temp = NULL;
    int i = 0;

  if((1<Pos) && (Pos>iCount+1))
  {
    cout<<"Unable to insert\n";
    return;
  }
  else if(Pos==1)
  {
    InsertFirst(No);
  }
  else if(Pos==(iCount+1))
  {
    InsertLast(No);
  }
  else
  {
    newn = new nodeSC<T>;
    
    newn->data = No;
    newn->next=NULL;

    temp = First;

    for(i=1;i<Pos-1;i++)
    {
      temp = temp->next;
    }
    newn->next = temp->next;
    temp->next = newn;
  }
  iCount++;
}

template<class T>
void SinglyCL<T> :: DeleteFirst()
{
  if((First==NULL)&& (Last==NULL))
  {
    return;
  }
  else if(First==Last)
  {
    delete First;
    First =NULL;
  }
  else
  {
    First = First->next;
    delete(Last->next);
    Last->next = First;
  }
  iCount--;
}

template <class T>
void SinglyCL <T> :: DeleteLast()
{
  if((First==NULL) && (Last==NULL))
  {
    return;
  }
  else if(First==Last)
  {
    delete First;
    First =NULL;
  }
  else
  {
    struct nodeSC<T>* temp = NULL;
     temp = First;

     while(temp->next!=Last)
     {
       temp = temp->next;
     }
     delete Last;
     Last = temp;
     Last->next = First;
 
}
  iCount--;
}

template <class T>
void SinglyCL <T> :: DeleteAtPos(int Pos)
{
    struct nodeSC<T>* temp1 = NULL;
      struct nodeSC<T>* temp2 = NULL;
    int i = 0;

  if((1<Pos) && (Pos>iCount))
  {
    cout<<"Unable to insert\n";
    return;
  }
  else if(Pos==1)
  {
    DeleteFirst();
  }
  else if(Pos==iCount)
  {
    DeleteLast();
  }
  else
  {
     temp1 = First;

        for(i = 1; i < Pos -1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1 -> next = temp2->next;
        delete(temp2);
  }
  iCount--;
}


template <class T>
T SinglyCL<T> :: Addition()
{
      int iSum = 0;
     struct nodeSC<T> * temp = First;

    while(temp!=NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }
    return iSum;
}

template <class T>
int SinglyCL <T> :: EvenCount()
{
  int iCount = 0;
  struct nodeSC<T> * temp = First;

  while(temp!=NULL)
  {
    if((temp->data)%2==0)
    {
      iCount++;
    }
    temp= temp->next;
  }
  return iCount;
  
}
template <class T>
int SinglyCL <T>:: OddCount()
{
  int iCount = 0;
 struct nodeSC<T> * temp = First;

  while(temp!=NULL)
  {
    if((temp->data)%2==1)
    {
      iCount++;
    }
    temp= temp->next;
  }
  return iCount;
  
}

template <class T>
bool SinglyCL <T> :: Search(T No)
{
  bool bFlag = false;
 struct nodeSC<T> * temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      bFlag=true;
      break;
    }
    temp= temp->next;
  }
  return bFlag;
}

template <class T>
int SinglyCL <T> :: SearchFirstOccurence(T No)
{
  int iPos = -1;
  int iCount = 1;
 struct nodeSC<T> * temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      iPos=iCount;
      break;
    }
    iCount++;
    temp = temp->next;
  }
  return iPos;

} 

template <class T>
int SinglyCL <T> :: SearchLastOccurence(T No)
{
  int iPos = -1;
  int iCount = 1;

  struct nodeSC<T> *temp = First;

  while(temp!=NULL)
  {
    if(temp->data==No)
    {
      iPos = iCount;

    }
    iCount++;
    temp = temp->next;
  }
  return iPos;
}

template <class T>
void SinglyCL <T>:: SumDigits()
{
  struct nodeSC<T> *temp = First;
  int iDigit = 0;
  int iNo = 0;
  int iSum = 0;
  
  while(temp!=NULL)
  {
    iNo = temp->data;

    while (iNo!=0)
    {
     iDigit = iNo % 10;
     iSum = iSum + iDigit;
     iNo = iNo/10;
    }
    cout<<iSum<<"\n";
    iSum = 0;

    temp = temp->next; 
  }
  
}

template <class T>
void SinglyCL <T> :: SumFactors()
{
  int i = 0, iSum = 0 , iNo = 0;

 struct nodeSC<T> * temp = First;

  while(temp!=NULL)
  {
    iNo = temp->data;

    for(i=1;i<=iNo;i++)
    {
      if(iNo%i==0)
      {
        iSum = iSum +i; 
      }
    }
    cout<<iSum<<endl;
    iSum = 0;

    temp = temp -> next;
  }
}

template <class T>
bool SinglyCL <T>:: ChkPerfect(T iNo)
{
  int iSum = 0;
  int i = 0;

  for(i=1;i<=iNo/2;i++);
  {
    if(iNo % i == 0)
    {
      iSum = iSum + i;
    }
  }
  if(iSum==iNo)
  {
      return true;
  }
  else
  {
     return false;
  }
}

template <class T>
void SinglyCL <T> :: Displayperfect()
{
  struct nodeSC<T>* temp = First;
  
  while(temp!=NULL)
  {
    if(ChkPerfect(temp->data)==true)
    {
      cout<<"Perfect Number from LL is"<<temp->data<<endl;
    }
    temp = temp -> next;
  }
}

template <class T>
T SinglyCL <T> :: MiddleElement()
{
   int iCnt = 0;
   int iPos = 0 , i =0;
  struct nodeSC<T> * temp = First;

   while(temp!=NULL)
   {
      iCnt++;
      temp = temp ->next;
   }
   iPos = iCnt / 2;
   for(i=1;i<=iPos;i++)
   {
    First = First->next;
   }
   return First->data;

}

template <class T>
T SinglyCL <T> :: MiddleElementX()
{
  struct nodeSC<T> * temp =First;
   struct nodeSC<T> * Teacher = temp;
   struct nodeSC<T> * Student = temp;

    while((Teacher != NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }
    return (Student->data);
}

template <class T>
bool SinglyCL <T>:: CheckLoop()
{
    struct nodeSC<T> * temp = First;
    struct nodeSC<T> *Teacher = temp;
    struct nodeSC<T> *Student = temp;
    bool bFlag = false;

    while((Teacher != NULL) && (Teacher->next != NULL))
    {
        Teacher = Teacher->next->next;

        if(Teacher == Student)
        {
            bFlag = true;
            break;
        }
        
        Student = Student->next;

        if(Teacher == Student)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeS
{
  T data;
  struct nodeS *next;
};
template<class T>

class Stack
{
  private:
  struct nodeS<T>*First;
  int iCount;
  
  public:
  Stack();
  void Display();
  int Count();

  void Push(T No);
  int Pop();

};

template<class T>
Stack<T> :: Stack()
{
  First =NULL;
  iCount =0;
}

template<class T>
void Stack <T>:: Display()
{
struct nodeS <T>*temp =NULL;
 temp = First;

 while(temp!=NULL)
 {
  cout<<temp->data<<endl;
  temp = temp->next;
 }
}

template<class T>
int Stack <T>:: Count()
{
  return iCount;
}

template<class T>
void Stack <T> :: Push(T No)
{
 struct nodeS<T>* newn = NULL;
 newn = new nodeS<T>;

  newn->data=No;
  newn->next=NULL;

  if(First==NULL)
  {
    First=newn;
  }
  else
  {
    newn->next=First;
    First=newn;
  }
  iCount++;
}

template<class T>
int Stack<T> :: Pop()
{
  int iValue = 0;

  if(First==NULL)
  {
    cout<<"Unable to pop the element as stack is empty\n";
    return -1;
  }
  else
  {
    struct nodeS<T> * temp = NULL;
    temp = First;

    iValue=First->data;
    First= First->next;
    delete(temp);

   iCount--;
  }
  return iValue;

}


/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

    
template<class T>
struct nodeQ
{
  T data;
  struct nodeQ *next;
};



template<class T>
class Queue
{
  private:
  struct nodeQ<T> * First;
  int iCount;

public:
 Queue();
 void Display();
 int Count();

 void EnQueue(T No);
 int DeQueue();
};

template<class T>
Queue <T> :: Queue()
{
  First = NULL;
  iCount = 0;
}

template<class T>
void Queue<T> :: Display()
{
 struct nodeQ<T>* temp = NULL;
 temp = First;

 while(temp!=NULL)
 {
  cout<<temp->data<<endl;
  temp = temp->next;
 }
}

template<class T>
int Queue<T> :: Count()
{
  return iCount;
}

template<class T>
void Queue <T>:: EnQueue(T No)
{
 struct nodeQ<T> *newn = NULL;

 newn = new nodeQ<T>;

 newn->data =No;
 newn->next=NULL;

 if(First==NULL)
 {
  First =newn;
 }
 else
 {
  struct nodeQ<T> *temp =NULL;
  temp =First;

  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next=newn;
 }
 iCount++;

}

template<class T>
int Queue<T> :: DeQueue()
{
  int iValue = 0;

 if(First==NULL)
 {
   cout<<"Unable to remove the element as queue is empty\n";
  return -1;
 }
 else
 {
  struct nodeQ<T> *temp = NULL;
  temp = First;
  

  iValue = First->data;
  First= First->next;
  delete(temp);

  iCount--;
 }
 return iValue;
 
}
/////////////////////////////////////////////////////////////
//
// Code of Searching & Sorting
//
/////////////////////////////////////////////////////////////


template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int Value);
        ~ArrayX();

        void Accept();
        void Display();
        
        bool LinearSearch(T Value);
        bool BiDirectionalSearch(T Value);
        bool BinarySearch(T Value);

        void BubbleSort();
        void BubbleSortEfficient();

        void SelectionSort();

        void InsertionSort();
};

template <class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void ArrayX<T>::Display()
{
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
}

template <class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BiDirectionalSearch(T Value)
{
    int iStart = 0, iEnd = 0;
    bool flag = false;

    for(iStart = 0, iEnd = iSize-1; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
                flag = true;
                break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BinarySearch(T Value)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool flag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == Value) || (Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
        else if(Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if(Value > Arr[iMid])
        {
            iEnd = iMid -1;
        }
    }

    return flag;
}

template <class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    //     1        2      3  
    for(i = 0; i < iSize -1; i++)  // Outer
    {   //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}   

template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    //     1        2      3  
    for(i = 0; (i < iSize -1) && (flag == true) ; i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
    
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

template <class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize -1; i++)
    {
        min_index = i;

        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}  

template <class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i =1 ; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}  


/////////////////////////////////////////////////////////////
//
// Code of Binary Search Tree
//
/////////////////////////////////////////////////////////////


template<class T>
struct node
{
  terminate_handler data;
  struct node *lchild;
  struct node *rchild;
};

template<class T>
class Tree
{
  public:
  struct node<T>*Root;

  Tree();
  void Insert(T No);
  void Inorder(struct node<T>*Root);
  void Preorder(struct node<T>*Root);
  void Postorder(struct node<T>*Root);
  void Display();

  bool Search(T No);

  
};

template <class T>
 Tree <T> :: Tree()
  {
    Root = NULL;
  }

  template <class T>
  void Tree <T> :: Insert(T No)
  {
    struct node<T>*newn = NULL;
    struct node<T>*temp = NULL;

    newn = new node<T>;

    newn->data = No;
    newn->rchild = NULL;
    newn->lchild = NULL;

    if(Root == NULL)
    {
      Root = newn;
    }
    else
    {
      temp=Root;

      while(1)
      {
        
        if((temp->data)==No)
        {
          delete(newn);
          break;
        }
        else if(No>temp->data)
        {
          if(temp->rchild==NULL)
          {
            temp->rchild=newn;
            break;
          }
          temp = temp->rchild;
        }
        else if(No<temp->data)
        {
          if(temp->lchild==NULL)
          {
            temp->lchild=newn;
            break;
          }
          temp = temp->lchild;
        }
      }
    }
  }
  template <class T>
  void Tree <T> :: Inorder(struct node<T>*Root)
  {
    struct node<T>*temp = Root;
    if(temp!=NULL)
    {
    Inorder(temp->lchild);
    cout<<temp->data<<endl;
    Inorder(temp->rchild);
  }
  }

  template <class T>
  void Tree <T> :: Preorder(struct node<T>*Root)
  {
   struct node<T>*temp = Root;
    if(temp!=NULL)
    {
       cout<<temp->data<<endl;
       Preorder(temp->lchild);
       Preorder(temp->rchild);
    }
  }

  template <class T>
  void Tree <T> :: Postorder(struct node<T>*Root)
  {
     struct node<T>*temp = Root;
    if(temp!=NULL)
    {
       Postorder(temp->lchild);
       Postorder(temp->rchild);
       cout<<temp->data<<endl;
    }
  }

  template <class T>
  bool Tree <T> :: Search(T No)
  {
    bool Flag = false;
    if(Root==NULL)
    {
      cout<<"Tree is Empty";
      return Flag;
    }

    while(Root!=NULL)
    {
      if(Root->data==No)
      {
        Flag = true;
        break;
      }
      else if(No>Root->data)
      {
        Root = Root->rchild;
      }
      else if(No<Root->data)
      {
        Root = Root->lchild;
      }
    }
    return Flag;
  }
  template <class T>
  void Tree <T> :: Display()
  {
    cout<<"Inorder traversal"<<endl;
    Inorder(Root);
    cout<<"Preorder traversal"<<endl;
    Preorder(Root);
    cout<<"Postorder traversal"<<endl;
    Postorder(Root);

  }

int main()
{
    
   
   

    return 0;
}