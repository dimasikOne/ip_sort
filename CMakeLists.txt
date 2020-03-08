cmake_minimum_required(VERSION 3.2)

project(ip_sort)

# find_package(Boost COMPONENTS unit_test_framework REQUIRED)

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
