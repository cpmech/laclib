add_executable(bmark_conv main.cpp)
target_link_libraries(bmark_conv PUBLIC laclib)
target_compile_definitions(bmark_conv PRIVATE "MTX_DIR=\"$ENV{HOME}/Downloads/matrix-market\"")
target_compile_definitions(bmark_conv PRIVATE "OUT_DIR=\"${CMAKE_SOURCE_DIR}/benchmarks/coo-to-csr/results\"")
