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




#endif 