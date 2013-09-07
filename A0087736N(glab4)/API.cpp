/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include "API.h"
#include "UI.h"
#include<Windows.h>

using namespace std;
UI obj1;
processJobs Jobdata;

bool API::API_addnewproduct(product *p)
{
	if(database->addnewproduct(p))
		return true;
	else 
		return false;
}

void API::API_addnewproduct(perishable *p1)
{
	database->addnewproduct(p1);
}

API::~API()
{
	delete database;
}

bool API::API_scrapproduct(long unsigned int Barcode_num)
{   
	if(database->deleteproduct(Barcode_num))
		return true;
	else 
		return false;
}

void API:: API_ResetProductSale(long unsigned int Barcode_num)
{
	database->ResetProductSale(Barcode_num);
}

bool API::API_SellProduct(long unsigned int Barcode_num,int Num_to_sell)
{
	if(database->SellProduct(Barcode_num,Num_to_sell))
		return true;
	else 
		return false;
}

bool API::API_RestockProduct(long unsigned int Barcode_num,int Num_to_add)
{
	if(database->RestockProduct(Barcode_num,Num_to_add))
		return true;
	else 
		return false;
}

void API::API_ListAllProducts()
{
	database->listallproducts();
}

bool API::API_LoadData(string s)
{
	if(database->inputfromfile(s))
		return true;
	else 
		return false;
}

bool API::API_CheckExpiry(string currentdate,long unsigned int Barcode_num)
{
	HANDLE outputScreen;
	outputScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );

	int result=database->checkexpiry(currentdate,Barcode_num);
	
	if(result==0)
	{	
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"Sorry there is no perishable product matching this Barcode number "<<endl;
		return false;
	}
	if(result==1)
	{	
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"Sorry there is no perishable product matching this Barcode number "<<endl;
	    return false;
	}
	if(result==2)
	{	
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"The product HAS expired!"<<endl;
		return false;
	}
	if(result==3)
	{	
		SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"The product HAS NOT expired!"<<endl;
		return true;
	}
}

void API::API_TOPXsellingproduct(int x)
{   
	database->TOPXsellingproduct(x);
}

void API::API_bestsellingcategory(string Category)
{
	database->Bestsellingcategory(Category);
}

void API::API_BestsellingManufacturer()
{	
	database->Bestsellingmanufacturer();
}

void API::API_search(int choice, int type)
{	
	string stringBarcode;
	HANDLE outputScreen;
	outputScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	string Name; 
	long unsigned int Barcode_num;
	string Category;
	string Manufacturer;

	do
	{
		switch(choice)
		{	
			SetConsoleTextAttribute(outputScreen,        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			case 1:	
				cout<<"Please enter the full name: ";
				getline(cin,Name);
				getline(cin,Name);
				database->searchbyName(Name);
				break;
			case 2:
				cout<<"Please enter the Barcode number: ";
				getline(cin,stringBarcode);
				getline(cin,stringBarcode);
				if(this->API_checkInt(stringBarcode))
				{
					Barcode_num=atoi(stringBarcode.c_str());
					database->searchbyBarcode(Barcode_num);
				}
				else
				{
					cout<<"Input must be of the correct format"<<endl;
				}
				break;
			case 3:
				cout<<"Please enter the Category: ";
				getline(cin,Category);
				getline(cin,Category);
				database->searchbyCategory(Category);
				break;
			case 4:
				cout<<"Please enter the Manufacturer: ";
				getline(cin,Manufacturer);
				getline(cin,Manufacturer);
				database->searchbyManu(Manufacturer);
				break;
			default:
				SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout<<"Invalid choice! Please TRY again!"<<endl;
				break;
		}
	}while(choice!=1&&choice!=2&&choice!=3&&choice!=4);
}

void API::API_initialize(int choice)
{
	switch(choice)
	{
		case 1:
			database= new productDataBaseLL();
			break;
		case 2:
			database=new vectoradt();
			break;
		case 3:
			database= new productDataBaseDA();
			break;
		default:
			cout<<"Invalid choice! Please TRY again!"<<endl;
			obj1.toAPI_initialize();
			break;
	}
}

bool API::API_writetofile(string s)
{   
	if(database->writetofile(s,database->getsize()))
		return true;
	else 
		return false;
}

bool API::API_loadJobData(string s)
{
	if(Jobdata.inputfromfile(s))
		return true;
	else
		return false;
}

void API::API_proceedjobs()
{
	Jobdata.proceedjobs(database);
}

void API::API_displayprofeatures(product* pointer)
{   
	obj1.UI_display_pro_features(pointer);
}

bool API::API_checkInt(string toCheck)
{
	char* temp = new char[toCheck.size()+1];
	strcpy(temp, toCheck.c_str());

	for(unsigned int i=0; i<strlen(temp); i++)
	{
		if((int)temp[i]<48 || (int)temp[i]>57)
		{
			return false;
		}
	}
	delete[] temp;
	return true;
}

bool API::API_checkDouble(string toCheck)
{
	char* temp = new char[toCheck.size()+1];
	strcpy(temp, toCheck.c_str());
	int dotCount=0;

	for(unsigned int i=0; i<strlen(temp); i++)
	{
		if((int)temp[i]<48 || (int)temp[i]>57)
		{
			if((int)temp[i]==46)
			{
				dotCount++;
				if(dotCount==2)
					return false;
			}
			else
				delete[] temp;
				return false;
		}
	}
	delete[] temp;
	return true;
}