/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include "product.h"
#include <iostream>
using namespace std;

product::product()
{}

product::product(char ifPerishable,string Name,string Category,long unsigned int Barcode_num,double Price,
	string Manufacturer,int Num_in_Stock,int Num_sold_per_month)
	:ifPerishable(ifPerishable),Name(Name),Category(Category),Barcode_num(Barcode_num),Price(Price),
	Manufacturer(Manufacturer),Num_in_Stock(Num_in_Stock),Num_sold_per_month(Num_sold_per_month){}

string product::getProduct_Name() const
{
	return Name;
}

string product::getCategory() const
{
	return Category;
}

long unsigned int product::getBarcode() const
{
	return Barcode_num;
}

double product::getPrice() const
{
	return Price;
}

string product::getManufacturer() const
{
	return Manufacturer;
}

int product::getNum_in_Stock() const
{
	return Num_in_Stock;
}

int product::getNum_sold_per_month() const
{
	return  Num_sold_per_month;
}

char product:: get_ifperishable() const
{
	return ifPerishable;
}

void product::Resetproductsale()
{
	Num_sold_per_month=0;
}

bool product::Sellproduct(int Num_to_sell)
{
	int num=Num_to_sell;
	
	if(num>this->getNum_in_Stock())
	{
		cout<<"Sorry, not enough! The number in stock is"<<this->getNum_in_Stock()<<endl;
		return false;
	}

	//Update the respective data in the database
	if(num<=this->getNum_in_Stock())
	{
		this->Num_sold_per_month+=num;
		this->Num_in_Stock-=num;
	}
	return true;
}

//This will set the number in stock to be the number user key in
bool product::Restockproduct(int Num_to_add)
{
	int num=Num_to_add;
	this->Num_in_Stock+=num;//new!!!!!
	return true;
}

//setter functions
void product::setperi(char value)
{
	ifPerishable=value;
}

void product::setProduct_Name(string value)
{
	Name=value;
}

void product::setCategory(string value)
{
	Category=value;
}

void product::setBarcode(long unsigned int value)
{
	Barcode_num=value;
}

void product::setPrice(double value)
{
	Price=value;
}

void product::setManufacturer(string value)
{
	Manufacturer=value;
}

void product::setNum_in_Stock(int value)
{
	Num_in_Stock=value;
}

void product::setNum_sold_per_month(int value)
{
	Num_sold_per_month=value;
}

 string product::getexpDate() const
{
	return "0";
}

double product::getDiscount_percentage() const
{
	return -1;
}