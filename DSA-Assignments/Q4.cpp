#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int num[100];
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
    cout << "The number is: [";
    for (int j = 0; j < n; j++)
    {
        cout << num[j] << ",";
    }
    cout << "]" << endl;
    // Output the sorted numbers in acsending order
    sort(num, num + n);
    cout << "the sorted numebers are: [";
    for (int k = 0; k < n; k++)
    {
        if (num[k] % 2 == 0)
        {
            cout << num[k] << ",";
        }
    }
    // Output the sorted numbers in descending order
    sort(num, num + n, greater<int>());
    for (int l = 0; l < n; l++)
    {
        if (num[l] % 2 != 0)
        {
            cout << num[l] << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}