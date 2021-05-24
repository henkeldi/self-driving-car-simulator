
include_directories(../src)

set(SRC ../src/model/kinematics/bicycle.cpp
        ../src/model/kinematics/model.cpp
        ../src/model/math/point2d.cpp
        ../src/model/math/pose2d.cpp)

#add_executable(test_bicycle test_bicycle.cpp ${SRC})
#target_link_libraries(test_bicycle gtest_main)

add_executable(test_integrator test_integrator.cpp ${SRC})
target_link_libraries(test_integrator gtest_main)
