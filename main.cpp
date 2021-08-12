/*A book shop maintains the inventory of books that are being sold at the shop. The list
includes details such as author, title, price, publisher and stock position. Whenever a
customer wants a book, the sales person inputs the title and author and the system
searches the list and displays whether it is available or not. If it is not, an appropriate
message is displayed. If it is, then the system displays the book details and requests
for the number of copies required. If the requested copies book details and requests
for the number of copies required. If the requested copies are available, the total cost
of the requested copies is displayed; otherwise the message “Required copies not in
stock” is displayed.
Design a system using a class called books with suitable member functions and
Constructors. Use new operator in constructors to allocate memory space required.
Implement C++ program for the system.*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class book
{
    private:
    char author, title, publisher;
    float price;
    int stock;

    public:
        book()
        {
           author= new char[20];
           title= new char[20];
           publisher= new char[20];
           price= new float;
           stock= new int;
        }

        void feeddata();
        void editdata();
        void showdata();
        int search(char[], char[]);
        void buybook();

};

void book ::feeddata()
{
    cin.ignore();
    cout <<"\nEnter Author Name: ";
    cin.getline(author,20);
    cout <<"Enter Title: ";
    cin.getline(title,20);
    cout <<"Enter Publisher Name: ";
    cin.getline(publisher,20);
    cout <<"Enter Price: ";
    cin>>*price;
    cout<<"Enter Stock Position";
    cin>>*stock;
}

void book ::editdata()
{
    cout <<"\nEnter Author Name: ";
    cin.getline(author,20);
    cout <<"Enter Title: ";
    cin.getline(title,20);
    cout <<"Enter Publisher Name: ";
    cin.getline(publisher,20);
    cout <<"Enter Price: ";
    cin>>*price;
    cout<<"Enter Stock Position";
    cin>>*stock;
}

void book ::showdata()
{
    cout<<"\nAuthor Name: "<<author;
    cout<<"\nTitle Name: "<<title;
    cout<<"\nPublisher Name: "<<publisher;
    cout<<"\nPrice: "<<*price;
    cout<<"\nStock Position: "<<*stock;
}

int book::search(char tbuy[20], char abuy[20])
{
    if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
        return 1;
    else return 0;
}

void book::buybook()
{
    int count;
    cout<<"\nEnter number of books to buy: ";
    cin>>count;
    if (count<=*stock)
    {
        *stock=*stock-count;
        cout<<"\nBooks bought successfully";
        cout<<"\nAmount: GHc "<<(*price)*count;
    }
    else
        cout <<"Sorry. Requested copies are not in stock.";
}

int main()
{
    book *B[20];
    int i=0,r,t, choice;
    char titlebuy[20], authorbuy[20];

    while(1)
        cout<<"\n\n\n\t\tMENU"
        <<"\n1. Entry of new book"
        <<"\n2. Buy Book"
        <<"\n3. Search for a book"
        <<"\n4. Edit details of a book"
        <<"\n5. Exit"
        <<"\n\nEnter your choice: ";
        cin>>choice;

        switch choice
        {
            case 1: B[i]= new book;
                    B[i]->feeddata();
                    i++;
                    break;
            case 2: cin.ignore();
                    cout<<"\nEnter title of book: ";
                    cin.getline(titlebuy,20);
                    cout<<"Enter author of the book: ";
                    cin.getline(authorbuy,20)
                    for (t=0;t<i;t++)
                {
					if(B[t]->search(titlebuy,authorbuy))
                    {
						B[t]->buybook();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Book is Not in Stock";

				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);

				for(t=0;t<i;t++)
                {
					if(B[t]->search(titlebuy,authorbuy))
					{
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;

			case 4: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);

				for(t=0;t<i;t++)
                {
					if(B[t]->search(titlebuy,authorbuy))
					{
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;

			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";

		}
	}



        }
    return 0;
}
