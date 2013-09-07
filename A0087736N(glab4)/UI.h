/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#ifndef UI_H
#define UI_H
#include "API.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class UI
{
	private:
		API user_API;
		string password;
	
	public:
		UI();
		//functions that involve display of output and accepting the input
		void keeppassword();
		void loadpassword();
		void toAPI_initialize();//new
		void getmainpage();
		void getstatspage();
		void UI_TOPXsellingproduct();
		void UI_bestsellingcategory();
		void UI_BestsellingManufacturer();
		void UI_addnewproduct();
		void UI_deleteproduct();
		void UI_ResetProductSale();
		void UI_SellProuct(int type);
		void UI_RestockProduct();
		void UI_ListAllProducts();
		void UI_LoadData();
		void UI_CheckExpiry(int type);
		void ClearScreen();
		void UI_search(int type);
		void UI_writetofile();
		void UI_LoadJobData();
		void UI_proceedJobs();
		void UI_display_pro_features(product*);
		bool checkpassword(string password);
		void getnormaluserpage();
		void setpassword(string newpassword);
		void changepassword(string newpassword);
		string encrypt(string password);
		string decrypt(string encpw);
};
#endif 