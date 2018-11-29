#pragma once

#include <math.h>
#include <vector>

using namespace std;


//a simple template point
template<typename T>
class Point {
public:
typedef vector<Point<T>> Polygon; 
    Point(const T, const T);
    ~Point();
    const T distance(const Point<T>&) const;
    const bool in_poly(const Polygon&) const;
    T x;
    T y;
};

template<typename T>
Point<T>::Point(const T _x, const T _y)
    : x(_x), y(_y)
{}

template<typename T>
Point<T>::~Point()
{}

template<typename T>
const T Point<T>::distance(const Point<T>& end) const
{
    return sqrt(pow(x - end.x, 2) + pow(y - end.y, 2));
}

//is the point in the polygon?
template<typename T>
const bool Point<T>::in_poly(const Polygon& polygon) const
{
  int i, j, nvert = polygon.size();
  bool c = false;

  for(i = 0, j = nvert - 1; i < nvert; j = i++) {
    if( ( (polygon[i].y >= y ) != (polygon[j].y >= y) ) &&
        (x <= (polygon[j].x - polygon[i].x) * (y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)
      )
      c = !c;
  }

  return c;
}