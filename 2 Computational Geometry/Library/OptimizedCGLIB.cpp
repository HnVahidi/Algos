#include<bits/stdc++.h>

using namespace std;


//////////////   GEOMETRY LIBRARY   \\\\\\\\\\\\\\\

const double PI=3.141592653589793238;//18 raqam
const double EPS=1e-10;
#define point complex<double>
#define X real()
#define Y imag()
#define pooyaAreIntersect LineIntersection
double Dot(const point &a, const point &b) { return real(conj(a) * b); }
double Cross(const point &a, const point &b) { return imag(conj(a) * b); }
double Determinant(const point &a, const point &b){return a.X*b.Y-a.Y*b.X;}
point LineIntersection(const point &a, const point &b, const point &p, const point &q)
{
	double d1 = Cross(p - a, b - a);
	double d2 = Cross(q - a, b - a);
	return (d1 * q - d2 * p) / (d1 - d2);
}

double TriangleArea(point a, point b, point c)
{return abs(Cross(b-a, c-a))/2.;}
double RAD_to_DEG(double rad)
{return rad*180./PI;}
double DEG_to_RAD(double theta)
{return theta*PI/180;}
point Rotate(point p, double theta)//theta is degree
{
  
  //rotation matrixR(theta) = [cos(theta) - sin(theta)]
  //                          [sin(theta) + cos(theta)]
  //usage: [x'] = R(theta)* [x]
  //       [y']             [y]
  double rad=DEG_to_RAD(theta);
  return point(p.X * cos(rad) - p.Y * sin(rad) ,
	       p.X * sin(rad) + p.Y * cos(rad)  );
}

/////////////////  END OF LIBRARY   \\\\\\\\\\\\\\\\\

int main()
{

  return 0;
}
