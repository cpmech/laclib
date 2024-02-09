#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "coo_matrix.h"

#define _SUBCASE(name) if (false)

using namespace std;

TEST_CASE("testing CooMatrix") {
    SUBCASE("make_new works with default values") {
        auto coo = CooMatrix::make_new(FULL_MATRIX, 3, 4);

        vector<INT> I_correct{0, 0, 0, 0};
        vector<INT> J_correct{0, 0, 0, 0};
        vector<double> X_correct{0.0, 0.0, 0.0, 0.0};

        CHECK(coo->layout == FULL_MATRIX);
        CHECK(coo->dimension == 3);
        CHECK(coo->pos == 0);
        CHECK(coo->max == 4);
        CHECK(coo->indices_i.size() == 4);
        CHECK(coo->indices_j.size() == 4);
        CHECK(coo->values_aij.size() == 4);
        CHECK(equal_vectors(coo->indices_i, I_correct));
        CHECK(equal_vectors(coo->indices_j, J_correct));
        CHECK(equal_vectors_tol(coo->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put works") {
        auto coo = CooMatrix::make_new(FULL_MATRIX, 3, 4);

        vector<INT> I_correct{0, 1, 2, 0};
        vector<INT> J_correct{0, 1, 2, 1};
        vector<double> X_correct{10.0, 11.0, 12.0, 4.0};

        coo->put(0, 0, 10.0);
        coo->put(1, 1, 11.0);
        coo->put(2, 2, 12.0);
        coo->put(0, 1, 4.0);

        CHECK(coo->pos == 4);
        CHECK(equal_vectors(coo->indices_i, I_correct));
        CHECK(equal_vectors(coo->indices_j, J_correct));
        CHECK(equal_vectors_tol(coo->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put works with duplicates") {
        size_t max = 6;
        auto coo = CooMatrix::make_new(FULL_MATRIX, 3, max);

        vector<INT> I_correct{0, 1, 2, 0, 0, 2};
        vector<INT> J_correct{0, 1, 2, 1, 0, 2};
        vector<double> X_correct{5.0, 11.0, 6.0, 4.0, 5.0, 6.0};

        coo->put(0, 0, 5.0);
        coo->put(1, 1, 11.0);
        coo->put(2, 2, 6.0);
        coo->put(0, 1, 4.0);
        coo->put(0, 0, 5.0); // << duplicate
        coo->put(2, 2, 6.0); // << duplicate

        CHECK(coo->pos == 6);
        CHECK(equal_vectors(coo->indices_i, I_correct));
        CHECK(equal_vectors(coo->indices_j, J_correct));
        CHECK(equal_vectors_tol(coo->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put handles exceptions") {
        auto coo = CooMatrix::make_new(FULL_MATRIX, 3, 4);

        CHECK_THROWS_WITH(coo->put(-1, 0, 10.0), "CooMatrix::put: index of row is outside range");
        CHECK_THROWS_WITH(coo->put(3, 0, 10.0), "CooMatrix::put: index of row is outside range");
        CHECK_THROWS_WITH(coo->put(0, -1, 11.0), "CooMatrix::put: index of column is outside range");
        CHECK_THROWS_WITH(coo->put(0, 3, 11.0), "CooMatrix::put: index of column is outside range");

        coo->put(0, 0, 1);
        coo->put(0, 1, 2);
        coo->put(1, 0, 3);
        coo->put(1, 1, 4);

        CHECK_THROWS_WITH(coo->put(0, 0, 4.0), "CooMatrix::put: max number of items has been exceeded");
    }

    SUBCASE("to_matrix and as_matrix work") {

        //  1  -1   .  -3   .
        // -2   5   .   .   .
        //  .   .   4   6   4
        // -4   .   2   7   .
        //  .   8   .   .  -5
        // first triplet with shuffled entries
        auto coo = CooMatrix::make_new(FULL_MATRIX, 5, 13);
        coo->put(2, 4, 4.0);
        coo->put(4, 1, 8.0);
        coo->put(0, 1, -1.0);
        coo->put(2, 2, 4.0);
        coo->put(4, 4, -5.0);
        coo->put(3, 0, -4.0);
        coo->put(0, 3, -3.0);
        coo->put(2, 3, 6.0);
        coo->put(0, 0, 1.0);
        coo->put(1, 1, 5.0);
        coo->put(3, 2, 2.0);
        coo->put(1, 0, -2.0);
        coo->put(3, 3, 7.0);

        auto part = Matrix::make_new(2, 3);
        coo->to_matrix(part);
        CHECK(equal_scalars_tol(part->get(0, 0), 1.0, 1e-15));
        CHECK(equal_scalars_tol(part->get(0, 1), -1.0, 1e-15));
        CHECK(equal_scalars_tol(part->get(0, 2), 0.0, 1e-15));
        CHECK(equal_scalars_tol(part->get(1, 0), -2.0, 1e-15));
        CHECK(equal_scalars_tol(part->get(1, 1), 5.0, 1e-15));
        CHECK(equal_scalars_tol(part->get(1, 2), 0.0, 1e-15));

        auto dense = coo->as_matrix();
        CHECK(equal_scalars_tol(dense->get(0, 0), 1.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(0, 1), -1.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(0, 2), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(0, 3), -3.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(0, 4), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(1, 0), -2.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(1, 1), 5.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(1, 2), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(1, 3), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(1, 4), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(2, 0), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(2, 1), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(2, 2), 4.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(2, 3), 6.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(2, 4), 4.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(3, 0), -4.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(3, 1), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(3, 2), 2.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(3, 3), 7.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(3, 4), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(4, 0), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(4, 1), 8.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(4, 2), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(4, 3), 0.0, 1e-15));
        CHECK(equal_scalars_tol(dense->get(4, 4), -5.0, 1e-15));
    }

    SUBCASE("coo_to_csc works") {
        //  1  -1   .  -3   .
        // -2   5   .   .   .
        //  .   .   4   6   4
        // -4   .   2   7   .
        //  .   8   .   .  -5
        // first triplet with shuffled entries
        auto nrow = 5;
        auto nnz = 15;
        auto coo = CooMatrix::make_new(FULL_MATRIX, nrow, nnz);
        coo->put(2, 4, 4.0);
        coo->put(4, 1, 8.0);
        coo->put(0, 1, -0.5); // duplicate
        coo->put(0, 1, -0.5); // duplicate
        coo->put(2, 2, 4.0);
        coo->put(4, 4, -5.0);
        coo->put(3, 0, -4.0);
        coo->put(0, 3, -3.0);
        coo->put(2, 3, 6.0);
        coo->put(0, 0, 1.0);
        coo->put(1, 1, 5.0);
        coo->put(3, 2, 2.0);
        coo->put(1, 0, -2.0);
        coo->put(3, 3, 3.5); // duplicate
        coo->put(3, 3, 3.5); // duplicate

        auto ncol = nrow;
        int *Ap = new int[ncol];
        int *Ai = new int[nnz];
        double *Ax = new double[nnz];

        int status = coo_to_csc(
            nrow,
            ncol,
            nnz,
            Ap,
            Ai,
            Ax,
            coo->indices_i.data(),
            coo->indices_j.data(),
            coo->values_aij.data());

        std::cout << "Ap = ";
        for (auto j = 0; j < ncol; j++) {
            std::cout << Ap[j] << ", ";
        }
        std::cout << std::endl;
        std::cout << "Ai = ";
        for (auto j = 0; j < ncol; j++) {
            std::cout << Ai[j] << ", ";
        }
        std::cout << std::endl;
        std::cout << "Ax = ";
        for (auto j = 0; j < ncol; j++) {
            std::cout << Ax[j] << ", ";
        }
        std::cout << std::endl;

        delete[] Ap;
        delete[] Ai;
        delete[] Ax;

        CHECK(status == 0);
    }
}
