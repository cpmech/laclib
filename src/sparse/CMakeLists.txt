set(TESTS
    z_test_coo_matrix
    z_test_csr_matrix
    z_test_read_matrix_market
    z_test_sparse_blas
    z_test_solver_dss
    z_test_solver_dss_bfwb62 
    z_test_solver_intel_dss_example
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC laclib_intel)
    target_compile_definitions(${var} PRIVATE "DATA_DIR=\"${CMAKE_SOURCE_DIR}/data\"")
endforeach(var)

target_compile_definitions(z_test_solver_dss_bfwb62 PRIVATE "DATA_DIR=\"${CMAKE_SOURCE_DIR}/data\"")

#set_tests_properties(z_test_csr_matrix PROPERTIES LABELS doMemcheck)
set_tests_properties(z_test_solver_dss PROPERTIES LABELS doMemcheck)

if(WITH_MUMPS)
    set(TESTS_MUMPS
        z_test_solver_mumps
        z_test_solver_mumps_bfwb62
    )
    foreach(var ${TESTS_MUMPS})
        add_executable(${var} "${var}.cpp")
        add_test(NAME ${var} COMMAND ${var})
        target_link_libraries(${var} PUBLIC laclib_open)
    endforeach(var)
    target_compile_definitions(z_test_solver_mumps_bfwb62 PRIVATE "DATA_DIR=\"${CMAKE_SOURCE_DIR}/data\"")
endif()
