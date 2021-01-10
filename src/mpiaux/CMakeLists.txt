set(TESTS_MPI_NP4
    zz_mpiaux_np4
)

foreach(var ${TESTS_MPI_NP4})
    add_executable(${var} "${var}.cpp" zz_mpi_main.cpp)
    add_test(NAME ${var} COMMAND mpirun -np 4 $<TARGET_FILE:${var}>)
endforeach(var)
