#include <iostream>
using namespace std;

int main()
{
    int n;
    int num[100];
    int multi = 1;
    int sum = 0;
    int result;
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
    cout << "Input: [";
    for (int j = 0; j < n; j++)
    {
        cout << num[j] << ",";
    }
    cout << "]" << endl;
    // Find the missing number
    multi = (n + 1) * (n + 2) / 2;
    for (int k = 0; k < n; k++)
    {
        sum += num[k];
    }
    result = multi - sum;
    // Output the missing number
    cout << "The missing number is: " << result << endl;
    return 0;
}