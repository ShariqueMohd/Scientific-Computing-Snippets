#ifndef __DENSE_MATRIX__
#define __DENSE_MATRIX__

#include <bits/stdc++.h>

using namespace std;

template<typename T>
class DenseMatrix {
	int rows, columns;
	vector< vector<T> > matrix;
public:
	DenseMatrix() {
		rows = columns = 0;
	}
	DenseMatrix(const int Rows=1, const int Columns=1) {
		if (Rows<0 || Columns<0) {
			cout << "Invalid Dimensions\n";
			return;
		}
		rows = Rows;
		columns = Columns;
		matrix.resize(rows, vector<T>(columns,0));
	}

	DenseMatrix(const int Rows, const int Columns,const int Value) {
		if(Rows<0 || Columns<0) {
			cout << "Invalid Dimensions\n";
			return;
		}
		rows = Rows;
		columns = Columns;
		matrix.resize(rows, vector<T>(columns, Value));	
	}

	int Rows() const {
		return rows;
	}

	int Columns() const {
		return columns;
	}

	std::vector<T>& operator[] (int index) {
		return matrix[index];
	}

	T operator() (int i, int j) {
		return matrix[i][j];
	}

	template<typename E>
	void operator= (const DenseMatrix<E> Matrix) {
		if (Matrix.Rows() != rows || Matrix.Columns() != columns) {
			throw "Failed: Invalid dimensions! Cannot equate.\n";
		}
		for(int i=0; i<rows; i++) {
			for(int j=0; j<columns; j++) {
				matrix[i][j] = Matrix[i][j];
			}
		}
	}
};

#endif