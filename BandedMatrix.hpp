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
		if(lowerBandwidth<0 || upperBandwidth) {
			cout << "Error: Invalid Bandwidth value(s)\n";
			return;
		}
		N = size;
		lowerBandwidth = LowerBandwidth;
		upperBandwidth = UpperBandwidth;

		// Size allocation to incorporate N
		matrix.resize(rows, vector<T>(columns));
	}

	BandedMatrix(const int size, const int LowerBandwidth, const int UpperBandwidth, 
				 const int Value) {
		if(lowerBandwidth<0 || upperBandwidth) {
			cout << "Error: Invalid Bandwidth value(s)\n";
			return;
		}
		N = size;
		lowerBandwidth = LowerBandwidth;
		upperBandwidth = UpperBandwidth;


		// Size allocation, slightly different
		matrix.resize(rows, vector<T>(columns, Value));
	}

	int LowerBandwidth() const {
		return lowerBandwidth;
	}

	int UpperBandwidth() const {
		return upperBandwidth;
	}

	void Set(int i, int j) {
		int x = i-j+upperBandwidth, y = j;


	}

	std::vector<T>& operator[] (int index) {
		return matrix[index];
	}

	template<E>
	void operator= (const BandedMatrix<E>& Matrix) {
		if(Matrix.LowerBandwidth() != lowerBandwidth || 
		   Matrix.UpperBandwidth() != upperBandwidth) {
			throw "Failed: Bandwidth mismatch!\n";
		}
		(*this) = matrix;
	}

};


#define __BANDED_MATRIX__