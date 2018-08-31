#pragma once
#include "HalfEdgeElement.h"
#include "HalfEdge.h"


namespace  Geometry
{
    class Face :public HalfEdgeElement
    {
    public:

        HalfEdgeIter & halfEdge() { return _halfEdfe; }

        HalfEdgeCIter halfEdge()const { return _halfEdfe; }

        Face(bool isBoundary=false):
        _isBoundary(isBoundary)
        {
            
        }

        Size degree() const;

        bool isBoundary();

        Vector3 normal() const;

        Vector3 centroid() const;

    protected:
        HalfEdgeIter _halfEdfe;
        bool _isBoundary;
        
    };
}
