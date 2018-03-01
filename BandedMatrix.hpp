#ifndef __BANDED_MATRIX__
#define __BANDED_MATRIX__

#include <bits/stdc++.h>

using namespace std;

template<typename T>
class BandedMatrix{
	int lowerBandwidth;
	int upperBandwidth;
	vector< vector<T> > matrix;
public:	
	BandedMatrix(const int LowerBandwidth, const int UpperBandwidth) {
		if(lowerBandwidth<0 || upperBandwidth) {
			cout << "Error: Invalid Bandwidth value(s)\n";
			return;
		}
		lowerBandwidth = LowerBandwidth;
		upperBandwidth = UpperBandwidth;
		matrix.resize(rows, vector<T>(columns));
	}

	BandedMatrix(const int LowerBandwidth, const int UpperBandwidth, const int Value) {
		if(lowerBandwidth<0 || upperBandwidth) {
			cout << "Error: Invalid Bandwidth value(s)\n";
			return;
		}
		lowerBandwidth = LowerBandwidth;
		upperBandwidth = UpperBandwidth;
		matrix.resize(rows, vector<T>(columns, Value));
	}

	int LowerBandwidth() const {
		return lowerBandwidth;
	}

	int UpperBandwidth() const {
		return upperBandwidth;
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