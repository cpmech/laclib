cmake_minimum_required(VERSION 3.16)
project(Project)

set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=definite,indirect,possible")
set(MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/valgrind.supp" CACHE FILEPATH "" FORCE)
include(CTest)

set(CMAKE_CXX_STANDARD 17)

# options ####################################################################################

option(A1_USE_INTEL "use Intel MKL and MPI" OFF)
option(A2_OPTIMIZED "Make optimized (-O2)" OFF)
option(A3_VERBOSE "Show additional messages during compilation/link?" OFF)

if(A1_USE_INTEL)
    add_definitions(-DUSE_INTEL -diag-disable=2196) # disable warning due to doctest.h functions: warning #2196: routine is both "inline" and "noinline"
endif()

if(A2_OPTIMIZED)
    add_definitions(-O2)
else()
    add_definitions(-g -Wall)
endif()

if(A3_VERBOSE)
    set(CMAKE_VERBOSE_MAKEFILE TRUE)
endif()

# dependencies ###############################################################################

if(A1_USE_INTEL)
    include(FindMKL.cmake)
    include_directories(${MKL_IDIRS})
endif()

include(FindMUMPS.cmake)
include_directories(${MUMPS_IDIRS})

# subdirectories #############################################################################

add_subdirectory(src)
add_subdirectory(benchmarks)

# library ####################################################################################

add_library(laclib SHARED 
    src/sparse/read_matrix.cpp
    src/sparse/read_matrix_for_mumps.cpp
    src/sparse/solver_mumps.cpp
    src/sparse/triplet.cpp
    src/sparse/triplet_for_mumps.cpp
)

if(A1_USE_INTEL)
    target_link_libraries(laclib PUBLIC nist-mmio ${MUMPS_LIBS} ${MKL_LIBS})
else()
    target_link_libraries(laclib PUBLIC nist-mmio ${MUMPS_LIBS})
endif()