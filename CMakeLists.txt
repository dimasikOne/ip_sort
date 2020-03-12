cmake_minimum_required(VERSION 3.2)

project(ip_sort VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(ip_sort src/ip_sort.cpp)

set_target_properties(ip_sort PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(ip_sort PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_sort PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ip_sort RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
