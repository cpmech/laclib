set(TESTS
    zz_conversions
    zz_double
    zz_high_level
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC ${LA_LIBS})
endforeach(var)
