#include "ExplicitCompCtrl.h"
#include <mc_rtc/unique_ptr.h>
#include <mc_solver/DynamicsConstraint.h>

ExplicitCompCtrl::ExplicitCompCtrl(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::fsm::Controller(rm, dt, config, Backend::Tasks)
{

  dynamicsConstraint = mc_rtc::unique_ptr<mc_solver::DynamicsConstraint>(new mc_solver::DynamicsConstraint(
      robots(), robot().robotIndex(), solver().dt(), std::array<double, 3>({0.1, 0.01, 0.5}), 1.0, false));

  mc_rtc::log::success("[ExplicitCompCtrl] Init done ");
}

bool ExplicitCompCtrl::run()
{
  return mc_control::fsm::Controller::run();
}

void ExplicitCompCtrl::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::fsm::Controller::reset(reset_data);
}
