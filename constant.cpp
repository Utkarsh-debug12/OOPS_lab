#include<iostream>
#include<string>
using namespace std;

class Crime{
    private:
    int year, theft, robbery, murder;
    
    public:
    // 'explicit' prevents accidental implicit type conversions (e.g., Crime c = 2020;)
    explicit Crime(int y, int t, int r, int m){
        year = y;
        theft = t;
        robbery = r;
        murder = m;
    }
    
    // 'const' at the end ensures this function cannot modify any member variables
    void display() const{
        cout << "Crime Report :- " << endl;
        cout << "Year    : " << year << endl;
        cout << "Theft   : " << theft << endl;
        cout << "Robbery : " << robbery << endl;
        cout << "Murder  : " << murder << endl;
    }
    
    // Non-const version: Called on standard, modifiable objects.
    // Returns a standard reference (int&) so the variable can be changed.
    int& accessTheft() {
        cout << "[Called non-const accessTheft()] ";
        return theft;
    }
    
    // Const version: Called on const objects.
    // Returns a read-only reference (const int&) to protect the variable.
    const int& accessTheft() const {
        cout << "[Called const accessTheft()] ";
        return theft;
    }
};

// Takes a const reference to guarantee 'data' won't be modified during analysis
void safeAnalysis(const Crime& data) {
    cout << "Performing safe analysis... ";
    cout << "Theft count is: " << data.accessTheft() << endl; // Calls the const getter
}

// Demonstrates const_cast to override read-only protections
void forceUpdateTheft(const Crime& data, int newThefts) {
    cout << "Warning: Using const_cast to modify read-only reference!" << endl;
    
    // Strips away the 'const' qualifier. 
    // WARNING: This is only safe if the original object passed in was NOT const.
    Crime& modifiableData = const_cast<Crime&>(data); 
    modifiableData.accessTheft() = newThefts;         
}

int main(){
    int y, t, r, m;
    
    // --- Data Input ---
    cout << "Enter the year : ";
    cin >> y;
    cout << "Enter the number of thefts in that year : ";
    cin >> t;
    cout << "Enter the number of robbery in that year : ";
    cin >> r;
    cout << "Enter the number of murder in that year : ";
    cin >> m;
    cout << "\n";    
    
    // --- Object Creation ---
    Crime mutableData(y, t, r, m);                  // Standard, modifiable object
    const Crime readOnlyData(y - 1, t/2, r/2, m/2); // Strictly read-only object

    // --- 1. Overloading on const ---
    cout << "### Overloading on const ###" << endl;
    
    // Compiler chooses the non-const accessTheft() because mutableData isn't const
    mutableData.accessTheft() = t + 50; 
    cout << "Updated theft count: " << mutableData.accessTheft() << "\n\n";

    // Compiler chooses the const accessTheft() because readOnlyData is const
    cout << "Read-only theft count: " << readOnlyData.accessTheft() << "\n\n";


    // --- 2. Const Correctness ---
    cout << "### Const Correctness ###" << endl;
    safeAnalysis(readOnlyData); 
    cout << "\n";


    // --- 3. Casting Away const ---
    cout << "### Casting Away const ###" << endl;
    mutableData.display();
    
    // Passes a non-const object into a function that expects a const object,
    // which then forcefully strips the const away. This works safely here 
    // ONLY because mutableData was not originally declared as 'const'.
    forceUpdateTheft(mutableData, 9999); 
    
    mutableData.display();

    return 0;
}
