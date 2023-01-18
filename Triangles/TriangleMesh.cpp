/**
 * \file TriangleMesh.cpp
 *
 * \author 
 */

#include "pch.h"
#include "TriangleMesh.h"
#include "Vertex.h"
#include <memory>

using namespace std;
using namespace Gdiplus;

/**
 * Get the number of triangles in the mesh.
 * \return Number of triangles
 */
int CTriangleMesh::GetNumTriangles()
{ 
    int num = 0;
    for (auto triangles : mTriangles)
    {
        num = num + 1;
    }

    return num;
}


/**
 * Get one of the mesh triangles.
 * \param n Triangle index, 0 to number of triangles-1.
 * \returns Triangle object.
 */
std::shared_ptr<CTriangle> CTriangleMesh::GetTriangle(int n)
{
    auto triangle = mTriangles[n];
    return triangle;
}





/**
 * Draw the triangle mesh.
 * \param graphics GDI+ graphics object to draw on.
 */
void CTriangleMesh::Draw(Gdiplus::Graphics* graphics)
{
    for (auto triangles : mTriangles)
    {
        triangles->Draw(graphics);
    }
}

/**
 * Create a vertex.
 * \param x Vertex X location
 * \param y Vertex Y location
 * \return Added vertex object
 */
std::shared_ptr<CVertex> CTriangleMesh::AddVertex(int x, int y)
{
    auto vertex = make_shared<CVertex>(x,y);
    return vertex;
}


/**
 * Create a triangle.
 * \param v1 First vertex
 * \param v2 Second vertex
 * \param v3 Third vertex
 * \param color Color to draw the triangle
 * \return CTriangle object.
 */
std::shared_ptr<CTriangle> CTriangleMesh::AddTriangle(std::shared_ptr<CVertex> v1,
    std::shared_ptr<CVertex> v2,
    std::shared_ptr<CVertex> v3,
    Gdiplus::Color color)
{
    auto triangle = make_shared<CTriangle>(v1,v2,v3,color);
    mTriangles.push_back(triangle);
    return triangle;
}

/**
 * Create a filled triangle.
 * \param v1 First vertex
 * \param v2 Second vertex
 * \param v3 Third vertex
 * \param color Color to draw the triangle
 * \return CTriangle object.
 */
std::shared_ptr<CTriangle> CTriangleMesh::AddFilledTriangle(std::shared_ptr<CVertex> v1,
    std::shared_ptr<CVertex> v2,
    std::shared_ptr<CVertex> v3,
    Gdiplus::Color color)
{
    auto filledtriangle = make_shared<CFilledTriangle>(v1, v2, v3, color);
    mTriangles.push_back(filledtriangle);
    return filledtriangle;
}

