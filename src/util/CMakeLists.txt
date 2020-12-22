set(TESTS
    z_test_path_tools
    z_test_string_tools
)

set(TESTS_MPI_NP3
    z_test_doctest_mpi
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    # disable warning due to doctest.h functions:
    # warning #2196: routine is both "inline" and "noinline"
    set_target_properties(${var} PROPERTIES COMPILE_FLAGS "-diag-disable=2196")
endforeach(var)

foreach(var ${TESTS_MPI_NP3})
    add_executable(${var} "${var}.cpp" z_test_doctest_main.cpp)
    add_test(NAME ${var} COMMAND mpirun -np 3 $<TARGET_FILE:${var}>)
    target_link_libraries(${var} PUBLIC ${LIBS})
    # disable warning due to doctest.h functions:
    # warning #2196: routine is both "inline" and "noinline"
    set_target_properties(${var} PROPERTIES COMPILE_FLAGS "-diag-disable=2196")
endforeach(var)
