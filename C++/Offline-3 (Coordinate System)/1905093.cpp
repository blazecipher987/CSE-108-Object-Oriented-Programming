#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;

public:

    //CONSTRUCTORS
    Vector()
    {
        x=0;
        y=0;
        z=0;
    }

    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }

    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }

    //COPY CONSTRUCTOR
    Vector(const Vector &obj1)
    {
        //cout<<"                             Constructor called!!!"<<endl;
        this->setName(obj1.name);
        //cout<<endl<<obj1.getName()<<endl;
        this->x= obj1.x;
        this->y = obj1.y;
        this->z = obj1.z;
    }


    //SETTER FUNCTIONS
    int setX(int a)
    {
        x=a;
    }
    int setY(int b)
    {
        y=b;
    }
    int setZ(int c)
    {
        z=c;
    }
    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];

        if(!name)
            cout<<"Allocation error"<<endl;
        strcpy(name,n);
    }


    //GETTER FUNCTIONS
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getZ()
    {
        return z;
    }

    char *getName()
    {
        return name;
    }

    //DESTRUCTOR
    ~Vector()
    {
        //cout<<"                     DESTRUCTOR CALLED"<<endl;
        delete []name;
    }


    //PRINT FUNCTION
    void print()
    {
        cout<<getName()<<": "<<noshowpos<<x<<showpos<<"x"<<y<<"y"<<z<<"z"<<endl;
    }

    //RELATIONAL OPERATOR FUNCTION
    int operator==(Vector obj)
    {
        return (x==obj.x) && (y==obj.y) && (z==obj.z);
    }

    //CROSS PRODUCT
    Vector operator^(Vector obj)
    {
        Vector p;

        int temp_x = (y*obj.z) - (z*obj.y);
        int temp_y = (z*obj.x) - (x*obj.z);
        int temp_z = (x*obj.y) - (y*obj.x);

        p.setX(temp_x);
        p.setY(temp_y);
        p.setZ(temp_z);
        p.setName("Result");

        return p;
    }

    //DOT PRODUCT
    Vector operator*(Vector obj)
    {
        Vector p ;

        int temp_x = x*obj.x;
        int temp_y = y*obj.y;
        int temp_z = z*obj.z;

        p.setX(temp_x);
        p.setY(temp_y);
        p.setZ(temp_z);
        p.setName("Result");

        return p;
    }

    //PROTOTYPES
    friend Vector operator*(Vector &obj, int i);
    friend Vector operator*(int i, Vector &obj);

    //OVERLOADING THE ASSIGNMENT OPERATOR TO MAKE DYNAMIC COPY OF *char
    Vector operator=(Vector obj)
    {
        if(strlen(name)< strlen(obj.name))
        {
            delete [] name;
            name =  new char[strlen(obj.name)+1];
        }

        strcpy(name,name);
        this->x= obj.x;
        this->y = obj.y;
        this->z = obj.z;
        return *this;
    }

};

// OBJECT*INTEGER FRIEND FUNCTION
Vector operator*(Vector &obj, int i)
{
    Vector p;
    //cout<<"obj int EXECUTED"<<endl;
    p.x = (obj.x) * i;
    p.y = (obj.y) * i;
    p.z = (obj.z) * i;
    p.setName(obj.name);

    return p;
}

//INTEGER*OBJECT FRIEND FUCNTION
Vector operator*(int i, Vector &obj)
{
    Vector p;
    //cout<<"int obj EXECUTED"<<endl;
    p.x = (obj.x) * i;
    p.y = (obj.y) * i;
    p.z = (obj.z) * i;
    p.setName(obj.name);

    return p;
}



int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    v1.print();     ///Print the components of vector v1
    v2.print();     ///Print the components of vector v2

    v3=v1^v2;       ///Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       ///Multiply each component of vector v1 with the given value
    v1.print();     ///Print the modified components of vector v1


    v2=2*v2;        ///Multiply each component of vector v2 with the given value
    v2.print();     ///Print the modified components of vector v2

    v3=v1*v2;       ///Multiply each component of vector v1 with the corresponding component of vector v2.
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}
