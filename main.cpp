#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string sumOp(string& num1, string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int maxLen = max(len1, len2);


    string result(maxLen, '0');
    int carry = 0;


    for (int i = 0; i < maxLen; i++) {
        int digitSum = carry;
        if (i < len1) {
            digitSum += num1[len1 - i - 1] - '0';
        }
        if (i < len2) {
            digitSum += num2[len2 - i - 1] - '0';
        }
        result[maxLen - i - 1] = (digitSum % 10) + '0';
        carry = digitSum / 10;
    }


    if (carry > 0) {
        result = char(carry + '0') + result;
    }

    return result;
}

string subOp(const string& num1, const string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int maxLen = max(len1, len2);

 
    string result(maxLen, '0');
    int borrow = 0;


    for (int i = 0; i < maxLen; i++) {
        int digitDiff = borrow;
        if (i < len1) {
            digitDiff += num1[len1 - i - 1] - '0'; 
        }
        if (i < len2) {
            digitDiff -= num2[len2 - i - 1] - '0'; 
        }
        if (digitDiff < 0) {
            digitDiff += 10; 
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[maxLen - i - 1] = (digitDiff % 10) + '0'; 
    }

  
    result.erase(0, result.find_first_not_of('0'));

    return result.empty() ? "0" : result; 
}

int main() {
    string firNum;
    string secNum;

    cout << "First number   >>";
    cin >> firNum;
    cout << "Second number  >>";
    cin >> secNum;


    string sum = sumOp(firNum, secNum);
    string sub = subOp(firNum, secNum);

    cout << "Sum: " << sum << endl;
    cout << "Sub: " << sub << endl;

    return 0;
}
