#include "gtest/gtest.h"

#include "model/kinematics/bicycle.h"

TEST(TestBicycle, ItShouldComputeTheStateEquations) {
  Bicycle model({{0, 0}, 0.6}, 0.5, 2.0);
  model.Velocity(0.2);
  model.SteeringVelocity(0.3);
  auto state_dot = model.ComputeStateEquations(0.0, model.GetState());
  ASSERT_EQ(state_dot.size(), 4);
  double x_dot = state_dot[0];
  double y_dot = state_dot[1];
  double orientation_dot = state_dot[2];
  double steering_angle_dot = state_dot[3];
  ASSERT_NEAR(x_dot, 0.129477199386929209482848, 1e-14);
  ASSERT_NEAR(y_dot, 0.152432459925428541711122, 1e-14);
  ASSERT_NEAR(orientation_dot, 0.052699611934650595847, 1e-14);
  ASSERT_EQ(steering_angle_dot, 0.3);
}
