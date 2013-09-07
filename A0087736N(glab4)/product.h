/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//this class will be involved in the maintainance of the database which will be created in the following labs  
class product
{
	protected:
		//includes the properties of the product like name,category etc.
		char ifPerishable;
		string Name;
		string Category;
		long unsigned int Barcode_num;
		double Price;
		string Manufacturer;
		int Num_in_Stock;
		int Num_sold_per_month;
   
	public:
		product();
		product(char ifPerishable,string Name,string Category,long unsigned int Barcode_num,double Price,
			string Manufacturer,int Num_in_Stock,int Num_sold_per_month);
		//getter functions of  the above properties
		virtual char get_ifperishable() const;
		virtual string getProduct_Name() const;
		virtual string getCategory() const;
		virtual long unsigned int getBarcode() const;
		virtual double getPrice() const;
		virtual string getManufacturer() const;
		virtual int getNum_in_Stock() const;
		virtual int getNum_sold_per_month() const;
		virtual void Resetproductsale();
		virtual bool Sellproduct(int Num_to_sell);
		virtual bool Restockproduct(int Num_to_add);
		virtual string getexpDate() const;
		virtual double getDiscount_percentage() const;
		void setperi(char);
		void setProduct_Name(string);
		void setCategory(string);
		void setBarcode(long unsigned int);
		void setPrice(double);
		void setManufacturer(string);
		void setNum_in_Stock(int);
		void setNum_sold_per_month(int);
};
#endif
