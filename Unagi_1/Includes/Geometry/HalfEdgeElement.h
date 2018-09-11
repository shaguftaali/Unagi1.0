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

    inline bool operator<(const HalfEdgeIter& i, const HalfEdgeIter& j) {
        return &*i < &*j;
    }
    inline bool operator<(const VertexIter& i, const VertexIter& j) {
        return &*i < &*j;
    }
    inline bool operator<(const EdgeIter& i, const EdgeIter& j) {
        return &*i < &*j;
    }
    inline bool operator<(const FaceIter& i, const FaceIter& j) {
        return &*i < &*j;
    }


    // We also need to know how to compare const iterators.
    inline bool operator<(const HalfEdgeCIter& i, const HalfEdgeCIter& j) {
        return &*i < &*j;
    }
    inline bool operator<(const VertexCIter& i, const VertexCIter& j) {
        return &*i < &*j;
    }
    inline bool operator<(const EdgeCIter& i, const EdgeCIter& j) {
        return &*i < &*j;
    }
    inline bool operator<(const FaceCIter& i, const FaceCIter& j) {
        return &*i < &*j;
    }

    class HalfEdgeElement
    {
        
    public:
        HalfEdge * getHalfEdge();

        Vertex* getVertex();

        Edge* getEdge();

        Face* getFace();

        virtual ~HalfEdgeElement();

    protected:
        list<HalfEdge> halfEdge;
        list<Vertex> vertices;
        list<Edge> edges;
        list<Face> faces;
        list<Face> boundaries;
    };

}