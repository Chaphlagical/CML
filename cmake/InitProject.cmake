macro(Initcpkg)
    include(FetchContent)
    set(cpkg_VERSION 0.0.4)
    message(STATUS "find package: cpkg ${cpkg_VERSION}")
    find_package(cpkg ${cpkg_VERSION} QUIET)
    if(NOT cpkg_FOUND)
        message(STATUS "cpkg ${cpkg_VERSION} not found")
        set(_address "https://github.com/Chaphlagical/cpkg")
        message(STATUS "fetch: ${_address} with tag ${cpkg_VERSION}")
        FetchContent_Declare(
            cpkg
            GIT_REPOSITORY ${_address}
            GIT_TAG ${cpkg_VERSION}
        )
        FetchContent_MakeAvailable(cpkg)
        message(STATUS "cpkg ${cpkg_VERSION} build done")
    endif()
endmacro()