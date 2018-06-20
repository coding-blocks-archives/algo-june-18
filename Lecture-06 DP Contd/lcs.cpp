#include<iostream>
#include<cstring>
using namespace std;


int lcs(char *a,char *b,int i,int j){
	if(i==0||j==0){
		return 0;
	}
	/*
	if(dp[i][j]!=-1){
		return dp[i][j];
	}*/

	if(a[i-1]==b[j-1]){
		return 1 + lcs(a,b,i-1,j-1);
	} 
	int ans = max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));

	//dp[i][j] = ans;
	return ans;
}



int main(){
	char a[] = "apple";
	char b[] = "maapele";

	cout<<lcs(a,b,strlen(a),strlen(b));

}