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

#include "subsystems/Communicator.h"
#include "AHRS.h"

<<<<<<< HEAD:mecannum/src/main/cpp/Robot.cpp
#include "Drivetrain.h"
#include "Climber.h"
#include "Elevator.h"

using namespace Drivetrain;
using namespace Climber;
using namespace Elevator;
=======
using namespace Communicator;
>>>>>>> d79e7dfe66b1dee5ec192e45f6e64e24ea867844:src/main/cpp/Robot.cpp

using namespace frc;
using namespace std;

class Robot : public frc::TimedRobot {

public:
    Timer *timer = new Timer();

    const int FRONT_LEFT_CIM = 1;
    const int FRONT_RIGHT_CIM = 2;
    const int REAR_LEFT_CIM = 3;
    const int REAR_RIGHT_CIM = 4;

    const int FRONT_CLIMB_CIM = ;
    const int BACK_CLIMB_CIM =;
    const int BACK_DRIVE_BAG =;

    const int LIFT_TALON_CIM =;
    const int GRAB_TALON_CIM =;

    const int CAM_SERVO_PORT = 8;

    Ultrasonic *ultraFront;
    TalonSRX FR, FL, RR, RL;
    TalonSRX frontClimb, backClimb, backDrive, liftTalon, grabTalon;

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

<<<<<<< HEAD:mecannum/src/main/cpp/Robot.cpp
    Drivetrain drive;
    Climber climber;
    Elevator elevator;
=======
    Communicator *comm = new Communicator();
>>>>>>> d79e7dfe66b1dee5ec192e45f6e64e24ea867844:src/main/cpp/Robot.cpp

    // SETUP SECTION
    //
    //
    //      FR.SetNeutralMode(NeutralMode::Brake);
    //      FL.SetNeutralMode(NeutralMode::Brake);
    //      RR.SetNeutralMode(NeutralMode::Brake);
    //      RL.SetNeutralMode(NeutralMode::Brake);

    Robot() :
        joystickMain(0),
        joystickMechanisms(1),
        FR(FRONT_RIGHT_CIM),
        FL(FRONT_LEFT_CIM),
        RR(RIGHT_REAR_CIM),
        RL(REAR_LEFT_CIM),

        frontCLimb(FRONT_CLIMB_CIM),
        backClimb(BACK_CLIMB_CIM),
        backDrive(BACK_DRIVE_BAG),

        liftTalon(LIFT_TALON_CIM),
        grabTalon(GRAB_TALON_CIM),

        horzCamServo(CAM_SERVO_PORT),
        inductiveSensor(0),
        red(0),
        green(1),
        blue(2),
        servoInput(1)
    
    {
<<<<<<< HEAD:mecannum/src/main/cpp/Robot.cpp
    
        // cout << horzCamServo->GetAngle() << endl;
        //table = NetworkTable::GetTable("Vision");

        //NetworkTable::AddTableListener("test", listener, true);
        preferences = Preferences::GetInstance();
        ahrs = new AHRS(SPI::Port::kMXP);

//      driverStation = DriverStation::GetInstance();
        drive = new Drivetrain(FL, FR, RL, RR);
        climb = new Climber(frontClimb, backClimb, backDrive);
        elevator = new Elevator(liftTalon, grabTalon);


=======
        preferences = Preferences::GetInstance();
        ahrs = new AHRS(SPI::Port::kMXP);
>>>>>>> d79e7dfe66b1dee5ec192e45f6e64e24ea867844:src/main/cpp/Robot.cpp
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

            double safeDist = 8 * (FRpow + FLpow + RLpow + RRpow + 1);
            cout << "SAFE" << safeDist << endl;

            if (!(j_y_L < 0 && ultraFront->GetRangeInches() < safeDist)) {
                drive.moveOrTurn(j_x_L, j_y_L, j_x_R, moderator);
            }
        }
            
        
    }

    bool buttonTurn()
    {   
        bool turned = false;

        // if (135 <= joystickMain.GetPOV() && joystickMain.GetPOV() <= 225) {

        //     if (joystickMain.GetRawButton(1)) {
        //         turnTo(180);
        //         turned = true;
        //     } else if (joystickMain.GetRawButton(2)) {
        //         turnTo(90);
        //         turned = true;
        //     } else if (joystickMain.GetRawButton(3)) {
        //         turnTo(-90);
        //         turned = true;
        //     } else if (joystickMain.GetRawButton(4)) {
        //         turnTo(0);
        //         turned = true;
        //     }
        // } else {

        if (joystickMain.GetRawButton(1)) {
            drive.turn(45);
            turned = true;
        } else if (joystickMain.GetRawButton(2)) {
            drive.turn(95);
            turned = true;
        } else if (joystickMain.GetRawButton(3)) {
            drive.turn(-95);
            turned = true;
        } else if (joystickMain.GetRawButton(4)) {
            drive.turn(180);
            turned = true;
        }
        //}

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