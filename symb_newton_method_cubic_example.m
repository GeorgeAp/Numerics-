function [y] = symb_newton_method_cubic_example(f, x_0, iter)
% f is the function to be evaluated 
% x_0 is the initial value of x and 
% iter is the number of iterations
syms x b n; % create symbolic variables 
%syms b;
%syms n;
%f = x^3 + 7*b*x - 8;
Df = diff(f); % differentiate f
x = x_0;
for idx = 1 : iter
    fv = subs(f, x); % compute for the value of f using x
    Dfv = subs(Df, x); % compute for the value of Df using x
    y(idx) = x - fv/Dfv; % Newton method
    x = y(idx);          % update x
    x = simplify(x);
end
%disp(x);

end
