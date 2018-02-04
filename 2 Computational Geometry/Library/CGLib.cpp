#include<iostream>
#include<cmath>


using namespace std;
const double EPS=1e-9;
const double PI=3.141592653589793238;//18 ragham
// PI= acos(-1) OR PI= 2*acos(0)

bool Equal(double d1,double d2)
{ return fabs(d1-d2)<EPS;}

struct line{double a,b,c;};
struct vec
{
  double x,y;
  vec(double _x=0,double _y=0)
  {x=_x;  y=_y;}
};
  
struct point_i
{
  int x,y;
  point_i(int _x=0,int _y=0){x=_x;y=_y;}
};
struct point
{
  double x,y;
  point(double _x=0,double _y=0){x=_x;y=_y;}
  bool operator < (point other)
  {  
    if(fabs(x-other.x)<EPS)
      return y<other.y;
    return x<other.x;}
  bool operator == (point other)
  {return (fabs(x-other.x)<EPS) && (fabs(y-other.y)<EPS) ;}
  
  
};
double Hypot(double dx,double dy)
{
  return sqrt(dx*dx+dy*dy);
}
double DistancePoint(point p1,point p2)
{
  return hypot(p1.x-p2.x,p1.y-p2.y);
}
double DEG_to_RAD(double theta)
{
  return theta*PI/180;
}
double RAD_to_DEG(double rad)
{
  return rad*180/PI;
}
point rotate(point p, double theta)//theta is degree
{
  
  //rotation matrixR(theta) = [cos(theta) - sin(theta)]
  //                          [sin(theta) + cos(theta)]
  //usage: [x'] = R(theta)* [x]
  //       [y']             [y]
  double rad=DEG_to_RAD(theta);
  return point(p.x * cos(rad) - p.y * sin(rad) ,
	       p.x * sin(rad) + p.y * cos(rad)  );
}
void PointsToLine(point p1,point p2,line *l)
{
  if(p1.x==p2.x) // vertical line handled here
    { l->a=1.0;   l->b= 0.0 ; l->c=-p1.x;}
  else
    {
      l->a=-(double)(p1.y-p2.y)/(p1.x-p2.x);
      l->b=1.0;
      l->c=-(double)(l->a * p1.x) - (l->b*p1.y);
    }
}
bool AreParallel(line l1,line l2)
{
  if(Equal(l2.b,0) && !Equal(l1.b,0))return false;
  if(Equal(l1.b,0) && !Equal(l2.b,0))return false;
  if(Equal(l2.a,0) && !Equal(l1.a,0))return false;
  if(Equal(l1.a,0) && !Equal(l2.a,0))return false;
  return Equal(l1.a*l2.b,l1.b*l2.a);
}
bool AreSame(line l1,line l2)
{
  if(!AreParallel(l1,l2))return false;
  if(Equal(l2.c,0) && !Equal(l1.c,0))return false;
  if(Equal(l1.c,0) && !Equal(l2.c,0))return false;
  double ratio=0;
  if(Equal(l2.b,0)==false)
    ratio=l1.b/l2.b;
  if(Equal(l2.a,0)==false)
    ratio=l1.a/l2.a;
  return Equal(l1.c/l2.c,ratio);
}
bool AreIntersect(line l1,line l2,point *p)//TO BE CHECKED (mine)
{
  if(AreSame(l1,l2))
    return false;
  if(AreParallel(l1,l2))
    return false;

  //solving
  double delta=(double)l1.a*l2.b - l1.b*l2.a;
  if(Equal(delta,0))//this if should never be true because lines are't parallel
    return false;
  //a1x+b1y=-c1
  //a2x+b2y=-c2
  p->x= (double)(-l1.c*l2.b+l2.c*l1.b) / delta;
  p->y= (double)(-l1.a*l2.c+l2.a*l1.c) / delta;
  return true;
}
vec ToVector(point p1,point p2)
{
  return vec(p2.x-p1.x,p2.y-p1.y);
}
vec ScaleVector(vec v, double s) // v*=s
{
  return vec(v.x*s,v.y*s);
}
point Translate(point p,vec move)//moves point p in direction of vector move
{
  return point(p.x+move.x , p.y + move.y);
}
double Dot(double x1,double y1 ,double x2,double y2)
{ return x1*x2+y1*y2;};
double Determinant(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;};

//angle A<BC (radian (PI) )
double Angle(point A,point B,point C)
{
  double dot=Dot(B.x-A.x,B.y-A.y,B.x-C.x,B.y-C.y);
  double det=Determinant(B.x-A.x,B.y-A.y,B.x-C.x,B.y-C.y);
  //atan2(y,x), or atan2(sin,cos)
  return atan2(det,dot);
}
double Cross(point p,point q,point r)
{
  return (r.x-q.x)*(p.y-q.y)-(r.y-q.y)*(p.x-q.x);
}
bool Collinear(point p,point q,point r)
{
  return Equal(Cross(p,q,r),0);
}
//returns true if point r is on the left side of line pq
bool CCW(point p,point q,point r)
{
   //can be modified to accept collinear ( >0 instead of >EPS )
  if(Cross(p,q,r) > EPS)
    return true;
  return false;
}

