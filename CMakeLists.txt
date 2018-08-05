cmake_minimum_required (VERSION 3.0)
project (Template)

########################################
######## Version

set(VERSION_MAJOR="1")
set(VERSION_MINOR="0")
set(VERSION_PATCH="0")

add_definitions (-DVERSION_MAJOR=1 -DVERSION_MINOR=0 -DVERSION_PATCH=0)


#########################################
####### Find packages

####### eigen3
find_package (Eigen3 3.3.4 REQUIRED NO_MODULE)

####### boost
add_definitions (-DBOOST_LOG_DYN_LINK)
find_package (Boost 1.58.0 COMPONENTS system
       	filesystem log unit_test_framework REQUIRED)

####### ros
find_package (catkin COMPONENTS roscpp rospy std_msgs)
#catkin_package (roscpp rospy std_msgs)


#########################################
#######

set(CMAKE_CXX_FLAGS "-std=c++11" )

######

include_directories(
	${Boost_INCLUDE_DIRS}
	${catkin_INCLUDE_DIRS}
	)


##########################################
#######

set(SRC_FILES 
	"src/Template.cpp"
	)
set(UNIT_TESTS 
	"unit-tests/TemplateUnit.cpp"
	)

###########################################
### main library
add_library(TemplateLib ${SRC_FILES})
target_link_libraries (TemplateLib 
		Eigen3::Eigen
		${Boost_LIBRARIES}
		${catkin_LIBRARIES}
	)

###########################################
### create binary using the library
add_executable(Template src/main.cpp)
target_link_libraries (Template
		TemplateLib
	)

############################################
####### unit tests
add_executable(unit-tests unit-tests/main.cpp ${UNIT_TESTS})
target_link_libraries (unit-tests TemplateLib)

include(${CMAKE_CURRENT_SOURCE_DIR}/unit-tests/CMakeLists.txt)




