#include<bits/stdc++.h>
using namespace std;

//HINT - for Sum It Up
//https://hack.codingblocks.com/contests/c/452/912
bool cmp1(vector<int> &a,vector<int> &b){
	//cout<<"Comparing "<<a.size() <<" and "<<b.size() <<endl;
	return a.size() > b.size();
}
bool cmp2(int &a,int &b){
	//cout<<"Comparing "<<a<<" and "<<b<<endl;
	return a < b;
}

int main(){

	vector<int> v;

	vector<vector<int> > v;
	v.reserve(200);

	int m,n;
	cin>>m;
	//cout<<m<<endl;

	for(int i=0;i<m;i++){
		
		cin>>n;
		//cout<<n<<" ";
		vector<int> tempV;

		for(int j=0;j<n;j++){
			int temp;
			cin>>temp;
			//cout<<temp<<" ";
			tempV.push_back(temp);
		}
		v.push_back(tempV);
	}

	//cout<<m<<endl;

	sort(v.begin(),v.end(),cmp1);

	for(int i=0;i<m;i++){
		sort(v[i].begin(),v[i].end(),cmp2);
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	//cout<<"Done";

return 0;
}