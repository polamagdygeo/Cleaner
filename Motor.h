#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

#define HARMONIC_REDUCTION_DELTA            5UL

#define MOTOR_OUTPUT_PERIOD_MS              10UL
#define MOTOR_HARMONIC_PERIOD_MS            20UL
#define MOTOR_SOFTSWITCH_PERIOD_MS          40UL

typedef enum{
    MOTOR_ANGLE_10 = 10,
    MOTOR_ANGLE_90 = 90,
    MOTOR_ANGLE_140 = 140,
    MOTOR_ANGLE_170 = 170
}tMotor_TargetAngle;

void Motor_Init(tMotor_TargetAngle initial_target_angle);
void Motor_SetTargetAngle(tMotor_TargetAngle target_angle);
void Motor_SoftSwitchingUpdate(void);
void Motor_HarmonicReductionUpdate(void);
void Motor_OutputUpdate(void);

#endif // MOTOR_H_INCLUDED
