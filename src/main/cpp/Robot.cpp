#include <string>

#include <iostream>

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

#include "frc/Servo.h"
#include "frc/PWM.h"

#include "frc/WPILib.h"

#include <frc/Ultrasonic.h>
#include <iostream>
#include <cmath>
#include <math.h>

#include "Communicator.h"
#include "AHRS.h"

using namespace Communicator;

using namespace frc;
using namespace std;

class Robot : public frc::TimedRobot {

public:
    Timer *timer = new Timer();
    const double LIFT_CONSTANT_COEFFICIENT = 10;

    const int FRONT_LEFT_CIM = 1;
    const int FRONT_RIGHT_CIM = 2;
    const int REAR_LEFT_CIM = 3;
    const int REAR_RIGHT_CIM = 4;

    Ultrasonic *ultraFront;
    TalonSRX FR, FL, RR, RL;

    AHRS *ahrs;
    double gyroAngDif = 0;

    DigitalOutput red;
    DigitalOutput green;
    DigitalOutput blue;

    double rightEncoderConstant, leftEncoderConstant;
    bool initialValueSet = false;
    double initialLiftPosition = 0;

    double leftEncoderInitial = 0.0;
    double rightEncoderInitial = 0.0;

    Servo horzCamServo;

    double horzCamServoAng = 0.5;

    int kTimeoutMs = 10;
    int kPIDLoopIdx = 0;
    int kSlotIdx = 0;

    double initialValTalon;
    Joystick joystickMain;
    Joystick joystickMechanisms;
    double lefty;

    double j_x_L, j_y_L, j_x_R;
    double moderator;

    double beginningDiff;

    string gameData;
    Preferences* preferences;

    bool done = false;

    bool inductiveSensorTriggered;

    int targetAngle = 0;

    Timer *autoTimer = new Timer();
    AnalogInput inductiveSensor;
    AnalogInput servoInput;

    Communicator *comm = new Communicator();

    // SETUP SECTION
    //
    //
    //      FR.SetNeutralMode(NeutralMode::Brake);
    //      FL.SetNeutralMode(NeutralMode::Brake);
    //      RR.SetNeutralMode(NeutralMode::Brake);
    //      RL.SetNeutralMode(NeutralMode::Brake);

    //      //FR(FRONT_RIGHT_CIM), FL(FRONT_LEFT_CIM), RR(REAR_RIGHT_CIM), RL(REAR_LEFT_CIM)

    Robot() :
        joystickMain(0),
        joystickMechanisms(1),
        FR(2),
        FL(1),
        RR(4),
        RL(3),
        horzCamServo(8),
        inductiveSensor(0),
        red(0),
        green(1),
        blue(2),
        servoInput(1)
    
    {
        preferences = Preferences::GetInstance();
        ahrs = new AHRS(SPI::Port::kMXP);
    }

    void setup()
    {
        beginningDiff = -1000000;
        moderator = 0.1;
        timer->Start();
    }

    void setupEncoderTalon(TalonSRX* talon) {
        int absPos = talon->GetSelectedSensorPosition(0) & 0xFFF;
        talon->SetSelectedSensorPosition(absPos, kPIDLoopIdx, kTimeoutMs);

        talon->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);
        talon->SetSensorPhase(true);
        talon->ConfigNominalOutputForward(0, kTimeoutMs);
        talon->ConfigNominalOutputReverse(0, kTimeoutMs);
        talon->ConfigPeakOutputForward(1, kTimeoutMs);
        talon->ConfigPeakOutputReverse(-1, kTimeoutMs);
        talon->Config_kF(kPIDLoopIdx, 0.0, kTimeoutMs);
        talon->Config_kP(kPIDLoopIdx, 0.1, kTimeoutMs);
        talon->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
        talon->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);
    }

    void RobotInit() {

        //TestMech hello;

        autoTimer->Start();

        ultraFront = new Ultrasonic(3, 4);
        ultraFront->SetAutomaticMode(true);

        //setupEncoderTalon(RL);
        //setupEncoderTalon(FR);

        timer->Start();
        resetGyro();
    }

// Autonomous SECTION
        //
        //
        //
        //
        //
        //
        //
        //
        //
        //

    void TestInit() {}

    void TestPeriodic() {}

    void AutonomousInit() {
        resetGyro();
        gameData = DriverStation::GetInstance().GetGameSpecificMessage();

        //driveSystemBrakeMode(false);

        FR.SetNeutralMode(NeutralMode::Brake);
        FL.SetNeutralMode(NeutralMode::Brake);
        RR.SetNeutralMode(NeutralMode::Brake);
        RL.SetNeutralMode(NeutralMode::Brake);

        done= false;

        autoTimer->Reset();

    }

    void AutonomousPeriodic() {
        if(gameData.length() > 0 && !done) {}
    }

    void resetEncoder() {
        leftEncoderInitial = RL.GetSelectedSensorPosition(kPIDLoopIdx);
        rightEncoderInitial = RL.GetSelectedSensorPosition(kPIDLoopIdx);
    }

