/// Apache License 2.0

#include <OpenSpaceToolkit/Physics/Environment/Object/Celestial/Earth.hpp>

inline void OpenSpaceToolkitPhysicsPy_Environment_Object_Celestial_Earth(pybind11::module& aModule)
{
    using namespace pybind11;

    using ostk::core::type::Integer;
    using ostk::core::type::Real;
    using ostk::core::type::Shared;

    using ostk::physics::unit::Length;
    using ostk::physics::unit::Derived;
    using ostk::physics::coordinate::Frame;
    using ostk::physics::time::Instant;
    using ostk::physics::environment::Ephemeris;
    using ostk::physics::environment::ephemeris::Analytical;
    using ostk::physics::environment::object::Celestial;
    using ostk::physics::environment::object::celestial::Earth;
    using EarthGravitationalModel = ostk::physics::environment::gravitational::Earth;
    using EarthMagneticModel = ostk::physics::environment::magnetic::Earth;
    using EarthAtmosphericModel = ostk::physics::environment::atmospheric::Earth;

    {
        class_<Earth, Celestial, Shared<Earth>>(aModule, "Earth")

            .def(
                init<
                    const Derived&,
                    const Length&,
                    const Real&,
                    const Real&,
                    const Real&,
                    const Shared<Ephemeris>&,
                    const Shared<EarthGravitationalModel>&,
                    const Shared<EarthMagneticModel>&,
                    const Shared<EarthAtmosphericModel>&>(),
                arg("gravitational_parameter"),
                arg("equatorial_radius"),
                arg("flattening"),
                arg("J2_parameter_value"),
                arg("J4_parameter_value"),
                arg("ephemeris"),
                arg("gravitational_model"),
                arg("magnetic_model"),
                arg("atmospheric_model")
            )

            .def(
                init<
                    const Shared<Ephemeris>&,
                    const Shared<EarthGravitationalModel>&,
                    const Shared<EarthMagneticModel>&,
                    const Shared<EarthAtmosphericModel>&>(),
                arg("ephemeris"),
                arg("gravitational_model") = pybind11::none(),
                arg("magnetic_model") = pybind11::none(),
                arg("atmospheric_model") = pybind11::none()
            )

            .def("__str__", &(shiftToString<Earth>))
            .def("__repr__", &(shiftToString<Earth>))

            .def_static("default", &Earth::Default)
            .def_static(
                "EGM2008",
                &Earth::EGM2008,
                arg_v("degree", Integer::Undefined(), "Integer.undefined()"),
                arg_v("order", Integer::Undefined(), "Integer.undefined()")
            )
            .def_static(
                "WGS84_EGM96",
                &Earth::WGS84_EGM96,
                arg_v("degree", Integer::Undefined(), "Integer.undefined()"),
                arg_v("order", Integer::Undefined(), "Integer.undefined()")
            )
            .def_static(
                "EGM96",
                &Earth::EGM96,
                arg_v("degree", Integer::Undefined(), "Integer.undefined()"),
                arg_v("order", Integer::Undefined(), "Integer.undefined()")
            )
            .def_static(
                "EGM84",
                &Earth::EGM84,
                arg_v("degree", Integer::Undefined(), "Integer.undefined()"),
                arg_v("order", Integer::Undefined(), "Integer.undefined()")
            )
            .def_static(
                "WGS84",
                &Earth::WGS84,
                arg_v("degree", Integer::Undefined(), "Integer.undefined()"),
                arg_v("order", Integer::Undefined(), "Integer.undefined()")
            )
            .def_static("spherical", &Earth::Spherical)

            .def_static("gravitational_only", &Earth::GravitationalOnly, arg("gravity_model"))
            .def_static("magnetic_only", &Earth::MagneticOnly, arg("magnetic_model"))
            .def_static("atmospheric_only", &Earth::AtmosphericOnly, arg("atmospheric_model"))
            .def_static(
                "from_models", &Earth::FromModels, arg("gravity_model"), arg("magnetic_model"), arg("atmospheric_model")
            )

            ;
    }
}
