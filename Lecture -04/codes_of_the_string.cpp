#include<iostream>
using namespace std;

void ACODE(char *in,char *out,int i,int j){
	//Base Case 
	if(in[i]=='\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	//Recusive Case

	//Convert 1 char at a time starting at index i
	int digit = in[i] - '0';
	char ch = 'A' - 1 + digit;
	if(digit!=0){
		out[j] = ch;
		ACODE(in,out,i+1,j+1);
	}
	//Convert 2 char at a time starting index i
	if(in[i+1]!='\0'){
		int secondDigit = in[i+1]-'0';
		int no = digit*10 + secondDigit;
		if(no<=26){
			ch = 64 + no;
			out[j] = ch;
			ACODE(in,out,i+2,j+1);
		}
	}
	return;
}

int main(){
	char input[1000];
	cin>>input;

	char output[1000];
	ACODE(input,output,0,0);


return 0;
}