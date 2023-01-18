/**
 * \file FilledTriangle.cpp
 *
 * \author 
 */

#include "pch.h"
#include "FilledTriangle.h"
#include "Vertex.h"

using namespace std;
using namespace Gdiplus;


CFilledTriangle::CFilledTriangle(std::shared_ptr<CVertex> v1, std::shared_ptr<CVertex> v2, std::shared_ptr<CVertex> v3, Gdiplus::Color color)
{
    CTriangle::SetV1(v1);
    CTriangle::SetV2(v2);
    CTriangle::SetV3(v3);
    CTriangle::SetColor(color);
}

void CFilledTriangle::Draw(Gdiplus::Graphics* graphics)
{
    SolidBrush brush(GetColor());
    auto v1 = CTriangle::GetV1();
    auto v2 = CTriangle::GetV2();
    auto v3 = CTriangle::GetV3();
    Point points[3];
    points[0] = Point(v1->GetX(), v1->GetY());
    points[1] = Point(v2->GetX(), v2->GetY());
    points[2] = Point(v3->GetX(), v3->GetY());

    graphics->FillPolygon(&brush, points, 3);
}
