#pragma once
#include "HalfEdgeElement.h"
#include "Edge.h"
#include "Vertex.h"
#include "Face.h"
#include "..\..\Includes/Maths/Vector3.h"



namespace  Geometry
{
    class HalfEdge: public HalfEdgeElement
    {
    public:
        HalfEdgeIter & twin()       { return _twin; }      ///< access the twin half edge
        HalfEdgeIter&   next()      { return _next; }      ///< access the next half edge
        VertexIter&     vertex()    { return _vertex; }    ///< access the vertex in the half edge
        EdgeIter&       edge()      { return _edge; }      ///< access the edge the half edge is on
        FaceIter&       face()      { return _face; }      ///< access the face the half edge is on

        HalfEdgeCIter   twin()   const { return _twin; }        ///< access the twin half edge (const iterator)
        HalfEdgeCIter   next()   const { return _next; }        ///< access the next half edge (comst iterator)
        VertexCIter     vertex() const { return _vertex; }      ///< access the vertex in the half edge (const iterator)
        EdgeCIter       edge()   const { return _edge; }        ///< access the edge the half edge is on (const iterator)
        FaceCIter       face()   const { return _face; }        ///< access the face the half edge is on (const iterator)

        bool isBoundary() const;

        void getPickPoints(Vector3& a, Vector3&b, Vector3& p, Vector3& q, Vector3& r) const;

        void setNeighbours(HalfEdgeIter next, HalfEdgeIter twin, VertexIter vertex, EdgeIter edge, FaceIter face);

    protected:
        HalfEdgeIter        _twin;
        HalfEdgeIter        _next;
        VertexIter          _vertex;
        EdgeIter            _edge;
        FaceIter            _face;

    };
}
