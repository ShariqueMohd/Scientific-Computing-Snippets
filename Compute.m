function [V, B] = Compute(Input)
Sigma = 0;
M = length(Input);
for i = 2 : M
    Sigma = Sigma + Input(i) * Input(i);
end

V = [1; Input(2:M)];
if Sigma != 0
    u = sqrt((Input(1) * Input(1)) + Sigma);
    if x(1) <= 0
        V(1) = Input(1) - u;
    else
        V(1) = -1 * Sigma / (Input(1) + u);
    end
    B = 2 * (V(1) * V(1))/(Sigma + V(1) * V(1));
    V = V / V(1);
else
    if x(1) >= 0
        B = 0;
    else
        B =- 2;
    end
end
