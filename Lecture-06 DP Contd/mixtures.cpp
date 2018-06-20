#include<iostream>
using namespace std;

int sum(int *a,int i,int j){
	int ans = 0;
	for(int k=i;k<=j;k++){
		ans += a[k];
	}
	return ans%100;
}

int smoke(int *a,int i,int j){
	if(i==j||i>j){
		return 0;
	}

	int finalAns = INT_MAX;
	//Rec Case
	for(int k=i;k<j;k++){
		int firstPart = smoke(a,i,k);
		int secondPart = smoke(a,k+1,j);

		int total_smoke = firstPart + secondPart + sum(a,i,k)*sum(a,k+1,j);
		finalAns = min(finalAns,total_smoke);
	}
	return finalAns;

}

int main(){

	int a[] = {40,60,20};
	int n = 3;

	cout<<smoke(a,0,n-1)<<endl;


}