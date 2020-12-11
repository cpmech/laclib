set(TESTS
  z_test_get_selfpath
)

foreach(var ${TESTS})
  add_executable(${var} "${var}.cpp")
  add_test(NAME ${var} COMMAND ${var})
endforeach(var)
