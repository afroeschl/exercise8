cmake_minimum_required(VERSION 3.20)

# define project metadata

    project(exercise8 LANGUAGES C
                    DESCRIPTION "exercise8"
                    HOMEPAGE_URL "https://sgit.iue.tuwien.ac.at/360062/exercise8")

# setting required language standards

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_C_STANDARD_REQUIRED True)
    set(CMAKE_C_EXTENSIONS OFF)    

# misc settings 

    # avoid ctest dashboard targets
    set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
    # generate a compile_commands.json
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
    # make all symbols visible on windows (which is default on unix)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 

# options

    option(BUILD_TESTING "enable testing with ctest" ON)
    
# testing

    include(CTest)

# find math library and link to all targets

    find_library(MATH_LIBRARY m)
    link_libraries(${MATH_LIBRARY})

# get/setup dependencies

    include_directories(include)

# include own targets

    add_executable(task1 task1.main.c)
    add_test(NAME task1 COMMAND task1 WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
    set_property(TEST task1 PROPERTY PASS_REGULAR_EXPRESSION "8")

    add_executable(task2 task2.c task2.test.c)
    add_test(NAME task2 COMMAND task2 WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

    add_executable(task3 task2.c task3.c task3.test.c)
    add_test(NAME task3 COMMAND task3 WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
