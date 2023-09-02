if(WITH_MUMPS)
    set(EXAMPLES_MUMPS
        ex_solver_mumps
    )
    foreach(var ${EXAMPLES_MUMPS})
        add_executable(${var} "${var}.cpp")
        target_link_libraries(${var} PUBLIC laclib_open)
    endforeach(var)
endif()