//returns the distance from p to line AB
// A and B must be different
//closest point is in *c
double DistToLine(point p,point A,point B,point *c)
{// formula : c= A+ (p-A).(A-B)/|B-A|*(B-A)
  double scale= (double)
    ((p.x-A.x)*(B.x-A.x)+(p.y-A.y)*(B.y-A.y))/
    ((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
  c->x= A.x + scale*(B.x - A.x);
  c->y= A.y + scale*(B.y - A.y);
  
  return DistancePoint(p,*c);
}
double DistToLineSegment(point p,point A,point B,point *c)
{
  if((B.x-A.x) * (p.x-A.x)+ (B.y-A.y)*(p.y-A.y) <EPS)
    { c->x=A.x ; c->y= A.y;
      return DistancePoint(p,A);}//closer to A
 
  if((A.x-B.x) * (p.x-B.x)+ (A.y-B.y)*(p.y-B.y) <EPS)
    { c->x=B.x ; c->y= B.y;
      return DistancePoint(p,B);}//closer to B

  return DistToLine(p,A,B,c);
  
}
//returns true if p is on segment AB
bool IsOnLineSegment(point p,point A,point B)
{
   if(Collinear(p,A,B)==false)
    return false;
  if(p==A || p==B)
    return true;
  double angle=Angle(A,p,B);
  if(Equal ( DistancePoint(p,A)+DistancePoint(p,B) , DistancePoint(A,B) ) )
    return true;
  if(Equal( angle, PI ) || Equal(angle,-PI) ||  Equal(RAD_to_DEG(angle),180) )
    return true;
  return false;
}
bool AreSegmentsIntersect(point A,point B,point C,point D,point *p)
{
  line l1,l2;
  PointsToLine(A,B,&l1);
  PointsToLine(C,D,&l2);
  if(AreSame(l1,l2))
    {  int cnt=0;
      if(IsOnLineSegment(A,C,D))cnt++;
      if(IsOnLineSegment(B,C,D))cnt++;
      if(IsOnLineSegment(C,A,B))cnt++;
      if(IsOnLineSegment(D,A,B))cnt++;
      if(cnt!=2)
	return false;
      if(A==C || A==D){
	p->x=A.x;
	p->y=A.y;
	return true;}
      if(B==C || B==D){
	p->x=B.x;
	p->y=B.y;
	return true;}
      return false;
    }
  if(AreIntersect(l1,l2,p))
    {
      if(IsOnLineSegment(*p,A,B) && IsOnLineSegment(*p,C,D))
	return true;
      return false;
    }
  return false;
}
bool SegmentRangeIntersection(point A,point B,point C,point D)
{
    line l1,l2;
  PointsToLine(A,B,&l1);
  PointsToLine(C,D,&l2);
  if(AreSame(l1,l2)==false)
    return false;
      int cnt=0;
      if(IsOnLineSegment(A,C,D))cnt++;
      if(IsOnLineSegment(B,C,D))cnt++;
      if(IsOnLineSegment(C,A,B))cnt++;
      if(IsOnLineSegment(D,A,B))cnt++;
      if(cnt)
	return true;//special case : one point
  return false;
}

/////--Circle--/////
/*
1. PI= acos(-1)
 */
struct circle
{
  point center;
  double r;
  circle(double x, double y,double _r)
  {center=point(x,y);r=_r;};
};
int InOnOutCircle(point p,point center , double radius)
{//In = -1 , On = 0 , Out=1
  double  Euc=Hypot(center.x-p.x,center.y-p.y);
  double rSq=radius;
  if(Equal(Euc,rSq))
    return 0;
  else if(Euc>rSq+EPS)
    return 1;
  else
    return -1;
}
double Arc(circle c,double deg)
{
  double perimeter=PI*2*c.r;
  return deg*(perimeter)/360;
}
double Chord(circle c,double deg)
{
  return 2*c.r*sin(deg/2);
}
double Sector(circle c, double deg)
{
  double area=PI*c.r*c.r;
  return deg*(area)/360;
}
void Segment()
{}
bool TwoPointToCircle(point p1,point p2,double r,point* c)
{//center at *c
  double d2=(p1.x-p2.x)*(p1.x-p2.x)+
            (p1.y-p2.y)*(p1.y-p2.y);
  double det=r*r/d2-0.25; // WTF ? :|
    if(det<0.0 + EPS)
      return false;
  double h=sqrt(det);
  c->x=(p1.x+p2.x)*0.5 + (p1.y-p2.y)*h;
  c->y=(p1.y+p2.y)*0.5 + (p2.x-p1.x)*h;
  return true;//to get the other circle ,reverse p1,p2
}

//A->center=B->center=R
double ThreePointToCircle(point A,point B,point C, point* center)
{
  if(Collinear(A,B,C)) return 0;
  //det|a1 b1|  detX|c1 b1|  detY|a1 c1|
  //   |a2 b2|      |c2 b2|      |a2 c2|
  double c1=(B.x*B.x+B.y*B.y) - (A.x*A.x+A.y*A.y);
  double c2=(C.x*C.x+C.y*C.y) - (A.x*A.x+A.y*A.y);
  double a1=2*(B.x-A.x) ; double a2=2*(C.x-A.x);
  double b1=2*(B.y-A.y) ; double b2=2*(C.y-A.y);
  double det=a1*b2-a2*b1;
  double detX=c1*b2-c2*b1;
  double detY=a1*c2-a2*c1;
  center->x=detX/det ;  center->y= detY/det;
  return hypot(A.x-center->x,A.y-center->y);
}
///*****************### End of Library ###*******************///








int main()
{
  point center;
  double r=ThreePointToCircle(point(2,1),point(0,5),point(-1,2),&center);
  cout<<center.x<<" "<<center.y<<endl;
  cout<<r<<endl;
  return 0;
}
