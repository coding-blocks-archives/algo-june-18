#include<iostream>
#include<cstring>
using namespace std;

void filterChars(int no,char a[100]){
	int j=0;

	while(no>0){
		int last_bit = no&1;
	
		if(last_bit){
			cout<<a[j];
		}
		j++;
		no >>=1;
	}
	cout<<endl;
}

int main(){

	char a[100];
	cin>>a;

	int len = strlen(a);
	for(int no=0;no<(1<<len);no++){
		filterChars(no,a);
	}
	return 0;
}