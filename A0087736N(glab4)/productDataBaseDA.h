/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#ifndef PRODUCTDATABASEDA_H
#define PRODUCTDATABASEDA_H
#include "productDataBaseBase.h"
#include "product.h"
#include <stdio.h>

#define ARRAYSIZE 10

using namespace std;

class productDataBaseDA:public productDataBaseBase
{
	private:
		int initialSize, i, size2, curPos;
	
	struct DataBaseDA
	{
		product *newProduct;
		perishable *newPerishable;
	};
	
	DataBaseDA* DA;

	public:
		productDataBaseDA();
		bool writetofile(string,int);
		bool addnewproduct(product *p);
		void addnewproduct(perishable*);
		bool deleteproduct(long unsigned int Barcode_num);
		void ResetProductSale(long unsigned int Barcode_num);
		bool SellProduct(long unsigned int Barcode_num, int Num_to_sell);
		bool RestockProduct(long unsigned int Barcode_num, int Num_to_add);
		DataBaseDA* foundbyBarcode(long unsigned int Barcode_num);
		perishable* getperishable(long unsigned int Barcode_num);
		bool Dispose(long unsigned int Barcode_num, string currentdate);
		product* traverse (int);
};
#endif