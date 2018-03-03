#ifndef __BANDED_MATRIX__
#define __BANDED_MATRIX__

#include <bits/stdc++.h>

using namespace std;

template<typename T>
class BandedMatrix{
	int N;
	int lowerBandwidth;
	int upperBandwidth;
	vector< vector<T> > matrix;
public:	
	BandedMatrix(const int size, const int LowerBandwidth, const int UpperBandwidth) {
		if(lowerBandwidth<0 || upperBandwidth<0) {
			cout << "Error: Invalid Bandwidth value(s)\n";
			return;
		}
		N = size;
		lowerBandwidth = LowerBandwidth;
		upperBandwidth = UpperBandwidth;

		// Size allocation to incorporate N
		matrix.resize(N, vector<T>(upperBandwidth + lowerBandwidth, 0));
	}

	BandedMatrix(const int size, const int LowerBandwidth, const int UpperBandwidth, 
				 const int Value) {
		if(lowerBandwidth<0 || upperBandwidth<0) {
			cout << "Error: Invalid Bandwidth value(s)\n";
			return;
		}
		N = size;
		lowerBandwidth = LowerBandwidth;
		upperBandwidth = UpperBandwidth;

		// Size allocation, slightly different
		matrix.resize(N, vector<T>(upperBandwidth + lowerBandwidth, Value));
	}

	int size() const {
		return N;
	}

	int LowerBandwidth() const {
		return lowerBandwidth;
	}

	int UpperBandwidth() const {
		return upperBandwidth;
	}

	void Set(int i, int j, T value) {
		if(i<0 || j<0) {
			cout << "Error: Invalid index\n";
			return;
		}
		int x = i-j+upperBandwidth, y = j;
		if (x<0 || (i-j)>=lowerBandwidth) {
			return;
		}
		matrix[x][y] = value;

	}

	T Get(int i, int j) {
		if(i<0 || j<0) {
			cout << "Error: Invalid index\n";
			return T(-1);
		}
		int x = i-j+upperBandwidth, y = j;
		if (x<0 || (i-j)>=lowerBandwidth) {
			return T(0);
		}
		return matrix[x][y];
	}

	T operator() (int i, int j) {
		Get(i,j);
	}

	template<typename E>
	void operator= (const BandedMatrix<E>& Matrix) {
		if(Matrix.LowerBandwidth() != lowerBandwidth || 
		   Matrix.UpperBandwidth() != upperBandwidth) {
			throw "Failed: Bandwidth mismatch!\n";
		}
		(*this) = matrix;
	}

};


#endif 