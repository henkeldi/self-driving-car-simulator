//
// Created by dh on 5/24/21.
//

#ifndef CAPSTONE_POINT2D_H
#define CAPSTONE_POINT2D_H

class Point2D {
 public:
  Point2D(double x, double y) : x_(x), y_(y) {}

  void X(double x) { x_ = x; }
  void Y(double y) { y_ = y; }
  double X() const { return x_; }
  double Y() const { return y_; }

 private:
  double x_;
  double y_;
};

#endif  // CAPSTONE_POINT2D_H
