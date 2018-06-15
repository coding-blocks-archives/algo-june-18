#include<iostream>
using namespace std;

bool isSafe(int board[][100],int i,int col,int n){
	`//Iteratively check over column, diagonals
	// O(n)

}

//Count and Print All Config
bool solveNQueen(int board[][100],int i,int n,int &cnt){
	//Base Case 
	if(i==n){
		//Print the board
		cnt+=1; 
		return true;
	}
	//Rec Case 
	//Place the queen in the ith row 
	int cnt = 0;
	for(int col=0;col<n;col++){
		//Check if i,col is safe to place the current queen
		if(isSafe(board,i,col,n)){
			//Place the queen 
			board[i][col] = 1;
			//Solve the remaining subproblem 
			bool nqueenSolved = solveNQueen(board,i+1,n);

			//Backtracking
			board[i][col] = 0;

		}
	}
	return false;
} 

int main(){
	int board[100][100];
	int n;
	cin>>n;




}