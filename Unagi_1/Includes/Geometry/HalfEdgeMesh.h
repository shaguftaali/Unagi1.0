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
        HalfEdgeMesh();

        const HalfEdgeMesh& operator=(const HalfEdgeMesh& mesh);

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

        VertexIter          newVertex();
        HalfEdgeIter        newHalfEdge();
        EdgeIter            newEdge();


        HalfEdgeIter        halfEdgesBegin();
        HalfEdgeIter        halfEdgesEnd();
        VertexIter          verticesBegin();
        VertexIter          verticesEnd();
        EdgeIter            edgesBegin();
        EdgeIter            edgesEnd();
        FaceIter            facesBegin();
        FaceIter            facesEnd();
        FaceIter            boudariesBegin();
        FaceIter            boudariesEnd();


    protected:
        list<HalfEdge>  halfEdges;
        list<Vertex>    vertices;
        list<Edge>      edges;
        list<Face>      faces;
        list<Face>      bounderies;

    };
}