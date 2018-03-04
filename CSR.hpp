#ifndef __CSR__
#define __CSR__

template<typename T>
class CSR {
	int row, col;
	vector<T> value;
	vector<int> col_indices;
	vector<int> row_pointers;
public:
	CSR() {
		row = 0, col = 0;
	}
	CSR(int Row, int Column) 
		row = Row; col = Column;
	}

	void insertValue(T val) {
		value.push_back(val);
	}

	void insertColumnIndex(int col_index) {
		col_indices.push_back(col_index);
	}

	void insertRowPointer(int row_pointer) {
		row_pointers.push_back(row_pointer);
	}

	int Rows() {
		return row;
	}

	int Columns() {
		return col;
	}

	T get(int i, int j) {
		int start = row_pointers[i];
		int last = (i == row_pointers.size()-1) ? value.size() : row_pointers[i+1];
		T val = 0;
		for(int i=start; i<last; i++) {
			if(j == col_indices[i]) {
				val = value[i];
				break;
			}
		}
		return val;	
	}	

	T operator()(int i, int j) {
		return get(i, j);
	}

};


#endif