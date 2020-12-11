set(MUMPS_INCLUDE_SEARCH_PATH
    /usr/local/include/mumps
)

set(MUMPS_LIBRARY_SEARCH_PATH
    /usr/local/lib/mumps
)

find_path(MUMPS_INC dmumps_c.h ${MUMPS_INCLUDE_SEARCH_PATH})
find_library(MUMPS_LIB NAMES dmumps PATHS ${MUMPS_LIBRARY_SEARCH_PATH})

set(MUMPS_FOUND 1)
foreach(var MUMPS_INC MUMPS_LIB)
    if(NOT ${var})
        set(MUMPS_FOUND 0)
    endif(NOT ${var})
endforeach(var)

if(MUMPS_FOUND)
    set(MUMPS_INCLUDE_DIRS ${MUMPS_INC})
    set(MUMPS_LIBRARIES ${MUMPS_LIB})
endif(MUMPS_FOUND)
