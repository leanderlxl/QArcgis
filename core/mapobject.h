#ifndef MAPOBJECT_H
#define MAPOBJECT_H


class mapObject
{
public:
    mapObject();
public:
    double area();
    double length();
};

class point:public mapObject
{
public:
    point() {}
};

#endif // MAPOBJECT_H
