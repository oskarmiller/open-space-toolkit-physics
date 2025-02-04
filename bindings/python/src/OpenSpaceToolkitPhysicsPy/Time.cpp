/// Apache License 2.0

#include <OpenSpaceToolkitPhysicsPy/Time/Date.cpp>
#include <OpenSpaceToolkitPhysicsPy/Time/DateTime.cpp>
#include <OpenSpaceToolkitPhysicsPy/Time/Duration.cpp>
#include <OpenSpaceToolkitPhysicsPy/Time/Instant.cpp>
#include <OpenSpaceToolkitPhysicsPy/Time/Interval.cpp>
#include <OpenSpaceToolkitPhysicsPy/Time/Scale.cpp>
#include <OpenSpaceToolkitPhysicsPy/Time/Time.cpp>

inline void OpenSpaceToolkitPhysicsPy_Time(pybind11::module& aModule)
{
    // Create "time" python submodule
    auto time = aModule.def_submodule("time");


    // Add objects to python "time" submodules
    OpenSpaceToolkitPhysicsPy_Time_Scale(time);
    OpenSpaceToolkitPhysicsPy_Time_Duration(time);
    OpenSpaceToolkitPhysicsPy_Time_DateTime(time);
    OpenSpaceToolkitPhysicsPy_Time_Date(time);
    OpenSpaceToolkitPhysicsPy_Time_Time(time);
    OpenSpaceToolkitPhysicsPy_Time_Interval(time);
    OpenSpaceToolkitPhysicsPy_Time_Instant(time);
}
