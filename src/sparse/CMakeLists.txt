set(TESTS
    z_test_read_matrix_market
    z_test_sparse_blas
    z_test_sparse_triplet
)

if(A0_MKL)
else()
    set(TESTS ${TESTS}
        z_test_solver_mumps
        z_test_solver_mumps_bfwb62
    )
endif()

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
endforeach(var)
