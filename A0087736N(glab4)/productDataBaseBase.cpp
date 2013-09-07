/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include"productDataBaseBase.h"
#include "API.h"
#include "UI.h"
#include <iostream>
API ctrl;

//Opening text file to read and to store the data using the respective List ADT
bool productDataBaseBase::inputfromfile(string s)
{
	ifstream inp;
	inp.open(s);
	if(!inp.is_open())
		return false;
	char  ifPerishable;
	long unsigned int bcode;
	double Price,Discount_percentage;
	string ch, pname,pcategory,pManufacturer,Expirydate;
	int Num_in_Stock,Num_sold_per_month,no_repeat;
	inp>>no_repeat;

	for(int i=0;i<no_repeat;i++)
	{
		inp>>ifPerishable;
		if(ifPerishable=='y')
		{	
			p1=new perishable();
			p1->setperi(ifPerishable);
			getline(inp,ch);
			getline(inp,pname);
			p1->setProduct_Name(pname);
			getline(inp,pcategory);
			p1->setCategory(pcategory);
			inp>>bcode;
			p1->setBarcode(bcode);
			inp>>Price;
			p1->setPrice(Price);
			getline(inp,ch);
			getline(inp,pManufacturer);
			p1->setManufacturer(pManufacturer);
			inp>>Num_in_Stock;
			p1->setNum_in_Stock(Num_in_Stock);
			inp>>Num_sold_per_month;
			p1->setNum_sold_per_month(Num_sold_per_month);
			getline(inp,ch);
			getline(inp,Expirydate);
			p1->setexpDate(Expirydate);
			inp>>Discount_percentage;
			p1->setDiscount_percentage(Discount_percentage);
			this->addnewproduct(p1);
			delete p1;
			p1=NULL;
		}
		else
		{	
			p=new product();
			p->setperi(ifPerishable);
			getline(inp,ch);	
			getline(inp,pname);
			p->setProduct_Name(pname);
			getline(inp,pcategory);
			p->setCategory(pcategory);
			inp>>bcode;
			p->setBarcode(bcode);
			inp>>Price;
			p->setPrice(Price);
			getline(inp,ch);
			getline(inp,pManufacturer);
			p->setManufacturer(pManufacturer);
			inp>>Num_in_Stock;
			p->setNum_in_Stock(Num_in_Stock);
			inp>>Num_sold_per_month;
			p->setNum_sold_per_month(Num_sold_per_month);
			this->addnewproduct(p);
			delete p;
			p=NULL;
		}	
	}
	
	inp.close();
	return true;
}

int productDataBaseBase::getsize() const
{
	return size;
}

int productDataBaseBase::setsize(int i) 
{
	size=i;
	return 0;
}

int productDataBaseBase::checkexpiry(string currentdate, long unsigned int Barcode_num)
{
	perishable *ptr=this->getperishable(Barcode_num);

	if(ptr==NULL)
		return 0;
	if(ptr->get_ifperishable()=='n')
		return 1;
	
	//Check expiry date by year
	string expirydate=ptr->getexpDate();
	for(int i=4;i<=7;i++)
	{ 
		if(currentdate[i]>expirydate[i])
			return 2;
		if(currentdate[i]<expirydate[i])
			return 3;
	}
	//Check expiry date by month
	for(int i=2;i<=3;i++)
	{ 
		if(currentdate[i]>expirydate[i])
			return 2;
		if(currentdate[i]<expirydate[i])
			return 3;
	}
	//Check expiry date by day
	for(int i=0;i<=1;i++)
	{ 
		if(currentdate[i]>expirydate[i])
			return 2;
		if(currentdate[i]<expirydate[i])
			return 3;
	}
	return 3;	   
}
 
 void productDataBaseBase::searchbyName(string Name)
 {	
	int i;
	bool found=false;
	for( i=0;i<this->getsize();i++)
	{	
		pointer=this->traverse(i);
		if(pointer->getProduct_Name()==Name)
		{
			ctrl.API_displayprofeatures(pointer);
			found=true;
		}
	}
	if(found==false)
		cout<<"Sorry No matched product found!"<<endl;
}

void productDataBaseBase::listallproducts()
{
	if(this->getsize()==0)
	{
		cout<<"Sorry,there is no product found!! "<<endl;
	}
	for(int i=0;i<this->getsize();i++)
	{	
		pointer=this->traverse(i);
		ctrl.API_displayprofeatures(pointer);
	}
}

void productDataBaseBase::searchbyManu(string Manufacturer)
{
	int i;
	bool found=false;
	for( i=0;i<this->getsize();i++)
	{	
		pointer=this->traverse(i);

		if(pointer->getManufacturer()==Manufacturer)
		{
			ctrl.API_displayprofeatures(pointer);
			found=true;
		}
	}
	if(found==false)
		cout<<"Sorry No matched product found!"<<endl;
}

void productDataBaseBase::searchbyBarcode(long unsigned int Barcode_num)
{
	int i;
	bool found=false;
	for( i=0;i<this->getsize();i++)
	{	
		pointer=this->traverse(i);

		if(pointer->getBarcode()==Barcode_num)
		{
			ctrl.API_displayprofeatures(pointer);
			found=true;
		}
	}
	if(found==false)
		cout<<"Sorry No matched product found!"<<endl;
}
		
