#pragma once
#include "HalfEdgeElement.h"
#include "../Maths/Vector3.h"



namespace  Geometry
{
    class  Edge:public HalfEdgeElement
    {
    public:
        HalfEdgeIter& halfEdge(){  return _halfEdge;    }

        HalfEdgeCIter  halfedge() const { return _halfEdge; }

        bool isBoundary();

        double length();
       

        unsigned int id;
        Vector3 newPosition;
        bool isNew;



    protected:
        HalfEdgeIter _halfEdge;
    };
}
