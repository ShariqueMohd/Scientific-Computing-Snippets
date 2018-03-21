#ifndef __LU__
#define __LU__

#include "DenseMatrx.hpp"

// We assume that the diagnol elements of lower triangular matrix
// are all ones.

template<typename T>
class LUFactorization {
	vector< vector<T> > DecomposedMatrix;
	vector< vector<T> > &Matrix;

	void LUFactorization(vector< vector<T> > &Input) {
		Matrix = Input;
		Decompose();
	}

	void Decompose() {
		int N = Matrix.size();
		vector<vector<T> > lower(N, vector<T>(N, 0));
		vector<vector<T> > upper(N, vector<T>(N, 0));
		DecomposedMatrix.resize(N, vector<T>(N, 0));

		for (int i=0; i<N; i++) {
        	for (int k=i; k<N; k++) {
        	    int sum = 0;
            	for (int j = 0; j < i; j++)
                	sum += (lower[i][j] * upper[j][k]);
 				upper[i][k] = mat[i][k] - sum;
        	}
 
        	for (int k = i; k < n; k++) {
            	if (i == k)
              	  lower[i][i] = 1;
            	else {
                	int sum = 0;
                	for (int j = 0; j < i; j++)
                    	sum += (lower[k][j] * upper[j][i]);
                	lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            	}
        	}
        }

        for(int i=0; i<N; i++) {
        	lower[i][i] = 0;
        }

        for(int i=0; i<N; i++) {
        	for(int j=0; j<N; j++) {
        		DecomposedMatrix[i][j] = lower[i][j] + upper[i][j]; 
        	}
        }
        lower.clear(); upper.clear();
    
	}

	vector<T> ForwardSubstition(vector<T> &b) {
		int N = b.size();
		vector<T> x(N, 0);
		for(int i=0; i<N; i++) {
			T sum = b[i];
			for(int k=0; k<i-1;k++) {
				sum -= Decomposed[i][k]*x[k];	
			}
			x[i] = sum; // since l[i][i] = 1;
		}
		return x;
	}

	vector<T> BackwardSubstitution(vector<T> b) {
		int N = b.size();
		vector<T> x(N,0);	
		for(int i=N-1; i>=0; i--) {
			T sum = b[i];
			for(int k=N-1; k>i+1; k--) {
				sum -= Decomposed[i][k]*x[k];
			}
			x[i] = sum/Decomposed[i][i];
		}
		return x;
	}

	vector<T> FindSolution(vector< vector<T> > &A, vector<T> &b) {
		Matrix = A;
		Decompose();
		vector<T> x;
		x = ForwardSubstition(b);
		x = ForwardSubstition(x);
		return x;
	}

	void Hessenberg_LU(vector< vector<T> > &A) {
		int N = Matrix.size();
		DecomposedMatrix.resize(N, vector<T>(N, 0));
		for(int k=0; k<N-1; k++) {
			DecomposedMatrix[k+1][k] = A[k+1][k]/A[k][k];
			for(int l=k+1; l<N; l++) {
				DecomposedMatrix[k+1][l] = A[k+1][l] - A[k+1][k]*A[k][l];
			}
		}
	}

};


#endif6	1