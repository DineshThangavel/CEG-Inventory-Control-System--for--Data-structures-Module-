/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#ifndef VECTORADT_H
#define VECTORADT_H
#include <vector>
#include "productDataBaseBase.h"
#include "product.h"
#include "API.h"

class vectoradt:public productDataBaseBase
{
	private:
		vector<perishable> _vdatabasep;
	
	public:
		vectoradt();
		bool addnewproduct(product *p);
		void addnewproduct(perishable*);
		bool deleteproduct(long unsigned int Barcode_num);
		void ResetProductSale(long unsigned int Barcode_num);
		bool SellProduct(long unsigned int Barcode_num,int);
		bool RestockProduct(long unsigned int Barcode_num,int);
		int findproduct(long unsigned int barcode);
		bool writetofile(string,int size);
		perishable * getperishable(long unsigned int Barcode_num);
		bool Dispose(long unsigned int Barcode_num, string currentdate);
		product* traverse (int);
};
#endif
