cmake_minimum_required (VERSION 3.0)
project (Template)

######## Version

add_definitions (-DVERSION_MAJOR=1 -DVERSION_MINOR=0 -DVERSION_PATCH=0)

#######


####### Dependencies

find_package (Eigen3 3.3.4 REQUIRED NO_MODULE)

#######


add_executable(Template src/template.cpp)
target_link_libraries (Template Eigen3::Eigen)
