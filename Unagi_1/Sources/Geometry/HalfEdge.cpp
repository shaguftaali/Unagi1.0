#include "HalfEdge.h"


namespace  Geometry
{

    bool HalfEdge::isBoundary() const
    {
        return false;
    }

    void HalfEdge::getPickPoints(Vector3 & a, Vector3 & b, Vector3 & p, Vector3 & q, Vector3 & r) const
    {
    }

    void HalfEdge::setNeighbours(HalfEdgeIter next, HalfEdgeIter twin, VertexIter vertex, EdgeIter edge, FaceIter face)
    {
        _next = next;
        _twin = twin;
        _vertex = vertex;
        _edge = edge;
        _face = face;   
    }
   
}
