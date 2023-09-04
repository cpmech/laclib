#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "coo_matrix.h"
#include "csr_matrix.h"

#define _SUBCASE(name) if (false)

using namespace std;

TEST_CASE("testing CsrMatrix") {

    //  1  -1   .  -3   .
    // -2   5   .   .   .
    //  .   .   4   6   4
    // -4   .   2   7   .
    //  .   8   .   .  -5
    // first triplet with shuffled entries
    auto coo_first_shuffled = CooMatrix::make_new(FULL_MATRIX, 5, 13);
    coo_first_shuffled->put(2, 4, 4.0);
    coo_first_shuffled->put(4, 1, 8.0);
    coo_first_shuffled->put(0, 1, -1.0);
    coo_first_shuffled->put(2, 2, 4.0);
    coo_first_shuffled->put(4, 4, -5.0);
    coo_first_shuffled->put(3, 0, -4.0);
    coo_first_shuffled->put(0, 3, -3.0);
    coo_first_shuffled->put(2, 3, 6.0);
    coo_first_shuffled->put(0, 0, 1.0);
    coo_first_shuffled->put(1, 1, 5.0);
    coo_first_shuffled->put(3, 2, 2.0);
    coo_first_shuffled->put(1, 0, -2.0);
    coo_first_shuffled->put(3, 3, 7.0);
    // solution
    vector<INT> correct_first_p{0, 3, 5, 8, 11, 13};
    vector<INT> correct_first_j{0, 1, 3, /**/ 0, 1, /**/ 2, 3, 4, /**/ 0, 2, 3, /**/ 1, 4};
    vector<double> correct_first_x{1.0, -1.0, -3.0, -2.0, 5.0, 4.0, 6.0, 4.0, -4.0, 2.0, 7.0, 8.0, -5.0};

    // 1  2  .  .  .
    // 3  4  .  .  .
    // .  .  5  6  .
    // .  .  7  8  .
    // .  .  .  .  9
    // small triplet with shuffled entries
    auto coo_small_shuffled = CooMatrix::make_new(FULL_MATRIX, 5, 9);
    coo_small_shuffled->put(4, 4, 9.0);
    coo_small_shuffled->put(0, 0, 1.0);
    coo_small_shuffled->put(1, 0, 3.0);
    coo_small_shuffled->put(2, 2, 5.0);
    coo_small_shuffled->put(2, 3, 6.0);
    coo_small_shuffled->put(0, 1, 2.0);
    coo_small_shuffled->put(3, 2, 7.0);
    coo_small_shuffled->put(1, 1, 4.0);
    coo_small_shuffled->put(3, 3, 8.0);
    // solution
    vector<INT> correct_small_p{0, 2, 4, 6, 8, 9};
    vector<INT> correct_small_j{0, 1, 0, 1, 2, 3, 2, 3, 4};
    vector<double> correct_small_x{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

    // 1  2  .  .  .
    // 3  4  .  .  .
    // .  .  5  6  .
    // .  .  7  8  .
    // .  .  .  .  9
    // with duplicates
    auto coo_small_duplicates = CooMatrix::make_new(FULL_MATRIX, 5, 11);
    coo_small_duplicates->put(4, 4, 9.0);
    coo_small_duplicates->put(0, 0, 1.0);
    coo_small_duplicates->put(1, 0, 3.0);
    coo_small_duplicates->put(2, 2, 5.0);
    coo_small_duplicates->put(2, 3, 3.0); // <<
    coo_small_duplicates->put(0, 1, 2.0);
    coo_small_duplicates->put(3, 2, 7.0);
    coo_small_duplicates->put(1, 1, 2.0); // <<
    coo_small_duplicates->put(3, 3, 8.0);
    coo_small_duplicates->put(2, 3, 3.0); // << duplicate
    coo_small_duplicates->put(1, 1, 2.0); // << duplicate

    //  9.00  1.5   6.0  0.750   3.0
    //  1.50  0.5   0.0  0.000   0.0
    //  6.00  0.0  12.0  0.000   0.0
    //  0.75  0.0   0.0  0.625   0.0
    //  3.00  0.0   0.0  0.000  16.0
    // upper triangular with ordered entries
    auto coo_upper_ordered = CooMatrix::make_new(UPPER_TRIANGULAR, 5, 9);
    coo_upper_ordered->put(0, 0, 9.0);
    coo_upper_ordered->put(0, 1, 1.5);
    coo_upper_ordered->put(1, 1, 0.5);
    coo_upper_ordered->put(0, 2, 6.0);
    coo_upper_ordered->put(2, 2, 12.0);
    coo_upper_ordered->put(0, 3, 0.75);
    coo_upper_ordered->put(3, 3, 0.625);
    coo_upper_ordered->put(0, 4, 3.0);
    coo_upper_ordered->put(4, 4, 16.0);
    // solution
    vector<INT> correct_upper_p{0, 5, 6, 7, 8, 9};
    vector<INT> correct_upper_j{0, 1, 2, 3, 4, 1, 2, 3, 4};
    vector<double> correct_upper_x{9.0, 1.5, 6.0, 0.75, 3.0, 0.5, 12.0, 0.625, 16.0};

    //  9.00  1.5   6.0  0.750   3.0
    //  1.50  0.5   0.0  0.000   0.0
    //  6.00  0.0  12.0  0.000   0.0
    //  0.75  0.0   0.0  0.625   0.0
    //  3.00  0.0   0.0  0.000  16.0
    // upper triangular with shuffled entries
    auto coo_upper_shuffled = CooMatrix::make_new(UPPER_TRIANGULAR, 5, 9);
    coo_upper_shuffled->put(2, 2, 12.0);
    coo_upper_shuffled->put(0, 0, 9.0);
    coo_upper_shuffled->put(3, 3, 0.625);
    coo_upper_shuffled->put(0, 1, 1.5);
    coo_upper_shuffled->put(0, 2, 6.0);
    coo_upper_shuffled->put(4, 4, 16.0);
    coo_upper_shuffled->put(0, 3, 0.75);
    coo_upper_shuffled->put(1, 1, 0.5);
    coo_upper_shuffled->put(0, 4, 3.0);

    //  9.00  1.5   6.0  0.750   3.0
    //  1.50  0.5   0.0  0.000   0.0
    //  6.00  0.0  12.0  0.000   0.0
    //  0.75  0.0   0.0  0.625   0.0
    //  3.00  0.0   0.0  0.000  16.0
    // upper triangular with diagonal entries being set first
    auto coo_upper_diagonal_first = CooMatrix::make_new(UPPER_TRIANGULAR, 5, 9);
    // diagonal
    coo_upper_diagonal_first->put(0, 0, 9.0);
    coo_upper_diagonal_first->put(1, 1, 0.5);
    coo_upper_diagonal_first->put(2, 2, 12.0);
    coo_upper_diagonal_first->put(3, 3, 0.625);
    coo_upper_diagonal_first->put(4, 4, 16.0);
    // upper diagonal
    coo_upper_diagonal_first->put(0, 1, 1.5);
    coo_upper_diagonal_first->put(0, 2, 6.0);
    coo_upper_diagonal_first->put(0, 3, 0.75);
    coo_upper_diagonal_first->put(0, 4, 3.0);

    //  9.00  1.5   6.0  0.750   3.0
    //  1.50  0.5   0.0  0.000   0.0
    //  6.00  0.0  12.0  0.000   0.0
    //  0.75  0.0   0.0  0.625   0.0
    //  3.00  0.0   0.0  0.000  16.0
    // lower diagonal with ordered entries
    auto coo_lower_ordered = CooMatrix::make_new(LOWER_TRIANGULAR, 5, 9);
    coo_lower_ordered->put(0, 0, 9.0);
    coo_lower_ordered->put(1, 0, 1.5);
    coo_lower_ordered->put(1, 1, 0.5);
    coo_lower_ordered->put(2, 0, 6.0);
    coo_lower_ordered->put(2, 2, 12.0);
    coo_lower_ordered->put(3, 0, 0.75);
    coo_lower_ordered->put(3, 3, 0.625);
    coo_lower_ordered->put(4, 0, 3.0);
    coo_lower_ordered->put(4, 4, 16.0);
    // solution
    vector<INT> correct_lower_p{0, 1, 3, 5, 7, 9};
    vector<INT> correct_lower_j{0, 0, 1, 0, 2, 0, 3, 0, 4};
    vector<double> correct_lower_x{9.0, 1.5, 0.5, 6.0, 12.0, 0.75, 0.625, 3.0, 16.0};

    //  9.00  1.5   6.0  0.750   3.0
    //  1.50  0.5   0.0  0.000   0.0
    //  6.00  0.0  12.0  0.000   0.0
    //  0.75  0.0   0.0  0.625   0.0
    //  3.00  0.0   0.0  0.000  16.0
    // lower triangular with diagonal entries being set first
    auto coo_lower_diagonal_first = CooMatrix::make_new(LOWER_TRIANGULAR, 5, 9);
    // diagonal
    coo_lower_diagonal_first->put(0, 0, 9.0);
    coo_lower_diagonal_first->put(1, 1, 0.5);
    coo_lower_diagonal_first->put(2, 2, 12.0);
    coo_lower_diagonal_first->put(3, 3, 0.625);
    coo_lower_diagonal_first->put(4, 4, 16.0);
    // lower diagonal
    coo_lower_diagonal_first->put(1, 0, 1.5);
    coo_lower_diagonal_first->put(2, 0, 6.0);
    coo_lower_diagonal_first->put(3, 0, 0.75);
    coo_lower_diagonal_first->put(4, 0, 3.0);

    // -------- local implementation (based on scipy) --------------------------------------------------------

    SUBCASE("local") {
        SUBCASE("convert to csr works (shuffled order)") {
            auto csr = CsrMatrix::from(coo_first_shuffled);
            // csr->print("first_shuffled");
            CHECK(equal_vectors(csr->row_pointers, correct_first_p));
            CHECK(equal_vectors(csr->column_indices, correct_first_j));
            CHECK(equal_vectors_tol(csr->values, correct_first_x, 1e-15));
        }

        SUBCASE("convert to csr works with small matrix") {
            auto csr = CsrMatrix::from(coo_small_shuffled);
            // csr->print("small_shuffled");
            CHECK(equal_vectors(csr->row_pointers, correct_small_p));
            CHECK(equal_vectors(csr->column_indices, correct_small_j));
            CHECK(equal_vectors_tol(csr->values, correct_small_x, 1e-15));
        }

        SUBCASE("convert to csr works with small matrix (sum duplicates)") {
            auto csr = CsrMatrix::from(coo_small_duplicates);
            // csr->print("small_duplicates");

            auto n_summed = coo_small_duplicates->pos - csr->nnz;
            CHECK(n_summed == 2);
            auto final_j = std::vector<INT>(csr->column_indices.begin(), csr->column_indices.end() - n_summed);
            auto final_x = std::vector<double>(csr->values.begin(), csr->values.end() - n_summed);

            CHECK(equal_vectors(csr->row_pointers, correct_small_p));
            CHECK(equal_vectors(final_j, correct_small_j));
            CHECK(equal_vectors_tol(final_x, correct_small_x, 1e-15));
        }

        SUBCASE("convert to csr works with symmetric matrix (upper triangular / ordered)") {
            auto csr = CsrMatrix::from(coo_upper_ordered);
            // csr->print("upper_ordered");
            CHECK(equal_vectors(csr->row_pointers, correct_upper_p));
            CHECK(equal_vectors(csr->column_indices, correct_upper_j));
            CHECK(equal_vectors_tol(csr->values, correct_upper_x, 1e-15));
        }

        SUBCASE("convert to csr works with symmetric matrix (upper triangular / shuffled)") {
            auto csr = CsrMatrix::from(coo_upper_shuffled);
            // csr->print("upper_shuffled");
            CHECK(equal_vectors(csr->row_pointers, correct_upper_p));
            CHECK(equal_vectors(csr->column_indices, correct_upper_j));
            CHECK(equal_vectors_tol(csr->values, correct_upper_x, 1e-15));
        }

        SUBCASE("convert to csr works with symmetric matrix (upper triangular / diagonal first)") {
            auto csr = CsrMatrix::from(coo_upper_diagonal_first);
            // csr->print("upper_diagonal_first");
            CHECK(equal_vectors(csr->row_pointers, correct_upper_p));
            CHECK(equal_vectors(csr->column_indices, correct_upper_j));
            CHECK(equal_vectors_tol(csr->values, correct_upper_x, 1e-15));
        }

        SUBCASE("convert to csr works with symmetric matrix (lower triangular / ordered)") {
            auto csr = CsrMatrix::from(coo_lower_ordered);
            // csr->print("lower_ordered");
            CHECK(equal_vectors(csr->row_pointers, correct_lower_p));
            CHECK(equal_vectors(csr->column_indices, correct_lower_j));
            CHECK(equal_vectors_tol(csr->values, correct_lower_x, 1e-15));
        }

        SUBCASE("convert to csr works with symmetric matrix (lower triangular / diagonal first)") {
            auto csr = CsrMatrix::from(coo_lower_diagonal_first);
            // csr->print("lower_diagonal_first");
            CHECK(equal_vectors(csr->row_pointers, correct_lower_p));
            CHECK(equal_vectors(csr->column_indices, correct_lower_j));
            CHECK(equal_vectors_tol(csr->values, correct_lower_x, 1e-15));
        }
    }

    // -------- using intel mkl ------------------------------------------------------------------------------

#ifdef USE_MKL

    SUBCASE("intel mkl") {
        SUBCASE("intel mkl: convert to csr works (shuffled order)") {
            auto csr = CsrMatrixMkl::from(coo_first_shuffled);
            // csr->print("intel mkl: random_01");
            CHECK(equal_arrays(csr->dimension + 1, csr->row_pointers, correct_first_p.data()));
            CHECK(equal_arrays(csr->nnz, csr->column_indices, correct_first_j.data()));
            CHECK(equal_arrays_tol(csr->nnz, csr->values, correct_first_x.data(), 1e-15));
        }

        SUBCASE("intel mkl: convert to csr works with small matrix") {
            auto csr = CsrMatrixMkl::from(coo_small_shuffled);
            // csr->print("intel mkl: small");
            CHECK(equal_arrays(csr->dimension + 1, csr->row_pointers, correct_small_p.data()));
            CHECK(equal_arrays(csr->nnz, csr->column_indices, correct_small_j.data()));
            CHECK(equal_arrays_tol(csr->nnz, csr->values, correct_small_x.data(), 1e-15));
        }

        SUBCASE("intel mkl: convert to csr works with small matrix (sum duplicates)") {
            auto csr = CsrMatrixMkl::from(coo_small_duplicates);
            // csr->print("intel mkl: small_duplicates");
            CHECK(equal_arrays(csr->dimension + 1, csr->row_pointers, correct_small_p.data()));
            CHECK(equal_arrays(csr->nnz, csr->column_indices, correct_small_j.data()));
            CHECK(equal_arrays_tol(csr->nnz, csr->values, correct_small_x.data(), 1e-15));
        }

        SUBCASE("intel mkl: convert to csr works with symmetric matrix (upper triangular / ordered)") {
            auto csr = CsrMatrixMkl::from(coo_upper_ordered);
            // csr->print("intel mkl: upper_ordered");
            CHECK(equal_arrays(csr->dimension + 1, csr->row_pointers, correct_upper_p.data()));
            CHECK(equal_arrays(csr->nnz, csr->column_indices, correct_upper_j.data()));
            CHECK(equal_arrays_tol(csr->nnz, csr->values, correct_upper_x.data(), 1e-15));
        }

        SUBCASE("intel mkl: convert to csr works with symmetric matrix (upper triangular / shuffled)") {
            auto csr = CsrMatrixMkl::from(coo_upper_shuffled);
            // csr->print("intel mkl: upper_shuffled");
            CHECK(equal_arrays(csr->dimension + 1, csr->row_pointers, correct_upper_p.data()));
            CHECK(equal_arrays(csr->nnz, csr->column_indices, correct_upper_j.data()));
            CHECK(equal_arrays_tol(csr->nnz, csr->values, correct_upper_x.data(), 1e-15));
        }

        SUBCASE("intel mkl: convert to csr works with symmetric matrix (upper triangular / diagonal first)") {
            auto csr = CsrMatrixMkl::from(coo_upper_diagonal_first);
            // csr->print("intel mkl: upper_diagonal_first");
            CHECK(equal_arrays(csr->dimension + 1, csr->row_pointers, correct_upper_p.data()));
            CHECK(equal_arrays(csr->nnz, csr->column_indices, correct_upper_j.data()));
            CHECK(equal_arrays_tol(csr->nnz, csr->values, correct_upper_x.data(), 1e-15));
        }

        SUBCASE("intel mkl: convert to csr works with symmetric matrix (lower triangular / ordered)") {
            auto csr = CsrMatrixMkl::from(coo_lower_ordered);
            // csr->print("intel mkl: lower_ordered");
            CHECK(equal_arrays(csr->dimension + 1, csr->row_pointers, correct_lower_p.data()));
            CHECK(equal_arrays(csr->nnz, csr->column_indices, correct_lower_j.data()));
            CHECK(equal_arrays_tol(csr->nnz, csr->values, correct_lower_x.data(), 1e-15));
        }

        SUBCASE("intel mkl: convert to csr works with symmetric matrix (lower triangular / diagonal first)") {
            auto csr = CsrMatrixMkl::from(coo_lower_diagonal_first);
            // csr->print("intel mkl: lower_diagonal_first");
            CHECK(equal_arrays(csr->dimension + 1, csr->row_pointers, correct_lower_p.data()));
            CHECK(equal_arrays(csr->nnz, csr->column_indices, correct_lower_j.data()));
            CHECK(equal_arrays_tol(csr->nnz, csr->values, correct_lower_x.data(), 1e-15));
        }
    }
#endif // USE_MKL
}