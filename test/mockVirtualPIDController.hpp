/**
 * @file mockVirtualPIDController.hpp
 * @brief  This file contains declarations for the
 *          mock test of PID controller class    
 * @author     : Kartik Madhira
 * @created on : November 24, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/VirtualPIDController.hpp"

class mockVirtualPIDController : public VirtualPIDController {
 public:
/**
   * @brief setGainValues mock, Initializes the mock.
   * @param kp kp proportional gain value
   * @param ki ki integral gain value
   * @param kd kd derivative gain value
   * @return bool
*/
 void setGainValues(float _kp, float _ki, float _kd) {
        this->Kp = _kp;
        this->Ki = _ki;
        this->Kd = _kd;
    }

 void setThreshold(float _threshold) {
    this->threshold = _threshold;
    }
//    MOCK_METHOD3(setGainValues, bool(float kp, float ki, float kd));
  /**
   * @brief setThreshold mock, initializes the mock
   * @param float threshold set the cut-off threshold for PID
   * @return bool
   */
  MOCK_METHOD0(getGainValues, vector<float>());

  /**
   * @brief compute PID mock, initializes the mock
   * 
   * @param setPointVel This is the reference velocity to be tracked by the 
   *                    controller.
   * @param inputVel  This is the input velocity to the controller.
   * @param prevError This is the error from the previous instant at which
   *                  PID controller error was calculated.
   */
//   MOCK_METHOD1(checkControlError, float(float setPointVel, float inputVel,
//                                      float prevError));
};

