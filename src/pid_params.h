#pragma once

#include <ros/ros.h>

class PIDParameters {
public:
    PIDParameters();
    ~PIDParameters();

    void run();

    float getKp() const;
    float getKi() const;
    float getKd() const;

    // Método para atualizar os coeficientes
    void updateCoefficients(float newKp, float newKi, float newKd);

private:
    ros::NodeHandle nh;
    float kp, ki, kd;
};
