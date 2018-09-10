#pragma once
#include <stdexcept>
#include <vector>
#include "../Maths/Vector3.h"
#include <list>

#include "Vertex.h"

using namespace std;




namespace  Geometry
{
    class HalfEdgeMesh
    {
    public:
        HalfEdgeMesh(){}

   //     const HalfEdgeMesh& operator=(const HalfEdgeMesh& mesh);

        HalfEdgeMesh(const HalfEdgeMesh& mesh);

        void build(
            const vector<vector<Index>>& polygons,
            const vector<Vector3>& vertexPositions
        );

        void GetIndexArray(vector<Index>& indices);

        Size nHalfEdge() const
        {
            return halfEdges.size();
        }

        Size nVertices() const
        {
            return vertices.size();
        }

        Size nEdges() const
        {
            return edges.size();
        }

        Size nFaces() const
        {
            return faces.size();
        }

        Size nBoundaries() const
        {
            return bounderies.size();
        }

        VertexIter          newVertex() { return vertices.insert(vertices.end(), Vertex()); }
        HalfEdgeIter        newHalfEdge(){ return  halfEdges.insert(halfEdges.end(), HalfEdge()); }
        EdgeIter            newEdge() { return edges.insert(edges.end(), Edge()); }


        HalfEdgeIter        halfEdgesBegin() { return halfEdges.begin(); }
        HalfEdgeIter        halfEdgesEnd() { return  halfEdges.end(); }
        VertexIter          verticesBegin() { return vertices.begin(); }
        VertexIter          verticesEnd() { return  vertices.end(); }
        EdgeIter            edgesBegin() { return  edges.begin(); }
        EdgeIter            edgesEnd() { return  edges.end(); }
        FaceIter            facesBegin() { return faces.begin(); }
        FaceIter            facesEnd() { return faces.end(); }
        FaceIter            boudariesBegin() { return  bounderies.begin(); }
        FaceIter            boudariesEnd() { return  bounderies.end(); }


    protected:
        list<HalfEdge>  halfEdges;
        list<Vertex>    vertices;
        list<Edge>      edges;
        list<Face>      faces;
        list<Face>      bounderies;

    };
}