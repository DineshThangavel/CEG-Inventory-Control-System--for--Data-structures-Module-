/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#ifndef PRODUCTDATABASELL_H
#define PRODUCTDATABASELL_H
#include "productDataBaseBase.h"
#include "product.h"

class productDataBaseLL:public productDataBaseBase
{
	private:
		struct DataBaseLL
		{
			product *newproduct;
			DataBaseLL* next;
			DataBaseLL* prev;
			perishable *ptr;
		};

    DataBaseLL* tail;

	public:
		productDataBaseLL();
		bool writetofile(string,int);
		bool addnewproduct(product *p);
		void addnewproduct(perishable* p1);
		bool deleteproduct(long unsigned int Barcode_num);
		void ResetProductSale(long unsigned int Barcode_num);
		bool SellProduct(long unsigned int Barcode_num,int Num_to_sell);
		bool RestockProduct(long unsigned int Barcode_num,int Num_to_add);
		DataBaseLL* foundbyBarcode(long unsigned int Barcode_num);
		perishable* getperishable(long unsigned int Barcode_num);
		bool Dispose(long unsigned int Barcode_num, string currentdate);
		product* traverse (int);
};
#endif
