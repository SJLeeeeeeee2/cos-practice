#include <iostream>
using namespace std;

extern "C" int decode1(long *xp,long *yp,long *zp);

int main(){
    long x,y,z;
    x=10000;
    y=20000;
    z=30000;

    cout <<":before decode1(): " << "x: " << x << " y: " << y << " z: " << z << endl;
    decode1(&x,&y,&z);
    cout <<":after decode1(): " << "x: " << x << " y: " << y << " z: " << z << endl;
    // x: 30000, y: 10000, z: 20000
    return 0;
}