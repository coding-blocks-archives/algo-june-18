#include<iostream>
using namespace std;

void generateMatrix(int a[][100],int m,int n){
	int val = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j] = val++;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

}
void spiralPrint(int a[][100],int m,int n){
	int startRow = 0,startCol=0,endRow = m-1,endCol = n-1;

	while(startRow<=endRow && startCol<=endCol){
		//Print the start Row 
		for(int i=startCol;i<=endCol;i++){
			cout<<a[startRow][i]<<" ";
		}
		startRow++;

		//Print the end col
		for(int i=startRow;i<=endRow;i++){
			cout<<a[i][endCol]<<" ";
		}
		endCol--;

		//Print the bottom row
		if(endRow>startRow){
			for(int i=endCol;i>=startCol;i--){
				cout<<a[endRow][i]<<" ";
			}
			endRow--;
		}

		//Print the start Col
		if(endCol>startCol){
			for(int i=endRow;i>=startRow;i--){
				cout<<a[i][startCol]<<" ";
			}
			startCol++;
		}
	}
	return;
}
int main(){

	int a[100][100];

	int m,n;
	cin>>m>>n;

	generateMatrix(a,m,n);
	spiralPrint(a,m,n);

	return 0;
}