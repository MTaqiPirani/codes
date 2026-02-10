#include <iostream>
using namespace std;

// Function to sum the digits of a number
int sumDigits(int n)
{
    // If the number is greater than 10, sum the digits
    while (n >= 10)
    {
        int sum = 0;
        // Sum the digits of the number
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        // Set the sum as the new number
        n = sum;
    }
    // Return the single-digit sum
    return n;
}

int main()
{
    int num;
    // Input a number
    cout << "Enter a number: ";
    cin >> num;
    // Call the function to sum the digits of the number
    int singleDigitSum = sumDigits(num);
    cout << "The single-digit sum is: " << singleDigitSum << endl;
    return 0;
}