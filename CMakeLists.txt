cmake_minimum_required(VERSION 3.30)
project(unit_test)

set(CMAKE_CXX_STANDARD 17)

# Opciones para habilitar pruebas unitarias y cobertura de código
option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(CODE_COVERAGE "Enable code coverage" ON)

if(CODE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(STATUS "Code coverage enabled")
        add_compile_options(--coverage)
        add_link_options(--coverage)
    endif()
endif()

# Descarga GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Archivos fuente
set(SOURCES
    main.cpp
    MyMathLib.h
    BasicMath.h
    AdvancedMath.h
)

add_executable(unit_test ${SOURCES})

if(ENABLE_TESTING)
    enable_testing()

    # Pruebas unitarias
    add_executable(test_suite test.cpp)

    # Enlazar GoogleTest
    target_link_libraries(test_suite PRIVATE gtest gtest_main)

    # Registrar pruebas
    add_test(NAME AllTests COMMAND test_suite)

    # Habilitar reportes de cobertura con gcovr
    find_program(GCOVR gcovr)
    if(GCOVR)
        add_custom_target(coverage
            COMMAND ${GCOVR} -r ${CMAKE_SOURCE_DIR} --xml -o ${CMAKE_BINARY_DIR}/coverage.xml
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating code coverage report with gcovr"
            VERBATIM
        )
    else()
        message(WARNING "gcovr not found, coverage report will not be generated")
    endif()
endif()
