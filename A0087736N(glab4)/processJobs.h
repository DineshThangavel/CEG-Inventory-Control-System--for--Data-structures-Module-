/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#ifndef PROCESSJOBS_H
#define PROCESSJOBS_H
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include "productDataBaseBase.h"
#include "productDataBaseLL.h"
#include "productDataBaseDA.h"
#include "vectoradt.h"
#include <iostream>

using namespace std;

class processJobs
{
	private:
		struct jobs
		{
			long unsigned int bcode;
			string pname, pcategory, pManufacturer, Currentdate, userName, jobOp;
			double Price;
			int Num_in_Stock, Num_to_Add, Num_to_Sell;
		};

		queue<stack<queue<jobs>>> queueStack;

	public:
		bool inputfromfile(string);
		int getNum_of_users();
		void proceedjobs(productDataBaseBase * database);
		bool dojobs(jobs job_to_do,productDataBaseBase * database);
};
#endif