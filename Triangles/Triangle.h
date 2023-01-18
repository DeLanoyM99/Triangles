/**
 * \file Triangle.h
 *
 * \author 
 *
 * Abstraction of a triangle.
 */

#pragma once
#include "Vertex.h"
#include <memory>

class CTriangleMesh;
/**
 * Abstraction of a triangle.
 */
class CTriangle
{
public:
    CTriangle(std::shared_ptr<CVertex> v1 = nullptr, std::shared_ptr<CVertex> v2 = nullptr, std::shared_ptr<CVertex> v3 = nullptr, Gdiplus::Color color = (0,0,0));
    /** Copy constructor disabled */
    CTriangle(const CTriangle&) = delete;
    /** Assignment operator disabled */
    void operator=(const CTriangle&) = delete;
    ~CTriangle() {}
    virtual void Draw(Gdiplus::Graphics* graphics);
    void Remove();
    Gdiplus::Color GetColor() { return mColor; }
    void SetColor(Gdiplus::Color color) { mColor = color; }
    std::shared_ptr<CVertex> GetV1();
    std::shared_ptr<CVertex> GetV2();
    std::shared_ptr<CVertex> GetV3();
    void SetV1(std::shared_ptr<CVertex> v1) { mV1 = v1; }
    void SetV2(std::shared_ptr<CVertex> v2) { mV2 = v2; }
    void SetV3(std::shared_ptr<CVertex> v3) { mV3 = v3; }
    
private:
    Gdiplus::Color mColor;
    std::shared_ptr<CVertex> mV1;
    std::shared_ptr<CVertex> mV2;
    std::shared_ptr<CVertex> mV3;
 
};

