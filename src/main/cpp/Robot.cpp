#include <string>
#include <iostream>

#include <frc/TimedRobot.h>
#include <frc/liveWindow/LiveWindow.h>
#include <frc/smartDashboard/SendableChooser.h>
#include <frc/smartDashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"
#include "frc/DriverStation.h"
#include <frc/Timer.h>
#include "frc/Preferences.h"
#include "frc/Joystick.h"
#include "frc/AnalogInput.h"
#include "frc/Servo.h"
#include "frc/PWM.h"

#include "frc/WPILib.h"

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

#include <frc/Ultrasonic.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include "AHRS.h"

using namespace frc;
using namespace std;


class Robot : public frc::TimedRobot {

public:
    // CONSTANTS
    //DRIVE MOTOR TALON IDS
    const int FRONT_LEFT_CIM = 6;
    const int FRONT_RIGHT_CIM = 5;
    const int REAR_LEFT_CIM = 7;
    const int REAR_RIGHT_CIM = 4;

    //CLIMB MECHANISM TALON IDS
    const int FRONT_CLIMB_CIM = 1;
    const int BACK_CLIMB_CIM = 3;
    const int BACK_DRIVE_BAG = 2;

    //GAME MECHANISM TALON IDS
    const int LIFT_ELEVATOR_CIM = 10;
    const int TILT_ELEVATOR_REDLINE = 8;
    const int INTAKE_ELEVATOR_BAG = 9;

    //CONSTANT MODERATORS
    const double climbMod = 0.7;


    const double frontClimbMod = 0.5;
    const double backClimbMod = 0.7;

    const double liftMod = 0.7;
    const double tiltMod = 0.55;
    const double elevatorMod = 0.5;
    const double autoTurnMod = 0.6;

    const double driveClimbPower = 0.8;

    //TURN VARIABLES
    const double turnCheckSeconds = 2; 
    double targetAngle ; 
    bool turning; 

    // ELEVATOR GOTO
    double elevatorTargetTick;
    bool elevatorAuto;
    const double elevatorCheckSeconds = 10;

    //DRIVE SPEED MODERATOR
    double driveSpeedMod;

    //INDUCTIVE SENSORS    
    const int INDUCTIVE_ELEVATOR_TOP = 1;
    const int INDUCTIVE_ELEVATOR_BOTTOM = 0;

    //ENCODER LIMITS
    const int TILT_MIN = 0;
    const int TILT_MAX = 425000; // CHANGE OR ELSE BAD STUFF HAPPENS

    //HOOK SERVO DETAILS
    const int HOOK_SERVO = 7;
    const int HOOK_IN_ANGLE = 0; //150;
    const int HOOK_OUT_ANGLE = 110; //0;

    // ELEVATOR TICKS
    const int MIDDLE_ELEVATOR_TICKS = 1088;
    const int TOP_ELEVATOR_TICKS = 2195;

    const int HUMAN_ELEVATOR_TOLERANCE = 20;

    // ESTOP
    const double ESTOP_BOUNDARY = 0.1;

    // CREATE HOOK SERVO OBJECT
    Servo hookServo;

    // TIMERS
    Timer *turnTimer = new Timer();
    Timer *elevatorTimer = new Timer();

    // ULTRASONICS
    Ultrasonic *ultraFront;

    // TALONS
    TalonSRX FR, FL, RR, RL;
    TalonSRX frontClimb, rearClimb, rearDrive;
    TalonSRX elevatorTalon, intakeTalon, tiltTalon;

    // GYRO
    AHRS *ahrs;
    double gyroAngDif = 0;
   
    // LED STRIPS
    DigitalOutput red;
    DigitalOutput green;
    DigitalOutput blue;

    //CREATING ENCODER OBJECTS
    Encoder elevatorEncoder;
    Encoder tiltEncoder;

    // CREATING JOYSTICK OBJECTS
    Joystick joystickMain;
    Joystick joystickMechanisms;
    
    //DRIVE VARIABLES
    double j_x_L, j_y_L, j_x_R;

    bool climbRetractionEnabled = false;

    //INDUCTIVE SENSOR OBJECTS
    AnalogInput elevatorInductiveTop, elevatorInductiveBottom;

    //ROBOT INSTANCE
    Robot() :
        joystickMain(0),
        joystickMechanisms(1),

        FR(FRONT_RIGHT_CIM),
        FL(FRONT_LEFT_CIM),
        RR(REAR_RIGHT_CIM),
        RL(REAR_LEFT_CIM),

