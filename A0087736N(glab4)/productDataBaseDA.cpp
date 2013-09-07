/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include "productDataBaseDA.h"
#include "product.h"
#include "perishable.h"
#include <iostream>

//Initial size of array of products is 10
productDataBaseDA::productDataBaseDA()
{
	//size2 is current size of array
	DA=new DataBaseDA[ARRAYSIZE];
	initialSize=ARRAYSIZE, size2=0, curPos=0;
}

//The write to file method is different for the three different list ADT 
bool productDataBaseDA::writetofile(string s,int size)
{
    ofstream out;
	out.open(s);
	if(!out.is_open())
		return false;
	if(size==0)
		return false;

	out<<size2<<endl;
	DataBaseDA *ptr=DA;

	for(i=0; i<size2; i++)
	{
		if(ptr[i].newProduct->get_ifperishable()=='y')
		{   
			out<<ptr[i].newPerishable->get_ifperishable()<<"\n";
			out<<ptr[i].newPerishable->getProduct_Name()<<"\n";
			out<<ptr[i].newPerishable->getCategory()<<"\n";
			out<<ptr[i].newPerishable->getBarcode()<<"\n";
			out<<ptr[i].newPerishable->getPrice()<<"\n";
			out<<ptr[i].newPerishable->getManufacturer()<<"\n";
			out<<ptr[i].newPerishable->getNum_in_Stock()<<"\n";
			out<<ptr[i].newPerishable->getNum_sold_per_month()<<"\n";
			out<<ptr[i].newPerishable->getexpDate()<<"\n";
			out<<ptr[i].newPerishable->getDiscount_percentage()<<"\n";
		}
		if(ptr[i].newProduct->get_ifperishable()=='n')
		{
			out<<ptr[i].newProduct->get_ifperishable()<<"\n";
			out<<ptr[i].newProduct->getProduct_Name()<<"\n";
			out<<ptr[i].newProduct->getCategory()<<"\n";
			out<<ptr[i].newProduct->getBarcode()<<"\n";
			out<<ptr[i].newProduct->getPrice()<<"\n";
			out<<ptr[i].newProduct->getManufacturer()<<"\n";
			out<<ptr[i].newProduct->getNum_in_Stock()<<"\n";
			out<<ptr[i].newProduct->getNum_sold_per_month()<<"\n";
		}
	}
	return true;
	out.close();
}

bool productDataBaseDA::addnewproduct(product *p)
{
	productDataBaseDA::DataBaseDA newnode;
	newnode.newProduct=new product(p->get_ifperishable(),p->getProduct_Name(),p->getCategory(),p->getBarcode(),
		p->getPrice(),p->getManufacturer(),p->getNum_in_Stock(),p->getNum_sold_per_month());
	newnode.newPerishable=NULL;

	DataBaseDA *ptr=DA;
	for(i=0; i<size2; i++)
	{
		if(ptr[i].newProduct->getBarcode()==newnode.newProduct->getBarcode())
			return false;
	}

	//When adding products and size of array is reached, double the array
	if(size2==initialSize)
	{
		initialSize*=2;
		DataBaseDA *newDA=new DataBaseDA[initialSize];
		for(i=0; i<size2; i++)
		{
			newDA[i]=DA[i];
		}
		delete DA;
		DA=newDA;
	}
	
	DA[size2]=newnode;
	size2++;
	this->setsize(size2+1);
	return true;
}

//When adding perishable product, add the same perishable product attributes to the product as well, the operations is based on
	//searching through products
void productDataBaseDA::addnewproduct(perishable* p1)
{
	productDataBaseDA::DataBaseDA newnode;
	newnode.newPerishable=new perishable(p1->get_ifperishable(),p1->getProduct_Name(),p1->getCategory(),p1->getBarcode(),
		p1->getPrice(),p1->getManufacturer(),p1->getNum_in_Stock(),p1->getNum_sold_per_month(),p1->getexpDate(),p1->getDiscount_percentage());
	newnode.newProduct=newnode.newPerishable;

	if(size2==initialSize)
	{
		initialSize*=2;
		DataBaseDA *newDA=new DataBaseDA[initialSize];
		for(i=0; i<size2; i++)
		{
			newDA[i]=DA[i];
		}
		delete DA;
		DA=newDA;
	}
	
	DA[size2]=newnode;
	this->setsize(size2+1);
	size2++;
}

