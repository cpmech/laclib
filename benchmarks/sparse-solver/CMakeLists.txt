add_executable(bmark_sparse_intel main.cpp)
target_link_libraries(bmark_sparse_intel PUBLIC laclib_intel)

if(WITH_MUMPS)
    add_executable(bmark_sparse_open main.cpp)
    target_link_libraries(bmark_sparse_open PUBLIC laclib_open)
endif()
