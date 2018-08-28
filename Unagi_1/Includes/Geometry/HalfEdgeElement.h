#pragma once
#include <stdexcept>
#include <list>

using namespace std;

namespace  Geometry
{
    class  Vertex;
    class  Edge;
    class  Face;
    class  HalfEdge;

    typedef list<Vertex>::iterator          VertexIter;
    typedef list<Edge>::iterator            EdgeIter;
    typedef list<Face>::iterator            FaceIter;
    typedef list<HalfEdge>::iterator        HalfEdgeIter;

    typedef list<Vertex>::const_iterator VertexCIter;
    typedef list<Edge>::const_iterator EdgeCIter;
    typedef list<Face>::const_iterator FaceCIter;
    typedef list<HalfEdge>::const_iterator HalfEdgeCIter;

    class HalfEdgeElement
    {
        
    };
}