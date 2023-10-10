set(BENCHES
    mm_dss
    mm_mumps
)

foreach(var ${BENCHES})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC laclib)
    target_compile_definitions(${var} PRIVATE "MTX_DIR=\"$ENV{HOME}/Downloads/matrix-market\"")
    target_compile_definitions(${var} PRIVATE "OUT_DIR=\"${CMAKE_SOURCE_DIR}/benchmarks/sparse-solver/results/latest\"")
endforeach(var)
