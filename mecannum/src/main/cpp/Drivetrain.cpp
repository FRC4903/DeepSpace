#include <frc/TimedRobot.h>
#include <frc/liveWindow/LiveWindow.h>
#include <frc/smartDashboard/SendableChooser.h>
#include <frc/smartDashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"
#include "frc/DoubleSolenoid.h"
#include "frc/DriverStation.h"
#include <frc/Timer.h>
#include "frc/Preferences.h"
#include "frc/Joystick.h"
#include "frc/AnalogInput.h"
//#include <opencv2>
#include "cameraserver/CameraServer.h"
#include "frc/Servo.h"
#include "frc/PWM.h"

#include "frc/WPILib.h"
//#include "frc/NetworkTables/NetworkTable.h"

#include <frc/Ultrasonic.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>

#include "Drive.h"

using namespace frc;
using namespace std;

Drivetrain(TalonSRX fl, TalonSRX fr, TalonSRX rl, TalonSRX rr) {
	FL = fl;
	FR  fr;
	RL = rl;
	RR = rr;
}

void moveOrTurn(double x, double y, double turnMag, double moderator) {

	double FRpow, FLpow, RRpow, RLpow = 0;
	bool manTurning = false;
	bool manMoving = false;

    if (x != 0 || y != 0){
        manMoving = true;

        double mag = hypot(x, y);
        double calcAng = getRealAngle(getPi() - atan2(y, x));   

        FRpow += ( - getWheelPower(calcAng, true) * mag * moderator );
        FLpow += ( - getWheelPower(calcAng, false) * mag * moderator );
        RRpow += getWheelPower(calcAng, false) * mag * moderator;
        RLpow += getWheelPower(calcAng, true) * mag * moderator;
     
    } 

    if (turnMag != 0) {
        manTurning = true;

        double turnMod = 1.0;

        if (! manMoving) {
            turnMod = 0.75;
        }
    
        FRpow += turnMag * turnMod;
        FLpow += turnMag * turnMod;
        RRpow += turnMag * turnMod;
        RLpow += turnMag * turnMod;

    } 
    if (manMoving && manTurning) {
        FRpow /= 2;
        FLpow /= 2;
        RRpow /= 2;
        RLpow /= 2;
    } else {
        FRpow = 0;
        FLpow = 0;
        RRpow = 0;
        RLpow = 0;
    }
    
	FR.Set(ControlMode::PercentOutput, FRpow * moderator);
	FL.Set(ControlMode::PercentOutput, FLpow * moderator);
	RR.Set(ControlMode::PercentOutput, RRpow * moderator);
	RL.Set(ControlMode::PercentOutput, RLpow * moderator);
}

double getWheelPower (double ang, bool A) {

    double toAdd = ang;
    int iter = 0;
    double pow = 1.0;

    double PI = getPi();
    int FR[4] = {-2, 0, 2, 0};
    int FL[4] = {0, -2, 0, 2};

    while (toAdd >= PI / 2) {
        toAdd -= PI/2;
        pow += (A ? FR[iter] : FL[iter]);
        iter++;
    }

    if(toAdd > 0) {
        pow += (toAdd / (PI / 2)) * (A ? FR[iter] : FL[iter]);
    }

    return pow;
}

void turn(double moveAngle)
{
    double autoTurnMod = 0.75;
    resetGyro();
    while (true)
    {
        if (ahrs->GetYaw() < moveAngle) {
            setRight(-moderator *autoTurnMod);
            setLeft(moderator *autoTurnMod);
        } else {
            setRight(moderator*autoTurnMod);
            setLeft(-moderator *autoTurnMod);
        }
        if (abs(ahrs->GetYaw() - moveAngle) < 36) { //arbitrary experimental value
            break;
        }
    }	
}

double getRealAngle(double degAng) {
    if (degAng < 0) {degAng += getPi() * 2; }

    return degAng;
}

double getPi() {
    return acos(-1);
}


// void turnTo(double moveAngle, double gyroAng, double gyroAngDif) 
// {
//     turn(moveAngle - gyroAng - gyroAngDif);
// }










































































































































































































































































































