        frontClimb(FRONT_CLIMB_CIM),
        rearClimb(BACK_CLIMB_CIM),
        rearDrive(BACK_DRIVE_BAG),

        elevatorTalon(LIFT_ELEVATOR_CIM),
        intakeTalon(INTAKE_ELEVATOR_BAG),
        tiltTalon(TILT_ELEVATOR_REDLINE),

        elevatorInductiveTop(INDUCTIVE_ELEVATOR_TOP),
        elevatorInductiveBottom(INDUCTIVE_ELEVATOR_BOTTOM),

        red(0),
        green(1),
        blue(2),

        elevatorEncoder(3, 4),
        tiltEncoder(8,9),

        hookServo(HOOK_SERVO)
    
    {
        ahrs = new AHRS(SPI::Port::kMXP);
    }

    //SETTING RGB COLOUR
    void setLED(bool r, bool g, bool b) {
        red.Set(!r);
        green.Set(!g);
        blue.Set(b);
    }

    void setup()
    {
        //turnTimer->Start();
    }

    void RobotInit() {
                
        CameraServer::GetInstance()->StartAutomaticCapture();

        //turnTimer->Start();
        resetGyro();
    }

    void TestInit() {}

    void TestPeriodic() {}

    void AutonomousInit() {
    //COOL PROGRAMMING STUFF USED TO BE HERE
        TeleopInit();
    }

    void AutonomousPeriodic() {
        TeleopPeriodic();
    }

    void TeleopInit() {


        // RESET VABLUES
        climbRetractionEnabled = false;

        //DRIVING IN BRAKE MODE
        FR.SetNeutralMode(NeutralMode::Brake);
        FL.SetNeutralMode(NeutralMode::Brake);
        RR.SetNeutralMode(NeutralMode::Brake);
        RL.SetNeutralMode(NeutralMode::Brake);

        //CLIMB IN BRAKE MODE
        frontClimb.SetNeutralMode(NeutralMode::Brake);
        rearClimb.SetNeutralMode(NeutralMode::Brake);
        rearDrive.SetNeutralMode(NeutralMode::Brake);

        //ELEVTOR AND MECHANISM IN BRAKE MODE    
        elevatorTalon.SetNeutralMode(NeutralMode::Brake);
        intakeTalon.SetNeutralMode(NeutralMode::Brake);
        tiltTalon.SetNeutralMode(NeutralMode::Brake);

        //RESET ENCODERS
        elevatorEncoder.Reset();
        tiltEncoder.Reset();
        
        //RESET GYRO
        resetGyro();

        
        elevatorTimer->Start();
        elevatorTimer->Reset();

        turnTimer->Start();
        turnTimer->Reset();
    }

    void TeleopPeriodic() {

        // ESTOP FOR TURN
        if (eStopTriggered(joystickMain.GetRawAxis(0), joystickMain.GetRawAxis(1), joystickMain.GetRawAxis(4), joystickMain.GetRawAxis(5)) && turning) {
            turning = false;

            cout << "TURNING ESTOP" << endl;
        }

        // ESTOP FOR ELEVATOR
        if (eStopTriggered(joystickMechanisms.GetRawAxis(0), joystickMechanisms.GetRawAxis(1), 0, 0) && elevatorAuto) {
            elevatorAuto = false;

            cout << "ELEVATOR ESTOP" << endl;
        }

        if (joystickMain.GetRawButton(7) && joystickMain.GetRawButton(8)) {
            climbRetractionEnabled = true;
            
            cout << "CLIMB RETRACT ACTIVATED!!!!!" << endl;
        }

        // DIsable driving if climbing
        if (!climbEnabled()) {
            driveSystem();      
        }

        mechanismSystem();
        updateTurn();
        updateElevator();
        //cout << ahrs->GetRate() << " " << ahrs->GetYaw() << endl;

        updateLED();
    }

    // Make LEDs green when within 10 ticks of top or middle elevator position
    void updateLED() {
        // Elevator range 
        if (abs(elevatorEncoder.Get() - MIDDLE_ELEVATOR_TICKS) < HUMAN_ELEVATOR_TOLERANCE || abs(elevatorEncoder.Get() - TOP_ELEVATOR_TICKS) < HUMAN_ELEVATOR_TOLERANCE) {
            setLED(false, true, false);
        } else if(climbRetractionEnabled) {
            setLED(true, true, false);
        } else {
            if (DriverStation::GetInstance().GetAlliance() == DriverStation::kRed) {
                setLED(true, false, false);
            } else {
                setLED(false, false, true);
            }
        }
    }

