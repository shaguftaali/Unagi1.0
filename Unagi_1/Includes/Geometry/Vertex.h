#pragma once
#include "HalfEdgeElement.h"
#include "TypeDef.h"
#include "../Maths/Matrix4.h"
#include "HalfEdge.h"


namespace Geometry
{
    class Vertex: public HalfEdgeElement
    {
    protected:
        HalfEdgeIter _halfEdge;
        //HalfEdgeIter
        //EdgeIter

    public:

        /**
        * returns halfedge rooted at this vertex (reference)
        */
        HalfEdgeIter& halfedge() { return _halfEdge; }

        /**
        * returns halfedge rooted at this vertex
        */
        HalfEdgeCIter halfedge() const { return _halfEdge; }

        Index id;
        Vector3 position;
        Vector3 color;
        Vector3 normal;

        const double offset = 0.001;

        Vector3 newPosition;
        bool isNew;

        bool isBoundary(void) const;

        Size degree(void) const;

        Matrix4 quardic;

    };

   

    
}