bool productDataBaseDA::deleteproduct(long unsigned int Barcode_num)
{
	if(size2==NULL)
	{
		cout<<"Sorry, the database is empty"<<endl;
		return false;
	}

	DataBaseDA *ptr=DA;
	DataBaseDA found;
	found.newProduct=NULL;

	//Searching for the product and get the current position of product to be deleted
	for(i=0; i<size2; i++)
	{
		if(ptr[i].newProduct->getBarcode()==Barcode_num)
		{
			found.newProduct=ptr[i].newProduct;
			curPos=i;
			break;
		}
	}

	//In case the product to be deleted is not in database
	if(found.newProduct == NULL)
	{
		cout<<"Sorry! NO matching product found to delete, please try again."<<endl;
		return false;
	}

	//Overwrite the item to be deleted with the next product in the array
	for(i=curPos; i<size2-1; i++)
	{
		ptr[i]=ptr[i+1];
	}

	//Deleting the product if the product to be deleted is in array
	delete found.newProduct;
	//Decrease the size of the array
	size2-=1;
	cout<<"Product with Barcode_num: "<<Barcode_num<<" has been deleted!"<<endl;
	return true;
}

void productDataBaseDA::ResetProductSale(long unsigned int Barcode_num)
{
	if(foundbyBarcode(Barcode_num)==NULL)
	{
		cout<<"sorry wrong Barcode number"<<endl;
	    return;
	}
	foundbyBarcode(Barcode_num)->newProduct->Resetproductsale();
}

bool productDataBaseDA::SellProduct(long unsigned int Barcode_num, int Num_to_sell)
{
	if(foundbyBarcode(Barcode_num)==NULL)
	{
		cout<<"sorry wrong Barcode number"<<endl;
	    return false;
	}
	if(foundbyBarcode(Barcode_num)->newProduct->Sellproduct(Num_to_sell))
		return true;
	else
		return false;
}
		
bool productDataBaseDA::RestockProduct(long unsigned int Barcode_num, int Num_to_add)
{
	if(foundbyBarcode(Barcode_num)==NULL)
	{
		cout<<"sorry wrong Barcode number"<<endl;
	    return false;
	}
	if(foundbyBarcode(Barcode_num)->newProduct->Restockproduct(Num_to_add))
		return true;
	else
		return false;
}

//Return product with the matching barcode number
productDataBaseDA::DataBaseDA* productDataBaseDA::foundbyBarcode(long unsigned int Barcode_num)
{
	if(size2==0)
	{
		cout<<"Sorry, the database is empty"<<endl;
		return NULL;
	}
	DataBaseDA *ptr=DA;
	DataBaseDA *found=NULL;

	for(i=0; i<size2; i++)
	{
		if(ptr[i].newProduct->getBarcode()==Barcode_num)
		{
			found=&ptr[i];
			break;
		}
	}

	if(found==NULL)
	{
	   cout<<"Sorry! NO matching product found, please try again."<<endl;
	   return NULL;
	}
	return found;	
}

perishable * productDataBaseDA :: getperishable(long unsigned int Barcode_num)
{
	productDataBaseDA::DataBaseDA* found;
	found= this->foundbyBarcode(Barcode_num);
	if(found==NULL)
	{
		return NULL;
    }
	else
		return found->newPerishable;
}

bool productDataBaseDA::Dispose(long unsigned int Barcode_num, string currentdate)
{
	DataBaseDA *found;

	if(this->foundbyBarcode(Barcode_num)!=NULL)
		found=this->foundbyBarcode(Barcode_num);
	else 
		return false;

	if(this->checkexpiry(currentdate,Barcode_num)==1)
		return false;
	if(this->checkexpiry(currentdate,Barcode_num)==3)
		return false;

	this->RestockProduct(Barcode_num,(this->foundbyBarcode(Barcode_num)->newProduct->getNum_in_Stock())*(-1));
	return true;
}

product* productDataBaseDA::traverse (int index)
{
	product *ptr1;

	ptr1=DA[index].newProduct;
	if(ptr1->get_ifperishable()=='y')
		return DA[index].newPerishable;
	else
	    return ptr1;
}