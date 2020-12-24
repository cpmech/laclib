set(CMAKE_C_COMPILER "mpiicc")
set(CMAKE_CXX_COMPILER "mpiicpc")

cmake_minimum_required(VERSION 3.16)
project(Project)
include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

# options ####################################################################################

option(A_MAKE_VERBOSE "Show additional messages during compilation/link?" OFF)
option(A_MAKE_ALL_WARNINGS "Make with all warnings (-Wall)" ON)
option(A_MAKE_DEBUG_SYMBOLS "Make with debug symbols (-g)" ON)
option(A_MAKE_OPTIMIZED "Make optimized (-O2)" OFF)
option(A_MAKE_PROFILING "Make with profiling information (-pg)" OFF)

if(A_MAKE_VERBOSE)
    set(CMAKE_VERBOSE_MAKEFILE TRUE)
endif(A_MAKE_VERBOSE)

if(A_MAKE_ALL_WARNINGS)
    add_definitions(-Wall)
endif(A_MAKE_ALL_WARNINGS)

if(A_MAKE_DEBUG_SYMBOLS)
    add_definitions(-g)
endif(A_MAKE_DEBUG_SYMBOLS)

if(A_MAKE_PROFILING)
    set(CMAKE_CXX_FLAGS -pg)
endif(A_MAKE_PROFILING)

if(A_MAKE_OPTIMIZED)
    add_definitions(-O2)
endif(A_MAKE_OPTIMIZED)

# dependencies ###############################################################################

include(FindMKL.cmake)
include(FindMUMPS.cmake)
include_directories(${MKL_IDIRS})
include_directories(${MUMPS_IDIRS})

# subdirectories #############################################################################

add_subdirectory(src)

# library ####################################################################################

add_library(laclib SHARED 
    src/blas/mkl_wrapper.cpp
    src/sparse/read_matrix.cpp
    src/sparse/read_matrix_for_mumps.cpp
    src/sparse/solver_mumps.cpp
    src/sparse/triplet.cpp
    src/sparse/triplet_for_mumps.cpp
)

target_link_libraries(laclib PUBLIC ${MUMPS_LIBS} ${MKL_LIBS})