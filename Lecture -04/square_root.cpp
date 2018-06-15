#include<iostream>
using namespace std;


float squareRoot(int n,int p){
	int s= 0;
	int e = n;

	float ans = -1;
	while(s<=e){
		int mid = (s+e)/2;
		
		if(mid*mid==n){
			ans = mid;
			break;
		}
		else if(mid*mid<n){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid  - 1;
		}

	}
	//Loop - Linear Search
	float inc = 0.1; 
	for(int place=0;place<p;place++){
		while(ans*ans<=n){
			ans += inc;
		}
		ans = ans - inc;
		inc /= 10.0;
	}

	return ans;

}

int main(){
	int n,p;
	cin>>n>>p;
	cout<<squareRoot(n,p)<<endl;

}