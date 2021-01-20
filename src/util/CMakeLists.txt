set(TESTS
    zz_formaters
    zz_memory_usage
    zz_path_tools
    zz_stopwatch
    zz_string_tools
)

set(TESTS_MPI_NP3
    zz_doctest_mpi
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
endforeach(var)

if(A2_MPI)
    foreach(var ${TESTS_MPI_NP3})
        add_executable(${var} "${var}.cpp" zz_doctest_main.cpp)
        add_test(NAME ${var} COMMAND mpirun -np 3 $<TARGET_FILE:${var}>)
        target_link_libraries(${var} PUBLIC ${LIBS})
    endforeach(var)
endif()

add_executable(zz_extract_arguments zz_extract_arguments.cpp)
add_test(NAME zz_extract_arguments COMMAND $<TARGET_FILE:zz_extract_arguments> first second third)

add_executable(zz_extract_first_default zz_extract_first_default.cpp)
add_test(NAME zz_extract_first_default COMMAND zz_extract_first_default)

add_executable(zz_get_envar zz_get_envar.cpp)
add_test(NAME zz_get_envar COMMAND zz_get_envar -E environment)
set_property(TEST zz_get_envar APPEND PROPERTY ENVIRONMENT OMP_NUM_THREADS=4)
