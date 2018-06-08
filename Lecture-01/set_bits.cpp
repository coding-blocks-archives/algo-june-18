#include<iostream>
using namespace std;

//Function to check last bit
int checkLast(int n){
	return n&1;
}
int getIthBit(int n,int j){
	return n&(1<<j);
}
//Pass by reference
void setIthBit(int &n,int j){
	n = n|(1<<j);
}
//Count Set Bits - Complexity O(Position of Largest Set Bit)
int countSetBits(int n){
	int cnt = 0;
	for( ;n>0;n=n>>1){
		cnt += n&1;
	}
	return cnt;
}
//Hack - N&(N-1) Hack(Faster) - O(No of Set Bits)
int countBitsHack(int n){
	int cnt = 0;
	while(n){
		cnt++;
		//Removes last set bit frm right
		n = n&(n-1);
	}
	return cnt;
}



int main(){

	int n;
	cin>>n;
	cout<<countBitsHack(n);


	return 0;
}
