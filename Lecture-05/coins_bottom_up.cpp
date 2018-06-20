


int countCoins(int N,int coins[],int m){
	int dp[100];

	dp[0] = 0;
	for(n=1;n<=N;n++){
		dp[n] = INT_MAX;

		for(int j=0;j<m;j++){
			
			if(n-coins[j]>=0){
				dp[n] = min(dp[n],dp[n-coins[j]]+1);
			}
		}
	}
	return dp[N];
}