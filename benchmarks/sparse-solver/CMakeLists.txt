add_executable(bmark_sparse main_intel.cpp)
target_link_libraries(bmark_sparse PUBLIC laclib)
target_compile_definitions(bmark_sparse PRIVATE "MTX_DIR=\"$ENV{HOME}/Downloads/matrix-market\"")
target_compile_definitions(bmark_sparse PRIVATE "OUT_DIR=\"${CMAKE_SOURCE_DIR}/benchmarks/sparse-solver/results/latest\"")
