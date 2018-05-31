#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
using namespace std;
int time1=0;

struct adjacency
{
char ele1;
adjacency *adj1;
};
adjacency *q,*q1;


struct node
{
char ele;
char clr;
int noa;//counts no of adjacent vertice s fior each.
int dtime;//discovery time
int ftime;//finish time
//node *pred;//stores the predecessor
adjacency *adj;
node *next;
};

ofstream file2;

node *start=NULL;
node *trail1,*p,*p1,*p2;
vector<char> d;
char *b;
char a[20][2];
int size,n=0;

void DFS(node *p)
{	adjacency *trail;
	//file2<<p->ele<<",";
	d.push_back(p->ele);
	//file2<<p->ele<<",";
	
	p->clr='g';	
	time1=time1+1;
	p->dtime=time1;	
	trail=p->adj;
	for(int i=0;i<p->noa;i++)
	{
	trail1=start;
	while(trail1->ele!=trail->ele1)
		{
		trail1=trail1->next;
		}
	if(trail1->clr=='w')
				{
//				trail1->pred=p;
				DFS(trail1);
				//d.push_back(trail1->ele);
				//for(int k=0;k<d.size();k++)
				//cout<<d[k];
				}

	trail=trail->adj1;
	}
	p->clr='b';
	time1=time1+1;
	p->ftime=time1;
/*					d.push_back(trail1->ele);
				for(unsigned int k=0;k<d.size();k++)
				cout<<d[k]<<"\t";
				cout<<"\n";
*/}
void sort(int size)
{
//cout<<" in bubble sort\t";
for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(b[j]>b[j+1])
			{
				int temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
//	for(int j=0;j<size;j++)
//		cout<<b[j];
	

}
void sort()
{
//cout<<" in bubble sort\t";
for(unsigned int i=0;i<d.size();i++)
	{
		for(unsigned int j=0;j<d.size()-i-1;j++)
		{
			if(d[j]>d[j+1])
			{
				int temp=d[j];
				d[j]=d[j+1];
				d[j+1]=temp;
			}
		}
	}
//	for(int j=0;j<size;j++)
//		cout<<b[j];
	

}
int main(int argc,char *argv[])
{
ifstream file1(argv[1]);
file2.open(argv[2]);
int count=0,i;
char line[20];
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
	{	
		for(i=0;i<size*2;i=i+2)
		{
			p=new node;
			p->ele=line[i];
			p->clr='w';
//			p->pred=NULL;
			p->adj=NULL;
			p->next=NULL;
			p->dtime=0;
			p->ftime=0;
			p->noa=0;		
			//arr[m++]=line[i];
			
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
//		 for(p=start;p!=NULL;p=p->next)
//		cout<<p->ele<<"\t";
		
	}


	else if(line[0]>='A' && line[0]<='z')
	{
		
	a[count-2][0]=line[0];
	a[count-2][1]=line[2];
//	cout<<a[count-2][0]<<a[count-2][1];	
	}
	count++;
}
}

//cout<<count<<"\n";
/*cout<<"\n elements are:::\n";
for(int i=0;i<=count-3;i++)
{for(int j=0;j<2;j++)
cout<<a[i][j]<<"   ";
cout<<"\n";
}

*/

p=start;
while(p!=NULL)
{
int cnt=0;
for(i=0;i<count-3;i++)
	if(p->ele==a[i][0]||p->ele==a[i][1])
	cnt++;


//cout<<"value of count="<<cnt;
b=new char[cnt];
int k=0;
for(int j=0;j<count-3;j++)
{
	if(k==cnt)
		break;
	else if(p->ele==a[j][0]||p->ele==a[j][1])
	{
	if(p->ele==a[j][0])
	b[k]=a[j][1];
	else
	b[k]=a[j][0];
	k++;
	}
}
p->noa=cnt;
if(cnt>0)
{sort(cnt);


q1=new adjacency;
q1->ele1=b[0];
q1->adj1=NULL;
p->adj=q1;
q=q1;
for(int k=1;k<p->noa;k++)
{
q1=new adjacency;
q1->ele1=b[k];
//cout<<"\nValue of the element"<<q1->ele1;
q1->adj1=NULL;
q->adj1=q1;
q=q1;
}
}


p=p->next;
}
/*
//printing the entire list
p=start;
while(p!=NULL)
{
cout<<p->ele<<p->clr<<p->dtime<<p->ftime<<"\n";
adjacency *trail1;
trail1=p->adj;
while(trail1!=NULL)
{
cout<<trail1->ele1<<"\t";
trail1=trail1->adj1;
}
p=p->next;
}
*/
for(p=start;p!=NULL;p=p->next)
{	//cout<<p->ele<<"\n";	
	if(p->clr=='w')
	{	DFS(p);
	unsigned int s;
	sort();
	for(s=0;s<d.size()-1;s++)
	file2<<d[s]<<",";
	file2<<d[s];
	file2<<"\n";
	d.clear();
	}

}
return 0;

}
