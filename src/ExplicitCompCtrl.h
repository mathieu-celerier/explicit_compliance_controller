#pragma once

#include <mc_control/fsm/Controller.h>
#include <mc_tasks/CompliantEndEffectorTask.h>
#include <mc_tasks/CompliantPostureTask.h>

#include "api.h"

struct ExplicitCompCtrl_DLLAPI ExplicitCompCtrl : public mc_control::fsm::Controller
{
  ExplicitCompCtrl(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);

  bool run() override;

  void reset(const mc_control::ControllerResetData & reset_data) override;

  std::shared_ptr<mc_tasks::CompliantEndEffectorTask> eeTask;
  std::shared_ptr<mc_tasks::CompliantPostureTask> postureTask;

private:
  mc_rtc::Configuration config_;
};
