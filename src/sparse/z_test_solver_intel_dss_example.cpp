#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"

#include "mkl_dss.h"
#include "mkl_types.h"
/*
** Define the array and rhs vectors
*/
#define NROWS 5
#define NCOLS 5
#define NNONZEROS 9
#define NRHS 1
static const MKL_INT nRows = NROWS;
static const MKL_INT nCols = NCOLS;
static const MKL_INT nNonZeros = NNONZEROS;
static const MKL_INT nRhs = NRHS;
static _INTEGER_t rowIndex[NROWS + 1] = {1, 6, 7, 8, 9, 10};
static _INTEGER_t columns[NNONZEROS] = {1, 2, 3, 4, 5, 2, 3, 4, 5};
static _DOUBLE_PRECISION_t values[NNONZEROS] = {9, 1.5, 6, .75, 3, 0.5, 12, .625, 16};
static _DOUBLE_PRECISION_t rhs[NCOLS] = {1, 2, 3, 4, 5};

// Define the format to printf MKL_INT values
#if !defined(MKL_ILP64)
#define IFORMAT "%i"
#else
#define IFORMAT "%lli"
#endif

TEST_CASE("testing sparse solver Intel DSS") {
    MKL_INT i;
    /* Allocate storage for the solver handle and the right-hand side. */
    _DOUBLE_PRECISION_t solValues[NROWS];
    _MKL_DSS_HANDLE_t handle;
    _INTEGER_t error;
    _CHARACTER_t statIn[] = "determinant";
    _DOUBLE_PRECISION_t statOut[5];
    MKL_INT opt = MKL_DSS_DEFAULTS;
    MKL_INT sym = MKL_DSS_SYMMETRIC;
    MKL_INT type = MKL_DSS_POSITIVE_DEFINITE;
    /* --------------------- */
    /* Initialize the solver */
    /* --------------------- */
    error = dss_create(handle, opt);
    if (error != MKL_DSS_SUCCESS)
        goto printError;
    /* ------------------------------------------- */
    /* Define the non-zero structure of the matrix */
    /* ------------------------------------------- */
    error = dss_define_structure(handle, sym, rowIndex, nRows, nCols, columns, nNonZeros);
    if (error != MKL_DSS_SUCCESS)
        goto printError;
    /* ------------------ */
    /* Reorder the matrix */
    /* ------------------ */
    error = dss_reorder(handle, opt, 0);
    if (error != MKL_DSS_SUCCESS)
        goto printError;
    /* ------------------ */
    /* Factor the matrix  */
    /* ------------------ */
    error = dss_factor_real(handle, type, values);
    if (error != MKL_DSS_SUCCESS)
        goto printError;
    /* ------------------------ */
    /* Get the solution vector  */
    /* ------------------------ */
    error = dss_solve_real(handle, opt, rhs, nRhs, solValues);
    if (error != MKL_DSS_SUCCESS)
        goto printError;
    /* ------------------------ */
    /* Get the determinant (not for a diagonal matrix) */
    /*--------------------------*/
    if (nRows < nNonZeros) {
        error = dss_statistics(handle, opt, statIn, statOut);
        if (error != MKL_DSS_SUCCESS)
            goto printError;
        /*-------------------------*/
        /* print determinant       */
        /*-------------------------*/
        printf(" determinant power is %g \n", statOut[0]);
        printf(" determinant base is %g \n", statOut[1]);
        printf(" Determinant is %g \n", (pow(10.0, statOut[0])) * statOut[1]);
    }
    /* -------------------------- */
    /* Deallocate solver storage  */
    /* -------------------------- */
    error = dss_delete(handle, opt);
    if (error != MKL_DSS_SUCCESS)
        goto printError;
    /* ---------------------- */
    /* Print solution vector  */
    /* ---------------------- */
    printf(" Solution array: ");
    for (i = 0; i < nCols; i++)
        printf(" %g", solValues[i]);
    printf("\n");
printError:
    printf("Solver returned error code " IFORMAT "\n", error);
}