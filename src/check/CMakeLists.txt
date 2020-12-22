set(TESTS
    z_test_equal_vectors
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    # disable warning due to doctest.h functions:
    # warning #2196: routine is both "inline" and "noinline"
    set_target_properties(${var} PROPERTIES COMPILE_FLAGS "-diag-disable=2196")
endforeach(var)
