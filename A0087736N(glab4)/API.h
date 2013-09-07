/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#ifndef API_H
#define API_H
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "productDataBaseBase.h"
#include "productDataBaseLL.h"
#include "productDataBaseDA.h"
#include "vectoradt.h"
#include "processJobs.h"

using namespace std;

class API
{
	private:
		productDataBaseBase* database;
		product pointer;
		
	public:
		void API_initialize(int choice);//new
		//these are the functions to add new product ,scrap  products,reset sales etc.The return and 
			//input parameters might be modified in the future labs depending on the implementation
		bool API_addnewproduct(product* p);//new
		void API_addnewproduct(perishable* p1);
		bool API_scrapproduct(long unsigned int Barcode_num);//new
		void API_ResetProductSale(long unsigned int Barcode_num);
		bool API_SellProduct(long unsigned int Barcode_num,int Num_to_sell);//new
		bool API_RestockProduct(long unsigned int Barcode_num,int Num_to_add);//new
		void API_ListAllProducts();
		bool API_LoadData(string);
		bool API_CheckExpiry(string currentdate, long unsigned int Barcode_num);//new
		void API_TOPXsellingproduct(int x);
		void API_bestsellingcategory(string Category);
		void API_BestsellingManufacturer();
		void API_search(int choice, int type);
		bool API_writetofile(string s);
		bool API_loadJobData(string s);
		void API_proceedjobs();
		void API_displayprofeatures(product*);
		bool API_checkInt(string toCheck);
		bool API_checkDouble(string toCheck);
		~API();
};
#endif 