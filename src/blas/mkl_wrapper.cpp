#include "mkl_wrapper.h"

void set_num_threads(int n)
{
    mkl_set_num_threads(n);
}

double ddot(int n, const std::vector<double> &x, int incx, const std::vector<double> &y, int incy)
{
    return cblas_ddot(n, x.data(), incx, y.data(), incy);
}