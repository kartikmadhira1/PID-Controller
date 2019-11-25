set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    mockTest.cpp
    ../app/PIDController.cpp
    mockVirtualPIDController.cpp
    ../app/VirtualPIDController.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include PUBLIC ../vendor/googletest/googlemock/include
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest gmock)
