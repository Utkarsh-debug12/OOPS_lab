#include <iostream>
using namespace std;

// Allows implicit conversions from double to Distance
class Distance {
private:
    double meters;   

public:
    Distance(double m) {         
        meters = m;
        cout << "Distance created: " << meters << "m" << endl;
    }

    double getMeters() const {    
        return meters;
    }
};

// Prevents implicit conversions due to 'explicit'
class SafeDistance {
private:
    double meters;  

public:
    explicit SafeDistance(double m) {   
        meters = m;
        cout << "SafeDistance created: " << meters << "m" << endl;
    }

    double getMeters() const {   
        return meters;
    }
};

void printDistance(Distance d) {
    cout << "Printing: " << d.getMeters() << "m" << endl;
}

void printSafeDistance(SafeDistance d) {
    cout << "Printing: " << d.getMeters() << "m" << endl;
}

int main() {
    // Implicit conversion (double -> Distance)
    Distance d1 = 10.5;        
    
    // Implicitly wraps 25.0 into a Distance object
    printDistance(25.0);       
    
    cout << "d1 meters: " << d1.getMeters() << endl;

    // Direct initialization
    SafeDistance d2(10.5);            
    
    // Explicit constructor call
    SafeDistance d3 = SafeDistance(10.5); 

    // Must construct explicitly; SafeDistance d4 = 10.5; would fail
    printSafeDistance(SafeDistance(25.0));  

    cout << "d2 meters: " << d2.getMeters() << endl;

    return 0;
}
