set(TESTS
    z_test_formaters
    z_test_memory_usage
    z_test_stopwatch
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
endforeach(var)

add_executable(z_test_extract_arguments z_test_extract_arguments.cpp)
add_test(NAME z_test_extract_arguments COMMAND $<TARGET_FILE:z_test_extract_arguments> first second third)

add_executable(z_test_extract_first_default z_test_extract_first_default.cpp)
add_test(NAME z_test_extract_first_default COMMAND z_test_extract_first_default)

add_executable(z_test_get_envar z_test_get_envar.cpp)
add_test(NAME z_test_get_envar COMMAND z_test_get_envar -E environment)
set_property(TEST z_test_get_envar APPEND PROPERTY ENVIRONMENT OMP_NUM_THREADS=4)
