/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include "perishable.h"

perishable::perishable()
{}

perishable::perishable(char ifPerishable,string Name,string Category,long unsigned int Barcode_num,double Price,
	string Manufacturer,int Num_in_Stock,int Num_sold_per_month,string _Expirydate,double Discount_percentage)
	:product(ifPerishable,Name,Category,Barcode_num,Price,Manufacturer,Num_in_Stock,Num_sold_per_month),
	Discount_percentage(Discount_percentage),Expirydate(_Expirydate){ }

string perishable::getexpDate() const
{   	
	return Expirydate; 
}

double perishable::getDiscount_percentage() const
{
	return Discount_percentage;
}

void perishable::setexpDate(string date) 
{
	this->Expirydate=date;
}

void perishable::setDiscount_percentage(double d) 
{
	Discount_percentage=d;
}