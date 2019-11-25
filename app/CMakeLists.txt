add_executable(shell-app main.cpp PIDController.cpp VirtualPIDController.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
