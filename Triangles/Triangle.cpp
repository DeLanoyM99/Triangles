/**
 * \file Triangle.cpp
 *
 * \author 
 */

#include "pch.h"
#include "Triangle.h"
#include <memory>

using namespace std;
using namespace Gdiplus;

CTriangle::CTriangle(std::shared_ptr<CVertex> v1, std::shared_ptr<CVertex> v2, std::shared_ptr<CVertex> v3, Gdiplus::Color color)
{
    mV1 = v1;
    mV2 = v2;
    mV3 = v3;
    mColor = color;
}

void CTriangle::Draw(Gdiplus::Graphics* graphics)
{
    Pen pen(mColor, 1);
    auto v1 = CTriangle::GetV1();
    auto v2 = CTriangle::GetV2();
    auto v3 = CTriangle::GetV3();
    graphics->DrawLine(&pen, v1->GetX(), v1->GetY(), v2->GetX(), v2->GetY());
    graphics->DrawLine(&pen, v2->GetX(), v2->GetY(), v3->GetX(), v3->GetY());
    graphics->DrawLine(&pen, v3->GetX(), v3->GetY(), v1->GetX(), v1->GetY());
}

void CTriangle::Remove()
{
    this->~CTriangle();
}

std::shared_ptr<CVertex> CTriangle::GetV1()
{
    return mV1;
}

std::shared_ptr<CVertex> CTriangle::GetV2()
{
    return mV2;
}

std::shared_ptr<CVertex> CTriangle::GetV3()
{
    return mV3;
}
