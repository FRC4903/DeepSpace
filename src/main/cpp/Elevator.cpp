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

#include "Elevator.h"

using namespace frc;
using namespace std;

Elevator::Elevator(TalonSRX LTalon, TalonSRX GTalon) {
	liftTalon = LTalon;
	grabTalon = GTalon;

	liftMod = 1.0;
}

void Elevator::lift(double moderator) {
	liftTalon.Set(ControlMode::PercentOutput, liftMod * moderator);
}

void Elevator::descend(double moderator) {
	liftTalon.Set(ControlMode::PercentOutput, - liftMod * moderator);
}


void Elevator::grab(double moderator) {
	grabTalon.Set(ControlMode::PercentOutput, liftMod * moderator);
}

void Elevator::release(double moderator) {
	grabTalon.Set(ControlMode::PercentOutput, - liftMod * moderator);
}