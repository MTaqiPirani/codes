#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;
    // Controlling the number of rows
    for (int i = 1; i <= rows; i++)
    {
        // Print spaces
        for (int space = 1; space <= rows - i; space++)
        {
            cout << " ";
        }
        // Print stars only odd number of times
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}