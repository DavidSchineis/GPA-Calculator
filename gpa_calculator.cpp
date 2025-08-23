// GPA Calculator 

// Import libs
#include <iostream>
#include <iomanip> 
#include <string>
#include <unordered_map>
using namespace std;

// Calculates the GPA needed in the upcoming semester to reach a desired cumulative GPA
double calculateNeededSemesterGPA(double credits, double gpa, double upcomingCredits, double desiredTotalGPA) {
    return ((credits + upcomingCredits) * desiredTotalGPA - credits * gpa) / upcomingCredits;
}

// Calculates the new cumulative GPA after adding the current semester GPA into the total
double calculateNewTotalGPA(double credits, double gpa, double upcomingCredits, double semesterGPA) {
    return (credits * gpa + upcomingCredits * semesterGPA) / (credits + upcomingCredits);
}

// Converts a letter grade into its GPA numeric equivalent
double letterToGPA(const string& grade) {

    // Map from letter grades to GPA value
    static unordered_map<string, double> gradeMap = {
        {"A", 4.0}, 
        {"A-", 3.7}, 
        {"B+", 3.3}, 
        {"B", 3.0}, 
        {"B-", 2.7},
        {"C+", 2.3}, 
        {"C", 2.0}, 
        {"C-", 1.7}, 
        {"D+", 1.3}, 
        {"D", 1.0}, 
        {"F", 0.0}
    };

    // Look up grade in map
    auto it = gradeMap.find(grade);
    if (it != gradeMap.end()) 
        return it->second; 

    // If an invalid grade is entered, return -1
    return -1.0; 
}

// Main
int main() {
    double credits, gpa;

    // Get students current academics
    cout << "Enter total completed credits: ";
    cin >> credits;
    cout << "Enter current GPA: ";
    cin >> gpa;

    // Menu
    int choice;
    cout << "\nChoose an option:\n";
    cout << "1. Desired total GPA → Find required semester GPA\n";
    cout << "2. Enter semester letter grades → Find new total GPA\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    // Formatting for all numbers to output with 2 decimals
    cout << fixed << setprecision(2);

    // Option 1: Desired GPA
    if (choice == 1) {
        double upcomingCredits, desiredTotalGPA;

        // User prompts
        cout << "Enter upcoming credits: ";
        cin >> upcomingCredits;
        cout << "Enter desired total GPA: ";
        cin >> desiredTotalGPA;

        double needed = calculateNeededSemesterGPA(credits, gpa, upcomingCredits, desiredTotalGPA);

        cout << "You need a semester GPA of: " << needed << endl;
    } 

    // Option 2: Semester GPA + New Total GPA
    else if (choice == 2) {
        int numCourses;

        // User prompts
        cout << "Enter number of courses this semester: ";
        cin >> numCourses;

        double totalQualityPoints = 0.0; 
        double semesterCredits = 0.0;  

        // Loop through each course
        for (int i = 0; i < numCourses; i++) {
            double courseCredits;
            string grade;
            cout << "Course " << i+1 << " credits: ";
            cin >> courseCredits;
            cout << "Course " << i+1 << " letter grade (A, A-, B+, etc.): ";
            cin >> grade;

            // Convert grade to GPA points
            double gradePoints = letterToGPA(grade);

            // Handle invalid grade
            if (gradePoints < 0) {
                cout << "Invalid grade entered. Try again.\n";
                i--;
                continue;
            }

            // Accumulate quality points and credits
            totalQualityPoints += courseCredits * gradePoints;
            semesterCredits += courseCredits;
        }

        // Compute semester GPA
        double semesterGPA = totalQualityPoints / semesterCredits;

        // Compute new cumulative GPA after this semester
        double newGPA = calculateNewTotalGPA(credits, gpa, semesterCredits, semesterGPA);

        // Output results
        cout << "Semester GPA: " << semesterGPA << endl;
        cout << "New cumulative GPA: " << newGPA << endl;
    } 

    // Invalid choice handling
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

