set(TESTS
    zz_read_matrix_market
    zz_sparse_blas
    zz_sparse_triplet
    zz_solver_mumps
    zzi_mumps_bfwb62
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
endforeach(var)
