#ifndef POINT_H_
#define POINT_H_

class Point {
    private:
    int x, y;
    public: 
    Point(int x, int y) : x(x), y(y) {}
    int getX();
    int getY();
};

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}


#endif