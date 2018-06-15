#include<iostream>
using namespace std;


bool canPlace(int cows,int stalls[],int dist,int n){

	int c = 1;
	int pos = stalls[0];

	for(int i=1;i<n;i++){
		if(stalls[i]-pos>=dist){
			c++;
			pos = stalls[i];
			
			if(c==cows){
				return true;
			}
		}
	}
	return false;
}


int main(){

	int n = 5;
	int cows = 3;
	int stalls[] = {1,2,4,8,9};

	int s = 0;
	int e = stalls[n-1] - stalls[0];
	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;
		if(canPlace(cows,stalls,mid,n)){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}

	cout<<ans<<endl;

	return 0;
}