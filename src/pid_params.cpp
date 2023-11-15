#include "pid_parameters.h"

PIDParameters::PIDParameters() {
    nh.param<float>("kp", kp);
    nh.param<float>("ki", ki);
    nh.param<float>("kd", kd);
}

PIDParameters::~PIDParameters() {
}

void PIDParameters::run() {
    nh.loadParam("/DriveModelNode", "ros__parameters");

    std::string yaml_file_path;
    nh.getParam("/DriveModelNode/ros__parameters/pid_controller", yaml_file_path);

    nh.loadParam(yaml_file_path);

    float kp, ki, kd;
    nh.param("kp", kp);
    nh.param("ki", ki);
    nh.param("kd", kd);

    ros::spin();
}

void PIDParameters::updateCoefficients(float newKp, float newKi, float newKd) {
    kp = newKp;
    ki = newKi;
    kd = newKd;
}

float PIDParameters::getKp() const {
    return kp;
}

float PIDParameters::getKi() const {
    return ki;
}

float PIDParameters::getKd() const {
    return kd;
}
