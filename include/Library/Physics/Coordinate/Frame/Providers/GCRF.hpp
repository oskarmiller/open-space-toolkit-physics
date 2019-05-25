////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library ▸ Physics
/// @file           Library/Physics/Coordinate/Frame/Providers/GCRF.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Physics_Coordinate_Frame_Providers_GCRF__
#define __Library_Physics_Coordinate_Frame_Providers_GCRF__

#include <Library/Physics/Coordinate/Transform.hpp>
#include <Library/Physics/Coordinate/Frame/Provider.hpp>
#include <Library/Physics/Time/Instant.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace physics
{
namespace coord
{
namespace frame
{
namespace provider
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::physics::time::Instant ;
using library::physics::coord::frame::Provider ;
using library::physics::coord::Transform ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Geocentric Celestial Reference Frame (GCRF) provider
///
/// @ref                        https://en.wikipedia.org/wiki/Earth-centered_inertial

class GCRF : public Provider
{

    public:

                                GCRF                                        ( ) ;

        virtual                 ~GCRF                                       ( ) override ;

        virtual GCRF*           clone                                       ( ) const override ;

        virtual bool            isDefined                                   ( ) const override ;

        virtual Transform       getTransformAt                              (   const   Instant&                    anInstant                                   ) const override ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
