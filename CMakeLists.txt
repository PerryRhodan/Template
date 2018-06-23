cmake_minimum_required (VERSION 3.0)
project (Template)

########################################
######## Version

set(VERSION_MAJOR="1")
set(VERSION_MINOR="0")
set(VERSION_PATCH="0")

add_definitions (-DVERSION_MAJOR=1 -DVERSION_MINOR=0 -DVERSION_PATCH=0)


#########################################
####### Dependencies

find_package (Eigen3 3.3.4 REQUIRED NO_MODULE)
find_package (Boost 1.58.0 COMPONENTS system filesystem unit_test_framework REQUIRED)


#########################################
#######

set(CMAKE_CXX_FLAGS "-std=c++11")


##########################################
#######

set(SRC_FILES "src/Template.cpp")

set(UNIT_TESTS "unit-tests/main.cpp" "unit-tests/TemplateUnit.cpp")

###########################################
### main binary
add_executable(Template "src/main.cpp" ${SRC_FILES})
target_link_libraries (Template Eigen3::Eigen ${Boost_LIBRARIES})

############################################
####### unit tests
add_executable(unit-tests ${UNIT_TESTS} ${SRC_FILES})
target_link_libraries (unit-tests Eigen3::Eigen ${Boost_LIBRARIES})

include(${CMAKE_CURRENT_SOURCE_DIR}/unit-tests/CMakeLists.txt)
