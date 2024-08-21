
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


class Point
{
private:
    int x;
    int y;

public:

    //CONSTRUCTORS
    Point() {}
    Point(int a, int b)
    {
        x=a;
        y=b;
    }

    //SETTER FUNCTION
    void set(int a, int b)
    {
        x=a;
        y=b;
    }

    //RETURN A POINTER TO AN ARRAY WHICH CONTAINS THE POINT VALUE
    int* get_values()
    {
        int *a;
        a = new int[2];

        a[0]=x;
        a[1]=y;

        return a;
    }



//    int get_x()
//    {
//        return x;
//    }
//
//    int get_y()
//    {
//        return y;
//    }

    void print()
    {
        cout<< "Coordinate: "<< x <<", " <<y <<endl;
    }

};




class Circle
{
private:
    Point p;
    int radius;

public:
    Circle(int x,int y,int r)
    {
        p.set(x,y);
        radius=r;
    }

    int get_radius()
    {
        return radius;
    }

    void print()
    {
        cout << "Center ";
        p.print();
        cout << "Radius: " << radius << endl;
    }


    //OVERLOADED UPDATE FUNCTIONS

    //FOR RADIUS INCREASE
    void update(int r1)
    {
        radius+= r1;
    }

    //FOR CENTER INCREASE
    void update( int x1,int y1)
    {
        int *center;
        center = p.get_values();
        *center+=x1;
        *(center+1)+=y1;
        p.set(center[0],center[1]);
    }

    //FOR RADIUS AND CENTER BOTH INCREASE
    void update( int x1,int y1, int r1)
    {
        int *center;
        center = p.get_values();
        *center+=x1;
        *(center+1)+=y1;
        p.set(center[0],center[1]);
        radius+=r1;
    }

};


class Line
{
private:
    Point p1,p2;

public:

    //INITIALIZES THE TWO POINTS
    Line(int a1, int b1, int a2, int b2)
    {
        p1.set(a1,b1);
        p2.set(a2,b2);
    }

    // TO DETERMINE LINE LENGTH
    float find_length()
    {
        int *point1, *point2;
        point1 = p1.get_values();
        point2 = p2.get_values();

        float result = sqrt(pow((point1[0]-point2[0]),2) + pow((point1[1]-point2[1]),2));
        return result;
    }

};

int main()
{
    Point p(5,5);
    Circle c(2, 3, 5);
    Line l(7,4,3,1);

    cout << endl << "Point Display" <<endl;
    p.print();
    cout << endl<< "Circle Display" <<endl;
    c.print();
    cout << endl;

    cout << "First Update" << endl;
    c.update(5,5);
    c.print();
    cout <<endl;

    cout << "Second Update" << endl;
    c.update(6);
    c.print();
    cout << endl;

    cout<< "Third Update" << endl;
    c.update(2,2,2);
    c.print();
    cout << endl;

    cout<<"Line length is "<<l.find_length()<<endl;
    return 0;
}
