cmake_minimum_required(VERSION 3.22)
project(aisdtomczykowskisekulawzorzecpon8)

set(CMAKE_CXX_STANDARD 14)

include_directories(PatternSearchingLib)
include_directories(PatternSearchingUnitTest)
include_directories(PatternSearchingApp)

add_library(PatternSearchingLib
        PatternSearchingLib/PatternSearchingLib.h
        PatternSearchingLib/PatternSearchingLib.cpp)

add_executable(PatternSearchingApp  PatternSearchingApp/PatternSearchingApp.cpp)
target_link_libraries(PatternSearchingApp PatternSearchingLib)

#testy
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if(WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(PatternSearchingUnitTest PatternSearchingUnitTest/PatternSearchingUnitTest.cpp )
target_link_libraries(PatternSearchingUnitTest PUBLIC gtest_main PatternSearchingLib)

include(GoogleTest)
gtest_discover_tests(PatternSearchingUnitTest)
