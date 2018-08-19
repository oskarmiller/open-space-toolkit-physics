////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           Library/Physics/Coordinate/Frame/Providers/CIRF.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Physics_Coordinate_Frame_Providers_CIRF__
#define __Library_Physics_Coordinate_Frame_Providers_CIRF__

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

/// @brief                      Celestial Intermediate Reference Frame (CIRF) provider
///
///                             Bias, precession-nutation
///
/// @ref                        https://www.iers.org/SharedDocs/Publikationen/EN/IERS/Publications/tn/TechnNote36/tn36_174.pdf?__blob=publicationFile&v=1

class CIRF : public Provider
{

    public:

                                CIRF                                        ( ) ;

        virtual                 ~CIRF                                       ( ) override ;

        virtual CIRF*           clone                                       ( ) const override ;

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