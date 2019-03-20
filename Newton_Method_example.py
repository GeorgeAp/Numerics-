from Newton_Method import Newton_Method_func

x = 3.0
e = 1.0e-15

nmax = 10

f = x**3 - 2*x**2 + x - 3
fp = 3*x**2 - 4*x + 1

x = Newton_Method_func(f,fp,x,nmax,e)
