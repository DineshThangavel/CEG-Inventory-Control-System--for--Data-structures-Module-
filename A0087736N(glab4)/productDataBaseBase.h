/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#ifndef PRODUCTDATABASEBASE_H
#define PRODUCTDATABASEBASE_H
#include <fstream>
#include <string>
#include "product.h"
#include "perishable.h"

using namespace std;

class productDataBaseBase
{
	protected:
		int size;
		product* p,*pointer;
		perishable* p1;

	public:
		bool inputfromfile(string);
		int getsize() const;
		int setsize(int);
		virtual bool addnewproduct(product *p)=0;
		virtual void addnewproduct(perishable *p1)=0;
		void listallproducts();
		virtual bool deleteproduct(long unsigned int Barcode_num)=0;
		void searchbyName(string Name);
		void searchbyManu(string Manufacturer);
		void searchbyBarcode(long unsigned int Barcode_num);
		void searchbyCategory(string Category);
		virtual void ResetProductSale(long unsigned int Barcode_num)=0;
		virtual bool SellProduct(long unsigned int Barcode_num,int Num_to_sell)=0;
		virtual bool RestockProduct(long unsigned int Barcode_num,int Num_to_add)=0;
		void TOPXsellingproduct(int x);
		void Bestsellingcategory(string Category);
		void Bestsellingmanufacturer();
		virtual bool writetofile(string,int size)=0;
		virtual perishable * getperishable(long unsigned int Barcode_num)=0;
		int checkexpiry(string currentdate, long unsigned int Barcode_num);
		virtual bool Dispose(long unsigned int Barcode_num, string currentdate)=0;
		virtual product* traverse(int )=0;
};
#endif