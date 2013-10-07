/*
 * File:   Line3.cpp
 * Author: JoPe
 *
 * Created on 6 de octubre de 2013, 16:02
 */

#include "LINE/Line3.hpp"

namespace line
{
    vec::Vector3 Line3::DistanceToPoint( vec::Vector3 const& i_point ) const
    {
        //{distance}({x} = {a} + t{n}, {p}) = ({a}-{p}) - ( ({a}-{p})dot{n} ){n}
        vec::Vector3 const pointToLineOrigin ( vec::Subtract( m_origin, i_point ) );
        vec::Vector3 const projectionAlongLineDirection ( vec::Scale( m_direction, vec::DotProduct( pointToLineOrigin, m_direction ) ) );
        return vec::Subtract( pointToLineOrigin, projectionAlongLineDirection );
    }

    vec::Vector3 Line3::Normal( vec::Vector3 const& i_vector ) const
    {
        vec::Vector3 const normalToLineVector ( vec::CrossProduct( m_direction, i_vector ) );
        vec::Vector3 const normalToLineNormal ( vec::Normalize( vec::CrossProduct( m_direction, normalToLineVector ) ) );

        return normalToLineNormal;
    }

    vec::Vector3 DistanceToPoint( Line3 const& i_line, vec::Vector3 const& i_point )
    {
        return i_line.DistanceToPoint( i_point );
    }

    vec::Vector3 Normal( Line3 const& i_line, vec::Vector3 const& i_vector )
    {
        return i_line.Normal( i_vector );
    }
}