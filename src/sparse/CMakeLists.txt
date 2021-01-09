set(TESTS
    z_test_read_matrix
    z_test_read_matrix_for_mumps
    z_test_sparse_blas
    z_test_triplet
    z_test_triplet_for_mumps
)

set(TESTS_MPI_NP1
    z_test_solver_mumps_np1
    z_integ_mumps_bfwb62_np1
)

set(TESTS_MPI_NP2
    z_test_solver_mumps_np2
    z_test_sparse_blas_np2
    z_test_read_matrix_for_mumps_np2
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC laclib)
endforeach(var)

foreach(var ${TESTS_MPI_NP1})
    add_executable(${var} "${var}.cpp" z_test_mpi_main.cpp)
    add_test(NAME ${var} COMMAND mpirun -np 1 $<TARGET_FILE:${var}>)
    target_link_libraries(${var} PUBLIC laclib)
endforeach(var)

foreach(var ${TESTS_MPI_NP2})
    add_executable(${var} "${var}.cpp" z_test_mpi_main.cpp)
    add_test(NAME ${var} COMMAND mpirun -np 2 $<TARGET_FILE:${var}>)
    target_link_libraries(${var} PUBLIC laclib)
endforeach(var)