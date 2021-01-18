set(MUMPS_INCLUDE_SEARCH_PATH
    /usr/local/include/mumps
)

set(MUMPS_LIBRARY_SEARCH_PATH
    /usr/local/lib/mumps
)

find_path(MUMPS_INC dmumps_c.h ${MUMPS_INCLUDE_SEARCH_PATH})

if(A1_USE_INTEL)
    if(A2_WITH_OMP)
        find_library(MUMPS_LIB NAMES dmumps_intel_omp PATHS ${MUMPS_LIBRARY_SEARCH_PATH})
    else()
        find_library(MUMPS_LIB NAMES dmumps_intel PATHS ${MUMPS_LIBRARY_SEARCH_PATH})
    endif()
else()
    if(A2_WITH_OMP)
        find_library(MUMPS_LIB NAMES dmumps_open_omp PATHS ${MUMPS_LIBRARY_SEARCH_PATH})
    else()
        find_library(MUMPS_LIB NAMES dmumps_open PATHS ${MUMPS_LIBRARY_SEARCH_PATH})
    endif()
endif()

set(MUMPS_FOUND 1)
foreach(var MUMPS_INC MUMPS_LIB)
    if(NOT ${var})
        set(MUMPS_FOUND 0)
    endif(NOT ${var})
endforeach(var)

if(MUMPS_FOUND)
    set(MUMPS_IDIRS ${MUMPS_INC})
    set(MUMPS_LIBS ${MUMPS_LIB})
else()
    message(FATAL_ERROR "cannot find MUMPS")
endif()
