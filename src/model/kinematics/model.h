//
// Created by dh on 5/24/21.
//

#ifndef CAPSTONE_MODEL_H
#define CAPSTONE_MODEL_H

#include <vector>

class Model {
 public:
  ~Model() = default;
  virtual std::vector<double> GetState() = 0;
  virtual std::vector<double> ComputeStateEquations(
      double time, std::vector<double> state) = 0;
  virtual void SetState(std::vector<double> state) = 0;
};

#endif  // CAPSTONE_MODEL_H
