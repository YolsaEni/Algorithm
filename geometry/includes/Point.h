#pragma once

#include "geometry_inner.h"
//#include "Edge.h"

namespace li {
    class Edge;
    enum {
        LEFT, RIGHT, BEYOND, BEHIND, BETWEEN, ORIGIN, DESTINATION
    };

    /*
     * Point may be extended to a polynomial, or a matrix, or any point in a vector space rather than just a point in a plane.
     * */
    class Point {
    public:
        double x;
        double y;

        Point(double _x = 0.0, double _y = 0.0);

        Point operator+(const Point &);

        Point operator-(const Point &);

        friend Point operator*(double, const Point &);

        double operator[](int);

        int operator==(Point &);

        int operator!=(Point &);

        // Operators < and > implement the lexicographic order relation
        int operator<(Point &);

        int operator>(Point &);

        int classify(Point &, Point &);

        int classify(Edge &);

        double polarAngle(void);

        double length(void) const;

        // Todo: p!=2
        double norm(int p=2) const;

        // This member function of class Point is passed an edge e, and it returns the
        // signed distance from this point to edge e. Here the distance from point p to
        // edge e equals the minimum distance from p to any point along the infinite line determined by e.
        // The signed distance is positive if p lies to the right of e, negative if p lies to the left of e, and zero if p is collinear with e.
        double distance(Edge &e);

        void log(int useEndl=0);

        WXJ_BOOL isZero() const;

        Point unit();

        Point normal();

        Point &rot(void);

        double dotProduct(const Point &p) const;

        //angle: [0, PI], normal vector angle in vector space
        double angle(const Point &p) const;

        //angle: [0, 2*PI).  angle from this to Point( 1, 0) in clockwise.
        double angleClockwise() const;

        // angle: [0, 2*PI).  angle from this to p in clockwise.
        double angleClockwise(const Point &p);
    };
}