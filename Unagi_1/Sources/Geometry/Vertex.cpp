#include "Vertex.h"

bool Geometry::Vertex::isBoundary(void) const
{
    return false;
}

Size Geometry::Vertex::degree(void) const
{
    Size d = 0;

    HalfEdgeIter h = _halfEdge;

    do
    {
        if(!h->face()->isBoundary())
        {
            d++;
        }
        h = h->twin()->next();
    } while (h != _halfEdge);
    return d;
}
