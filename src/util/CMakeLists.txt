set(TESTS
    z_test_path_tools
    z_test_string_tools
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
endforeach(var)

add_executable(z_test_doctest_mpi z_test_doctest_main.cpp z_test_doctest_mpi.cpp)
add_test(NAME z_test_doctest_mpi COMMAND mpirun -np 3 $<TARGET_FILE:z_test_doctest_mpi>)
target_link_libraries(z_test_doctest_mpi PUBLIC ${LIBS})
