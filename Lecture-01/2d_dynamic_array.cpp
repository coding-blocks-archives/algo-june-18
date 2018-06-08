#include<iostream>
using namespace std;


int main(){

	int rows,cols;
	cin>>rows>>cols;

	//Allocation
	int **a = new int*[rows];
	for(int i=0;i<rows;i++){
		a[i] = new int[cols];
	}

	//Destroy
	for(int i=0;i<rows;i++){
		//a[i] points to array of integers
		delete [] a[i];
	}

	//a points to array of integer pointers(row addresses)
	delete [] a;
	return 0;
}