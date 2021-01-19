set(TESTS_MPI_NP4
    zz_mpiaux_np4
)

set(TESTS_NO_MPI
    zz_mpiaux_no_mpi
)

if(A2_MPI)
    foreach(var ${TESTS_MPI_NP4})
        add_executable(${var} "${var}.cpp" zz_mpi_main.cpp)
        add_test(NAME ${var} COMMAND mpirun -np 4 $<TARGET_FILE:${var}>)
    endforeach(var)
else()
    foreach(var ${TESTS_NO_MPI})
        add_executable(${var} "${var}.cpp")
        add_test(NAME ${var} COMMAND ${var})
    endforeach(var)
endif()
