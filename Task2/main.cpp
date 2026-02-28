
#include <iostream>
#include "ClassA.h"
#include "ClassB.h"

using namespace std;

void testAdd(ClassA& a, ClassB& b, const string& bName, const string& aName){
    cout << "\nAdding connect " << bName << " with " << aName << endl;
    a.addB(b);
    cout << bName << " has connect with " << aName << " ? " << b.hasA() << endl;
    cout << "Number of connects of " << aName << " = " << a.getMultiplicity() << endl;
}

int main(){
    ClassA a1, a2;
    ClassB b1, b2, b3, b4, b5;

    //исходные данные 
    cout << "Start state" << endl;
    cout << "a1 has connects? " << a1.hasB() << endl;
    cout << "a2 has connects? " << a2.hasB() << endl;
    cout << "\nb1 has connect? " << b1.hasA() << endl;
    cout << "b2 has connect? " << b2.hasA() << endl;
    cout << "b3 has connect? " << b3.hasA() << endl;
    cout << "b4 has connect? " << b4.hasA() << endl;
    cout << "b5 has connect? " << b5.hasA() << endl;

    cout << "Number of connects of a1: " << a1.getMultiplicity() << endl;

    //a1 + b1 + b2 + b3 + ?b4?
    cout << "\nAdding b1, b2, b3, b4 to a1" << endl;
    testAdd(a1, b1, "b1", "a1");
    testAdd(a1, b2, "b2", "a1");
    testAdd(a1, b3, "b3", "a1");
    testAdd(a1, b4, "b4", "a1");
    cout << "\nList of B objects connected to a1" << endl;    
    cout << "Number of connects of a1: " << a1.getMultiplicity() << endl;

    cout << "\nchecking connect with 5th" << endl;
    testAdd(a1, b5, "b5", "a1");

    cout << "\nAdding b1 to a2" << endl;
    a2.addB(b1);
    cout << "a2 has connects? " << a2.hasB() << endl;
    cout << "a2 is connected to b1? " << a2.hasB(b1) << endl;
    cout << "b1 is still connected to a1? " << b1.hasA() << endl;

    cout << "\nRemoving connect a1 with b2" << endl;
    a1.removeВ(b2);
    cout << "a1 is connected to b2? " << a1.hasB(b2) << endl;
    cout << "b2 has connect? " << b2.hasA() << endl;
    cout << "Number of connects of a1: " << a1.getMultiplicity() << endl;

    cout << "\nChecking remaining connects of a1" << endl;
    cout << "a1 is connected to b1? " << a1.hasB(b1) << endl;
    cout << "a1 is connected to b3? " << a1.hasB(b3) << endl;
    cout << "\nList of B objects connected to a1" << endl;

    cout << "\nRemov ALL connects of a1" << endl;
    a1.removeB();
    cout << "a1 has connects? " << a1.hasB() << endl;
    cout << "b1 has connect? " << b1.hasA() << endl;
    cout << "b3 has connect? " << b3.hasA() << endl;
    cout << "Number of connects of a1: " << a1.getMultiplicity() << endl;

    //CLassB
    cout << "\n\nEstablishing connect via *.addA(*)" << endl;
    b2.addA(a2);
    cout << "b2 has connect? " << b2.hasA() << endl;
    cout << "a2 is connected to b2? " << a2.hasB(b2) << endl;
    cout << "Number of connects of a2: " << a2.getMultiplicity() << endl;

    cout << "\nBreaking connect via *.removeA()" << endl;
    b2.removeA();
    cout << "b2 has connect? " << b2.hasA() << endl;
    cout << "a2 is connected to b2? " << a2.hasB(b2) << endl;

    a1.removeB();
    a1.addB(b1);
    a1.addB(b2);
    a1.addB(b3);
    a1.addB(b4);
    cout << "After adding b1,b2,b3,b4: connect a1 = " << a1.getMultiplicity() << endl;
    a1.addB(b5);

    cout << "Attempt to add b5: connect a1 = " << a1.getMultiplicity() << endl;

    return 0;
}