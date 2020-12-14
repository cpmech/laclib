add_library(laclib SHARED 
    read_matrix.cpp
    read_matrix_for_mumps.cpp
    solver_mumps.cpp
    triplet.cpp
    triplet_for_mumps.cpp
)

target_link_libraries(laclib PUBLIC ${LIBS})

set(TESTS
    z_test_read_matrix
    z_test_read_matrix_for_mumps
    z_test_triplet
    z_test_triplet_for_mumps
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC laclib)
endforeach(var)

set(TESTS_MPI_NP1
    z_test_solver_mumps_np1
)

foreach(var ${TESTS_MPI_NP1})
    add_executable(${var} "${var}.cpp" z_test_mpi_main.cpp)
    add_test(NAME ${var} COMMAND mpirun -np 1 ${var})
    target_link_libraries(${var} PUBLIC laclib ${LIBS})
endforeach(var)
