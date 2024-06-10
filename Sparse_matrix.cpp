#include<iostream>
#include<cstdlib>

using namespace std;

int const MaxRows = 5;
int const MaxCols = 5;

class sparse{
	
	public:
		int nonZeroEl(int mat[][MaxCols], int row, int col){
			
			int cnt = 0;
			for(int i = 0; i < row; ++i){
				for(int j = 0; j < col; ++j){
					cnt += (mat[i][j] != 0);
				}
			}
			return cnt;
		}
		
		void makeSparse(int mat[][MaxCols], int **sparse, int row, int col){
			
			int index = 0;
			
			for(int i = 0; i < row; ++i){
				
				for(int j = 0; j < col; ++j){
					
					if(mat[i][j]){
						
						sparse[0][index] = i+1;
						sparse[1][index] = j+1;
						sparse[2][index] = mat[i][j];
						
						index++;
					}
				}
			}
		}
};

void loadDiagonal(int mat[][MaxCols], int row, int col){
	
	for(int i = 0; i < row; ++i){
		
		for (int j = 0; j < col; ++j){
			
			if (i == j) mat[i][j] = rand()%10 + 1;
			else mat[i][j] = 0;
		}
	}
}

void display(int mat[][MaxCols], int row, int col){
	
	for (int i = 0; i < row; ++i){
		
		for(int j = 0; j < col; ++j){
			
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
	
	
	int mat[MaxRows][MaxCols];
	
	loadDiagonal(mat,MaxRows,MaxCols);
	display(mat,MaxRows,MaxCols);
	
	sparse sp;
	
	int size = sp.nonZeroEl(mat,MaxRows,MaxCols); 
	
	int **sparseMatrix = (int**)malloc(sizeof(int*)*3);
	
	for(int i = 1; i <= 3; ++i)
		sparseMatrix[i-1] = (int*)malloc(sizeof(int)*size);
		
	sp.makeSparse(mat, sparseMatrix, MaxRows, MaxCols);
	
	for(int i = 0; i < 3; ++i){
		
		for(int j = 0; j < size; ++j){
			
			cout<<sparseMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
