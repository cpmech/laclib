set(TESTS
    zz_cblas_tools
    zz_stats
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
endforeach(var)
