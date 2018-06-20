#include<iostream>
using namespace std;

int minSteps(int n,int *dp){
	if(n==1){
		return 0;
	}
	//Top Down DP
	if(dp[n]!=0){
		return dp[n];
	}

	int ans = minSteps(n-1,dp);
	if(!(n&1)){
		ans = min(ans,minSteps(n/2,dp));
	}
	if(n%3==0){
		ans = min(ans,minSteps(n/3,dp));
	}
	//Top Down Dp
	return dp[n] = ans + 1;
}

int minStepsBottomUp(int n){
	int dp[1000];

	dp[1] = 0;
	for(int i=2;i<=n;i++){
		int ans = dp[i-1];
		if(i%2==0){
			ans = min(dp[i/2],ans);
		}
		if(i%3==0){
			ans = min(dp[i/3],ans);
		}
		dp[i] = ans + 1;
	}

}

int main(){

	int dp[1000] ={0};
	cout<<minSteps(10,dp);

	return 0;
}