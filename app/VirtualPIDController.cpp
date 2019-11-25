/**@file VirtualPIDController.cpp
 * @brief This file containts definitions for functions
 * declared in header file.    
 * @author     :Kartik Madhira
 * @created on : Sep 27, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#include "../include/VirtualPIDController.hpp"

VirtualPIDController::VirtualPIDController() {
    this->Kp = 0;
    this->Ki = 0;
    this->Kd = 0;
    this->controlError = 0;
    this->cumulativeError = 0;
    this->threshold = 0;
}

vector<float> VirtualPIDController::getGainValues() {
    vector<float> gains = {this->Kp, this->Ki, this->Kd};
    return gains;
}

float VirtualPIDController::getControlError() {
    return this->controlError;
}

VirtualPIDController::~VirtualPIDController() {
}
