cmake_minimum_required(VERSION 3.18)
project(google-test-systemc)

# Set SystemC environment ###############################################
set (SYSTEMC_PATH /opt/systemc)
include_directories(${SYSTEMC_PATH}/include)
find_library(systemc systemc REQUIRED PATHS ${SYSTEMC_PATH}/lib)
link_directories(${SYSTEMC_PATH}/lib)
##########################################################################

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
# For SystemC requirements
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSC_INCLUDE_FX") # fixed-point support

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_counter3
  test_counter3.cpp
  counter3.cpp
)
target_link_libraries(
  test_counter3
  systemc
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_counter3)
