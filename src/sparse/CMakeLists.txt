set(TESTS
    zz_read_matrix_market_part
    zz_read_matrix_market
    zz_sparse_blas
    zz_sparse_triplet
)

set(TESTS_MPI_NP1
    zz_solver_mumps_np1
    zzi_mumps_bfwb62_np1
)

set(TESTS_MPI_NP2
    zz_solver_mumps_np2
    zz_sparse_blas_np2
    zzi_mumps_bfwb62_np2
)

set(TESTS_SEQ
    zz_solver_mumps_seq
    zzi_mumps_bfwb62_seq
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
endforeach(var)

if(A2_MPI)
    foreach(var ${TESTS_MPI_NP1})
        add_executable(${var} "${var}.cpp" zz_mpi_main.cpp)
        add_test(NAME ${var} COMMAND mpirun -np 1 $<TARGET_FILE:${var}>)
        target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
    endforeach(var)

    foreach(var ${TESTS_MPI_NP2})
        add_executable(${var} "${var}.cpp" zz_mpi_main.cpp)
        add_test(NAME ${var} COMMAND mpirun -np 2 $<TARGET_FILE:${var}>)
        target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
    endforeach(var)
else()
    foreach(var ${TESTS_SEQ})
        add_executable(${var} "${var}.cpp")
        add_test(NAME ${var} COMMAND ${var})
        target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
    endforeach(var)
endif()
