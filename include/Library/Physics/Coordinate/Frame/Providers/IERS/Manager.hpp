////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           Library/Physics/Coordinate/Frame/Providers/IERS/Manager.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Physics_Coordinate_Frame_Providers_IERS_Manager__
#define __Library_Physics_Coordinate_Frame_Providers_IERS_Manager__

#include <Library/Physics/Coordinate/Frame/Providers/IERS/BulletinA.hpp>
#include <Library/Physics/Time/Instant.hpp>

#include <Library/Core/Containers/Array.hpp>
#include <Library/Core/Types/Index.hpp>

#include <mutex>

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
namespace iers
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::Index ;
using library::core::ctnr::Array ;

using library::physics::time::Instant ;
using library::physics::coord::frame::provider::iers::BulletinA ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      IERS bulletins manager (thread-safe)

class Manager
{

    public:

                                Manager                                     ( ) ;

        const BulletinA&        accessBulletinAAt                           (   const   Instant&                    anInstant                                   ) const ;

        void                    addBulletinA                                (   const   BulletinA&                  aBulletinA                                  ) ;

    private:

        Array<BulletinA>        aBulletins_ ;
        
        mutable std::mutex      mutex_ ;

        mutable Index           aBulletinIndex_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////