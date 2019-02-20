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

#include <frc/Ultrasonic.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include "AHRS.h"

using namespace frc;
using namespace std;

/*
class MotorController {
    public:
        MotorController(TalonSRX* talon, Encoder* encoder, AnalogInput* lowerInductive, AnalogInput* upperInductive, int encoderLimit, double moderator) {
            this->talon = talon;
            this->encoder = encoder;
            this->lowerInductive = lowerInductive;
            this->upperInductive = upperInductive;
            this->encoderLimit = encoderLimit;
            this->moderator = moderator;
        }

        void MotorController::goToTick(int tick) {
            this->target = tick;
            this->searching = true;
        }

        void MotorController::applyPower(double power) {

            if (power < 0 && !checkInductive(this->lowerInductive)) {

            } else if (power < 0 && !checkInductive(this->lowerInductive)) {

            }

        }

        void MotorController::update() {

            if (this->encoder->Get() < this->target && !checkInductive(this->lowerInductive)) {
                this->talon->Set(ControlMode::PercentOutput, this->moderator / pow(abs(this->encoder->Get() - this->target), 2));
            } else if (this->encoder->Get() > this->target && !checkInductive(this->upperInductive)) {
                this->talon->Set(ControlMode::PercentOutput, -1 * this->moderator / pow(abs(this->encoder->Get() - this->target), 2));
            } else {
                this->talon->Set(ControlMode::PercentOutput, 0);
                this->searching = false;
            }
            
        }

        bool checkInductive(AnalogInput* inductive) {
            return inductive->GetVoltage > 3.0;
        }

    private:
        TalonSRX* talon;
        Encoder* encoder;
        AnalogInput* lowerInductive;
        AnalogInput* upperInductive;
        int encoderLimit;
        int target = 0;
        double moderator = 0;

        bool searching = false;

}*/

class Robot : public frc::TimedRobot {

public:

    // CONSTANTS
    const double LIFT_CONSTANT_COEFFICIENT = 10;

    const int FRONT_LEFT_CIM = 6;
    const int FRONT_RIGHT_CIM = 5;
    const int REAR_LEFT_CIM = 7;
    const int REAR_RIGHT_CIM = 4;

    const int FRONT_CLIMB_CIM = 1;
    const int BACK_CLIMB_CIM = 3;
    const int BACK_DRIVE_BAG = 2;

    const int LIFT_ELEVATOR_CIM = 10;
    const int TILT_ELEVATOR_REDLINE = 8;
    const int INTAKE_ELEVATOR_BAG = 9;

    const double climbMod = 1.0;
    const double backAngle = 10.0;

    const int ELEVATOR_ENCODER_LIMIT = 2000;

    const int INDUCTIVE_ELEVATOR_TOP = 1;
    const int INDUCTIVE_ELEVATOR_BOTTOM = 0;

    const int TILT_MIN = 0;
    const int TILT_MAX = 425000; // CHANGE OR ELSE BAD STUFF HAPPENS

    const int HOOK_SERVO = 7;
    const int HOOK_IN_ANGLE = 0;
    const int HOOK_OUT_ANGLE = 110;

    // Servo
    Servo hookServo;

    // TIMERS
    Timer *timer = new Timer();

    // ULTRASONICS
    Ultrasonic *ultraFront;

    // VECTOR<TALONS> <- Encoder monitoring
    //vector<MotorController> motorControllerVector;

    // TALONS
    TalonSRX FR, FL, RR, RL;
    TalonSRX frontClimb, rearClimb, rearDrive;
    TalonSRX elevatorTalon, intakeTalon, tiltTalon;

    // GYRO
    AHRS *ahrs;
    double gyroAngDif = 0;
    bool done = false;

    // LED STRIPS
    DigitalOutput red;
    DigitalOutput green;
    DigitalOutput blue;

    // ENCODERS
    // double rightEncoderConstant, leftEncoderConstant;
    // bool initialValueSet = false;
    // double initialLiftPosition = 0;

    // double leftEncoderInitial = 0.0;
    // double rightEncoderInitial = 0.0;

    Encoder elevatorEncoder;
    Encoder tiltEncoder;

    // ENCODER PID
    int kTimeoutMs = 10;
    int kPIDLoopIdx = 0;
    int kSlotIdx = 0;

    // INPUT
    double initialValTalon;
    Joystick joystickMain;
    Joystick joystickMechanisms;
    double lefty;

