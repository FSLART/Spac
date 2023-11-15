#ifndef FMATH_H_
#define FMATH_H_
#include <cstdint>
#include "pid_parameters.h"

#ifdef __FSIPLEIRIA_PID_DOUBLE_PRECISION__
	typedef int64_t fs_PidFloat_t;
#else
	typedef int32_t fs_PidFloat_t;
#endif

class PID_Controller {
public:
    // Construtor da classe PID_Controller que aceita um objeto PIDParameters
    PID_Controller(const PIDParameters& params);
    ~PID_Controller();

    fs_PidFloat_t compute(fs_PidFloat_t setpoint, fs_PidFloat_t input);
    int s_Tunings(fs_PidFloat_t Kp, fs_PidFloat_t Ki, fs_PidFloat_t Kd);
    fs_PidFloat_t g_Proportion();
    fs_PidFloat_t g_Integral();
    fs_PidFloat_t g_Derivative();

protected:
    // Construtor protegido da classe PID_Controller
    PID_Controller();

    // Coeficientes do PID e variáveis de erro
    fs_PidFloat_t kp, ki, kd;
    fs_PidFloat_t error, error_prev, error_sum;

private:
    // Adicione um membro para armazenar o objeto PIDParameters
    PIDParameters parameters;
};
#endif // FMATH_H_