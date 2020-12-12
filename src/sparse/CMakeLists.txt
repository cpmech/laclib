add_library(laclib SHARED 
    read_matrix.cpp
    solver_mumps.cpp
    triplet.cpp
    triplet_for_mumps.cpp
)

set(TESTS
    z_test_read_matrix
    z_test_solver_mumps
    z_test_triplet
    z_test_triplet_for_mumps
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC laclib)
endforeach(var)
