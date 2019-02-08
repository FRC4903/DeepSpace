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

#include "Climber.h"

using namespace frc;
using namespace std;

Climber::Climber(TalonSRx FClimb, TalonSRX BClimb, TalonSRX BDrive) {
	frontClimb = FClimb;
	backClimb = BClimb;
	backDrive = BDrive;

	climbMod = 1.0;
	enabled = false;

	backAngle = 10.0;
}

void toggleDisable() {
	enabled = !enabled;
}

void frontDown(moderator) {
	frontClimb.Set(ControlMode::PercentOutput, climbMod * moderator);
}

void frontUp(moderator) {
	frontClimb.Set(ControlMode::PercentOutput, - climbMod * moderator)
}

void backDown(moderator) {
	backClimb.Set(ControlMode::PercentOutput, climbMod * moderator);
}

void backUp(moderator) {
	backCLimb.Set(ControlMode::PercentOutput, - climbMod * moderator);
}

void bothDown(moderator) {
	frontClimb.Set(ControlMode::PercentOutput, cos(atan(backOffset / downExtend)) * climbMod * moderator);
	backClimb.Set(ControlMode::PercentOutput, climbMod * moderator);
}

void drive(moderator) {
	backDrive.Set(ControlMode::PercentOutput, moderator);
}