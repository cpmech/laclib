set(TESTS
    z_test_cblas_wrapper
    z_test_matrix
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC laclib_intel)
endforeach(var)
