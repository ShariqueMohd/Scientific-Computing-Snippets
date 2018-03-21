#ifndef __QRDECOMPOSITION__
#define __QRDECOMPOSITION__

#include "DenseMatrix.hpp"

template<typename T>
class QRDecompisition {
	vector< DenseMatrix<T> > qv;
	DenseMatrix<T> Q, R;
	DenseMatrix<T> &Matrix;

	QRDecompisition(DenseMatrix<T> &Input) {
		Matrix = Input;
		int M = Input.Rows(), N = Input.Columns();
		qv.resize(M);
	}

	void HouseHolder() {
		//DenseMatrix<T> Z(Matrix);
	}
};

#endif