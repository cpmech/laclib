set(TESTS
    zz_equal_scalars
    zz_equal_vectors
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
endforeach(var)
