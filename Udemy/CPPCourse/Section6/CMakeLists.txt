include(CMakePrintHelpers)

cmake_minimum_required(VERSION 3.21.3)

project( main )

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

add_executable( ${PROJECT_NAME} main.cpp )

add_subdirectory(BankAccount)
add_subdirectory(Pizza)

target_include_directories( ${PROJECT_NAME} 
  PUBLIC BankAccount
	PUBLIC Pizza
)

target_link_libraries( ${PROJECT_NAME} 
	BankAccount
  Pizza
)