function Matrix = QR_HH(Matrix)

%Dimensions of the Matrix
[Rows, Columns] = size(Matrix); 

for i = 1: Columns
    [V, B] = Compute(Matrix(i: Rows, i)); 
    % Identity Matrix
    I = eye(Rows - i + 1, Rows - i + 1); 
    Matrix(i: Rows, i: Columns) = (I - B * V * V') * Matrix(i: Rows, i: Columns); 
    if i < m
        Matrix(i + 1: Rows, i) = V(2: Rows - i + 1); 
    end
end
