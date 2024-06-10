#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

const int MaxSize = 100;

class sparseMatrix{
	private:
		int mat[MaxSize][MaxSize];
		int sparse[3][MaxSize*MaxSize];
		int row,col;
		int size;
	public:
		sparseMatrix(){};
		sparseMatrix(int r, int c){
			
			for(int i = 0; i < r; ++i)
				for(int j = 0; j < c; ++j)
					if(i == j)
						mat[i][j] = rand()%10+1;
					else
						mat[i][j] = 0;
			
			row = r;
			col = c;	
		}
		
		int getSize(){return size;};
		void makeSparse();
		void showMatrix();
		void showSparse();
		
		friend sparseMatrix addSparse(sparseMatrix, sparseMatrix);
};

void sparseMatrix::makeSparse(){
	
	size = 1;
	
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			
			if(mat[i][j]){
				
				sparse[0][size] = i+1;
				sparse[1][size] = j+1;
				sparse[2][size] = mat[i][j];
				
				size++;
			}
		}
	}
	
	sparse[0][0] = row;
	sparse[1][0] = col;
	sparse[2][0] = size-1;
}

void sparseMatrix::showSparse(){
	
	for(int i = 0; i < 3; ++i){
		
		for(int j = 0; j < size; ++j){
			
			cout<<sparse[i][j]<<" ";
		}
		cout<<endl;
	}
}

sparseMatrix addSparse(sparseMatrix m1, sparseMatrix m2){
	
	if(m1.row != m2.row and m1.col != m2.col){
		
		cout<<"Addition Not Possible!!!"<<endl;
		exit(0);
	}
	
	sparseMatrix sum;
	
	int a,b,c;
	a=b=c=1;
	
	while(true){
		
		int m1Row = m1.sparse[0][a];
		int m2Row = m2.sparse[0][b];
		int m1Col = m1.sparse[1][a];
		int m2Col = m2.sparse[1][b];
		
		if(m1Row == m2Row){
			
			if(m1Col == m2Col){
				
				sum.sparse[0][c] = m1Row;
				sum.sparse[1][c] = m1Col;
				sum.sparse[2][c] = m1.sparse[2][a] + m2.sparse[2][b];
				a++;b++;
			}
			else if(m1Col < m2Col){
				
				sum.sparse[0][c] = m1Row;
				sum.sparse[1][c] = m1Col;
				sum.sparse[2][c] = m1.sparse[2][a];
				a++;
			}
			else{
				
				sum.sparse[0][c] = m2Row;
				sum.sparse[1][c] = m2Col;
				sum.sparse[2][c] = m2.sparse[2][b];
				b++;
			}
		}
		else if(m1Row < m2Row){
			
			sum.sparse[0][c] = m1Row;
			sum.sparse[1][c] = m1Col;
			sum.sparse[2][c] = m1.sparse[2][a];
			a++;
		}
		else{
			sum.sparse[0][c] = m2Row;
			sum.sparse[1][c] = m2Col;
			sum.sparse[2][c] = m2.sparse[2][b];
			b++;
		}
		c++;
		
	
		if(a == m1.getSize()){
		
			while(b < m2.getSize()){
			
				sum.sparse[0][c] = m2Row;
				sum.sparse[1][c] = m2Col;
				sum.sparse[2][c] = m2.sparse[2][b];
				b++;
			}
			break;
		}
		else if(b == m2.getSize()){
		
			while(a < m1.getSize()){
			
				sum.sparse[0][c] = m1Row;
				sum.sparse[1][c] = m1Col;
				sum.sparse[2][c] = m1.sparse[2][a];
				a++;
			}
			break;
		}
	}
	
	sum.size = c;
	
	return sum;
}

int main(){
	
	sparseMatrix m1(5,5);
	m1.makeSparse();
	
	
	sparseMatrix m2(5,5);
	m2.makeSparse();
	
	
	sparseMatrix sum = addSparse(m1,m2);
	sum.showSparse();
			
	return 0;
}
