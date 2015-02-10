cmake_minimum_required(VERSION 2.8.3)
project(luctor_classes)

set(CMAKE_CXX_FLAGS "-std=c++0x -fPIC")

find_package( catkin REQUIRED 
	COMPONENTS
	roscomm
	rose_common
	rose_conversions
)

include_directories( ${PROJECT_SOURCE_DIR}/include ${catkin_INCLUDE_DIRS})

catkin_package(
  	INCLUDE_DIRS 
  		include 
 	LIBRARIES 
 		luctor_classes  
  	CATKIN_DEPENDS 
  		roscomm 
  		rose_common 
  		rose_conversions
  DEPENDS
)


add_library( luctor_classes SHARED 	src/luctor_base_class.cpp
							src/bounding_box.cpp
							src/item.cpp
							src/person.cpp
							src/resource.cpp
							src/script.cpp
							src/waypoint.cpp 
)

target_link_libraries( luctor_classes ${catkin_LIBRARIES} )
