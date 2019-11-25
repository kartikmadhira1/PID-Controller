/**
 * @file mockVirtualPIDController.hpp
 * @brief  This file contains declarations for the
 *          mock test of PID controller class    
 * @author     : Kartik Madhira
 * @created on : November 24, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/VirtualPIDController.hpp"

class mockVirtualPIDController : public VirtualPIDController {
 public:
    mockVirtualPIDController(){};
    /**
     * @brief This function implements the error formula for the PID controller
     * for a given set point and the input. This is calculated at a particular 
     * time instant. If the control error is beyond a certain limit then the 
     * controller sets the control error to the value set by the setThreshold() 
     * function.
     * @param setPointVel This is the reference velocity to be tracked by the
     *                    controller.
     * @param inputVel  This is the input velocity to the controller.
     * @param prevError This is the error from the previous instant at which 
     *                  PID controller error was calculated. 
     */
    void computePidError(float setPointVel,
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
    /**
     * @brief This function sets the required gain values for 
     * the PID controller.
     * @param _kp - This is the proportional controller gain to be set.
     * @param _ki - This is the integral controller gain to be set. 
     * @param _kd - This is the differential controller gain to be set. 
     */
    void setGainValues(float _kp, float _ki, float _kd) {
        this->Kp = _kp;
        this->Ki = _ki;
        this->Kd = _kd;
        }
    /**
     * @brief This function sets the threshold value for the control error 
     * beyond which the PID controller outputs the saturation value.
     * @param _threshold This is a float type threshold value for the 
     * controller. 
     */
    void setThreshold(float _threshold) {
        this->threshold = _threshold;
    }
    /**
     * @brief getGainValues mock, initializes the mock and returns
     * the Kp, Ki and Kd gains
     * @return vector
     */
    MOCK_METHOD0(getGainValues, vector<float>());
    /**
     * @brief getThreshold mock, initializes the mock
     * @param float threshold get the thresold value
     * @return float
     */
    MOCK_METHOD0(getThreshold, float());
    virtual ~mockVirtualPIDController(){};
};

