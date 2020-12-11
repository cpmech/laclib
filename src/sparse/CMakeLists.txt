add_library(laclib SHARED 
    read_matrix.cpp
    triplet.cpp
)

set(TESTS
    z_test_read_matrix
    z_test_triplet
)

foreach(var ${TESTS})
  add_executable(${var} "${var}.cpp")
  add_test(NAME ${var} COMMAND ${var})
  target_link_libraries(${var} PUBLIC laclib)
endforeach(var)
