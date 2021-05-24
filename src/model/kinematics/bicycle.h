
#ifndef CAPSTONE_BICYCLE_H
#define CAPSTONE_BICYCLE_H

#include <cassert>
#include <cmath>
#include <vector>

#include "model/kinematics/model.h"
#include "model/math/pose2d.h"

class Bicycle : public Model {
 public:
  Bicycle(Pose2D pose, double steering_angle, const double length)
      : pose_(pose), steering_angle_(steering_angle), length_(length) {}
  void Velocity(double velocity) { velocity_ = velocity; }
  void SteeringVelocity(double steering_velocity) {
    steering_velocity_ = steering_velocity;
  }
  std::vector<double> GetState() override {
    return {pose_.Position().X(), pose_.Position().Y(), pose_.Orientation(),
            steering_angle_};
  }
  std::vector<double> ComputeStateEquations(
      double time, std::vector<double> state) override {
    assert(state.size() == 4);
    double orientation = state[2];
    double slip_angle = atan(0.5 * tan(steering_angle_));
    double x_dot = velocity_ * cos(orientation + slip_angle);
    double y_dot = velocity_ * sin(orientation + slip_angle);
    double orientation_dot =
        (velocity_ * cos(slip_angle) * tan(steering_angle_)) / length_;
    double steering_angle_dot = steering_velocity_;
    return {x_dot, y_dot, orientation_dot, steering_angle_dot};
  }
  void SetState(std::vector<double> state) override {
    assert(state.size() == 4);
    pose_.Position().X(state[0]);
    pose_.Position().Y(state[1]);
    pose_.Orientation(state[2]);
    steering_angle_ = state[3];
  }

 private:
  Pose2D pose_;
  double steering_angle_;

  double velocity_{0.0};
  double steering_velocity_{0.0};

  const double length_;
};

#endif  // CAPSTONE_BICYCLE_H
