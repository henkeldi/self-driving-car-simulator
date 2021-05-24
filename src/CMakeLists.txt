
include_directories(.)
add_executable(car_simulator
        main.cpp model/kinematics/bicycle.cpp model/kinematics/bicycle.h model/math/pose2d.cpp model/math/pose2d.h model/simulation/integrator.cpp model/simulation/integrator.h model/kinematics/model.cpp model/kinematics/model.h)
