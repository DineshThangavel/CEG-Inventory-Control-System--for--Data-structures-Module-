/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include <iostream>
#include "UI.h"
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>
#include "API.h"
#include "product.h"
#include "perishable.h"
#include "processJobs.h"
#include<Windows.h>
using namespace std;
  
UI::UI()
{
	this->loadpassword();
}

void UI::getmainpage()
{  
	string stringChoice;
	int choice, type=1;
	string newpassword;
	do
	{	
		HANDLE outputScreen;
		outputScreen = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"|";SetConsoleTextAttribute(outputScreen,       FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<< "           CEG Hypermarket Inventory Control and Monitoring System           ";    
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );  
		cout<<" |"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		SetConsoleTextAttribute(outputScreen,        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
		cout<<"0.Change Password"<<endl;
		cout<<"1.Add New Product"<<endl;
		cout<<"2.Delete Product"<<endl;
		cout<<"3.Reset Product Sales"<<endl;
		cout<<"4.Sell Product"<<endl;
		cout<<"5.Restock Product "<<endl;
		cout<<"6.Generate Statistics"<<endl;
		cout<<"7.List All Products"<<endl;
		cout<<"8.Load Data"<<endl;
		cout<<"9.Check Expiry"<<endl;
		cout<<"10.Search for product"<<endl;
		cout<<"11.Load Jobs"<<endl;
		cout<<"12.Proceed Jobs"<<endl;
		cout<<"13.Quit"<<endl<<endl;
		SetConsoleTextAttribute(outputScreen,       FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<"What would you like to do?  [PLease enter number]: ";
		cin>>stringChoice;
		if(user_API.API_checkInt(stringChoice))
		{
			choice=atoi(stringChoice.c_str());
		}
		else
		{
			cout<<"Input must be of the correct format"<<endl;
			this->getmainpage();
		}
		switch(choice)
		{
		    case 0:
				cout<<"please enter the newpassword: ";
				cin>>password;
				this->changepassword(password);
				break;
			case 1:
				this->UI_addnewproduct();
				break;
			case 2:
				this->UI_deleteproduct();
				break;
			case 3:
				this->UI_ResetProductSale();
				break;
			case 4:
				this->UI_SellProuct(type);
				break;
			case 5:
				this->UI_RestockProduct();
				break;
			case 6:
				this->getstatspage();
				break;
			case 7:
				this->UI_ListAllProducts();
				break;
			case 8:
				this->UI_LoadData();
				break;
			case 9:
				this->UI_CheckExpiry(type);
				break;
			case 10:
				this->UI_search(type);
				break;
			case 11:
				this->UI_LoadJobData();
				break;
			case 12:
				this->UI_proceedJobs();
				break;
			case 13:
				this->keeppassword();
				this->UI_writetofile();
				break;
			default:
				SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"Invalid Choice! Please Try Again!"<<endl;
				break;
		}
	}while(choice!=13);   
}

void UI::getstatspage()
{   
	string stringChoice;
	HANDLE outputScreen;
	outputScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice=0;

	do
	{
		ClearScreen();
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"-------------------------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(outputScreen,        FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<"                              SUBMENU                                          "<<endl;
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"-------------------------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(outputScreen, FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"1.TOP X selling product"<<endl;
		cout<<"2.Best selling product in one given category"<<endl;
		cout<<"3.Best selling manufacturer"<<endl;
		cout<<"4.Go Back"<<endl;
		SetConsoleTextAttribute(outputScreen,       FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		ClearScreen();
		cin>>stringChoice;
		if(user_API.API_checkInt(stringChoice))
		{
			choice=atoi(stringChoice.c_str());
		}
		else
		{
			cout<<"Input must be of the correct format"<<endl;
			this->getmainpage();
		}

		switch(choice)
		{
			case 1:
				this->UI_TOPXsellingproduct();
				break;
			case 2:
				this->UI_bestsellingcategory();
				break;
			case 3:
				this->UI_BestsellingManufacturer();
				break;
			case 4:
				cout<<"Going Back to Main Menu"<<endl;
				break;
		}
	}while(choice!=4);
}

void UI::UI_addnewproduct()
{   
	string stringChoice;
	string stringBarcode;
	string stringPrice;
	string stringNum_in_Stock;
	string stringNum_sold_per_month;
	string stringDiscount_percentage;
	string Name;
	string Category;
	long unsigned int Barcode_num;
	double Price;
	string Manufacturer;
	int Num_in_Stock;
	int Num_sold_per_month;
	string Expirydate;
	double Discount_percentage;
	int choice;
	cout<<"What kind of product do you want to add?   1.common product    2.perishable product"<<endl;
	cin>>stringChoice;
	if(user_API.API_checkInt(stringChoice))
	{
		choice=atoi(stringChoice.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
	cout<<"Name: ";
	getline(cin,Name);
	getline(cin,Name);
	cout<<"Category: ";
	getline(cin,Category);
	cout<<"Barcode number: ";
	getline(cin,stringBarcode);
	if(user_API.API_checkInt(stringBarcode))
	{
		Barcode_num=atoi(stringBarcode.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
	cout<<"Price: ";
	getline(cin,stringPrice);
	if(user_API.API_checkDouble(stringPrice))
	{
		Price=atoi(stringPrice.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
	cout<<"Manufacturer: ";
	getline(cin,Manufacturer);
	cout<<"Number in stock: ";
	getline(cin,stringNum_in_Stock);
	if(user_API.API_checkInt(stringNum_in_Stock))
	{
		Num_in_Stock=atoi(stringNum_in_Stock.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
	cout<<"Number sold per month: ";
	getline(cin,stringNum_sold_per_month);
	if(user_API.API_checkInt(stringNum_sold_per_month))
	{
		Num_sold_per_month=atoi(stringNum_sold_per_month.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
	
	if(choice==2)
	{
		cout<<"Expiry date: ";
		getline(cin,Expirydate);
		cout<<"Discount percentage: ";
		getline(cin,stringDiscount_percentage);
		if(user_API.API_checkDouble(stringDiscount_percentage))
		{
			Discount_percentage=atoi(stringDiscount_percentage.c_str());
		}
		else
		{
			cout<<"Input must be of the correct format"<<endl;
			this->getmainpage();
		}
		perishable *p= new perishable('y',Name,Category,Barcode_num,Price,Manufacturer,Num_in_Stock,Num_sold_per_month,Expirydate,Discount_percentage);
		user_API.API_addnewproduct(p);
	}
	else 
    { 
		product *p=new product('n',Name,Category,Barcode_num,Price,Manufacturer,Num_in_Stock,Num_sold_per_month);
		user_API.API_addnewproduct(p);
    } 
	cout<<"Product added"<<endl;
}

void UI:: UI_deleteproduct()
{   
	string stringBarcode;
	long unsigned int Barcode_num;
	cout<<"Please enter the Barcode of the product that you want to delete:";
	cin>>stringBarcode;
	if(user_API.API_checkInt(stringBarcode))
	{
		Barcode_num=atoi(stringBarcode.c_str());
		user_API.API_scrapproduct(Barcode_num);
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
}

void UI:: UI_ResetProductSale()
{   
	string stringBarcode;
	long unsigned int Barcode_num;
	cout<<"what is the Barcode Number of the product that you want to reset? ";
	cin>>stringBarcode;
	if(user_API.API_checkInt(stringBarcode))
	{
		Barcode_num=atoi(stringBarcode.c_str());
		user_API.API_ResetProductSale(Barcode_num);
		cout<<"Product sales reset"<<endl;
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
}

void UI::UI_SellProuct(int type)
{
	string stringBarcode, stringNum_to_sell;
	int Num_to_sell;
	long unsigned int Barcode_num;
	cout<<"what is the Barcode Number of the product that you want to sell? ";
	cin>>stringBarcode;
	if(user_API.API_checkInt(stringBarcode))
	{
		Barcode_num=atoi(stringBarcode.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		if(type==1)
			this->getmainpage();
		else
			this->getnormaluserpage();
	}
    cout<<"How many product you want to sell? ";
	cin>>stringNum_to_sell;
	if(user_API.API_checkInt(stringNum_to_sell))
	{
		Num_to_sell=atoi(stringNum_to_sell.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		if(type==1)
			this->getmainpage();
		else
			this->getnormaluserpage();
	}
	user_API.API_SellProduct(Barcode_num,Num_to_sell);
	cout<<"Product Sold"<<endl;
}

void UI::UI_RestockProduct()
{
	string stringBarcode, stringNum_to_add;
	int Num_to_add;
	long unsigned int Barcode_num;
	cout<<"what is the Barcode Number of the product that you want to restock? ";
	cin>>stringBarcode;
	if(user_API.API_checkInt(stringBarcode))
	{
		Barcode_num=atoi(stringBarcode.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
	cout<<"How many product you want to add? ";
	cin>>stringNum_to_add;
	if(user_API.API_checkInt(stringNum_to_add))
	{
		Num_to_add=atoi(stringNum_to_add.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
	user_API.API_RestockProduct(Barcode_num,Num_to_add);
	cout<<"Product Restocked"<<endl;
}

void UI::UI_ListAllProducts()
{
	user_API.API_ListAllProducts();
	cout<<"List of All products provided"<<endl;
}

void UI::UI_LoadData()
{	
	string str;
	cout<<"Enter the name of the file"<<endl;
	cin>>str;
	if(user_API.API_LoadData(str))
		cout<<"Data loaded"<<endl;
	else
		cout<<"error in loading data"<<endl;
}

void UI:: UI_CheckExpiry(int type)
{
	string stringBarcode;
	long unsigned int Barcode_num;
	string currentdate;
	cout<<"What is the current date? ";
	cin>>currentdate;
	cout<<"Which product do you want to check? Please enter the Barcode Number ";
	getline(cin,stringBarcode);
	getline(cin,stringBarcode);
	if(user_API.API_checkInt(stringBarcode))
	{
		Barcode_num=atoi(stringBarcode.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		if(type==1)
			this->getmainpage();
		else
			this->getnormaluserpage();
	}
	user_API.API_CheckExpiry(currentdate,Barcode_num);
	cout<<"Expiry Checked"<<endl;
}

void UI:: ClearScreen()
{
    for(int i=0;i<4;i++)
		cout<<endl;
}

void UI::UI_TOPXsellingproduct()
{
	string stringX;
	int x;
	cout<<"What is the TOP number you want? ";
	cin>>stringX;
	if(user_API.API_checkInt(stringX))
	{
		x=atoi(stringX.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->getmainpage();
	}
	user_API.API_TOPXsellingproduct(x);
	cout<<"Top Selling Product found"<<endl;
}

void UI:: UI_bestsellingcategory()
{   
	string Category;
	cout<<"What is the Category?";
	getline(cin,Category);
	getline(cin,Category);
	user_API.API_bestsellingcategory(Category);
}

void UI::UI_BestsellingManufacturer()
{   
	user_API.API_BestsellingManufacturer();
}

void UI::toAPI_initialize()
{	
	int choice;
	string stringChoice;
	HANDLE outputScreen;
	outputScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(outputScreen, FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<"what kind of containers is needed for database?";
	SetConsoleTextAttribute(outputScreen,       FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout<<"1.LL  2.Vector  3.Dynamic Array"<<endl;
	cin>>stringChoice;
	if(user_API.API_checkInt(stringChoice))
	{
		choice=atoi(stringChoice.c_str());
		user_API.API_initialize(choice);
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		this->toAPI_initialize();
	}
}

void UI::UI_search(int type)
{     
	string stringChoice;
	int choice;
	cout<<"Please choose from below for a search:"<<endl;
	cout<<"1.	Full product name"<<endl;
	cout<<"2.	Barcode number   "<<endl;
	cout<<"3.	Category         "<<endl;
	cout<<"4.	Manufacturer     "<<endl;
	cin>>stringChoice;
	if(user_API.API_checkInt(stringChoice))
	{
		choice=atoi(stringChoice.c_str());
	}
	else
	{
		cout<<"Input must be of the correct format"<<endl;
		if(type==1)
			this->getmainpage();
		else
			this->getnormaluserpage();
	}
	user_API.API_search(choice, type);
}

void UI::UI_writetofile()
{
	string str;
	cout<<"Enter the name of the outputfile"<<endl;
	cin>>str;
	if(user_API.API_writetofile(str))
		cout<<"Data written"<<endl;
	else
		cout<<"error in writing data"<<endl;
}

void UI::UI_LoadJobData()
{
    string str;
	cout<<"Enter the name of the job data:"<<endl;
    cin>>str;
	if(user_API.API_loadJobData(str))
		cout<<"Data Loaded"<<endl;
	else 
		cout<<"errot in loading data"<<endl;
}

void UI::UI_proceedJobs()
{
	user_API.API_proceedjobs();
}

void UI::UI_display_pro_features(product* p)
{	
	HANDLE outputScreen;
	outputScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(outputScreen,        FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	cout<<"Perisable:            "<<p->get_ifperishable()<<endl;
	cout<<"Name:                 "<<p->getProduct_Name()<<endl;
	cout<<"Category:             "<<p->getCategory()<<endl;
	cout<<"Barcode number:       "<<p->getBarcode()<<endl; 
	cout<<"Price:                "<<p->getPrice()<<endl;
	cout<<"Manufacturer:         "<<p->getManufacturer()<<endl;
	cout<<"Number in Stock:      "<<p->getNum_in_Stock()<<endl;
	cout<<"Number sold per month:"<<p->getNum_sold_per_month()<<endl;

	if(p->get_ifperishable()=='y')
	{
		cout<<"Expiry Date;          "<<p->getexpDate()<<endl;
		cout<<"Discount Percentage:  "<<p->getDiscount_percentage()<<endl;
	}
	SetConsoleTextAttribute(outputScreen,       FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"--------------------------------------------------------------------------------";
}

void UI::setpassword(string newpassword)
{
	this->password=newpassword;
}

bool UI::checkpassword(string password)
{
	if(this->password==password)
		return true;
	else
		return false;
}

void UI::getnormaluserpage()
{
	string stringChoice;
	int choice, type=0;
	
	do
	{ 
		HANDLE outputScreen;
		outputScreen = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"|";SetConsoleTextAttribute(outputScreen,       FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<< "           CEG Hypermarket Inventory Control and Monitoring System           ";    
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );  
		cout<<" |"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		SetConsoleTextAttribute(outputScreen,        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<"1.Sell Product"<<endl;
		cout<<"2.List All Products"<<endl;
		cout<<"3.Load Data"<<endl;
		cout<<"4.Check Expiry"<<endl;
		cout<<"5.Search for product"<<endl;
		cout<<"6.Quit"<<endl<<endl;
		cout<<"What would you like to do?  [PLease enter number]: ";
		
		cin>>stringChoice;
		if(user_API.API_checkInt(stringChoice))
		{
			choice=atoi(stringChoice.c_str());
		}
		else
		{
			cout<<"Input must be of the correct format"<<endl;
			this->getnormaluserpage();
		}
		switch(choice)
		{
			case 1:
				this->UI_SellProuct(type);
				break;
			case 2:
				this->UI_ListAllProducts();
				break;
			case 3:
				this->UI_LoadData();
				break;
			case 4:
				this->UI_CheckExpiry(type);
				break;
			case 5:
				this->UI_search(type);
				break;
			case 6:
				this->UI_writetofile();
				break;
			default:
				cout<<"Invalid Choice! Please Try Again!"<<endl;
				break;
		}
	}while(choice!=6);   
}

void UI::changepassword(string newpassword)
{
	this->setpassword(newpassword);
}

void UI::loadpassword()
{
	ifstream in;
	in.open("password.txt");
	string encpw;
	in>>encpw;
	password=this->decrypt(encpw);
	this->changepassword(password);
	in.close();
}

void UI::keeppassword()
{
	string encpw=password;
	ofstream out;
	out.open("password.txt");
	encpw=encrypt(password);
	out<<encpw<<endl;
	out.close();
}

string UI::decrypt(string encpw)
{	
	string pw=encpw;
	for(int i=0;i<encpw.size();i++)
	{	
		pw[i]=(char)(encpw[i]-11);
	}
	return pw;
}

string UI::encrypt(string pw)
{	
	string encpw=pw;
	for(int i=0;i<pw.size();i++)
		encpw[i]=(char)(pw[i]+11);
	return encpw;
}