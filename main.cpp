#include<iostream>
#include<fstream> 
#include<windows.h>
using namespace std;

class shopping
{
private:
    int pcode; // p -> product
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping :: menu()
{
m: 
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t______________________________________\n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t          Supermarket Main Menu       \n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t______________________________________\n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t\t|  1) Administrator   |\n";
    cout<<"\t\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t\t|  2) Buyer           |\n";
    cout<<"\t\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t\t|  3) Exit            |\n";
    cout<<"\t\t\t\t\t|                     |\n";
    cout<<endl;
    cout<<"\n\t\t\t\t Please select : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
    case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<endl;
        cout<<"\t\t\t Enter Email   : ";
        cin>>email;
        cout<<"\t\t\t Password      : ";
        cin>>password;

        if(email=="xyz@email.com" && password=="xyz@123")
        {
            administrator();
        }
        else
        {
            cout<<"Invalid email/password";
        }
        break;


    case 2:
    {
        buyer();

    }

    case 3:
    {
        exit(0);
    }

    default :
    {
        cout<< "Please select from the given options";
    }
    }
    goto m; 
}

void shopping :: administrator()
{
m:
    int choice;
    cout<<"\n\n\n\t\t\t\t\t Administrator menu";
    cout<<endl;
    cout<<"\n\t\t\t\t|_____1) Add the product________|";
    cout<<"\n\t\t\t\t|                               |";
    cout<<"\n\t\t\t\t|_____2) Modify the product_____|";
    cout<<"\n\t\t\t\t|                               |";
    cout<<"\n\t\t\t\t|_____3) Delete the product_____|";
    cout<<"\n\t\t\t\t|                               |";
    cout<<"\n\t\t\t\t|_____4) Back to main menu______|";

    cout<<"\n\n\t\t Please enter your choice ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem(); // remove
        break;

    case 4:
        menu();
        break;

    default :
        cout<<"Invalid choice!";

    }
    goto m;
}

void shopping :: buyer()
{
m:
    int choice;
    cout<<endl;
    cout<<"\t\t\t\t\t\tBuyer\n";
    cout<<"\t\t\t\t______________________________________\n";
    cout<<"                     \n";
    cout<<"\t\t\t\t\t1) Buy product \n";
    cout<<"                     \n";
    cout<<"\t\t\t\t\t2) Go back     \n";
    cout<<"\t\t\t\t______________________________________\n";
    cout<<endl;
    cout<<"\t\t\t Enter your choice : ";

    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu(); 

    default :
        cout<<"invalid choice";
    }

    goto m;
}

void shopping :: add()
{
m:
    fstream data;
    int c; // code
    int token=0;
    float p; // price
    float d; // discount
    string n; // name

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product : ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product : ";
    cin>>pname;
    cout<<"\n\n\t Price of the product : ";
    cin>>price;
    cout<<"\n\n\t Discount on product : ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c == pcode)
            {
                token++; // if duplicacy exist

            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1)
        {
            cout<<endl;
            cout<<"\n\n\t Please enter unique product code !";
            cout<<endl;
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\t Record inserted !";
}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record ";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\nFile doesn't exist! ";
    }
    else
    {

        data1.open("database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code : ";
                cin>>c;
                cout<<"\n\t\t Name of the product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;

                pcode=c;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found sorry!";
        }
    }
}

void shopping::rem()
{

    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product ";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<"File doesnt exist";

    }

    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|___________________________________________________________|\n";
    cout<<"Product Code\t\tName\t\tPrice\n";
    cout<<"\n\n|___________________________________________________________|\n";

    data>>pcode>>pname>>price>>dis;

    while(!data.eof())
    {
        cout<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;

    }
    data.close();
}

void shopping::receipt()
{
    system("cls"); // Clear the console screen
    fstream data;
    int arrc[100], arrq[100]; // Arrays to store product codes and quantities
    char choice;
    int c = 0; // Product count
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t Receipt ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout << "\n ____________________________";
        cout << "\n|                            |";
        cout << "\n|    Please place the order  |";
        cout << "\n|____________________________|\n";

        cout << "\n\nDo you want to place an order? Press 'y' for yes, 'n' to exit: ";
        cin >> choice;
        if (choice != 'y')
        {
            cout << "\nExiting without placing an order.\n";
            return;
        }

        do
        {
m:
            cout << "\n\n Product Code : ";
            cin >> arrc[c];
            cout << "\n Product Quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate Product Code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Want to buy another product? Press 'y' for yes and 'n' for no : ";
            cin >> choice;
        }
        while (choice == 'y');
        system("cls");

        cout << "\n\n\t\t\t__________RECEIPT______________\n";
        cout << "\nProduct Number\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        cout << "\n\n----------------------------------------------------------------------------------";
        cout << "\n Total Amount : " << total;
        cout << "\n\n----------------------------------------------------------------------------------";
        cout << endl;
        cout << endl;
    }
}

int main()
{
    // 0 for background Color(Black)
    // A for text color(Green)
    system("Color 0A");

    shopping s;
    s.menu();
}

