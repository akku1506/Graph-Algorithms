#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;


struct node
{
char ele;
node *adj;
node *next;
};

node *start=NULL;
node *trail,*p,*p1,*p2;


int main(int argc,char *argv[])
{

char line[20],arr[20];
int count=0,i,size,frequency[20];
ifstream file1(argv[1]);
ofstream file2(argv[2]);
while(!file1.eof())
{
	if(!file1.eof())
	{
	file1.getline(line,20);
	if(count==0)
		{	int k=0;
			char f[20];
			for(;line[k]!=',';k++)
				f[k]=line[k];
			size=atoi(f);
			//cout<<size<<"\n";
		}
	else if(count==1)
	{	int m=0;
		for(i=0;i<size*2;i=i+2)
		{
			p=new node;
			p->ele=line[i];
			p->adj=NULL;
			p->next=NULL;		
			arr[m++]=line[i];
			
			if(start==NULL)
			{
				start=p;
				p2=p;
			}
			else
			{
				p2->next=p;
				p2=p;
			}	
		}
		//for(p=start;p!=NULL;p=p->next)
		//	cout<<p->ele<<"\t";
	}
	else if(line[0]>=65&&line[0]<=117)
	{
	char x=line[0];
	char y=line[2];
	//cout<<"x\t"<<x<<"\ty\t"<<y<<"\n";
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
	count++;
	}
}
file1.close();

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
int cnt;
//cout<<"size is"<<size;
/*for(int j=0;j<size;j++)
cout<<arr[j]<<" "<<"===";
*/
for(int j=0;j<size;j++)
{
	//cout<<"\n";
	//cout<<"arrayelement"<<arr[j]<<"\t";
	int flag;
	p=start;	
	node *trail1;
	cnt=0;
	while(p!=NULL)
	{
		flag=0;
		//cout<<"element"<<p->ele<<"\t";
		trail1=trail=p;
		if(p->ele==arr[j])
		{	trail1=trail1->adj;
			while(trail1!=NULL)
			{
				cnt++;
				//cout<<"count"<<cnt<<"\t";
				trail1=trail1->adj;
					
			}
			flag=1;
		}
		//cout<<"flag"<<flag<<"\t";
		if(flag==0)
		{
			while(trail!=NULL)
			{
				if(trail->ele==arr[j])
				cnt++;
				trail=trail->adj;
							
			}
			//cout<<"count"<<cnt<<"\t";
		}
		p=p->next;
	}
	frequency[j]=cnt;
	//cout<<frequency[j]<<"\t";
}
int j;
for(j=0;j<size-1;j++)
file2<<arr[j]<<" "<<frequency[j]<<"\n";
file2<<arr[j]<<" "<<frequency[j];






return 0;
}
