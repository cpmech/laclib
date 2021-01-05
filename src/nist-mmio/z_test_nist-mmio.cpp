#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "../check/check.h"
#include "wrapper.h"
#include <vector>
using namespace std;

TEST_CASE("testing NIST-MMIO")
{
    auto data_path = path_get_current() + "/../../../data/sparse-matrix/";

    vector<int> Icorrect = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
    vector<int> Jcorrect = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
    vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

    SUBCASE("read sparse-matrix ok1")
    {
        auto mtx = data_path + "ok1.mtx";

        vector<int> I;
        vector<int> J;
        vector<double> X;

        auto allocator = [&](int m, int n, int nnz) {
            I.resize(nnz);
            J.resize(nnz);
            X.resize(nnz);
        };

        auto setter = [&](int k, int ik_onebased, int jk_onebased, double xk) {
            I[k] = ik_onebased - 1;
            J[k] = jk_onebased - 1;
            X[k] = xk;
        };

        auto symmetric = read_mtx(mtx, allocator, setter);

        CHECK(symmetric == false);
        CHECK(equal_vectors(I, Icorrect) == true);
        CHECK(equal_vectors(J, Jcorrect) == true);
        CHECK(equal_vectors_tol(X, Xcorrect, 1e-15) == true);
    }
}