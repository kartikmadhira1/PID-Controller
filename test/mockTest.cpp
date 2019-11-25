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
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mockVirtualPIDController.hpp"
#include "../include/VirtualPIDController.hpp"
#include "../include/PIDController.hpp"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


/**
 * @brief Test if 
 */
TEST(mockVirtualPIDControllerTest, getGainValues) {
  auto gpid = new mockVirtualPIDController();
  PIDController pid;
  gpid->setGainValues(0.1, 0.2, 0.3);
  std::cout << "Here" << gpid->getGainValues().size() << "\n";
  EXPECT_CALL(*gpid, getGainValues()).
        Times(1).WillRepeatedly(Return(vector<float> {0.1, 0.2, 0.3}));
  pid.computePidError(9, 4, 2);
  
}