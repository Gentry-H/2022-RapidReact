/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberUp.h"
#include <iostream>

CmdClimberUp::CmdClimberUp(SubClimber *SubClimber, frc::Joystick* auxController) : m_subClimber(SubClimber), m_auxController(auxController){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(SubClimber);

}

// Called when the command is initially scheduled.
void CmdClimberUp::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClimberUp::Execute()
{
  double speed = m_auxController->GetRawAxis(AXIS_R_TRIG);
  if (speed < 0.1) {
    speed = 0;
  }
  speed = speed;
  // Move Climber to set position
  std::cout << "Climber Speed " << speed << std::endl;

  m_subClimber->MoveClimber(speed);
}

// Called once the command ends or is interrupted.
void CmdClimberUp::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClimberUp::IsFinished()
{
  return false;
}
