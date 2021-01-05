add_library(nist-mmio SHARED mmio.c wrapper.cpp)

set(TESTS
    z_test_nist-mmio
)

foreach(var ${TESTS})
    add_executable(${var} "${var}.cpp")
    add_test(NAME ${var} COMMAND ${var})
    target_link_libraries(${var} PUBLIC nist-mmio)
endforeach(var)