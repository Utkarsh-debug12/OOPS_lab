#include <iostream>
using namespace std;
class SimpleInterest {
private:
    double principal;
    double rate;
    double time;
    double interest;
public:
    // Explicit constructor prevents implicit conversions
    // e.g. SimpleInterest si = 5000; would be an ERROR because of 'explicit'
    explicit SimpleInterest(double p, double r = 0, double t = 0) {
        principal = p;
        rate = r;
        time = t;
        interest = (principal * rate * time) / 100;
    }
    void display() {
        cout << "Principal = " << principal << endl;
        cout << "Rate      = " << rate << endl;
        cout << "Time      = " << time << endl;
        cout << "Simple Interest = " << interest << endl;
    }
};
int main() {
    double p, r, t;
    cout << "Enter Principal Amount: ";
    cin >> p;
    cout << "Enter Rate of Interest: ";
    cin >> r;
    cout << "Enter Time (in years): ";
    cin >> t;
    // Must call constructor explicitly with all arguments
    SimpleInterest si(p, r, t);
    si.display();
    return 0;
}
