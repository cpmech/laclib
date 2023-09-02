cmake_minimum_required(VERSION 3.16)
project(Project)

set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=definite,indirect,possible")
set(MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/zscripts/valgrind.supp" CACHE FILEPATH "" FORCE)
include(CTest)

set(CMAKE_CXX_STANDARD 20)

# options ####################################################################################

option(A1_OPTIMIZED "Make optimized (-O)" OFF)

set(WITH_MUMPS ON)

if(WIN32)
    set(WITH_MUMPS OFF)
endif()

if(A1_OPTIMIZED)
    add_definitions(-O)
else()
    add_definitions(-g -Wall)
endif()

# dependencies ###############################################################################

find_package(MKL CONFIG REQUIRED PATHS $ENV{MKLROOT})

if(WITH_MUMPS)
    include(zscripts/FindOBLAS.cmake)
    include(zscripts/FindMUMPS.cmake)
    include_directories(${OBLAS_IDIRS})
    include_directories(${MUMPS_IDIRS})
endif()

# library ####################################################################################

set(COMMON_SRC_FILES
    src/sparse/coo_matrix.cpp
    src/sparse/csr_matrix.cpp
    src/sparse/read_matrix_market.cpp
    src/sparse/sparse_blas.cpp
)

add_library(laclib_intel SHARED ${COMMON_SRC_FILES} src/sparse/solver_dss.cpp)
target_compile_definitions(laclib_intel PUBLIC USE_MKL)
target_link_libraries(laclib_intel PUBLIC MKL::MKL)

if(WITH_MUMPS)
    add_library(laclib_open SHARED ${COMMON_SRC_FILES} src/sparse/solver_mumps.cpp)
    target_link_libraries(laclib_open PUBLIC ${MUMPS_LIBS} ${OBLAS_LIBS})
endif()

# subdirectories #############################################################################

add_subdirectory(benchmarks)
add_subdirectory(examples)
add_subdirectory(src)
