#ifndef __MULTIPLY__
#define __MULTIPLY__

#include "DenseMatrix.hpp"
#include "BandedMatrix.hpp"

template<typename T>
DenseMatrix<T> operator* (DenseMatrix<T> &A, DenseMatrix<T> &B) {
	DenseMatrix<T> resultant(A.Rows(), B.Columns(), 0);
	for(int i=0; i<A.Rows(); i++) {
		for(int j=0; j<B.Columns(); j++) {
			for(int k=0; k<A.Columns(); k++) {
				resultant[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return resultant;
}

template<typename T>
DenseMatrix<T> operator* (BandedMatrix<T> &A, BandedMatrix<T> &B) {
	DenseMatrix<T> resultant(A.size(),B.size(), 0);
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<B.size(); j++) {
			for(int k=0; k<A.size(); k++) {
				resultant[i][j] += A(i,k) * B(k,j);
			}
		}
	}
}

template<typename T>
COO<T> operator* (COO<T> &A, COO<T> &B) {	
	COO<T> resultant;
	int rows = A.Rows(), columns = B.Columns();
	for(int i=0; i<rows; i++) {
		for(int j=0; j<columns; j++) {
			T sum = 0;
			for(int k=0; k<A.Columns(); k++) {
				sum += A(i,k) * B(k,j);
			}
			if(sum>0) {
				resultant.insert(i, j, sum);
			} 
		}
	}
}




#endif 