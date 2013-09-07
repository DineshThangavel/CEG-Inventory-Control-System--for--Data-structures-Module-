/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include "productDataBaseLL.h"
#include "product.h"
#include "perishable.h"
#include <iostream>

productDataBaseLL::productDataBaseLL()
{
	tail=NULL;
	setsize(0);
}

//The write to file method is different for the three different list ADT 
bool productDataBaseLL::writetofile(string s,int size)
{
    ofstream out;
	out.open(s);
	if(!out.is_open())
		return false;
	if(size==0)
		return false;

	out<<size<<endl;
	DataBaseLL* cur;
	cur=tail->next;

	for(int i=0;i<size;i++)
	{
		if(cur->newproduct->get_ifperishable()=='y')
		{   
			out<<cur->ptr->get_ifperishable()<<"\n";
			out<<cur->ptr->getProduct_Name()<<"\n";
			out<<cur->ptr->getCategory()<<"\n";
			out<<cur->ptr->getBarcode()<<"\n";
			out<<cur->ptr->getPrice()<<"\n";
			out<<cur->ptr->getManufacturer()<<"\n";
			out<<cur->ptr->getNum_in_Stock()<<"\n";
			out<<cur->ptr->getNum_sold_per_month()<<"\n";
			out<<cur->ptr->getexpDate()<<"\n";
			out<<cur->ptr->getDiscount_percentage()<<"\n";
			cur=cur->next;
		}
		if(cur->newproduct->get_ifperishable()=='n')
		{
			out<<cur->newproduct->get_ifperishable()<<"\n";
			out<<cur->newproduct->getProduct_Name()<<"\n";
			out<<cur->newproduct->getCategory()<<"\n";
			out<<cur->newproduct->getBarcode()<<"\n";
			out<<cur->newproduct->getPrice()<<"\n";
			out<<cur->newproduct->getManufacturer()<<"\n";
			out<<cur->newproduct->getNum_in_Stock()<<"\n";
			out<<cur->newproduct->getNum_sold_per_month()<<"\n";
			cur=cur->next;
		}
	}
	return true;
	out.close();
}

bool productDataBaseLL::addnewproduct(product *p)
{
	productDataBaseLL::DataBaseLL* newnode;
	newnode= new DataBaseLL;
	newnode->newproduct= new product(p->get_ifperishable(),p->getProduct_Name(),p->getCategory(),p->getBarcode(),p->getPrice(),p->getManufacturer(),p->getNum_in_Stock(),p->getNum_sold_per_month());
	newnode->next=NULL;
	newnode->prev=NULL;
	newnode->ptr=NULL;
	
	if(tail==NULL)
	{
		tail=newnode;
		newnode->next=newnode;
		newnode->prev=newnode;
	}

	else 
	{
	
		DataBaseLL *cur;
	    cur=tail->next;
	    while(cur!=tail)
	   {
		   if(cur->newproduct->getBarcode()==newnode->newproduct->getBarcode())
			   return false;
		   cur=cur->next;
	   }
	       if(tail->newproduct->getBarcode()==newnode->newproduct->getBarcode())
		   return false;
   }
	
	tail->next->prev=newnode;
	newnode->prev=tail;
	newnode->next=tail->next;
	tail->next=newnode;
	tail=newnode;
	this->setsize(this->getsize()+1);
	return true;
}

//When adding perishable product, add the same perishable product attributes to the product as well, the operations is based on
	//searching through products
void productDataBaseLL::addnewproduct(perishable* p1)
{
	productDataBaseLL::DataBaseLL* newnode;
	newnode= new DataBaseLL;
	newnode->ptr=new perishable(p1->get_ifperishable(),p1->getProduct_Name(),p1->getCategory(),p1->getBarcode(),p1->getPrice(),p1->getManufacturer(),p1->getNum_in_Stock(),p1->getNum_sold_per_month(),p1->getexpDate(),p1->getDiscount_percentage());
	newnode->newproduct=newnode->ptr;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(tail==NULL)
	{
		tail=newnode;
		newnode->next=newnode;
		newnode->prev=newnode;
	}
	tail->next->prev=newnode;
	newnode->prev=tail;
	newnode->next=tail->next;
	tail->next=newnode;
	tail=newnode;
	this->setsize(this->getsize()+1);
}

