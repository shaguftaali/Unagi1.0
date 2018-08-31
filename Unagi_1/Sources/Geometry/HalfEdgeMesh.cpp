#include "..\..\Includes\Geometry\HalfEdgeMesh.h"
#include "..\..\Includes/Geometry/HalfEdge.h"
#include "..\..\Includes/Geometry/Vertex.h"
#include <map>
#include "../../Includes/Geometry/TypeDef.h"
#include <iostream>
#include <set>

using namespace std;

/*
 * const vector<vector<Index>>& polygons represents two dimensional array
 * in simple lagnguage it represent's list of faces
 * each vector<Index> represent's one face with its vertices list
 */

void Geometry::HalfEdgeMesh::build(const vector<vector<Index>>& polygons, const vector<Vector3>& vertexPositions)
{


    typedef vector<Index>                   IndexList;
    typedef IndexList::const_iterator       IndexListCIter;
    typedef vector<IndexList>               FaceList;
    typedef FaceList::const_iterator        FaceListCIter;
    typedef pair<Index, Index>              IndexPair;         // ordered pair of vertex indices, corresponding to an edge

     // Clear any existing elements.
    halfEdges.clear();
    vertices.clear();
    edges.clear();
    faces.clear();
    bounderies.clear();

    map<Index, VertexIter> indexToVertex;           // maps a vertex index to the corresponding vertex

    //number of vertices used in a face
    map<VertexIter, Size> vertexDegree;

    for (FaceListCIter f=polygons.begin();f!=polygons.end();f++)
    {
        if(f->size()<3)
        {
            /*
             * minimum 3 vertices are required to form a face of a manifold geometry
             * so if number of vertices in a face is less than 3 throw an exception
             */
            std::cerr << "Error converting polygons to halfedge mesh: each polygon must have at least three vertices." << endl;
            exit(1);
        }

        //set of indices of a
        set<Index> faceIndicesSet;

        //iteration for each faces
        for(IndexListCIter i=f->begin();i!=f->end();i++)
        {
            faceIndicesSet.insert(*i);

            if(indexToVertex.find(*i)==indexToVertex.end())
            {
                VertexIter v = newVertex();
                v->halfEdge() = halfEdges.end();
                indexToVertex[*i] = v;
                vertexDegree[v] = 1;
            }
            else
            {
                vertexDegree[indexToVertex[*i]]++;
            }

        }

        Size degree = f->size();            //number of vertices in a face
        if(faceIndicesSet.size()<degree)
        {
            cerr << "Error converting polygons to halfedge mesh: one of the input polygons does not have distinct vertices!" << endl;
            cerr << "(vertex indices:";
            for (IndexListCIter i = p->begin(); i != p->end(); i++)
            {
                cerr << " " << *i;
            }
            cerr << ")" << endl;
            exit(1);
        }

       

    }

        Size nVertices = indexToVertex.size();

        Size nFaces = polygons.size();
        faces.resize(nFaces);


        map<IndexPair, HalfEdgeIter> pairToHalfEdge;

        //building half edge connectivity for face
        FaceListCIter faceListCIter;
        FaceIter faceIter;

        for (faceListCIter=polygons.begin(),faceIter=faces.begin();faceListCIter!=polygons.end();faceListCIter++,faceIter++)
        {
            vector<HalfEdgeIter> faceHalfEdges;
            Size degree = faceListCIter->size();

            for(Index i=0;i<degree;i++)
            {
                Index a = (*faceListCIter)[i];
                Index b = (*faceListCIter)[(i + 1) % degree];
                IndexPair ab(a, b);
                HalfEdgeIter hab;

                if(pairToHalfEdge.find(ab)!=pairToHalfEdge.end())
                {
                    //TODO
                    exit(1);
                }
                else
                {
                    hab = newHalfEdge();
                    pairToHalfEdge[ab] = hab;

                    hab->face() = faceIter;
                    hab->face()->halfEdge() = hab;

                    hab->vertex() = indexToVertex[a];
                    hab->vertex()->halfedge() = hab;

                    faceHalfEdges.push_back(hab);
                }

                IndexPair ba(b, a);
                map<IndexPair, HalfEdgeIter>::iterator iba = pairToHalfEdge.find(ba);
                if(iba!=pairToHalfEdge.end())
                {
                    HalfEdgeIter hba = iba->second;

                    hab->twin() = hba;
                    hba->twin() = hab;


                    EdgeIter e = newEdge();
                    hab->edge() = e;
                    hba->edge() = e;
                    e->halfEdge() = hab;
                }
                else
                {
                    hab->twin() = halfEdges.end();
                }
            }

            // Now that all the halfedges of this face have been allocated,
            // we can link them together via their "next" pointers.
            for (Index i=0;i<degree;i++)
            {
                Index j = (i + 1) % degree;
                faceHalfEdges[i]->next() = faceHalfEdges[j];
            }
        }

        Index faceIndex = 0;
    for (FaceIter f=facesBegin();f!=facesEnd();f++,faceIndex++)
    {
        if(!f->isBoundary())
        {
            f->id = faceIndex;
        }
    }

    for(VertexIter v=vertices.begin();v!=vertices.end();v++)
    {
        if(v->halfedge()==halfEdges.end())
        {
            cerr << "Error converting polygons to halfedge mesh: some vertices are not referenced by any polygon." << endl;
            exit(1);
        }

        Size count = 0;
        HalfEdgeIter h = v->halfedge();
        do
        {
            if(!h->face()->sBoundary())
            {
                count++;
            }
            h = h->twin()->next();

        } while (h != v->halfedge());

        if(count!=vertexDegree[v])
        {
            cerr << "Error converting polygons to halfedge mesh: at least one of the vertices is nonmanifold." << endl;
            exit(1);
        }
    }

    if(vertexPositions.size()!=vertices.size())
    {
        //TODO
        exit(1);
    }

    int i = 0;
    for (map<Index,VertexIter>::const_iterator e=indexToVertex.begin();e!=indexToVertex.end();e++)
    {
        VertexIter v = e->second;

        v->position = vertexPositions[i];
        v->id = e->first;
        i++;
    }

    unsigned int edgeId = 0;
    for(auto e=edgesBegin();e!=edgesEnd();e++)
    {
        e->id = edgeId;
        edgeId++;
    }
}

VertexIter Geometry::HalfEdgeMesh::newVertex()
{
    return vertices.insert(vertices.end(),Vertex());
}

FaceIter Geometry::HalfEdgeMesh::facesBegin()
{
    return faces.begin();
}

FaceIter Geometry::HalfEdgeMesh::facesEnd()
{
    return faces.end();
}
