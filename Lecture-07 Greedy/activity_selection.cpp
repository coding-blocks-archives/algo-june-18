#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int> p1,pair<int,int> p2){
	return p1.second < p2.second;
}

int main(){
	vector<pair<int,int> > v;
	int n;
	cin>>n;

	int s,e;
	for(int i=0;i<n;i++){
		cin>>s>>e;
		v.push_back(make_pair(s,e));
	}

	//Sort the Vector based upon end time.
	sort(v.begin(),v.end(),comp);

	//Activity Selection
	int act = 1;
	int last = v[0].second;

	for(int i=1;i<n;i++){
		if(v[i].first>=last){
			act++;
			last = v[i].second;
		}
	}
	cout<<act<<endl;

return 0;
}