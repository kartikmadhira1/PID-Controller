/**@file VirtualPIDController.hpp
 * @brief This file contains declarations for the
 * PID controller class    
 * @author     : Arjun Gupta, Kartik Madhira
 * @created on : Sep 27, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */
#pragma once

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::flush;

class VirtualPIDController {
 public:
    /**
    * @brief default constructor
    */
    VirtualPIDController();
    /**
     * @brief This function sets the required gain values for 
     * the PID controller.
     * @param _kp - This is the proportional controller gain to be set.
     * @param _ki - This is the integral controller gain to be set. 
     * @param _kd - This is the differential controller gain to be set. 
     */
    void setGainValues(float _kp, float _ki, float _kd);
    /**
     * @brief This function returns the gain values set by the user.
     * @return A float vector that contains the gain values
     * in the order Kp,Ki and Kd in the vector.
     */
    vector<float> getGainValues();
    /**
     * @brief This function sets the threshold value for the control error 
     * beyond which the PID controller outputs the saturation value.
     * @param _threshold This is a float type threshold value for the 
     * controller. 
     */
    void setThreshold(float _threshold);
    /**
     * @brief Default Destructor
     */
    ~VirtualPIDController();

 private:
    /** Declares the variables for proportional gain, integral gain, 
     * differential gain and the threshold limit for saturation, in 
     * the same order.
      */
    float Kp, Ki, Kd, threshold;
    // Cumulative error for the controller
    double cumulativeError;
    // control error for the controller
    float controlError;
};
