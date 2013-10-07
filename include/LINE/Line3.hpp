/*
 * File:   Line3.hpp
 * Author: JoPe
 *
 * Created on 6 de octubre de 2013, 16:02
 */

#ifndef LINE3_HPP
#define	LINE3_HPP

#include "VEC/Vector3.hpp"

namespace line
{
    struct Line3
    {
        vec::Vector3 m_origin;
        vec::Vector3 m_direction;   // Should always be normalized

        vec::Vector3 DistanceToPoint( vec::Vector3 const& i_point ) const;
        vec::Vector3 Normal( vec::Vector3 const& i_point ) const;
    };

    vec::Vector3 DistanceToPoint( Line3 const& i_line, vec::Vector3 const& i_point );
    vec::Vector3 Normal( Line3 const& i_line, vec::Vector3 const& i_point );
}

#endif	/* LINE3_HPP */

