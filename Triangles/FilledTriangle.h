/**
 * \file FilledTriangle.h
 *
 * \author 
 *
 * Class for a triangle drawn as a filled triangle.
 */

#pragma once
#include "Triangle.h"

class CTriangleMesh;
/**
 * Class for a triangle drawn as a filled triangle.
 */
class CFilledTriangle : public CTriangle
{
public:
    CFilledTriangle(std::shared_ptr<CVertex> v1, std::shared_ptr<CVertex> v2, std::shared_ptr<CVertex> v3, Gdiplus::Color color);
    ~CFilledTriangle() {};
    virtual void Draw(Gdiplus::Graphics* graphics);
};

