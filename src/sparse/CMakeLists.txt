set(TESTS
    zz_read_matrix_market
    zz_sparse_blas
    zz_sparse_triplet
)

if(A0_MKL)
else()
    set(TESTS ${TESTS}
        zz_solver_mumps
        zzi_mumps_bfwb62
    )
endif()

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
endforeach(var)
