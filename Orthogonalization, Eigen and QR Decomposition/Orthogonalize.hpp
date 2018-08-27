#ifndef __ORTHO__
#define __ORTHO__

#include <bits/stdc++h.>

using namespace std;

template<typename T>
void dot(vector<T> A, vector<T> B) {
	T val = 0;
	for(int i=0; i<A.size(); i++) {
		val += A[i] * B[i];
	}
	return val;
}

template<typename T>
void operator*(vector<T> &basis, T val) {
	int N = basis.size();
	for(int i=0; i<N; i++) {
		basis[i] *= val;
	}
}

template<typename T>
vector<T> operator-(vector<T> &A, vector<T> &B) {
	int N = A.size();
	vector<T> Temp(N,0);
	for(int i=0; i<N; i++) {
		Temp[i] = A[i] - B[i];
	}
	return Temp;
}

template<typename T>
vector<T> operator/(vector<T> &basis, T val) {
	int N = basis.size();
	vector<T> Temp(N,0);
	for(int i=0; i<N; i++) {
		Temp[k] = Basis[k]/ val;
	}
	return Temp;
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
vector< vector<T> > Process(vector< vector<T> > &Basis) {
	int basisCount = Basis.size(), dimensions = Basis[0].size();
	vector< vector<T> > r(basisCount, vector<T>(dimensions,0));
	for(int k=0; k<basisCount; k++) {
		for(int i=0; i<k; i++) {
			r[i][k] = dot(Basis[k], Basis[i]);
		}
		for(int i=0; i<k; i++) {
			Basis[k] = Basis[k] - Basis[i]*r[i][k];
		}
		r[k][k] = L2Norm(Basis[k]);
		if(r[k][k] == 0) {
			cout << "The new vectors are still dependent.\n";
			return;
		}
		Basis[k] = Basis[k]/r[k][k];
	}
	return r;
}

template<typename T>
void gramSchmidt(vector< vector<T> > &Basis) {
	Process(Basis);
}

template<typename T>
void ProcessModified(vector< vector<T> > &Basis) {
	int basisCount = Basis.size(), dimensions = Basis[0].size();
	vector< vector<T> > r(basisCount, vector<T>(dimensions, 0));
	for(int k=0; k<basisCount; k++) {
		for(int i=0; i<k; i++) {
			r[i][k] = dot(Basis[k], Basis[i]);
			Basis[k] = Basis[k] - Basis[i]*r[i][k];
		}
		r[k][k] = L2Norm(Basis[k]);
		if(r[k][k] == 0) {
			cout << "The new vectors are still dependent.\n";
			return;
		}
		Basis[k] = Basis[k]/r[k][k];
	}
	r.clear();
}

template<typename T>
void gramSchmidtModified(vector< vector<T> > &Basis) {
	ProcessModified(Basis);
}


#endif