/*  double getLeftEncoderValue() {
        return (talonRight1.GetSelectedSensorPosition(kPIDLoopIdx) - leftEncoderInitial) / leftEncoderConstant;
    }

    double getRightEncoderValue() {
        return (talonLeft2.GetSelectedSensorPosition(kPIDLoopIdx) - rightEncoderInitial) / rightEncoderConstant;
    }*/


/*  double convertAngle(double val)
    {
        return (double)(val - initialValTalon)/2000*360;
    }*/

// TELEOP SECTION


    void TeleopInit() {
        //driveSystemBrakeMode(true);  //DRIVING

        FR.SetNeutralMode(NeutralMode::Brake);
        FL.SetNeutralMode(NeutralMode::Brake);
        RR.SetNeutralMode(NeutralMode::Brake);
        RL.SetNeutralMode(NeutralMode::Brake);

        resetGyro();
        timer->Start();
        timer->Reset();
    }

    void TeleopPeriodic() {
        driveSystem();      //uncomment to drive

    }


    // DRIVE SYSTEM

    void driveSystem()
    {

        if (inductiveSensorState()) {

            red.Set(0);
            green.Set(1);
            blue.Set(1);
        } else {
            red.Set(1);
            green.Set(0);
            blue.Set(1);
        }

        cameraSwivel();

        bool turned = buttonTurn();
        ahrs->UpdateDisplacement(ahrs->GetWorldLinearAccelX(), ahrs->GetWorldLinearAccelY(), 50, ahrs->IsMoving());
		cout << "ANGLE: " << ahrs->GetYaw() << endl;
        cout << "DISANCE: " << ultraFront->GetRangeInches() << endl;
        cout << "DX: " << ahrs->GetDisplacementX() << endl;
        cout << "DY: " << ahrs->GetDisplacementY() << endl;

        //bool newSystem = preferences->GetBoolean("driveSystem", false);

		
        if (joystickMain.GetRawButton(6)) // if green a button is pressed
            moderator = 0.85; // makes robot go faster .. 1.0 for carpet
        else if (joystickMain.GetRawButton(5)) // if red b button is pressed
            moderator = 0.5; // make it really slow
        else // base case let it be half speed
            moderator = 0.75; // limits the range given from the controller // 0.85 for carpet

		if (!turned) {
			j_x_L = joystickMain.GetRawAxis(0);
			j_y_L = joystickMain.GetRawAxis(1);

			j_x_R = joystickMain.GetRawAxis(4);

			if((j_x_L < 0 && j_x_L >= -0.05) || (j_x_L > 0 && j_x_L <= 0.05)) { j_x_L = 0; }
			if((j_y_L < 0 && j_y_L >= -0.05) || (j_y_L > 0 && j_y_L <= 0.05)) { j_y_L = 0; }
			if((j_x_R < 0 && j_x_R >= -0.05) || (j_x_R > 0 && j_x_R <= 0.05)) { j_x_R = 0; }

			double FRpow, FLpow, RRpow, RLpow = 0;
			bool manTurning = false;
			bool manMoving = false;

            double safeDist = 8 * (FRpow + FLpow + RLpow + RRpow + 1);
            cout << "SAFE" << safeDist << endl;

            
            if (!(j_y_L < 0 && ultraFront->GetRangeInches() < safeDist)) {

                if (j_x_L != 0 || j_y_L != 0){
                    manMoving = true;

                    double mag = hypot(j_x_L, j_y_L);
                    double calcAng = getRealAngle(getPi() - atan2(j_y_L, j_x_L));
                    //double gAng = getRealAngle(gyro.GetAngle());
                    double gAng = 0;

                    /*
                    setFrontRight(getWheelPower(calcAng - gAng, true) * mag * moderator);
                    setFrontLeft(getWheelPower(calcAng - gAng, false) * mag * moderator);
                    setRearRight(getWheelPower(calcAng - gAng, false) * mag * moderator);
                    setRearLeft(getWheelPower(calcAng - gAng, true) * mag * moderator);*
                    */
                    FRpow += ( - getWheelPower(calcAng - gAng, true) * mag * moderator );
                    FLpow += ( - getWheelPower(calcAng - gAng, false) * mag * moderator );
                    RRpow += getWheelPower(calcAng - gAng, false) * mag * moderator;
                    RLpow += getWheelPower(calcAng - gAng, true) * mag * moderator;

                    
                } 

                if (j_x_R != 0) {
                    manTurning = true;

                    double turnMod = 1.0;

                    if (! manMoving) {
                        turnMod = 0.75;
                    }
                
                    FRpow += j_x_R * turnMod;
                    FLpow += j_x_R * turnMod;
                    RRpow += j_x_R * turnMod;
                    RLpow += j_x_R * turnMod;
                    // FR.Set(ControlMode::PercentOutput, j_x_R * moderator);
                    // FL.Set(ControlMode::PercentOutput, j_x_R * moderator);
                    // RR.Set(ControlMode::PercentOutput, j_x_R * moderator);
                    // RL.Set(ControlMode::PercentOutput, j_x_R * moderator);
                    /*
                    setFrontRight(- j_x_R * moderator);
                    setFrontLeft(j_x_R * moderator);
                    setRearRight(- j_x_R * moderator);
                    setRearLeft(j_x_R * moderator);*/

                } 
                if (manMoving && manTurning) {
                    FRpow /= 2;
                    FLpow /= 2;
                    RRpow /= 2;
                    RLpow /= 2;
                }
            } else {
                cout << "STOPPED" << endl;

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
    }



    double getRealAngle(double degAng) {
        if (degAng < 0) {degAng += getPi() * 2; }

        return degAng;
    }

    double getPi() {
        return acos(-1);
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
            if (abs(ahrs->GetYaw() - moveAngle) < 36) { //3 is abitrary, i just stuck in a value
                break;
            }
        }

		
    }

    void turnTo(double moveAngle) 
    {
        turn(moveAngle - ahrs->GetYaw() - gyroAngDif);
    }

    bool buttonTurn()
    {   
        bool turned = false;

        if (135 <= joystickMain.GetPOV() && joystickMain.GetPOV() <= 225) {

            if (joystickMain.GetRawButton(1)) {
                turnTo(180);
                turned = true;
            } else if (joystickMain.GetRawButton(2)) {
                turnTo(90);
                turned = true;
            } else if (joystickMain.GetRawButton(3)) {
                turnTo(-90);
                turned = true;
            } else if (joystickMain.GetRawButton(4)) {
                turnTo(0);
                turned = true;
            }
        } else {

            if (joystickMain.GetRawButton(1)) {
                turn(45);
                turned = true;
            } else if (joystickMain.GetRawButton(2)) {
                turn(95);
                turned = true;
            } else if (joystickMain.GetRawButton(3)) {
                turn(-95);
                turned = true;
            } else if (joystickMain.GetRawButton(4)) {
                turn(180);
                turned = true;
            }
        }

        return turned;
    }

    void setRight(double val) {
        RR.Set(ControlMode::PercentOutput, -val);
        FR.Set(ControlMode::PercentOutput, -val);
    }

    void setLeft(double val) {  
        RL.Set(ControlMode::PercentOutput, val);
        FL.Set(ControlMode::PercentOutput, val);        
    }

    void cameraSwivel () 
    {
        inductiveSensorTriggered = inductiveSensorState();
        
        if (!inductiveSensorTriggered){
            if (45 <= joystickMechanisms.GetPOV(0) && joystickMechanisms.GetPOV(0) <= 135) {
                horzCamServoAng += 0.025;
            } else if (225 <= joystickMechanisms.GetPOV(0) && joystickMechanisms.GetPOV(0) <= 315) {
                horzCamServoAng -= 0.025;
            } 

            if (joystickMechanisms.GetRawButton(9)) {
                horzCamServoAng = 0.5;
            } 

            horzCamServo.Set(horzCamServoAng);
        }
    }

    bool inductiveSensorState(){
        bool state = (inductiveSensor.GetVoltage() > 3.0 ? true : false);
        cout << "SERVO VALL: " << ( (servoInput.GetValue() * 0.47) - 33.4) << endl;
        return state;
    }

    void resetGyro() {
        gyroAngDif += ahrs->GetYaw();
        gyroAngDif = normalizeAng(gyroAngDif);
        ahrs->Reset();
    }

    double normalizeGyro(double num) {
        if (num > 180) {
            num -= 360;
        } else if (num < -180) {
            num += 360;
        }

        return num;
    }

    double normalizeAng(double ang) {
        if (ang > 360) {
            ang -= 360;
        } else if (ang < -360) {
            ang += 360;
        }

        return ang;
    }

    void stopDriveMotors(){}

    void DisabledInit() {}

    void DisabledPeriodic() {}
};

START_ROBOT_CLASS(Robot)