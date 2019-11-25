/**
 * @file mockTest.cpp
 * @brief This file containts definitions for functions
 *        declared in header file.    
 * @author     : Kartik Madhira
 * @created on : November 24, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mockVirtualPIDController.cpp"
#include "../include/VirtualPIDController.hpp"
#include "../include/PIDController.hpp"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


/**
 * @brief Checking if getGainValues is working
 */
TEST(mockVirtualPIDControllerTest, getGainValues) {
    VirtualPIDController *gpid = new mockVirtualPIDController();
    gpid->setGainValues(0.1, 0.2, 0.3);
    delete gpid;
    // EXPECT_CALL(*gpid, getGainValues()).
    //     Times(1).WillRepeatedly(Return(vector<float> {0.1, 0.2, 0.3}));
    // gpid->computePidError(1, 2, 4);
}
/**
 * @brief Checking if getThreshold is working
 */
TEST(mockVirtualPIDControllerTest, getThreshold) {
    VirtualPIDController *gpid = new mockVirtualPIDController();
    gpid->setThreshold(0.1);
    delete gpid;

    // EXPECT_CALL(*gpid, getThreshold()).
        // Times(1).WillRepeatedly(Return(0.1));
    // gpid->computePidError(1, 2, 4);
}
