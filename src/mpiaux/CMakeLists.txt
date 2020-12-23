set(TESTS_MPI_NP2
    z_test_mpiaux
)

foreach(var ${TESTS_MPI_NP2})
    add_executable(${var} "${var}.cpp" z_test_mpi_main.cpp)
    add_test(NAME ${var} COMMAND mpirun -np 2 $<TARGET_FILE:${var}>)
    # disable warning due to doctest.h functions:
    # warning #2196: routine is both "inline" and "noinline"
    set_target_properties(${var} PROPERTIES COMPILE_FLAGS "-diag-disable=2196")
endforeach(var)