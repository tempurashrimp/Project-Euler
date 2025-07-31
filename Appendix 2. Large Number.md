The LargeNumber class simulates arithmetic operations by storing numbers as strings.

```cpp
LargeNumber::LargeNumber(string n) {
    number = n;
}

LargeNumber operator+ (const LargeNumber &n1, const LargeNumber &n2) {
    string sumNumber = "";

    int carry = 0;
    string shorterNumber, longerNumber;
    size_t longerLength;

    if (n1.number.length() < n2.number.length()) {
        longerNumber = n2.number;
        longerLength = n2.number.length();
        shorterNumber = n1.number;
    } else {
        longerNumber = n1.number;
        longerLength = n1.number.length();
        shorterNumber = n2.number;  
    }

    reverse(shorterNumber.begin(), shorterNumber.end());
    reverse(longerNumber.begin(), longerNumber.end());

    while(shorterNumber.length() < longerLength) {
        shorterNumber.push_back('0');
    }
  
    for(size_t i = 0; i < longerLength; i++) {
        int digit = (shorterNumber.at(i) - 48) + (longerNumber.at(i) - 48) + carry;

        if (digit > 9) {
            carry = 1;
            digit -= 10;
        } else {
            carry = 0;
        }

        sumNumber.push_back(digit + '0');
    }

    if (carry) {
        sumNumber.push_back(carry + '0');
    }

    reverse(sumNumber.begin(), sumNumber.end());
    return LargeNumber(sumNumber);
}

LargeNumber operator* (const LargeNumber &n1, const LargeNumber &n2) {
    LargeNumber product("");

    int carry = 0;
    string shorterNumber, longerNumber;
    size_t shorterLength, longerLength;

    if (n1.number.length() < n2.number.length()) {
        longerNumber = n2.number;
        longerLength = n2.number.length();
        shorterNumber = n1.number;
        shorterLength = n1.number.length();
    } else {
        longerNumber = n1.number;
        longerLength = n1.number.length();
        shorterNumber = n2.number;
        shorterLength = n2.number.length();
    }

    reverse(shorterNumber.begin(), shorterNumber.end());
    reverse(longerNumber.begin(), longerNumber.end());

    for(size_t i = 0; i < shorterLength; i++) {
        LargeNumber innerProduct("");
        int currentDigit = shorterNumber.at(i) - '0';
        carry = 0;
  
        for (size_t j = 0; j < longerLength; j++) {
            int digit = currentDigit * (longerNumber.at(j) - '0') + carry;
            carry = digit / 10;
            digit = digit % 10;

            innerProduct.number.push_back(digit + '0');
        }

        if (carry) {
            innerProduct.number.push_back(carry + '0');
        }

        reverse(innerProduct.number.begin(), innerProduct.number.end());

        for (size_t j = 0; j < i; j++) {
            innerProduct.number.push_back('0');
        }

        product = product + innerProduct;
    }
  
    return product;
}
```