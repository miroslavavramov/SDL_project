#ifndef __Vector2D__
#define __Vector2D__
#include <math.h>

class Vector2D
{
public:

    Vector2D(){}
    Vector2D(float x, float y):m_x(x), m_y(y){}

    Vector2D& operator+(const Vector2D& v2) const
    { 
        Vector2D* v1 = new Vector2D(m_x + v2.m_x, m_y + v2.m_y);
        return *v1;
    }

    Vector2D& operator +=( const Vector2D& v2)
    {
        m_x += v2.m_x;
        m_y += v2.m_y;

        return *this;
    }

    inline Vector2D& operator *(float scalar)
    {
        Vector2D* v1 = new Vector2D(m_x * scalar, m_y * scalar);
        return *v1;
    }

    Vector2D& operator *=(float scalar)
    {
        m_x *= scalar;
        m_y *= scalar;

        return *this;
    }

    Vector2D& operator -(const Vector2D& v2) const
    {
        Vector2D* v1 = new Vector2D(m_x - v2.m_x, m_y - v2.m_y);
        return *v1;
    }

    Vector2D& operator -=( const Vector2D& v2)
    {
        m_x -= v2.m_x;
        m_x -= v2.m_x;

        return *this;
    }

    Vector2D& operator /(float scalar)
    {
        Vector2D* v1 = new Vector2D(m_x / scalar, m_y / scalar);
        return *v1;
    }

    Vector2D& operator /=(float scalar)
    {
        m_x /= scalar;
        m_y /= scalar;

        return *this;
    }

    void normalize()
    {
        float l = length();
        if(l>0)
        {
            (*this) *= 1/l;
        }
    }

    inline float getX(){ return m_x;}
    inline float getY(){ return m_y;}

    inline void setX(float x){m_x = x;}
    inline void setY(float y){m_y = y;}
    
    inline float length(){ return sqrt(m_x*m_x + m_y*m_y);}

private:
    float m_x;
    float m_y;
};
#endif
