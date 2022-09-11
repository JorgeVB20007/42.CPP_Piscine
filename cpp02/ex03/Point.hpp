#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point &tocopy);
		Point(const Point &tocopy);
		Point(const float x, const float y);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
		Point & operator = (Point const &toequalize);
	private:
		Fixed const x;
		Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif