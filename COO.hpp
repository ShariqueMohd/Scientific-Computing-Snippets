#ifndef __COO__
#define __COO__

template<typename T>
class COO {
	int nz;
	int rows, columns;
	vector<int> row_indices;
	vector<int> col_indices;
	vector<T> values;
public:
	COO() {
		nz = 0;
	}
	COO(int Rows, int Columns, int n) {
		nz = n;	rows = Rows; columns = Columns;
		row_indices.resize(n);
		col_indices.resize(n);
		values.resize(n);
	}

	~COO() {
		row_indices.clear();
		col_indices.clear();
		values.clear();
	}

	int Rows() {
		return rows;
	}

	int Columns() {
		return columns;
	}

	void insert(int row, int col, T val) {
		row_indices.push_back(row);
		col_indices.push_back(col);
		values.push_back(val);
		nz += 1;
	}

	T get(int row, int col) {
		T val = 0;
		for(int i=0; i<nz; i++) {
			if(row_indices[i] == row && col_indices[i] == col) {
				val = values[i];
				break;
			}
		}
		return val;
	}

	T operator()(int  row, int col) {
		return get(row, col);
	}
};



#endif