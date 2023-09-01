#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>

#include "../check/check.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "sparse_triplet.h"

#define _SUBCASE(name) if (false)

#define VERBOSE true
#define PRINT_CSR(name)                        \
    if (VERBOSE) {                             \
        std::cout << std::endl                 \
                  << name << std::endl;        \
        print_vector("p", csr.row_pointers);   \
        print_vector("j", csr.column_indices); \
        print_vector("x", csr.values);         \
    }

using namespace std;

TEST_CASE("testing SparseTriplet (put)") {
    SUBCASE("make_new works with default values") {
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 4);

        vector<INT> I_correct{0, 0, 0, 0};
        vector<INT> J_correct{0, 0, 0, 0};
        vector<double> X_correct{0.0, 0.0, 0.0, 0.0};

        CHECK(trip->layout == FULL_MATRIX);
        CHECK(trip->dimension == 3);
        CHECK(trip->pos == 0);
        CHECK(trip->max == 4);
        CHECK(trip->indices_i.size() == 4);
        CHECK(trip->indices_j.size() == 4);
        CHECK(trip->values_aij.size() == 4);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put works") {
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 4);

        vector<INT> I_correct{0, 1, 2, 0};
        vector<INT> J_correct{0, 1, 2, 1};
        vector<double> X_correct{10.0, 11.0, 12.0, 4.0};

        trip->put(0, 0, 10.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 12.0);
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put works with duplicates") {
        size_t max = 6;
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, max);

        vector<INT> I_correct{0, 1, 2, 0, 0, 2};
        vector<INT> J_correct{0, 1, 2, 1, 0, 2};
        vector<double> X_correct{5.0, 11.0, 6.0, 4.0, 5.0, 6.0};

        trip->put(0, 0, 5.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 6.0);
        trip->put(0, 1, 4.0);
        trip->put(0, 0, 5.0); // << duplicate
        trip->put(2, 2, 6.0); // << duplicate

        CHECK(trip->pos == 6);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put handles exceptions") {
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 4);

        CHECK_THROWS_WITH(trip->put(-1, 0, 10.0), "SparseTriplet::put: index of row is outside range");
        CHECK_THROWS_WITH(trip->put(3, 0, 10.0), "SparseTriplet::put: index of row is outside range");
        CHECK_THROWS_WITH(trip->put(0, -1, 11.0), "SparseTriplet::put: index of column is outside range");
        CHECK_THROWS_WITH(trip->put(0, 3, 11.0), "SparseTriplet::put: index of column is outside range");

        trip->put(0, 0, 1);
        trip->put(0, 1, 2);
        trip->put(1, 0, 3);
        trip->put(1, 1, 4);

        CHECK_THROWS_WITH(trip->put(0, 0, 4.0), "SparseTriplet::put: max number of items has been exceeded");
    }

    // -------- conversion -----------------------------------------------------------------------------------

    //  1  -1   .  -3   .
    // -2   5   .   .   .
    //  .   .   4   6   4
    // -4   .   2   7   .
    //  .   8   .   .  -5
    // random order
    auto coo_random_01 = SparseTriplet::make_new(FULL_MATRIX, 5, 13);
    coo_random_01->put(2, 4, 4.0);
    coo_random_01->put(4, 1, 8.0);
    coo_random_01->put(0, 1, -1.0);
    coo_random_01->put(2, 2, 4.0);
    coo_random_01->put(4, 4, -5.0);
    coo_random_01->put(3, 0, -4.0);
    coo_random_01->put(0, 3, -3.0);
    coo_random_01->put(2, 3, 6.0);
    coo_random_01->put(0, 0, 1.0);
    coo_random_01->put(1, 1, 5.0);
    coo_random_01->put(3, 2, 2.0);
    coo_random_01->put(1, 0, -2.0);
    coo_random_01->put(3, 3, 7.0);

    // 1  2  .  .  .
    // 3  4  .  .  .
    // .  .  5  6  .
    // .  .  7  8  .
    // .  .  .  .  9
    auto coo_small = SparseTriplet::make_new(FULL_MATRIX, 5, 9);
    coo_small->put(4, 4, 9.0);
    coo_small->put(0, 0, 1.0);
    coo_small->put(1, 0, 3.0);
    coo_small->put(2, 2, 5.0);
    coo_small->put(2, 3, 6.0);
    coo_small->put(0, 1, 2.0);
    coo_small->put(3, 2, 7.0);
    coo_small->put(1, 1, 4.0);
    coo_small->put(3, 3, 8.0);

    // 1  2  .  .  .
    // 3  4  .  .  .
    // .  .  5  6  .
    // .  .  7  8  .
    // .  .  .  .  9
    // with duplicates
    auto coo_small_duplicates = SparseTriplet::make_new(FULL_MATRIX, 5, 11);
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
    auto coo_upper_ordered = SparseTriplet::make_new(UPPER_TRIANGULAR, 5, 9);
    coo_upper_ordered->put(0, 0, 9.0);
    coo_upper_ordered->put(0, 1, 1.5);
    coo_upper_ordered->put(1, 1, 0.5);
    coo_upper_ordered->put(0, 2, 6.0);
    coo_upper_ordered->put(2, 2, 12.0);
    coo_upper_ordered->put(0, 3, 0.75);
    coo_upper_ordered->put(3, 3, 0.625);
    coo_upper_ordered->put(0, 4, 3.0);
    coo_upper_ordered->put(4, 4, 16.0);

    //  9.00  1.5   6.0  0.750   3.0
    //  1.50  0.5   0.0  0.000   0.0
    //  6.00  0.0  12.0  0.000   0.0
    //  0.75  0.0   0.0  0.625   0.0
    //  3.00  0.0   0.0  0.000  16.0
    // upper triangular with shuffled entries
    auto coo_upper_shuffled = SparseTriplet::make_new(UPPER_TRIANGULAR, 5, 9);
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
    auto coo_upper_diagonal_first = SparseTriplet::make_new(UPPER_TRIANGULAR, 5, 9);
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
    auto coo_lower_ordered = SparseTriplet::make_new(LOWER_TRIANGULAR, 5, 9);
    coo_lower_ordered->put(0, 0, 9.0);
    coo_lower_ordered->put(1, 0, 1.5);
    coo_lower_ordered->put(1, 1, 0.5);
    coo_lower_ordered->put(2, 0, 6.0);
    coo_lower_ordered->put(2, 2, 12.0);
    coo_lower_ordered->put(3, 0, 0.75);
    coo_lower_ordered->put(3, 3, 0.625);
    coo_lower_ordered->put(4, 0, 3.0);
    coo_lower_ordered->put(4, 4, 16.0);

    //  9.00  1.5   6.0  0.750   3.0
    //  1.50  0.5   0.0  0.000   0.0
    //  6.00  0.0  12.0  0.000   0.0
    //  0.75  0.0   0.0  0.625   0.0
    //  3.00  0.0   0.0  0.000  16.0
    // lower triangular with diagonal entries being set first
    auto coo_lower_diagonal_first = SparseTriplet::make_new(LOWER_TRIANGULAR, 5, 9);
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

    SUBCASE("convert to csr works (random order)") {
        auto csr = coo_random_01->to_csr();
        PRINT_CSR("random_01")
        vector<INT> correct_p{0, 3, 5, 8, 11, 13};
        vector<INT> correct_j{0, 1, 3, /**/ 0, 1, /**/ 2, 3, 4, /**/ 0, 2, 3, /**/ 1, 4};
        vector<double> correct_x{1.0, -1.0, -3.0, -2.0, 5.0, 4.0, 6.0, 4.0, -4.0, 2.0, 7.0, 8.0, -5.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("convert to csr works with small matrix") {
        auto csr = coo_small->to_csr();
        PRINT_CSR("small")
        vector<INT> correct_p{0, 2, 4, 6, 8, 9};
        vector<INT> correct_j{0, 1, 0, 1, 2, 3, 2, 3, 4};
        vector<double> correct_x{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("convert to csr works with small matrix (sum duplicates)") {
        auto csr = coo_small_duplicates->to_csr();
        PRINT_CSR("small_duplicates")

        auto n_summed = coo_small_duplicates->pos - csr.nnz;
        CHECK(n_summed == 2);
        auto final_j = std::vector<INT>(csr.column_indices.begin(), csr.column_indices.end() - n_summed);
        auto final_x = std::vector<double>(csr.values.begin(), csr.values.end() - n_summed);

        vector<INT> correct_p{0, 2, 4, 6, 8, 9};
        vector<INT> correct_j{0, 1, 0, 1, 2, 3, 2, 3, 4};
        vector<double> correct_x{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(final_j, correct_j));
        CHECK(equal_vectors_tol(final_x, correct_x, 1e-15));
    }

    SUBCASE("convert to csr works with symmetric matrix (upper triangular / ordered)") {
        auto csr = coo_upper_ordered->to_csr();
        PRINT_CSR("upper_ordered")
        vector<INT> correct_p{0, 5, 6, 7, 8, 9};
        vector<INT> correct_j{0, 1, 2, 3, 4, 1, 2, 3, 4};
        vector<double> correct_x{9.0, 1.5, 6.0, 0.75, 3.0, 0.5, 12.0, 0.625, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("convert to csr works with symmetric matrix (upper triangular / shuffled)") {
        auto csr = coo_upper_shuffled->to_csr();
        PRINT_CSR("upper_shuffled")
        vector<INT> correct_p{0, 5, 6, 7, 8, 9};
        vector<INT> correct_j{0, 1, 2, 3, 4, 1, 2, 3, 4};
        vector<double> correct_x{9.0, 1.5, 6.0, 0.75, 3.0, 0.5, 12.0, 0.625, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("convert to csr works with symmetric matrix (upper triangular / diagonal first)") {
        auto csr = coo_upper_diagonal_first->to_csr();
        PRINT_CSR("upper_diagonal_first")
        vector<INT> correct_p{0, 5, 6, 7, 8, 9};
        vector<INT> correct_j{0, 1, 2, 3, 4, 1, 2, 3, 4};
        vector<double> correct_x{9.0, 1.5, 6.0, 0.75, 3.0, 0.5, 12.0, 0.625, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("convert to csr works with symmetric matrix (lower triangular / ordered)") {
        auto csr = coo_lower_ordered->to_csr();
        PRINT_CSR("lower_ordered")
        vector<INT> correct_p{0, 1, 3, 5, 7, 9};
        vector<INT> correct_j{0, 0, 1, 0, 2, 0, 3, 0, 4};
        vector<double> correct_x{9.0, 1.5, 0.5, 6.0, 12.0, 0.75, 0.625, 3.0, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("convert to csr works with symmetric matrix (lower triangular / diagonal first)") {
        auto csr = coo_lower_diagonal_first->to_csr();
        PRINT_CSR("lower_diagonal_first")
        vector<INT> correct_p{0, 1, 3, 5, 7, 9};
        vector<INT> correct_j{0, 0, 1, 0, 2, 0, 3, 0, 4};
        vector<double> correct_x{9.0, 1.5, 0.5, 6.0, 12.0, 0.75, 0.625, 3.0, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    // -------- using intel mkl ------------------------------------------------------------------------------

    SUBCASE("intel mkl: convert to csr works (random order)") {
        auto csr = coo_random_01->to_csr();
        PRINT_CSR("intel mkl: random_01")
        vector<INT> correct_p{0, 3, 5, 8, 11, 13};
        vector<INT> correct_j{0, 1, 3, /**/ 0, 1, /**/ 2, 3, 4, /**/ 0, 2, 3, /**/ 1, 4};
        vector<double> correct_x{1.0, -1.0, -3.0, -2.0, 5.0, 4.0, 6.0, 4.0, -4.0, 2.0, 7.0, 8.0, -5.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("intel mkl: convert to csr works with small matrix") {
        auto csr = coo_small->to_csr();
        PRINT_CSR("intel mkl: small")
        vector<INT> correct_p{0, 2, 4, 6, 8, 9};
        vector<INT> correct_j{0, 1, 0, 1, 2, 3, 2, 3, 4};
        vector<double> correct_x{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("intel mkl: convert to csr works with small matrix (sum duplicates)") {
        auto csr = coo_small_duplicates->to_csr();
        PRINT_CSR("intel mkl: small_duplicates")

        auto n_summed = coo_small_duplicates->pos - csr.nnz;
        CHECK(n_summed == 2);
        auto final_j = std::vector<INT>(csr.column_indices.begin(), csr.column_indices.end() - n_summed);
        auto final_x = std::vector<double>(csr.values.begin(), csr.values.end() - n_summed);

        vector<INT> correct_p{0, 2, 4, 6, 8, 9};
        vector<INT> correct_j{0, 1, 0, 1, 2, 3, 2, 3, 4};
        vector<double> correct_x{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(final_j, correct_j));
        CHECK(equal_vectors_tol(final_x, correct_x, 1e-15));
    }

    SUBCASE("intel mkl: convert to csr works with symmetric matrix (upper triangular / ordered)") {
        auto csr = coo_upper_ordered->to_csr();
        PRINT_CSR("intel mkl: upper_ordered")
        vector<INT> correct_p{0, 5, 6, 7, 8, 9};
        vector<INT> correct_j{0, 1, 2, 3, 4, 1, 2, 3, 4};
        vector<double> correct_x{9.0, 1.5, 6.0, 0.75, 3.0, 0.5, 12.0, 0.625, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("intel mkl: convert to csr works with symmetric matrix (upper triangular / shuffled)") {
        auto csr = coo_upper_shuffled->to_csr();
        PRINT_CSR("intel mkl: upper_shuffled")
        vector<INT> correct_p{0, 5, 6, 7, 8, 9};
        vector<INT> correct_j{0, 1, 2, 3, 4, 1, 2, 3, 4};
        vector<double> correct_x{9.0, 1.5, 6.0, 0.75, 3.0, 0.5, 12.0, 0.625, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("intel mkl: convert to csr works with symmetric matrix (upper triangular / diagonal first)") {
        auto csr = coo_upper_diagonal_first->to_csr();
        PRINT_CSR("intel mkl: upper_diagonal_first")
        vector<INT> correct_p{0, 5, 6, 7, 8, 9};
        vector<INT> correct_j{0, 1, 2, 3, 4, 1, 2, 3, 4};
        vector<double> correct_x{9.0, 1.5, 6.0, 0.75, 3.0, 0.5, 12.0, 0.625, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("intel mkl: convert to csr works with symmetric matrix (lower triangular / ordered)") {
        auto csr = coo_lower_ordered->to_csr();
        PRINT_CSR("intel mkl: lower_ordered")
        vector<INT> correct_p{0, 1, 3, 5, 7, 9};
        vector<INT> correct_j{0, 0, 1, 0, 2, 0, 3, 0, 4};
        vector<double> correct_x{9.0, 1.5, 0.5, 6.0, 12.0, 0.75, 0.625, 3.0, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }

    SUBCASE("intel mkl: convert to csr works with symmetric matrix (lower triangular / diagonal first)") {
        auto csr = coo_lower_diagonal_first->to_csr();
        PRINT_CSR("intel mkl: lower_diagonal_first")
        vector<INT> correct_p{0, 1, 3, 5, 7, 9};
        vector<INT> correct_j{0, 0, 1, 0, 2, 0, 3, 0, 4};
        vector<double> correct_x{9.0, 1.5, 0.5, 6.0, 12.0, 0.75, 0.625, 3.0, 16.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }
}
