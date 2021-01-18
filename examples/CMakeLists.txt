set(EXAMPLES
    ex_solver_mumps
)

foreach(var ${EXAMPLES})
    add_executable(${var} "${var}.cpp")
    target_link_libraries(${var} PUBLIC ${LACLIB_NAME})
endforeach(var)
