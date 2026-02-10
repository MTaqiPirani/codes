#include <iostream>
using namespace std;

int main()
{
    int n;
    string num[100];
    // Input the length of the digits
    cout << "Enter the length of digits: ";
    cin >> n;
    // Input numbers
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the digit: ";
        cin >> num[i];
    }
    cout << endl;
    // Output the input numbers in one line
    cout << "The number is: ";
    for (int j = 0; j < n; j++)
    {
        cout << num[j];
    }
    cout << endl;
    // Output the reverse of the input numbers
    cout << "The reverse of the number is: ";
    for (int k = 0; k < n; k++)
    {
        // If the first digit is negative, output the negative sign
        if (num[0] == "-")
        {
            num[0] = "-";
            cout << num[0];
            for (int l = n; l > 0; l--)
            {
                cout << num[l];
            }
            return 0;
        }
        // If the first digit is positive, output the positive sign
        else if (num[0] == "+")
        {
            num[0] = "+";
            cout << num[0];
            for (int l = n; l > 0; l--)
            {
                cout << num[l];
            }
            return 0;
        }
        // If the first digit is not a sign, output the reverse of the number
        else
        {
            for (int m = n; m >= 0; m--)
            {
                cout << num[m];
            }
            return 0;
        }
    }
    return 0;
}