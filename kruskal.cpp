//minimum spanning tree using kruskal approach

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

//set and its iterator declarations
set< set < char> > sets;
set<char>::iterator s1;
set < set <char> >::iterator sets1,sets2;

ofstream file2;				//file declaration

struct matrix
{
	char edge1;
	char edge2;
	int wt;
}adj;

vector<matrix> arr;

int size,s=1;	
			
bool sort1(matrix a,matrix b)
{
	return (a.wt<b.wt);
}



//finds whether they have same or different set
int findset(char u,char v)
{
	for(sets1=sets.begin();sets1!=sets.end();sets1++)
	{
	s1=sets1->find(u);
	if(s1!=sets1->end())
	break;
	}
	for(sets2=sets.begin();sets2!=sets.end();sets2++)
	{
	s1=sets2->find(v);
	if(s1!=sets2->end())
	break;
	}
	if(sets1==sets2)
	return 0;
	else 
	return 1;
}

//combines the two different sets
void unionset(char u,char v)
{

	if(s==size-1)
	file2<<u<<","<<v;
	else
	file2<<u<<","<<v<<"\n";
	set<char> s3;
	for(s1=sets1->begin();s1!=sets1->end();s1++)
	s3.insert(*s1);
	for(s1=sets2->begin();s1!=sets2->end();s1++)
	s3.insert(*s1);
	sets.erase(sets1);
	sets.erase(sets2);
	sets.insert(s3);
	s++;
}


int main(int argc,char*argv[])
{
	char line[20];
	int count=0,i;
	ifstream file1(argv[1]);
	file2.open(argv[2]);
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
		set<char> s;
		s.insert(line[i]);
		sets.insert(s);
		}
	}
	else if(line[0]>='a' && line[0]<='z')
	{
	//matrix adj;
	adj.edge1=line[0];
	adj.edge2=line[2];
	int k=4,m=0;
	char f[20];
	for(;line[k]>='0'&&line[k]<='9';k++)
			f[m++]=line[k];
	f[m]='\0';	
	adj.wt=atoi(f);		
	arr.push_back(adj);
	}
	count++;
	}
	}
	file1.close();

	//for(unsigned int k=0;k<arr.size();k++)
	//cout<<arr[k].edge1<<arr[k].edge2<<arr[k].wt;
	//cout<<count<<"\n";	
	sort(arr.begin(),arr.end(),sort1);
	//for(unsigned int k=0;k<arr.size();k++)
	//cout<<arr[k].edge1<<arr[k].edge2<<arr[k].wt;
	//cout<<"\n array size"<<arr.size();
	while(!arr.empty())
	{
	char u=arr.front().edge1;
	char v=arr.front().edge2;
	//cout<<u<<v;
	int x=findset(u,v);
	//cout<<x;
	if(x==1)
	unionset(u,v);
	arr.erase(arr.begin());

	}
	return 0;
}
