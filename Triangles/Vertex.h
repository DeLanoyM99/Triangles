/**
 * \file Vertex.h
 *
 * \author 
 *
 * A vertex (point on the screen).
 */

#pragma once

class CTriangle;

/**
 * A vertex (point on the screen).
 */
class CVertex
{

public:
    CVertex(int x = 5, int y = 5);
    ~CVertex() {};
    int GetX() { return mX; }
    int GetY() { return mY; }

private:
    int mX;
    int mY;
};

