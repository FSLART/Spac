#include "fmath.h"
#include "pid_params.h"

/**
* @brief Public Constructor for the PID_Controller class
*/
PID_Controller::PID_Controller(const PIDParameters& params) : PID_Controller(), parameters(params) {
    // Configura os parâmetros usando a classe PIDParameters
    s_Tunings(params.getKp(), params.getKi(), params.getKd());
}

/**
* @brief Constructor meant to setup everything to 0 It should not be used directly, and its only public so that it can be used in the other constructor
*/
PID_Controller::PID_Controller(){
	kp=0;
	ki=0;
	kd=0;
	error=0;
	error_prev=0;
	error_sum=0;
}
fs_PidFloat_t PID_Controller::compute(fs_PidFloat_t setpoint, fs_PidFloat_t input){
	error=setpoint-input;
	error_sum+=error;
	fs_PidFloat_t output=kp*error+ki*error_sum+kd*(error-error_prev);
	error_prev=error;
	return output;
}
/**
* @brief Setter for the PID Tunings/Constants
*/
// Atualiza os coeficientes da PIDParameters usando o método updateCoefficients
void PID_Controller::s_Tunings(fs_PidFloat_t Kp, fs_PidFloat_t Ki, fs_PidFloat_t Kd) {
    parameters.updateCoefficients(Kp, Ki, Kd);

    // Configura os parâmetros da própria classe
    kp = Kp;
    ki = Ki;
    kd = Kd;
		return 0;
}

fs_PidFloat_t PID_Controller::g_Proportion(){
	return kp;
}
fs_PidFloat_t PID_Controller::g_Integral(){
	return ki;
}
fs_PidFloat_t PID_Controller::g_Derivative(){
	return kd;
}