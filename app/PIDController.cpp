/**@file pid_controller.cpp
 * @brief This file containts definitions for functions
 * declared in header file.    
 * @author     : Arjun Gupta, Kartik Madhira
 * @created on : Sep 27, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#include "../include/PIDController.hpp"

PIDController::PIDController() {
    this->Kp = 0;
    this->Ki = 0;
    this->Kd = 0;
    this->controlError = 0;
    this->cumulativeError = 0;
    this->threshold = 0;
}

void PIDController::setGainValues(float _kp, float _ki, float _kd) {
    this->Kp = _kp;
    this->Ki = _ki;
    this->Kd = _kd;
}

void PIDController::setThreshold(float _threshold) {
    this->threshold = _threshold;
}

vector<float> PIDController::getGainValues() {
    vector<float> gains = {this->Kp, this->Ki, this->Kd};
    return gains;
}

void PIDController::computePidError(float setPointVel,
                                    float inputVel,
                                    float prevError) {
    auto currentError = setPointVel - inputVel;
    cumulativeError+=currentError;
    controlError = Kp*currentError + Kd*(currentError - prevError)
     + Ki*(cumulativeError);
    if (controlError > threshold)
        controlError = threshold;
    else
        std::cout << "Control error is:" << controlError;
    cout << "New velocity is: " << controlError + inputVel << endl;
}

float PIDController::getControlError() {
    return this->controlError;
}

PIDController::~PIDController() {
}