void productDataBaseBase::searchbyCategory(string Category)
{
	int i;
	bool found=false;
	for( i=0;i<this->getsize();i++)
	{	
		pointer=this->traverse(i);

		if(pointer->getCategory()==Category)
		{
			ctrl.API_displayprofeatures(pointer);
			found=true;
		}
	} 
	if(found==false)
		cout<<"Sorry No matched product found!"<<endl;
}

void productDataBaseBase::TOPXsellingproduct(int x)
{
	int num=1;
	double high=0, gross, low, lowerbound=0, upperbound;

	//Searching for the highest gross value
	for(int i=0;i<this->getsize();i++)
	{	
		pointer=this->traverse(i);
		gross=(pointer->getNum_sold_per_month())*(pointer->getPrice());
		if(gross>high)
			high=gross;
	}

	if(high==0)
	{
		cout<<"sorry all the products have not been sold!";
		return;
	}
	cout<<"the No."<<num<<" selling products: "<<endl;

	//Print out all the products with gross revenue equal to the highest gross value
	for(int i=0;i<this->getsize();i++)
	{	
		pointer=this->traverse(i);
	    gross=(pointer->getNum_sold_per_month())*(pointer->getPrice());
		if(gross==high)
			ctrl.API_displayprofeatures(pointer);
	}

	low=high;
	
	//Finding the lowest gross value
	for(int i=0;i<this->getsize();i++)
	{	
		pointer=this->traverse(i);
		gross=(pointer->getNum_sold_per_month())*(pointer->getPrice());
		if(gross<low)
			low=gross;
	}

	upperbound=high;
	num++;
	bool isleft;

	//When finding 2 or more top selling products
	while(num<=x)
	{
		isleft=false;
		int i=0;

		//Finding the next top selling product
		for(i=0;i<this->getsize();i++)
		{     
			pointer=this->traverse(i);
			gross=(pointer->getNum_sold_per_month())*(pointer->getPrice());
			
			if(gross>lowerbound&&gross<upperbound)
		    { 
				high=gross;
				isleft=true;
				lowerbound=high;
		    } 
			
			if((this->getsize()-1)==i)
			{   
				lowerbound=0;
				upperbound=high;
				break;
		    }
		}
	  
		//When user request for the number of top selling products exceed the products in database
		if(isleft==false)
		{
			cout<<"sorry! not enough products for TOP "<<x<<"products";
			cout<<"The max number of the TOP X list is "<<num-1<<endl;
			return;
		}
		cout<<"the No."<<num<<" selling products: "<<endl;
    
		//Print out all the products with gross revenue equal to the next highest gross value
		for(int i=0;i<this->getsize();i++)
		{	 
			pointer=this->traverse(i);
			gross=(pointer->getNum_sold_per_month())*(pointer->getPrice());
			
			if(gross==high)
				ctrl.API_displayprofeatures(pointer);
		}
	num++;
	}
}

void productDataBaseBase::Bestsellingcategory(string Category)
{
	int found=-1;
	double high=0;
	int i=0;

	//Search for the best selling product in the given category
	for(i=0;i<this->getsize();)
	{	
		pointer=this->traverse(i);
		
		if(pointer->getPrice()*pointer->getNum_sold_per_month()>high&&pointer->getCategory()==Category)
		{
			high=pointer->getPrice()*pointer->getNum_sold_per_month();
			found=i;
		}
		else
			i++;
	}

	if(found==-1)
	{
		cout<<"Sorry! No such Category Found!";
		return;
	}

	if(high==0)
	{
		cout<<"Sorry! No product has been sold yet!";
		return;
	}
	
	//If the next best selling product has the same gross value, print it as well
	for(i=0;i<this->getsize();)
	{	
		pointer=this->traverse(i);
		
		if(pointer->getPrice()*pointer->getNum_sold_per_month()==high && pointer->getCategory()==Category)
		ctrl.API_displayprofeatures(pointer);
			i++;
	}
}

void productDataBaseBase::Bestsellingmanufacturer()
{
	struct newbasenode
	{
		string manu;
		double gross;
	};
	vector<newbasenode> newbase;

	bool found;

	for(unsigned int i=0; i<this->getsize(); i++)
	{
		found=false;
		pointer=this->traverse(i);
		
		for(unsigned int j=0;j<newbase.size();j++)
		{
			if(newbase.at(j).manu==pointer->getManufacturer())
			{
				newbase.at(j).gross+=pointer->getNum_sold_per_month()*pointer->getPrice();
				found=true;
			}
		}
	
		if(found==false)
		{
			newbasenode temp;
			temp.gross=pointer->getNum_sold_per_month()*pointer->getPrice();
			temp.manu=pointer->getManufacturer();
			newbase.push_back(temp);
		}
	}

	double high=0;

	for(unsigned int i=0;i<newbase.size();i++)
		if(newbase.at(i).gross>high)
			high=newbase.at(i).gross;

	if(high==0)
	{
		cout<<"Sorry no product has been sold!!"<<endl;
		return;
	}

	cout<<"The bestselling Manufacture:"<<endl;

	for(unsigned int i=0;i<newbase.size();i++)
		if(newbase.at(i).gross==high)
			cout<<newbase.at(i).manu<<endl;
}