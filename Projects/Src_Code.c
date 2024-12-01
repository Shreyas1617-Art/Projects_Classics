#include <iostream>
#include <string.h>
using namespace std;

#define ARRAY_BOOKS 100

struct book
{
  int bookID;
  char name[50];
  char tittle[50];
  float price;
};

class member
{
    protected :
       char name[50];
       int memberID;
    
    public :
    //construtor to store member Data
    
    member(const char *n,int ID)
    {
        strcpy(name,n);
        memberID = ID;
    }
    
    virtual void displaydetials()
    {
        cout<<"name = "<<name<<"\n"<<"memberID ="<<memberID<<endl;
    }
};


class librerian : public member
{
    public :
    librerian(const char *n ,int ID): member(n,ID) {}
    
    void displaydetials()override{
        
        cout<<"member detials"<<endl;
        member::displaydetials();
        
           cout<<"\n"<<endl;
    }
    
    void addbook(book *books,int &count,const char *name,const char *tittle,float price,int Id)
    {
        books[count].bookID = Id;
        strcpy(books[count].name,name);
        strcpy(books[count].tittle,tittle);
        books[count].price = price;
        count++;
        
       cout<<"book of tittle  "<<tittle<<"  added succesfully"<<endl;
    }
};


class borrower : public member
{
    protected :
       int borrowedbooks[10];
       
       int borrrowedcount=0;
       
       int borrowerID[10];
       
       
    public :
    borrower(const char *name,int ID):member(name,ID){}
    
    void borrowbook( book *books , int bookID ,int count)
    {
        for(int i=0;i<count;i++)
        {
            if(books[i].bookID == bookID)
            {
                borrowedbooks[borrrowedcount++]=bookID;
                
                cout<<"book of tittle "<<books[i].tittle<<"found" <<endl;
                return ;
            }
        }
        cout<<"book with iD"<<bookID<<"not found"<<endl;
    }
    
    // if the borrower returns the book.
    
    void returnbook(book *books,int bookID,int count)
    {
        bool Bookfound = false;
        for(int i=0;i<borrrowedcount;i++)
        {
            if(borrowedbooks[i] == bookID)
            {
                for(int j = i;j<borrrowedcount;j++)
                {
                    borrowedbooks[j]=borrowedbooks[j+1];
                }
                borrrowedcount--;
                
                Bookfound = true;
                
               for(int k=0;k<count;k++)
               {
                  if(books[k].bookID == bookID)
                  {
                 cout<<"book found "<<  books[k].tittle<<endl;
                  break;
                  }
               }
               break;
            }

        }
        if(!Bookfound)
            {
                cout<<"invalidd"<<endl;
            }
       
    }
    
    
    
    void displaydetials()override{
        cout<<"member detials"<<endl;
        member::displaydetials();
        cout<<"\n"<<endl;
        if(borrrowedcount == 0)
        {
            cout<<"NONE"<<endl;
        }
        else
        {
            for(int i =0;i<borrrowedcount;++i)
            {
                cout<<"books ="<<borrowedbooks[i]<<endl;
            }
        }
    }
    
    
};


int main()
{
  book *books = new book[100];
  
  int bookcount = 0;
  
  librerian Librerian("Alice",100);
  
  borrower Borrower("Bob",110);
  
  Librerian.displaydetials();
  
  
  
  Librerian.addbook(books,bookcount,"Mark","Trade",100,2345);
  
  Librerian.addbook(books,bookcount,"Minervini","Stock",102,2376);
  
  Librerian.addbook(books,bookcount,"Mini","ACC",130,3567);
   
  Librerian.addbook(books,bookcount,"Meth","ABB",140,9823);
  
  Borrower.borrowbook(books,3567, bookcount);
  
  Borrower.borrowbook( books,2376, bookcount);
  Borrower.borrowbook( books,9823, bookcount);
  
  Borrower.displaydetials();
  
  Borrower.returnbook(books,9823,bookcount);
  
  Borrower.returnbook(books,122334,bookcount);
  
  Borrower.returnbook(books,2376,bookcount);
  
  delete[] books;
 
}