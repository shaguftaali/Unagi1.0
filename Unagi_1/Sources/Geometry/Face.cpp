#include "../../Includes/Geometry/Face.h"
#include "../../Includes/Scene/Scene.h"

//returns the number of edges (or equivalently, vertices) of this face
Size Geometry::Face::degree() const
{
    Size d = 0;
    HalfEdgeIter h = _halfEdfe;
    do
    {
        d++;
        h = h-> next();
    } while (h != _halfEdfe);
    
    return d;
}

bool Geometry::Face::isBoundary()
{
    return _isBoundary;
}

Vector3 Geometry::Face::normal() const
{
    Vector3 N;
    HalfEdgeCIter h = halfEdge();
    do
    {
        Vector3 p0 = h->vertex()->position;
        Vector3 p1 = h->next()->vertex()->position;

        N =N+ Vector3::CrossProduct(p0, p1);
        h = h->next();
    } while (h != halfEdge());
    return N.Normalization();
}

Vector3 Geometry::Face::centroid() const
{
    return Vector3();
}