    double j_x_L, j_y_L, j_x_R;
    double moderator;

    bool climbEnabled = false;

    const double liftMod = 0.5;
    const double tiltMod = 0.5;

    double beginningDiff;

    int alt = 0;

    Preferences* preferences;

    bool inductiveSensorTriggered;
    int targetAngle = 0;

    float ballPower = 0;

    AnalogInput elevatorInductiveTop, elevatorInductiveBottom;

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
        preferences = Preferences::GetInstance();
        ahrs = new AHRS(SPI::Port::kMXP);

        //motorControllerVector.push_back(MotorController (&elevatorTalon, &elevatorEncoder, &lowerInductive, &upperInductive, 100, 1));
    }


    void setLED(bool r, bool g, bool b) {
        red.Set(!r);
        green.Set(!g);
        blue.Set(!b);
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
        ultraFront = new Ultrasonic(3, 4);
        ultraFront->SetAutomaticMode(true);

        //setupEncoderTalon(RL);
        //setupEncoderTalon(FR);

        CameraServer::GetInstance()->StartAutomaticCapture();

        timer->Start();
        resetGyro();
    }

    void TestInit() {}

    void TestPeriodic() {}

    void AutonomousInit() {

    }

    void AutonomousPeriodic() {

    }

    void resetEncoder() {
        // leftEncoderInitial = RL.GetSelectedSensorPosition(kPIDLoopIdx);
        // rightEncoderInitial = RL.GetSelectedSensorPosition(kPIDLoopIdx);
    }

    void TeleopInit() {
        //driveSystemBrakeMode(true);  //DRIVING

        FR.SetNeutralMode(NeutralMode::Brake);
        FL.SetNeutralMode(NeutralMode::Brake);
        RR.SetNeutralMode(NeutralMode::Brake);
        RL.SetNeutralMode(NeutralMode::Brake);
        frontClimb.SetNeutralMode(NeutralMode::Brake);
        rearClimb.SetNeutralMode(NeutralMode::Brake);

        elevatorTalon.SetNeutralMode(NeutralMode::Brake);
        intakeTalon.SetNeutralMode(NeutralMode::Brake);
        
        elevatorEncoder.Reset();
        tiltEncoder.Reset();
        
        resetGyro();
        timer->Start();
        timer->Reset();

        // Set LED strip to alliance color
        if (DriverStation::GetInstance().GetAlliance() == DriverStation::kRed) {
            setLED(true, false, false);
        } else {
            setLED(false, false, true);
        }
    }

    void TeleopPeriodic() {
        driveSystem();

        moveElevator(joystickMechanisms.GetRawAxis(1));
        moveTilt(joystickMechanisms.GetRawAxis(3));

        doClimbMechanism();
        doHatchMechanism();
        
    }


    // DRIVE SYSTEM

    void driveSystem()
    {

        cout << "Elevator Encoder" << elevatorEncoder.Get() << endl;
        cout << "Tilt Encoder" << tiltEncoder.Get() << endl;

        bool turned = buttonTurn();
        
        ahrs->UpdateDisplacement(ahrs->GetWorldLinearAccelX(), ahrs->GetWorldLinearAccelY(), ahrs->GetActualUpdateRate(), ahrs->IsMoving());
        alt += ahrs->GetDisplacementZ();
        cout << alt << endl;

        if (joystickMain.GetRawButton(6)) // if green a button is pressed
            moderator = 1.0; // makes robot go faster .. 1.0 for carpet
        else if (joystickMain.GetRawButton(5)) // if red b button is pressed
            moderator = 0.4; // make it really slow
        else // base case let it be half speed
            moderator = 0.8; // limits the range given from the controller // 0.85 for carpet

        if (!turned) {
            roboMove(); 
        }
    }

    void roboMove() {
        j_x_L = joystickMain.GetRawAxis(0);
        j_y_L = joystickMain.GetRawAxis(1);

        j_x_R = joystickMain.GetRawAxis(4);

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
            //double gAng = getRealAngle(gyro.GetAngle());
            double gAng = 0;

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
        // } else {
        //     //cout << "STOPPED" << endl;

        //     FRpow = 0;
        //     FLpow = 0;
        //     RRpow = 0;
        //     RLpow = 0;
        // }
        
        FR.Set(ControlMode::PercentOutput, FRpow * moderator);
        FL.Set(ControlMode::PercentOutput, FLpow * moderator);
        RR.Set(ControlMode::PercentOutput, RRpow * moderator);
        RL.Set(ControlMode::PercentOutput, RLpow * moderator);
    }

    void doIntakeMechanism() {
        // Ball mech
        if (joystickMechanisms.GetRawButton(6)) {
            intakeTalon.Set(ControlMode::PercentOutput, -0.75);
        } else if (joystickMechanisms.GetRawButton(5)) {
            intakeTalon.Set(ControlMode::PercentOutput, 0.5);
        } else {

            intakeTalon.Set(ControlMode::PercentOutput, 0);
        }
    }

    void doHatchMechanism() {
        if (joystickMechanisms.GetRawButton(4)) {
            hookOut();
        } else if (joystickMechanisms.GetRawButton(2)) {
            hookIn();
        }
    }

    void doClimbMechanism() {
        if (joystickMechanisms.GetRawButton(6)) {
            climbFrontUp();
        } else if (joystickMechanisms.GetRawButton(8)) {
            climbFrontDown();
        }

        if (joystickMechanisms.GetRawButton(5)) {
            climbRearUp();
        } else if (joystickMechanisms.GetRawButton(7)) {
            climbRearDown();
        }  

        if (joystickMechanisms.GetRawButton(10)) {
            climbBothDown();
        }

        if (joystickMechanisms.GetPOV() == 315 || joystickMechanisms.GetPOV() == 0 || joystickMechanisms.GetPOV() == 45) {
            climbDriveForward();
        } else if (joystickMechanisms.GetPOV() >= 135 || joystickMechanisms.GetPOV() <= 225) {
            climbDriveReverse();
        }  

        climbBothDown(joystickMechanisms.GetRawAxis(1));
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
            // }else if (joystickMain.GetRawButton(5)) {
            //     turn(-1);
            //     turned = true;
            // }else if (joystickMain.GetRawButton(6)) {
            //     turn(1);
            //     turned = true;
            // }

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

    void DisabledPeriodic() {}

    void climbToggleDisable() {
        climbEnabled = !climbEnabled;
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

    void climbBothDown() {
        frontClimb.Set(ControlMode::PercentOutput, cos(backAngle) * climbMod);
        rearClimb.Set(ControlMode::PercentOutput, climbMod);
    }

    void climbBothDown(double pow) {
        frontClimb.Set(ControlMode::PercentOutput,  1.4*climbMod * pow);
        rearClimb.Set(ControlMode::PercentOutput, climbMod * pow);
        //cout << ahrs->GetRoll() << endl;
    }

    void climbDriveForward() {
        rearDrive.Set(ControlMode::PercentOutput, 0.5);
    }

    void climbDriveReverse() {
         rearDrive.Set(ControlMode::PercentOutput, - 0.5);
    }

    void hookIn() {

        hookServo.SetAngle(HOOK_IN_ANGLE);

    }

    void hookOut() {

        hookServo.SetAngle(HOOK_OUT_ANGLE);

    }

    void moveElevator(double pow) {

        pow *= -1;

        // Down?
        if ((pow > 0.05 && !inductiveSensorState(&elevatorInductiveTop)) || (pow < -0.05 && !inductiveSensorState(&elevatorInductiveBottom))) {
            elevatorTalon.Set(ControlMode::PercentOutput, liftMod * pow);

        } else { // stawp
        
            cout << "Elevator locked" << endl;
            elevatorTalon.Set(ControlMode::PercentOutput, 0); // make the speed 0.05 and see what happens

        }

        cout << "Elevator power" << liftMod * pow << endl;
        cout << "Elevator Encoder" << elevatorEncoder.Get() << endl;
    }

    
    void moveTilt(double pow) {

        pow *= -1;

        cout << "TILT ENCODER" << tiltEncoder.Get() << endl;

        if ((pow < 0 && tiltEncoder.Get() >= TILT_MIN) || (pow > 0 && tiltEncoder.Get() <= TILT_MAX)) {
            tiltTalon.Set(ControlMode::PercentOutput, tiltMod * pow);

        } else { // stawp
        
            cout << "Tilt locked" << endl;
            tiltTalon.Set(ControlMode::PercentOutput, 0);

        }

        cout << "Tilt power" << tiltMod * pow << endl;
    }

    void intakeElevator(double pow) {
        intakeTalon.Set(ControlMode::PercentOutput, tiltMod * pow);
    }
};

START_ROBOT_CLASS(Robot)