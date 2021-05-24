
#ifndef CAPSTONE_POSE2D_H
#define CAPSTONE_POSE2D_H

#include "model/math/point2d.h"

class Pose2D {
 public:
  Pose2D(Point2D position, double angle) : position_(position), angle_(angle) {}

  void Orientation(double angle) { angle_ = angle; }

  Point2D Position() { return position_; }
  double Orientation() const { return angle_; }
 private:
  Point2D position_;
  double angle_;
};

#endif  // CAPSTONE_POSE2D_H
