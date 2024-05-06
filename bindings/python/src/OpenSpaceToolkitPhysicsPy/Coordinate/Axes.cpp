/// Apache License 2.0

#include <OpenSpaceToolkit/Physics/Coordinate/Axes.hpp>

inline void OpenSpaceToolkitPhysicsPy_Coordinate_Axes(pybind11::module& aModule)
{
    using namespace pybind11;

    using ostk::core::type::Shared;

    using ostk::mathematics::object::Vector3d;

    using ostk::physics::coordinate::Axes;
    using ostk::physics::coordinate::Frame;

    class_<Axes>(aModule, "Axes",
        R"doc(
        Axes in a frame of reference.

        )doc"
    )

        .def(
            init<const Vector3d&, const Vector3d&, const Vector3d&, const Shared<const Frame>&>(),
            arg("x_axis"),
            arg("y_axis"),
            arg("z_axis"),
            arg("frame"),
            R"doc(
            Constructs axes in a frame of reference.

            Args:
                x_axis [Vector3d]: X-axis.
                y_axis [Vector3d]: Y-axis.
                z_axis [Vector3d]: Z-axis.
                frame [Frame]: Frame of reference.

            )doc"
        )

        .def(self == self,
            R"doc(
            Equality operator.

            Args:
                other (Axes): Other Axes.

            Returns:
                bool: True if equal.
            )doc"
        )
        .def(self != self,
            R"doc(
            Inequality operator.

            Args:
                other (Axes): Other Axes.

            Returns:
                bool: True if not equal.
            )doc"
        )

        .def("__str__", &(shiftToString<Axes>))
        .def("__repr__", &(shiftToString<Axes>))

        .def("is_defined", &Axes::isDefined,
            R"doc(
            Check if defined.

            Returns:
                bool: True if defined.
            )doc"
        )

        .def(
            "x",
            +[](const Axes& anAxes) -> Vector3d
            {
                return anAxes.x();
            },
            R"doc(
                Get the X-axis.

            Returns:
                Vector3d: X-axis.
            )doc"
        )
        .def(
            "y",
            +[](const Axes& anAxes) -> Vector3d
            {
                return anAxes.y();
            },
            R"doc(
                Get the Y-axis.

            Returns:
                Vector3d: Y-axis.

            )doc"
        )
        .def(
            "z",
            +[](const Axes& anAxes) -> Vector3d
            {
                return anAxes.z();
            },
            R"doc(
                Get the Z-axis.

            Returns:
                Vector3d: Z-axis.

            )doc"
        )
        .def("get_frame", &Axes::getFrame,
            R"doc(
            Get the frame of reference.

            Returns:
                Frame: Frame of reference.
            )doc"
        )
        .def("in_frame", &Axes::inFrame, arg("frame"), arg("instant"),
            R"doc(
            Get the axes in another frame of reference.

            Args:
                frame (Frame): Frame of reference.
                instant (Instant): Instant.

            Returns:
                Axes: Axes in the other frame of reference.
            )doc"
        )

        .def_static("undefined", &Axes::Undefined,
            R"doc(
            Get undefined axes.

            Returns:
                Axes: Undefined axes.
            )doc"
        )

        ;
}