    bool climbEnabled() {

        return joystickMain.GetRawAxis(2) > 0.95 && joystickMain.GetRawAxis(3) > 0.95;
    }

    // DRIVE SYSTEM
    void driveSystem()
    {  
        double leftX = joystickMain.GetRawAxis(0);
        double leftY = joystickMain.GetRawAxis(1);

        double rightX = joystickMain.GetRawAxis(4);


        nt::NetworkTableInstance::GetDefault().GetTable("Vision")->PutNumber("test", leftY);


        driveSystem(leftY, leftX, rightX);
    }

    void driveSystem(double leftY, double leftX, double rightX)
    {
        buttonTurn();
        
        //ahrs->UpdateDisplacement(ahrs->GetWorldLinearAccelX(), ahrs->GetWorldLinearAccelY(), ahrs->GetActualUpdateRate(), ahrs->IsMoving());
        if (joystickMain.GetRawButton(6)) // if green a button is pressed
            driveSpeedMod = 0.95; // makes robot go faster .. 1.0 for carpet
        else if (joystickMain.GetRawButton(5)) // if red b button is pressed
            driveSpeedMod = 0.4; // make it really slow
        else // base case let it be half speed
            driveSpeedMod = 0.75; // limits the range given from the controller // 0.85 for carpet

                    
        j_x_L = leftX;
        j_y_L = leftY;

        j_x_R = rightX;

        if((j_x_L < 0 && j_x_L >= -0.05) || (j_x_L > 0 && j_x_L <= 0.05)) { j_x_L = 0; }
        if((j_y_L < 0 && j_y_L >= -0.05) || (j_y_L > 0 && j_y_L <= 0.05)) { j_y_L = 0; }
        if((j_x_R < 0 && j_x_R >= -0.05) || (j_x_R > 0 && j_x_R <= 0.05)) { j_x_R = 0; }

        double FRpow, FLpow, RRpow, RLpow = 0;
        bool manTurning = false;
        bool manMoving = false;

        if (j_x_L != 0 || j_y_L != 0){
            manMoving = true;

            double mag = hypot(j_x_L, j_y_L);
            double calcAng = getRealAngle(getPi() - atan2(j_y_L, j_x_L));
            double gAng = 0;

            FRpow += ( - getWheelPower(calcAng - gAng, true) * mag * driveSpeedMod );
            FLpow += ( - getWheelPower(calcAng - gAng, false) * mag * driveSpeedMod );
            RRpow += getWheelPower(calcAng - gAng, false) * mag * driveSpeedMod;
            RLpow += getWheelPower(calcAng - gAng, true) * mag * driveSpeedMod;
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
        } 

        if (manMoving && manTurning) {
            FRpow /= 2;
            FLpow /= 2;
            RRpow /= 2;
            RLpow /= 2;
        }

        FR.Set(ControlMode::PercentOutput, FRpow * driveSpeedMod);
        FL.Set(ControlMode::PercentOutput, FLpow * driveSpeedMod);
        RR.Set(ControlMode::PercentOutput, RRpow * driveSpeedMod);
        RL.Set(ControlMode::PercentOutput, RLpow * driveSpeedMod);
    }

    void mechanismSystem() {
        doElevatorMechanism();

        if (climbEnabled()) {
            doClimbMechanism();
        }

        doIntakeMechanism();
        doHatchMechanism();
    }

    void doHatchMechanism(){
        if (joystickMechanisms.GetRawButton(4)) {
            hookOut();
        } else if (joystickMechanisms.GetRawButton(2)) {
            hookIn();
        }
    }

    void doIntakeMechanism(){
        if (joystickMechanisms.GetRawButton(1)) {
            intakeTalon.Set(ControlMode::PercentOutput, -0.65);
        } else if (joystickMechanisms.GetRawButton(3)) {
            intakeTalon.Set(ControlMode::PercentOutput, 0.65);
        } else {
            intakeTalon.Set(ControlMode::PercentOutput, 0);
        }
    }

    void doElevatorMechanism() {
        moveElevator(joystickMechanisms.GetRawAxis(1));
        moveTilt(joystickMechanisms.GetRawAxis(3));
        
        if (joystickMechanisms.GetRawButton(5) && joystickMechanisms.GetRawButton(6)) { // LEVEL 3

            initElevator(MIDDLE_ELEVATOR_TICKS);

        } else if (joystickMechanisms.GetRawButton(7) && joystickMechanisms.GetRawButton(8)) { // LEVEL 2
        
            initElevator(TOP_ELEVATOR_TICKS);
        }
    }

