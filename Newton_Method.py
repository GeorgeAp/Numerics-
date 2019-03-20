# In this code, we create a function for computing Newton Method

def Newton_Method_func(f, fp, x, nmax, e):
    #f is an inline function which we apply Newton's method on
    #  fp is an inline function that is the derivative of function f 
    # x is the initial guess of the root
    # nmax is the total number of iterations done
    # e is the error used to control convergence

    print('x = %10g \n ', x)
    for n in range(nmax):
        d = f/fp
        x = x - d
        print('x = %10g \n', n, x)
        if abs(d) > e:
            print('Converged!')
            return d
        return d

    