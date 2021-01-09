set(TESTS
    z_test_conversions
    z_test_double
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC ${LA_LIBS})
endforeach(var)