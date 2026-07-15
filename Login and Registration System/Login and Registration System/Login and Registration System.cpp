#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n===== REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    // Validate username
    if (username.empty())
    {
        cout << "Username cannot be empty!\n";
        return;
    }

    // Check if username already exists
    ifstream checkFile(username + ".txt");

    if (checkFile.is_open())
    {
        cout << "Username already exists! Try another one.\n";
        checkFile.close();
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    // Validate password
    if (password.length() < 6)
    {
        cout << "Password must be at least 6 characters long.\n";
        return;
    }

    // Create file for new user
    ofstream file(username + ".txt");

    if (!file)
    {
        cout << "Error creating file!\n";
        return;
    }

    file << username << endl;
    file << password << endl;

    file.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string storedUser, storedPass;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file(username + ".txt");

    if (!file)
    {
        cout << "User not found!\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);

    file.close();

    if (username == storedUser && password == storedPass)
    {
        cout << "Login Successful!\n";
    }
    else
    {
        cout << "Incorrect Password!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank you for using the system.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}