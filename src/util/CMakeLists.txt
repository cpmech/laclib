set(TESTS
    z_test_nanoseconds_to_string
    z_test_path_tools
    z_test_stopwatch
    z_test_string_tools
)

set(TESTS_MPI_NP3
    z_test_doctest_mpi
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
endforeach(var)

foreach(var ${TESTS_MPI_NP3})
    add_executable(${var} "${var}.cpp" z_test_doctest_main.cpp)
    add_test(NAME ${var} COMMAND mpirun -np 3 $<TARGET_FILE:${var}>)
    target_link_libraries(${var} PUBLIC ${LIBS})
endforeach(var)

add_executable(z_test_extract_arguments z_test_extract_arguments.cpp)
add_test(NAME z_test_extract_arguments COMMAND $<TARGET_FILE:z_test_extract_arguments> first second third)

add_executable(z_test_extract_first_default z_test_extract_first_default.cpp)
add_test(NAME z_test_extract_first_default COMMAND z_test_extract_first_default)