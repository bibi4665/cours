cmake_minimum_required(VERSION 3.20)
project(fiboexe VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(GNUInstallDirs)

option(FIBOEXE_ENABLE_TIME "Enable time measurement" ON)

# vraiment inutile mais pour votre apprentissage
option(FIBOEXE_RECURSIVE "Enable recursive mode" OFF) 

message(STATUS "PARAMETRAGE DE FIBOEXE")
message(STATUS "FIBOEXE_ENABLE_TIME = ${FIBOEXE_ENABLE_TIME}")
message(STATUS "FIBOEXE_RECURSIVE = ${FIBOEXE_RECURSIVE}")

set(HEADERS
    "include/Vector.h"
)

set(SOURCES # attention pas de main.c!
    "src/Vector.cpp"
)

# on gere les options de compilation
if(FIBOEXE_RECURSIVE)
    add_compile_definitions(FIBOEXE_RECURSIVE)
endif()
if(FIBOEXE_ENABLE_TIME)
    add_compile_definitions(ENABLE_TIME)
endif()

add_executable(fiboexe "src/main.cpp" ${SOURCES})
target_include_directories(fiboexe PUBLIC "include") # pour retrouver fibo

add_executable(up::fiboexe ALIAS fiboexe)

## parties des tests

enable_testing()

# on cherche la dépendance Google Test (gtest) pour les tests unitaires
find_package(GTest QUIET)
if (NOT GTest_FOUND)
    message(STATUS "Google Test not found, downloading...")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    # Force le meme runtime CRT que le projet sous MSVC
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    message(STATUS "Google Test fetched with success.")
else()
    message(STATUS "Google Test found")
endif()

add_executable(fibo_tests "tests/tests.cpp" ${SOURCES})
target_include_directories(fibo_tests PRIVATE include)
target_link_libraries(fibo_tests PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(fibo_tests)