    void doClimbMechanism() {
        //ASSIGN PROPER CONTROLLER AND CONTROLS BEFORE TESTING

        double leftValue = joystickMain.GetRawAxis(1);
        double rightValue = joystickMain.GetRawAxis(5);

        // So that the motor doesn't activate randomly
        if((leftValue < 0 && leftValue >= -0.05) || (leftValue > 0 && leftValue <= 0.05)) { leftValue = 0; }
        if((rightValue < 0 && rightValue >= -0.05) || (rightValue > 0 && rightValue <= 0.05)) { rightValue = 0; }

        // Prevent retraction of climb until end is reached
        if (!climbRetractionEnabled) {
            if (leftValue > 0) {
                leftValue = 0;
            }

            if (rightValue > 0) {
                rightValue = 0;
            }
        }
        
        rearClimb.Set(ControlMode::PercentOutput, backClimbMod * rightValue);
        frontClimb.Set(ControlMode::PercentOutput, frontClimbMod * leftValue);   

        // if (joystickMechanisms.GetRawButton(6)) {
        //     climbFrontUp();
        // } else if (joystickMechanisms.GetRawButton(8)) {
        //     climbFrontDown();
        // } else{
        //     stopFrontClimb();
        //}

        // if (joystickMechanisms.GetRawButton(5)) {
        //     climbRearUp();
        // } else if (joystickMechanisms.GetRawButton(7)) {
        //     climbRearDown();
        // }else{
        //     stopBackClimb();
        // }

        // Drive forward with dpad or forward stick going down
        if (joystickMain.GetPOV() == 0) {
            rearDrive.Set(ControlMode::PercentOutput, -0.3);

            driveSystem(-driveClimbPower, 0, 0); // Drive primary wheels

                /*
            FR.Set(ControlMode::PercentOutput, -0.7 * driveSpeedMod);
            FL.Set(ControlMode::PercentOutput, -0.7 * driveSpeedMod);
            RR.Set(ControlMode::PercentOutput, 0.7 * driveSpeedMod);
            RL.Set(ControlMode::PercentOutput, 0.7 * driveSpeedMod);*/
        } else if (joystickMain.GetPOV() == 180) {
            rearDrive.Set(ControlMode::PercentOutput, 0.3);

            driveSystem(driveClimbPower, 0, 0); // Drive primary wheels


            /*                
            FR.Set(ControlMode::PercentOutput, FRpow * driveSpeedMod);
            FL.Set(ControlMode::PercentOutput, FLpow * driveSpeedMod);
            RR.Set(ControlMode::PercentOutput, RRpow * driveSpeedMod);
            RL.Set(ControlMode::PercentOutput, RLpow * driveSpeedMod);*/

        } else {
            rearDrive.Set(ControlMode::PercentOutput, 0);
            driveSystem(0, 0, 0);
        }
    }

    double getRealAngle(double degAng) {
        if (degAng < 0) {degAng += getPi() * 2; }
        return degAng;
    }

    bool outOfBoundary(double limit, double value) {
        return abs(value) >= limit;
    }

    bool eStopTriggered(double a, double b, double c, double d) {

        return outOfBoundary(ESTOP_BOUNDARY, a) || outOfBoundary(ESTOP_BOUNDARY, b) || outOfBoundary(ESTOP_BOUNDARY, c) || outOfBoundary(ESTOP_BOUNDARY, d);

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
        double autoTurnMod = 0.5;
        resetGyro();
        while (true)
        {
            if (ahrs->GetYaw() < moveAngle) {
                setRight(-autoTurnMod);
                setLeft(autoTurnMod);
            } else {
                setRight(autoTurnMod);
                setLeft(-autoTurnMod);
            }
            if (abs(ahrs->GetYaw() - moveAngle) < 36) {
                break;
            }
        }
    }

    void initElevator(double ticks) {

        elevatorTargetTick = ticks;
        elevatorAuto = true;

        elevatorTimer->Reset();

        cout << "Starting auto elevator to level: " << ticks << endl;

        // Timer????

    }

