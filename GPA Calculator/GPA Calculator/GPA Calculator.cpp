#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int semesters;
    float sum = 0;

    cout << "===== CGPA CALCULATOR =====" << endl;
    cout << "Enter the number of semesters: ";
    cin >> semesters;

    vector<float> gpa(semesters);

    cout << "Enter GPA for each semester:";

    for (int i = 0; i < semesters; i++)
    {
        do
        {
            cout << "Semester " << i + 1 << ": ";
            cin >> gpa[i];

            if (gpa[i] < 0 || gpa[i] > 4)
            {
                cout << "Invalid GPA! Enter a value between 0.0 and 4.0." << endl;
            }

        } while (gpa[i] < 0 || gpa[i] > 4);

        sum += gpa[i];
    }

    float cgpa = sum / semesters;

    cout << fixed << setprecision(2) << endl;
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
