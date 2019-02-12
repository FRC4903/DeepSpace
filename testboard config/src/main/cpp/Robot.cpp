/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <string>
#include <bits/stdc++.h>

#include <frc/Joystick.h>
#include <frc/Compressor.h>
#include <frc/DriverStation.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/livewindow/LiveWindow.h>
#include "ctre/Phoenix.h"
#include <frc/PWMTalonSRX.h> //Added this
#include <frc/DoubleSolenoid.h>
#include <iostream>
#include <frc/Ultrasonic.h> 
#include <frc/Servo.h>
#include <frc/Compressor.h>
#include <frc/AnalogInput.h>
#include <frc/Encoder.h>
#include <frc/AnalogInput.h>
#include <math.h>
#include <frc/WPILib.h>

using namespace frc;
using namespace std;

class Robot : public TimedRobot {
 public:
  
  TalonSRX talonLeft, talonRight;

  Ultrasonic *ultra;
  AnalogInput ainput;
  Servo servo;
  bool ran = false;
  int num;
  int range;
  double targetTick;
  
  double servoAngle = 0.5;
  //Compressor c;

  DoubleSolenoid  *leftSol = new DoubleSolenoid(2,3);
  DoubleSolenoid  *rightSol= new DoubleSolenoid(0,1);
  Joystick joystickMain;

  bool run = false; 
  double percentSpeed = 0;
  AnalogInput servoInput;
 bool inductiveSensor;

  Encoder encoder;

  bool ramping_up = true;
  bool ramping_down = false;

  double level1 = 0;
  double level2 = 400000; 
  double level3 = 800000;
  // int pos = encoder.Get();
  double target;
  int progression = 0;
  double buttonVal;
  double currLevel = 0;
  Robot() : talonLeft(2), talonRight(1), joystickMain(0), servo(0), servoInput(0), encoder(8, 9), ainput(2)
  {
    //m_robotDrive.SetExpiration(0.1);
    m_timer.Start();
    encoder.SetDistancePerPulse((double) 1024);
  }

  void AutonomousInit() override {
    m_timer.Reset();
    m_timer.Start();
    talonLeft.SetNeutralMode(NeutralMode::Brake);
    talonRight.SetNeutralMode(NeutralMode::Brake);
  }

  void AutonomousPeriodic() override {
    
  }

  void TeleopInit() override {
    encoder.Reset();
    talonLeft.SetNeutralMode(NeutralMode::Brake);
    talonRight.SetNeutralMode(NeutralMode::Brake);
    ultra = new Ultrasonic(1, 0); // assigns ultra to be an ultrasonic sensor which uses DigitalOutput 1 for the echo pulse and DigitalInput 1 for the trigger pulse
		servo.Set(0);
    //inductiveSensor = new DigitalInput(2);
    // targetTick = 1023*20*1.50421652;
    // targetTick = targetTick - (targetTick*0.335202089);
    targetTick = 41000;
      // servo.Set(270);
      // cout << servoInput.GetValue() * 0.47 - 33.4 << endl;
    
    //ultrasonic
    ultra->SetAutomaticMode(true);
    
    
  }

