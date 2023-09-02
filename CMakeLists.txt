cmake_minimum_required(VERSION 3.16)
project(Project)

set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=definite,indirect,possible")
set(MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/zscripts/valgrind.supp" CACHE FILEPATH "" FORCE)
include(CTest)

set(CMAKE_CXX_STANDARD 20)

# options ####################################################################################

option(A1_MKL "Use Intel MKL instead of OpenBLAS+MUMPS" OFF)
option(A2_OPTIMIZED "Make optimized (-O)" OFF)

if(WIN32)
    set(A1_MKL ON)
endif()

if(A1_MKL)
    message(">> Using Intel MKL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<")
    add_definitions(-DUSE_MKL)
    set(PLAT "_intel")
else()
    message(">> Using OpenBLAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<")
    set(PLAT "_open")
endif()

if(A2_OPTIMIZED)
    add_definitions(-O)
else()
    add_definitions(-g -Wall)
endif()

# dependencies ###############################################################################

if(A1_MKL)
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

set(COMMON_SRC_FILES
    src/sparse/coo_matrix.cpp
    src/sparse/csr_matrix.cpp
    src/sparse/read_matrix_market.cpp
    src/sparse/sparse_blas.cpp
)

if(A1_MKL)
    add_library(${LACLIB_NAME} SHARED
        ${COMMON_SRC_FILES}
        src/sparse/solver_dss.cpp
    )
    target_link_libraries(${LACLIB_NAME} PUBLIC MKL::MKL)
else()
    add_library(${LACLIB_NAME} SHARED
        ${COMMON_SRC_FILES}
        src/sparse/solver_mumps.cpp
    )
    target_link_libraries(${LACLIB_NAME} PUBLIC ${MUMPS_LIBS} ${LA_LIBS})
endif()

# subdirectories #############################################################################

add_subdirectory(benchmarks)
add_subdirectory(examples)
add_subdirectory(src)
