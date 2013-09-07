/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include "vectoradt.h"
#include "product.h"
#include "perishable.h"
#include <iostream>

bool vectoradt::addnewproduct(product* p )
{		
	perishable pr;
	pr.setperi(p->get_ifperishable());
	pr.setProduct_Name(p->getProduct_Name());
	pr.setCategory(p->getCategory());
	pr.setBarcode(p->getBarcode());
	if(this->findproduct(p->getBarcode())!=-1)
		return false;
	pr.setPrice(p->getPrice());
	pr.setManufacturer(p->getManufacturer());
	pr.setNum_in_Stock(p->getNum_in_Stock());
	pr.setNum_sold_per_month(p->getNum_sold_per_month());
	pr.setexpDate("-1");
	pr.setDiscount_percentage(-1);
	_vdatabasep.push_back(pr);
	this->setsize(getsize()+1);
	return true;
}

void vectoradt::addnewproduct(perishable *p1)
{	
	perishable pr;
	pr=*p1;
	_vdatabasep.push_back(pr);
	this->setsize(getsize()+1);
}

vectoradt::vectoradt()
{
	this->setsize(0);
}

int vectoradt::findproduct(long unsigned int Barcode_num)
{	
	int i=-1,j;
	for(j=0; j<this->getsize(); j++)
	{
		if(this->_vdatabasep[j].getBarcode()==Barcode_num)
		{	i=j;
			break;
		}
	}
	return i;
}

bool vectoradt::deleteproduct(long unsigned int Barcode_num)
{	
	if(this->getsize()==0)
	{
		cout<<"Sorry, the database is empty"<<endl;
		return false;
	}
	int i,j;
	i=findproduct(Barcode_num);
	if(i==-1)
	{
		cout<<"barcode not found"<<endl;
		return false;
	}
	for(j=i;j<this->getsize()-1;j++)
	{
		this->_vdatabasep[j]=this->_vdatabasep[j+1];
	}
	this->setsize(getsize()-1);
	return true;
}

void vectoradt::ResetProductSale(long unsigned int Barcode_num)
{	
	int i;
	i=findproduct(Barcode_num);
	if(i==-1)
	{
		cout<<"sorry wrong Barcode number"<<endl;
		return;
	}
	_vdatabasep[i].Resetproductsale();
}

bool vectoradt::SellProduct(long unsigned int Barcode_num,int num_to_sell)
{
	int i;
	i=findproduct(Barcode_num);
	if(i==-1)
	{
		cout<<"sorry wrong Barcode number"<<endl;
		return false;
	}
	_vdatabasep[i].Sellproduct(num_to_sell);
	return true;
}

bool vectoradt::RestockProduct(long unsigned int Barcode_num,int num_to_restock)
{
	int i;
	i=findproduct(Barcode_num);
	if(i==-1)
	{
		cout<<"sorry wrong Barcode number"<<endl;
		return false;
	}
	_vdatabasep[i].Restockproduct(num_to_restock);
	return true;
}

//The write to file method is different for the three different list ADT 
bool vectoradt::writetofile(string s,int size)
{
	ofstream out;
	out.open(s);

	if(!out.is_open())
		return false;
	if(size==0)
		return 0;
	
	out<<size<<endl;

	for(int i=0;i<this->getsize();i++)
	{
		out<<_vdatabasep[i].get_ifperishable()<<"\n";
		out<<_vdatabasep[i].getProduct_Name()<<"\n";
		out<<_vdatabasep[i].getCategory()<<"\n";
		out<<_vdatabasep[i].getBarcode()<<"\n";
		out<<_vdatabasep[i].getPrice()<<"\n";
		out<<_vdatabasep[i].getManufacturer()<<"\n";
		out<<_vdatabasep[i].getNum_in_Stock()<<"\n";
		out<<_vdatabasep[i].getNum_sold_per_month()<<"\n";

		if(_vdatabasep[i].get_ifperishable()=='y')
		{
			out<<_vdatabasep[i].getexpDate()<<"\n";
			out<<_vdatabasep[i].getDiscount_percentage()<<"\n";
		}
	}
	return true;
}  

perishable *  vectoradt::getperishable(long unsigned int Barcode_num)
{	
	perishable *ptr;
	int i;
	i=findproduct(Barcode_num);
	if(i==-1)
		return NULL;
	else
	{	
		ptr=&_vdatabasep[i];
		return ptr;
	}
}

bool vectoradt::Dispose(long unsigned int Barcode_num, string currentdate)
{
	int val;
	if(this->findproduct(Barcode_num)==-1)
		return false;
	else
		val=this->findproduct(Barcode_num);
	if(this->checkexpiry(currentdate,Barcode_num)==1)
		return false;
	if(this->checkexpiry(currentdate,Barcode_num)==3)
		return false;

	this->RestockProduct(Barcode_num,(this->_vdatabasep[val].getNum_in_Stock())*(-1));
		return true;
}

product* vectoradt::traverse(int index)
{	
	product *ptr1;
    ptr1=&(_vdatabasep[index]);
	
	return ptr1;
}