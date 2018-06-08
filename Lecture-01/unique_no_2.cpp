#include<iostream>
using namespace std;

int getIthBit(int n,int j){
	return n&(1<<j);
}

int main(){

	int a[] = {1,1,2,3,8,3,6,5,5,6};
	int n = sizeof(a)/sizeof(int);

	//First Step 
	int res = 0;
	for(int i=0;i<n;i++){
		res = res^a[i];
	}

	//Second Step - Find pos of last set bit in res 
	int pos = 0;
	int res_cpy= res;
	while(1){
		int last_bit = res&1;
		if(last_bit==1){
			break;
		}
		else{
			pos++;
			res >>= 1;
		}
	}
	cout<<pos<<endl;

	//Next Step - Iterate over array and find setA XOR
	int setA = 0;
	for(int i=0;i<n;i++){
		if((a[i]&(1<<pos))!=0){
			//cout<<a[i]<<endl;
			setA ^= a[i];
		}
	}
	int firstUniq = setA;
	int secondUniq = res_cpy^firstUniq;

	cout<<firstUniq<<","<<secondUniq<<endl;

	return 0;
}