  void TeleopPeriodic() override {
    // Drive with arcade style (use right stick)
    //m_robotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());  
    double getx, gety, SpeedMod;
    

    //printing range
    range = ultra->GetRangeInches(); // reads the range on the ultrasonic sensor
    //cout << range << endl ;

    //inductive sensor
    inductiveSensor = (ainput.GetVoltage() > 3.0 ? true : false);
    //cout << ainput.GetVoltage() << endl ;
    // topInductiveSensor = ainput.GetValue();
    // cout << topInductiveSensor << endl;
    //getting axis
    getx = joystickMain.GetRawAxis(1);
    gety = joystickMain.GetRawAxis(5);

    // cout << getx << endl;

    //cout << encoder.Get() << endl;

    if (!inductiveSensor) {
      talonLeft.Set(ControlMode::PercentOutput, getx);
      talonRight.Set(ControlMode::PercentOutput, gety);
    }
    
    else{
      talonLeft.Set(ControlMode::PercentOutput, 0);
      talonRight.Set(ControlMode::PercentOutput, 0);
    }
    
    
    //solenoids
    // cout << servoInput.GetValue() * 0.47 - 33.4 << endl;
    
    // encoder.Reset();
    if (joystickMain.GetRawButton(2)) { // red
      // rightSol->Set(DoubleSolenoid::kForward);
      // servo.SetAngle(270*2/3);
      buttonVal = encoder.Get();
      target = level1 - buttonVal;
      currLevel = level1;
    }

    else if (joystickMain.GetRawButton(4)) { // yellow
      // leftSol->Set(DoubleSolenoid::kForward);
      
      // servo.SetAngle(0*2/3);
    }

    else if (joystickMain.GetRawButton(1)) { // green
      // leftSol->Set(DoubleSolenoid::kReverse);
    //  servo.SetAngle(180*2/3);
      buttonVal = encoder.Get();
    currLevel = level2;
    target = level2 - buttonVal;
    }

    else if (joystickMain.GetRawButton(3)) { // blue
      // rightSol->Set(DoubleSolenoid::kReverse);
      // servo.SetAngle(90*2/3);
      buttonVal = encoder.Get();
      currLevel = level3;
      target = level3 - buttonVal;
      // elevator(target, level3);
    }
    elevator(target, currLevel);

    // elevator(800000, level3);
    /*
    cout << "encoder:" << encoder.Get() << endl;
      // encoder.Reset();
      // ran = true;
        if (encoder.Get() < targetTick){
          cout << "before ramp" << encoder.Get() << endl;
          percentSpeed = rampSpeed(targetTick, percentSpeed);
          cout << percentSpeed << endl;
          talonLeft.Set(ControlMode::PercentOutput, percentSpeed);
        }
        else{
          talonLeft.Set(ControlMode::PercentOutput, 0);
        }
        
       //talonLeft.Set(ControlMode::PercentOutput, 0.05);

    // if (joystickMain.GetRawButton(6)){
      // if (percentSpeed < 1.0 && ramping_up){
      //   percentSpeed += 0.01;
      // }else{
      //   ramping_down = true;
      //   ramping_up = false;
      // } 
      
      // if(percentSpeed > 0 && ramping_down){
      //   percentSpeed -= 0.01;
      // }else{
      //   ramping_down = false;
      //   // ramping_up = true;
      // }
      // cout << percentSpeed << endl;
      // talonLeft.Set(ControlMode::PercentOutput, percentSpeed);

    // }
    
      // talonLeft.Set(ControlMode::PercentOutput, 0.25);
      // talonLeft.Set(ControlMode::PercentOutput, 0.25);      

  // talonLeft.Set(ControlMode::PercentOutput,0) ;
  // talonRight.Set(ControlMode::PercentOutput,SpeedMod) ;
  */
  


    

    
  }

  void TestPeriodic() override {
    //c.SetClosedLoopControl(1);
  }
 private:
  // Robot drive system
    

  Joystick m_stick{0};
  LiveWindow& m_lw = *frc::LiveWindow::GetInstance();
  Timer m_timer;

  double rampSpeed(double targetTick, double speed){
    double currentTick = encoder.Get();
    
    
    if (currentTick/targetTick < 0.75) {
        if (speed < 1){
          speed += 0.05;
        }
        
        
      }
      
     
      
    else {
      speed = (1-currentTick/targetTick);
      if (speed <= 0.05 && currentTick<targetTick){
        speed = 0.05;
      }
      
    }
      
    return speed;
  }

  void elevator(double target, double level){
    double progression = encoder.Get() - buttonVal;
    double progress = (progression / target);
    double speed = (level < encoder.Get() ? -1 : 1) * (-4 * (progress * progress) + 1);
    // double speed = (-4 * (progress * progress) + 1);
    
    cout << "TARGET: " << target<< endl;
    cout << "PROGRESSION: " << progression << endl;
    cout << "PROGRESS: " << progress << endl;
    cout << "BUTTONVAL: " << buttonVal << endl;
    cout << "SPEED" << speed << endl;
    
    
    
    if (progress <= 0.5){
      talonLeft.Set(ControlMode::PercentOutput, speed); 
    }
    


  }


#ifndef RUNNING_FRC_TESTS
int main() { return StartRobot<Robot>(); }
#endif
};

START_ROBOT_CLASS(Robot);