    void updateElevator() {

        if (elevatorAuto) {

            // Go up if up and down if down
            if (elevatorTargetTick > elevatorEncoder.Get() && !inductiveSensorState(&elevatorInductiveTop)) {
                elevatorTalon.Set(ControlMode::PercentOutput, elevatorMod);
            } else if (elevatorTargetTick < elevatorEncoder.Get() && !inductiveSensorState(&elevatorInductiveBottom)) {
                elevatorTalon.Set(ControlMode::PercentOutput, -elevatorMod);
            }

            // Kill everything if inductive is reached
            if (abs(elevatorTargetTick - elevatorEncoder.Get()) < 10 || inductiveSensorState(&elevatorInductiveTop) || inductiveSensorState(&elevatorInductiveBottom)  || elevatorTimer->Get() > elevatorCheckSeconds) {
                elevatorAuto = false;
            }

        }

    }

    void beginTurn(double moveAngle){
        targetAngle = moveAngle;
        turning = true;
        turnTimer->Reset();
        resetGyro();
        
        cout << "Starting auto turn to angle: " << moveAngle << endl;
    }
          

    void updateTurn(){

        if (turning){

            if (ahrs->GetYaw() < targetAngle) {
                setRight(-autoTurnMod);
                setLeft(autoTurnMod);
            } else {
                setRight(autoTurnMod);
                setLeft(-autoTurnMod);
            }
            if (abs(ahrs->GetYaw() - targetAngle) < 20 || turnTimer->Get() > turnCheckSeconds) {
                turning = false;
            }
        }
    }   

    // void turnTo(double moveAngle) 
    // {
    //     turn(moveAngle - ahrs->GetYaw() - gyroAngDif);
    // }

    void buttonTurn()
    {   
       
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
        //} else {
                   
            if (joystickMain.GetRawButton(2)) {
                //turn(95);
                beginTurn(90);
                
            } else if (joystickMain.GetRawButton(3)) {
                //turn(-95);
                beginTurn(-90);
               
            } else if (joystickMain.GetRawButton(4)) {
                //turn(180);
                beginTurn(180);
                
            }
        //}
        
    }

    void setRight(double val) {
        RR.Set(ControlMode::PercentOutput, -val);
        FR.Set(ControlMode::PercentOutput, -val);
    }

    void setLeft(double val) {  
        RL.Set(ControlMode::PercentOutput, val);
        FL.Set(ControlMode::PercentOutput, val);        
    }

    bool inductiveSensorState(AnalogInput *input){
        return input->GetVoltage() > 3.0;
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

    void DisabledPeriodic() {
        setLED(false, false, true);
    }

    void climbFront(float power) {
        frontClimb.Set(ControlMode::PercentOutput, climbMod * power);
    }

    void climbFrontDown() {
        frontClimb.Set(ControlMode::PercentOutput, climbMod);
    }

    void climbFrontUp() {
        frontClimb.Set(ControlMode::PercentOutput, - climbMod);
    }

    void climbRearDown() {
        rearClimb.Set(ControlMode::PercentOutput, climbMod);
    }

    void climbRearUp() {
        rearClimb.Set(ControlMode::PercentOutput, - climbMod);
    }
    void stopFrontClimb(){
        frontClimb.Set(ControlMode::PercentOutput, 0);
    }
    void stopBackClimb(){
        rearClimb.Set(ControlMode::PercentOutput, 0);
    }

    void climbDriveForward() {
        rearDrive.Set(ControlMode::PercentOutput, -0.5);
    }

    void climbDriveReverse() {
         rearDrive.Set(ControlMode::PercentOutput, 0.5);
    }

    void hookIn() {
        hookServo.SetAngle(HOOK_IN_ANGLE);
    }

    void hookOut() {
        hookServo.SetAngle(HOOK_OUT_ANGLE);
    }

    void moveElevator(double pow) {
        pow *= -1;
        if ((pow > 0.05 && !inductiveSensorState(&elevatorInductiveTop)) || (pow < -0.05 && !inductiveSensorState(&elevatorInductiveBottom))) {
            elevatorTalon.Set(ControlMode::PercentOutput, liftMod * pow);

        } else {
            elevatorTalon.Set(ControlMode::PercentOutput, 0); 

        }
    }

    void moveTilt(double pow) {
        pow *= -1;
        if (true  || (pow < 0 && tiltEncoder.Get() >= TILT_MIN) || (pow > 0 && tiltEncoder.Get() <= TILT_MAX)) {
            tiltTalon.Set(ControlMode::PercentOutput, tiltMod * pow);
        } else {
            tiltTalon.Set(ControlMode::PercentOutput, 0);
        }
    }

    void intakeElevator(double pow) {
        intakeTalon.Set(ControlMode::PercentOutput, tiltMod * pow);
    }
};

START_ROBOT_CLASS(Robot)