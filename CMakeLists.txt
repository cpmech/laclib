cmake_minimum_required(VERSION 3.25)
project(Project)

set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=definite,indirect,possible")
set(MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/zscripts/valgrind.supp" CACHE FILEPATH "" FORCE)
include(CTest)

set(CMAKE_CXX_STANDARD 20)

# options ####################################################################################

option(A1_OPTIMIZED "Make optimized (-O3)" OFF)

# set(CMAKE_VERBOSE_MAKEFILE TRUE)

if(A1_OPTIMIZED)
    add_definitions(-O3)
else()
    add_definitions(-g -Wall)
endif()

# dependencies ###############################################################################

set(MKL_INTERFACE lp64)
find_package(MKL CONFIG REQUIRED PATHS $ENV{MKLROOT})

include(zscripts/FindMUMPS.cmake)
include_directories(${MUMPS_IDIRS})

# library ####################################################################################

add_library(laclib SHARED ${COMMON_SRC_FILES} 
    src/sparse/coo_matrix.cpp
    src/sparse/csr_matrix.cpp
    src/sparse/read_matrix_market.cpp
    src/sparse/solver_dss.cpp
    src/sparse/solver_mumps.cpp
    src/sparse/sparse_blas.cpp
)
target_compile_definitions(laclib PUBLIC USE_MKL)
target_link_libraries(laclib PUBLIC ${MUMPS_LIBS} MKL::MKL)

# subdirectories #############################################################################

add_subdirectory(benchmarks)
add_subdirectory(examples)
add_subdirectory(src)
