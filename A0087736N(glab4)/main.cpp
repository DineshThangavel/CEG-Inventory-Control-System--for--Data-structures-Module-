/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include <iostream>
#include "API.h"
#include "UI.h"
#include <Windows.h>
using namespace std;

int main()
{   
	HANDLE outputScreen;
	outputScreen = GetStdHandle(STD_OUTPUT_HANDLE);

	int trynum=0;
	string password;
	string ch;
	UI user;
	user.toAPI_initialize();//new
	SetConsoleTextAttribute(outputScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"Choose your status: "<<endl;
	cout<<"1.Normal user    2. Manager   3.Exit"<<endl;
	int choice;
	cin>>choice;

	if(choice==1)
		user.getnormaluserpage();
	if(choice==2)
	{
		getline(cin,ch);

		while(trynum<5)
		{
			cout<<"Password: ";
			getline(cin,password);
		
			if(user.checkpassword(password))
			{
				user.getmainpage();
				getchar();
				getchar();
				return 0;
			}   
			else
			{
				SetConsoleTextAttribute(outputScreen,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"sorry, wrong password!"<<endl;
				trynum++;
		    }
		}
		cout<<"Sorry, you have exceeded the allowed trying times! Program will exit now!";
		getchar();
		getchar();
		return 0;
	}
	if(choice==3)
		return 0;
}