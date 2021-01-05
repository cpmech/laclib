#pragma once
#include <string>
#include <functional>

// returns if symmetric or not
bool read_mtx(const std::string &filename,
              std::function<void(int m, int n, int nnz)> allocator,
              std::function<void(int k, int ik_onebased, int jk_onebased, double xk)> setter);