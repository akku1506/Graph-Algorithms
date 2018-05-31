#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>


using namespace std;


struct node
{
int ele;
node *adj;
node *next;
};

node *start=NULL;
node *trail,*p,*p1,*p2;

int main(int argc,char *argv[])
{
char line[20],arr[20];
int count=0,path[20],q=0;
ifstream file1(argv[1]);
ofstream file2(argv[2]);
while(!file1.eof())
{
	if(!file1.eof())
	{
	file1.getline(line,20);
	if(line[0]>='0' && line[0]<='9')
	count++;
	}
}
//cout<<count;
file1.close();
ifstream file3(argv[1]);
int g=0;

while(!file3.eof())
{

if(!file3.eof())
{
	file3.getline(line,20);
	//cout<<line;
	if(g==1)
		{
		int k=0;
		for(int l=0;line[l]==','||(line[l]>='0'&&line[l]<='9');l=l+1)		
		{
		
		if(line[l]==',')
		{	
		
		//int x;
		//cout<<x;
		p=new node;
		p->adj=NULL;
		p->next=NULL;
		p->ele=atoi(arr);
		//cout<<"p->ele"<<p->ele<<"\n";
		//cout<<"printing";
		if(start==NULL)
				start=p;
			
		else
				p2->next=p;
				
		p2=p;	
		//l=l+k+1;
		k=0;
		}
		else
		arr[k++]=line[l];
		//cout<<start->ele;
		//cout<<l<<"\t";		
		}
		p=new node;
		p->adj=NULL;
		p->next=NULL;
		p->ele=atoi(arr);
		p2->next=p;
		//cout<<"\n";
		//cout<<"g=2";		
		//for(p=start;p!=NULL;p=p->next)
		//cout<<p->ele<<"\t";

		}

	else if(g>=2 && g<count-1)
	{
	//cout<<"lop2";
	int x;
	int y,k=0;
	for(int l=0;line[l]==','||(line[l]>='0'&&line[l]<='9');l=l+1)		
	{
		
		if(line[l]==',')
		{
		x=atoi(arr);
		k=0;
		}
		else
		arr[k++]=line[l];		
		}
	y=atoi(arr);
	p=start;
	p1=new node;
	p1->ele=y;
	p1->adj=NULL;
	p1->next=NULL;
	while(p!=NULL)
	{
		if(p->ele==x)
		{
			p2=p;
			while(p2!=NULL)
			{
				trail=p2;
				p2=p2->adj;
			}
			trail->adj=p1;
			break;
		}
		p=p->next;
	}


}

else if(g==count-1)
{
	
	int m=0,k=0;
	for(;line[m]==','||(line[m]>='0'&&line[m]<='9');m++)	
	{
	if(line[m]==',')
	{
	path[q++]=atoi(arr);	
	k=0;
	}
	else
	arr[k++]=line[m];

	}
	path[q]=atoi(arr);
	//cout<<"path\n";
	//for(int f=0;f<=q;f++)	
	//cout<<path[f]<<"\t";	
	


}



g++;
//cout<<"value of g"<<g<<"\n";
}

}
file3.close();

/*p=start;
for(;p!=NULL;p=p->next)
{
	trail=p;
	cout<<p->ele<<"\t";
	while(trail!=NULL)
	{
		cout<<trail->ele<<"\t";
		trail=trail->adj;

	}
	cout<<"\n";
}
*/
//file1.close();
int flag2,flag1;
for(int j=0;j<q;j++)
{
//cout<<"hellb";
p=start;	
node *trail1;
while(p!=NULL)
	{
		flag1=0;
		//cout<<"element"<<p->ele<<"\t";
		trail1=trail=p;
		if(p->ele==path[j])
		{	trail1=trail1->adj;
			while(trail1!=NULL)
			{
				if(trail1->ele==path[j+1])	
				{//cout<<"count"<<cnt<<"\t";
				flag1=1;				
				
								
				}
				trail1=trail1->adj;	
			}
			if(flag1==0)
			{

		//cout<<"final0";
			flag2=1;
			break;
			}
		}
		
		p=p->next;
	}
//if(flag1==0)
//	break;
}
if(flag2!=1)
file2<<"1";
else 
file2<<"0";


return 0;
}
