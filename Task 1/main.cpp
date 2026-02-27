#include <iostream>
#include "ClassA.h"
#include "ClassB.h"

using namespace std;

int main(){   
    
    
    ClassA a;

    cout << "Initial count: " << a.getN() << endl;

    cout << "\nAdding elements:\n";
    a.add(5);
    a.add(19);
    a.add(27);

    cout << "Count elements: " << a.getN() << endl;

    int count = 0;
    const ClassB** parts = a.getB(count);

    cout << "\nElements:\n";
    for (int i = 0; i < count; ++i)
        cout << "Index " << i << " value = " << parts[i]->getX() << endl;

    cout << "\nFind element 19: index = " << a.find(19) << endl;
    cout << "\nFind element 20: index = " << a.find(20) << endl;

    cout << "\nDelete element 19\n";
    a.del(19);
    parts = a.getB(count);
    cout << "Elements:\n";
    for (int i = 0; i < count; ++i)
        cout << "Index " << i << " value = " << a.getX(i) << endl;
    
    cout << "\nDelete element 20\n";
    a.del(20);
    parts = a.getB(count);
    cout << "Elements:\n";
    for (int i = 0; i < count; ++i)
        cout << "Index " << i << " value = " << a.getX(i) << endl;

    //ClassB
    ClassB b1;
    ClassB b2;

    b1.setX(11);
    b2.setX(22);

    cout << "\n\nb1 = " << b1.getX() << endl;
    cout << "b2 = " << b2.getX() << endl;

    cout << "b1.verify(111) = " << b1.verify(111) << endl;
    cout << "b1.verify(11) = " << b1.verify(11) << endl;

    cout << "b1 == b2 : " << (b1 == b2) << endl;
    cout << "b1 != b2 : " << (b1 != b2) << endl;

    cout << "\nAssign b2 = b1\n";
    b2 = b1;

    cout << "b1 = " << b1.getX() << endl;
    cout << "b2 = " << b2.getX() << endl;

    cout << "b1 == b2 : " << (b1 == b2) << endl;
    cout << "b1 != b2 : " << (b1 != b2) << endl;

    return 0;
}