set(TESTS
    z_test_conversions
)

set(TESTS_INTEL
    z_test_mkl_double
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC)
endforeach(var)

if(A1_USE_INTEL)
    foreach(var ${TESTS_INTEL})
        add_executable(${var} "${var}.cpp")
        add_test(NAME ${var} COMMAND ${var})
        target_link_libraries(${var} PUBLIC ${MKL_LIBS})
    endforeach(var)
endif()