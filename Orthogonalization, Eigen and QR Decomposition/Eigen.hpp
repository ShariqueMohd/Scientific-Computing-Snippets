#ifndef __EIGEN__
#define __EIGEN__

#include "CSR.hpp"

template<typename T>
vector<T> operator*(CSR<T> &A, vector<T> &q) {
	int rows = A.Rows();
	int cols = A.Columns();
	vector<T> Q;
	for(int i=0; i<rows; i++) {
		T val = 0;
		for(int j=0; j<cols; j++) {
			val += A(i,j) * q[j];
		}
		Q.push_back(val);
	}
	return Q;	
}

template<typename T>
T L2Norm(vector<T> &basis) {
	T val = 0;
	for(int i=0; i<basis.size(); i++) {
		val += basis[i] * basis[i];
	}
	return T(sqrt(val));
}

template<typename T>
vector<T> operator/(vector<T> &Q, T mod) {
	int N = Q.size();
	for(int i=0; i<N; i++) {
		Q[i] = Q[i] / mod;
	}
	return Q;
}

template<typename T>
vector<T> power_method(CSR<T> &A, int m) {
	vector<T> Q(A.Rows()), newQ(A.Rows());
	srand (time(NULL));
	for(int i=0; i<m; i++) {
		for(int i=0; i<Q.size(); i++) {
			Q[i] = rand();
		}
		for(int i=0; i<m; i++) {
			newQ = A * Q;
		}
		T mod = L2Norm(newQ);
		newQ = newQ/mod;
		if(diffMod(newQ, Q) < 14e-10) {
			return newQ;
		}
		Q = newQ;
	}
	return Q;
}



#endif