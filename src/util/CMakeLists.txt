set(TESTS
  z_test_path_tools
  z_test_string_tools
)

foreach(var ${TESTS})
  add_executable(${var} "${var}.cpp")
  add_test(NAME ${var} COMMAND ${var})
endforeach(var)
