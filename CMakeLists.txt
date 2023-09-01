cmake_minimum_required(VERSION 3.16)
project(Project)

set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=definite,indirect,possible")
set(MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/zscripts/valgrind.supp" CACHE FILEPATH "" FORCE)
include(CTest)

set(CMAKE_CXX_STANDARD 20)

# options ####################################################################################

option(A0_MKL "Use Intel MKL instead of OpenBLAS+MUMPS" OFF)
option(A1_OMP "(not for MKL) Allow use of OpenMP when posible" ON)
option(A2_OPTIMIZED "Make optimized (-O3)" OFF)
option(A3_VERBOSE "Show additional messages during compilation/link?" OFF)

if(WIN32)
    set(A0_MKL ON)
endif()

if(A0_MKL)
    message(">> Using Intel MKL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<")
    add_definitions(-DUSE_MKL)
    set(PLAT "_intel")
else()
    set(PLAT "_open_seq")
    if(A1_OMP)
        add_definitions(-DHAS_OMP)
        set(PLAT "${PLAT}_omp")
    endif()
endif()

if(A2_OPTIMIZED)
    add_definitions(-O3)
else()
    add_definitions(-g -Wall)
endif()

if(A3_VERBOSE)
    set(CMAKE_VERBOSE_MAKEFILE TRUE)
endif()

# dependencies ###############################################################################

if(A0_MKL)
    find_package(MKL CONFIG REQUIRED PATHS $ENV{MKLROOT})
else()
    include(zscripts/FindOBLAS.cmake)
    include_directories(${OBLAS_IDIRS})
    set(LA_LIBS ${OBLAS_LIBS})

    include(zscripts/FindMUMPS.cmake)
    include_directories(${MUMPS_IDIRS})
endif()

# library ####################################################################################

set(LACLIB_NAME "laclib${PLAT}")

if(A0_MKL)
    add_library(${LACLIB_NAME} SHARED
        src/sparse/coo_matrix.cpp
        src/sparse/csr_matrix.cpp
        src/sparse/read_matrix_market.cpp
        src/sparse/sparse_blas.cpp
        src/sparse/solver_dss.cpp
    )
    target_link_libraries(${LACLIB_NAME} PUBLIC MKL::MKL)
else()
    add_library(${LACLIB_NAME} SHARED
        src/sparse/coo_matrix.cpp
        src/sparse/csr_matrix.cpp
        src/sparse/read_matrix_market.cpp
        src/sparse/solver_mumps.cpp
        src/sparse/sparse_blas.cpp
    )
    target_link_libraries(${LACLIB_NAME} PUBLIC ${MUMPS_LIBS} ${LA_LIBS})
endif()

# subdirectories #############################################################################

add_subdirectory(src)
add_subdirectory(benchmarks)
add_subdirectory(examples)