bool productDataBaseLL::deleteproduct(long unsigned int Barcode_num)
{   	
	if(tail==NULL)
	{
	 cout<<"Sorry, the database is empty"<<endl;
	 return false;
	}

	DataBaseLL *found=NULL;
	found=this->foundbyBarcode(Barcode_num);

	if(found==NULL)
		return false;
	
    found->prev->next=found->next;
	found->next->prev=found->prev;
	found->next=NULL;   
	found->prev=NULL;

	if(found==tail)
		tail=NULL;

	delete found;
	this->setsize(this->getsize()-1);
	cout<<"Product with Barcode_num: "<<Barcode_num<<" has been deleted!"<<endl;
	return true;
}

void productDataBaseLL:: ResetProductSale(long unsigned int Barcode_num)
{
	if(foundbyBarcode(Barcode_num)==NULL)
	{
		cout<<"sorry wrong Barcode number"<<endl;
	    return;
	}
	foundbyBarcode(Barcode_num)->newproduct->Resetproductsale();
}

bool productDataBaseLL:: SellProduct(long unsigned int Barcode_num,int Num_to_sell)
{   
	if(foundbyBarcode(Barcode_num)==NULL)
	{
		cout<<"sorry wrong Barcode number"<<endl;
	    return false;
	}
	if(foundbyBarcode(Barcode_num)->newproduct->Sellproduct(Num_to_sell))
		return true;
	else 
		return false;
}
		
bool productDataBaseLL:: RestockProduct(long unsigned int Barcode_num, int Num_to_add)
{   
	if(foundbyBarcode(Barcode_num)==NULL)
	{
		cout<<"sorry wrong Barcode number"<<endl;
	    return false;
	}
	foundbyBarcode(Barcode_num)->newproduct->Restockproduct(Num_to_add);
	    return true;
}

//Return product with the matching barcode number
productDataBaseLL:: DataBaseLL* productDataBaseLL::foundbyBarcode(long unsigned int Barcode_num)
{
	if(tail==NULL)
	{
		cout<<"Sorry, the database is empty"<<endl;
		return NULL;
	}
	DataBaseLL *cur;
	DataBaseLL *found=NULL;
	cur=tail->next;

	while(cur!=tail)
	{
		if(cur->newproduct->getBarcode()==Barcode_num)
			found=cur;
		cur=cur->next;
	}

	if(cur->newproduct->getBarcode()==Barcode_num)
	{
		found=cur;
	}

	if(found==NULL)
	{
		cout<<"Sorry! NO matching product found, please try again."<<endl;
		return NULL;
	}
	return found;	
}

perishable * productDataBaseLL :: getperishable(long unsigned int Barcode_num)
{
	productDataBaseLL::DataBaseLL* found;
	found= this->foundbyBarcode(Barcode_num);
	if(found==NULL)
	{
		return NULL;
    }
	else
		return found->ptr;
}

bool productDataBaseLL::Dispose(long unsigned int Barcode_num, string currentdate)
{
	//DataBaseLL * found;
	if(this->foundbyBarcode(Barcode_num)==NULL)
		return false;
	if(this->checkexpiry(currentdate,Barcode_num)==1)
		return false;
	if(this->checkexpiry(currentdate,Barcode_num)==3)
		return false;

	this->RestockProduct(Barcode_num,(this->foundbyBarcode(Barcode_num)->newproduct->getNum_in_Stock())*(-1));
		return true;
}

product* productDataBaseLL::traverse (int index)
{
   DataBaseLL * cur;
   cur=tail->next;
   for(int i=0;i<index;i++)
	   cur=cur->next;
   if(cur->newproduct->get_ifperishable()=='y')
	   return cur->ptr;
   else 
	   return cur->newproduct;
}