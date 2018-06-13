#include<iostream>
using namespace std;

int crossInv(int *a,int s,int e){
	int i = s;
	int mid =(s+e)/2;
	int j = mid + 1;
	int k = s;

	int temp[1000];
	int cnt = 0;
	while(i<=mid && j<=e){
		if(a[i]<a[j]){
			temp[k] = a[i];
			k++; i++;
		}
		else{
			temp[k] = a[j];
			cnt += (mid -i +1);
			k++; j++;
		}
	}

	while(i<=mid){
		temp[k++] = a[i++];
	}
	while(j<=e){
		temp[k++] = a[j++];
	}
	for(int i=s;i<=e;i++){
		a[i] = temp[i];
	}
	return cnt;
}

int invCnt(int *a,int s,int e){
	//Base Case
	if(s>=e){
		return 0;
	}
	//Rec Case
	int mid = (s+e)/2;
	int left = invCnt(a,s,mid);
	int right = invCnt(a,mid+1,e);
	int ans = left + right + crossInv(a,s,e);
	return ans;
}

int main(){

	int a[] = {5,1,2,4,3};
	int n = sizeof(a)/sizeof(int);
	cout<<invCnt(a,0,n-1)<<endl;

	return 0;
}