#include<iostream>
#include<queue>
#include<vector>
using namespace std;




int main()
{
//BY default- It is MAX HEAP
//greater<int> implies it is MIN HEAP
	priority_queue<int,vector<int>,greater<int> > h;
	for(int i=0;i<10;i++)
	{
	     h.push(i);
	}
	//h.push(4);
	//h.push(2);

	while(!h.empty())
	{
	    cout<<h.top()<<endl;
	    h.pop();
	}
}