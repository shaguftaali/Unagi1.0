#include "../../Includes/Geometry/HalfEdge.h"
#include "../../Includes/Geometry/Edge.h"


namespace  Geometry
{

    bool Edge::isBoundary()
    {
        return false;
    }

    double Edge::length()
    {
        Vector3 p0 = halfEdge()->vertex()->position;
        Vector3 p1 = halfEdge()->vertex()->position;

        return Vector3::Distance(p0, p1);

    }
}
