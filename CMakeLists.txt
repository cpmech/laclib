cmake_minimum_required(VERSION 3.16)
project(Project)

set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=definite,indirect,possible")
set(MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/zscripts/valgrind.supp" CACHE FILEPATH "" FORCE)
include(CTest)

set(CMAKE_CXX_STANDARD 17)

# options ####################################################################################

option(A1_INTEL "Use the Intel tools" OFF)
option(A2_MPI "Use {Intel,Open}MPI" OFF)
option(A3_OMP "Allow use of OpenMP when posible" ON)
option(A4_OPTIMIZED "Make optimized (-O3)" OFF)
option(A5_VERBOSE "Show additional messages during compilation/link?" OFF)

set(PLAT "_open")

if(A1_INTEL)
    set(PLAT "_intel")
    add_definitions(-DUSE_INTEL)
    add_definitions(-diag-disable=2196) # disable warning due to doctest.h functions: warning #2196: routine is both "inline" and "noinline"
endif()

if(A2_MPI)
    add_definitions(-DHAS_MPI)
    set(PLAT "${PLAT}_mpi")
else()
    set(PLAT "${PLAT}_seq")
endif()

if(A3_OMP)
    add_definitions(-DHAS_OMP)
    set(PLAT "${PLAT}_omp")
endif()

if(A4_OPTIMIZED)
    add_definitions(-O3)
else()
    add_definitions(-g -Wall)
endif()

if(A5_VERBOSE)
    set(CMAKE_VERBOSE_MAKEFILE TRUE)
endif()

# dependencies ###############################################################################

if(A1_INTEL)
    include(zscripts/FindMKL.cmake)
    include_directories(${MKL_IDIRS})
    set(LA_LIBS ${MKL_LIBS})
else()
    include(zscripts/FindOBLAS.cmake)
    include_directories(${OBLAS_IDIRS})
    set(LA_LIBS ${OBLAS_LIBS})
endif()

include(zscripts/FindMUMPS.cmake)
include_directories(${MUMPS_IDIRS})

# library ####################################################################################

set(LACLIB_NAME "laclib${PLAT}")

add_library(${LACLIB_NAME} SHARED
    src/sparse/read_matrix_market.cpp
    src/sparse/solver_mumps.cpp
    src/sparse/sparse_blas.cpp
    src/sparse/sparse_triplet.cpp
)

target_link_libraries(${LACLIB_NAME} PUBLIC ${MUMPS_LIBS} ${LA_LIBS})

# subdirectories #############################################################################

add_subdirectory(src)
add_subdirectory(benchmarks)
add_subdirectory(examples)
