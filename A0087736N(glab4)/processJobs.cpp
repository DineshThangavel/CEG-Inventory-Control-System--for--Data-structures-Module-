/* ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
 CG1103  G-Lab 3.
 Discussion Group: C3-20
 (Names and matric numbers of all group members)
 Yang Mo  A0091836X
 Dinesh Thangavel A0088592M
 Yong Jia Hong A0087736N
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ */

#include"processJobs.h"
#include <iostream>

bool processJobs::inputfromfile(string s)
{
	int Num_of_user, Num_of_jobs, Num_in_Stock, Num_to_Add, Num_to_Sell, i, j;
	string userName, ch, jobOp, pname, pcategory, pManufacturer, Currentdate;
	long unsigned int bcode;
	double Price;
	stack<queue<jobs>> *stackQueue;
	stackQueue=new stack<queue<jobs>>;

	ifstream inp;
	inp.open(s);
	if(!inp.is_open())
		return false;
	inp>>Num_of_user;
	
	getline(inp,ch);
	for(i=0; i<Num_of_user; i++)
	{
		queue<jobs> *jobsnew;
		jobsnew=new queue<jobs>;
		getline(inp,userName);
		inp>>Num_of_jobs;
		getline(inp,ch);

		for(j=0; j<Num_of_jobs; j++)
		{
			jobs *job_details=new jobs;
			getline(inp,jobOp);
		
			if(jobOp=="ADD")
			{
				job_details->jobOp=jobOp;
				job_details->userName=userName;
				getline(inp,pname);
				job_details->pname=pname;
				getline(inp,pcategory);
				job_details->pcategory=pcategory;
				inp>>bcode;
				job_details->bcode=bcode;
				inp>>Price;
				job_details->Price=Price;
				getline(inp,ch);
				getline(inp,pManufacturer);
				job_details->pManufacturer=pManufacturer;
				inp>>Num_in_Stock;
				job_details->Num_in_Stock=Num_in_Stock;
				getline(inp,ch);
			}
			if(jobOp=="DELETE")
			{
				job_details->jobOp=jobOp;
				job_details->userName=userName;
				inp>>bcode;
				job_details->bcode=bcode;
				getline(inp,ch);
			}
			if(jobOp=="RESTOCK")
			{
				job_details->jobOp=jobOp;
				job_details->userName=userName;
				inp>>bcode;
				job_details->bcode=bcode;
				inp>>Num_to_Add;
				job_details->Num_to_Add=Num_to_Add;
				getline(inp,ch);
			}
			if(jobOp=="DISPOSE")
			{
				job_details->jobOp=jobOp;
				job_details->userName=userName;
				inp>>bcode;
				job_details->bcode=bcode;
				getline(inp,ch);
				getline(inp,Currentdate);
				job_details->Currentdate=Currentdate;
			}
			if(jobOp=="SALE")
			{
				job_details->jobOp=jobOp;
				job_details->userName=userName;
				inp>>bcode;
				job_details->bcode=bcode;
				inp>>Num_to_Sell;
				job_details->Num_to_Sell=Num_to_Sell;
				getline(inp,ch);
			}
			jobsnew->push(*job_details);
			delete job_details;
		}
		stackQueue->push(*jobsnew);
		delete jobsnew;
	}
	queueStack.push(*stackQueue);
	delete stackQueue;
	inp.close();
	return true;
}

int processJobs::getNum_of_users()
{
	return queueStack.size();
}

void processJobs::proceedjobs(productDataBaseBase * database)
{
	ofstream out;
	out.open("log.txt");
	if(!out.is_open())
	{
		cout<<"error in opening";
		return;
	}

	while(!queueStack.empty())
	{
		stack<queue<jobs>> stackQueue;
		stackQueue=queueStack.front();

		while(!stackQueue.empty())
		{
			queue<jobs> jobs_for_one;
			jobs_for_one=stackQueue.top();
		
			while(!jobs_for_one.empty())
			{
				jobs job_to_do;
				job_to_do=jobs_for_one.front();
		
				if(dojobs(job_to_do,database)==false)
				{
					out<<job_to_do.bcode<<"  ";
					out<<job_to_do.jobOp<<"  ";
					out<<job_to_do.userName<<endl;
				}
				jobs_for_one.pop();
			}
			stackQueue.pop();
		}
		queueStack.pop();
	}
	out.close();
}

bool processJobs::dojobs(jobs job_to_do,productDataBaseBase * database)
{
	if(job_to_do.jobOp=="ADD")
	{
		product *p;
		p= new product('n',job_to_do.pname,job_to_do.pcategory,job_to_do.bcode,job_to_do.Price,job_to_do.pManufacturer,job_to_do.Num_in_Stock,0);
		if(database->addnewproduct(p))
			return true;
		else 
			return false;
	}

	if(job_to_do.jobOp=="DELETE")
	{
		if(database->deleteproduct(job_to_do.bcode))
			return true;
		else
			return false;
	}

	if(job_to_do.jobOp=="RESTOCK")
	{
		if(database->RestockProduct(job_to_do.bcode,job_to_do.Num_to_Add))
			return true;
		else
			return false;
	}

	if(job_to_do.jobOp=="SALE")
	{
		if(database->SellProduct(job_to_do.bcode,job_to_do.Num_to_Sell))
			return true;
		else
			return false;
	}

	if(job_to_do.jobOp=="DISPOSE")
	{
		if(database->Dispose(job_to_do.bcode,job_to_do.Currentdate))
			return true;
		else 
			return false;
	}
}

