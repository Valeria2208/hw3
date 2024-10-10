//
//  main.cpp
//  hw3
//
//  Created by Valeria Dudinova on 10.10.2024.
//

#include <iostream>
using namespace std;

class MyString
{
private:
    char* str;
    int length;

    int getLength(const char* s) const
    {
        int len = 0;
        while (s[len] != '\0')
        {
            len++;
        }
        return len;
    }

    void copyStr(char* dest, const char* src) const
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    MyString() : str(nullptr), length(0) {}

    MyString(const char* s)
    {
        length = getLength(s);
        str = new char[length + 1];
        copyStr(str, s);
    }
    ~MyString()
    {
        delete[] str;
    }

    // Метод [] для доступу до символу рядка
    char& operator[](int index)
    {
        if (index >= 0 && index < length)
        {
            return str[index];
        }
        throw out_of_range("Index out of range");
    }
    // Метод () для ініціалізації рядка з клавіатури
    void operator()()
    {
        cout << "Enter string: ";
        char buffer[100];
        cin.getline(buffer, 100);

        length = getLength(buffer);
        delete[] str;
        str = new char[length + 1];
        copyStr(str, buffer);
    }
    // Оператор додавання символу до кінця рядка (obj + 'A')
    MyString operator+(char c) const
    {
        MyString newStr;
        newStr.length = length + 1;
        newStr.str = new char[newStr.length + 1];

        copyStr(newStr.str, str);
        newStr.str[length] = c;
        newStr.str[newStr.length] = '\0';

        return newStr;
    }
    // Оператор додавання символу на початок рядка ('A' + obj)
    MyString addToStart(char c) const
    {
        MyString newStr;
        newStr.length = length + 1;
        newStr.str = new char[newStr.length + 1];

        newStr.str[0] = c;
        for (int i = 0; i < length; ++i)
        {
            newStr.str[i + 1] = str[i];
        }
        newStr.str[newStr.length] = '\0';

        return newStr;
    }
    // Оператор додавання 10 символів на кінець рядка (obj + 10)
    MyString operator+(int n) const
    {
        MyString newStr;
        newStr.length = length + n;
        newStr.str = new char[newStr.length + 1];

        copyStr(newStr.str, str);
        for (int i = length; i < newStr.length; ++i)
        {
            newStr.str[i] = '#';  // Добавляем любые символы
        }
        newStr.str[newStr.length] = '\0';

        return newStr;
    }
    // Оператор додавання 10 символів на початок рядка (10 + obj)
    MyString addToStart(int n) const
    {
        MyString newStr;
        newStr.length = length + n;
        newStr.str = new char[newStr.length + 1];

        for (int i = 0; i < n; ++i)
        {
            newStr.str[i] = '#';  // Додаємо будь-які символи
        }
        for (int i = 0; i < length; ++i)
        {
            newStr.str[n + i] = str[i];
        }
        newStr.str[newStr.length] = '\0';

        return newStr;
    }
    // Префіксний інкремент (obj++)
    MyString& operator++()
    {
        char* newStr = new char[length + 2];
        copyStr(newStr, str);
        newStr[length] = '#';  // Додаємо будь-який символ
        newStr[length + 1] = '\0';

        delete[] str;
        str = newStr;
        length++;
        
        return *this;
    }
    // Постфіксний інкремент (obj++)
    MyString operator++(int)
    {
        MyString temp = *this;
        char* newStr = new char[length + 2];
        newStr[0] = '#';
        for (int i = 0; i < length; ++i)
        {
            newStr[i + 1] = str[i];
        }
        newStr[length + 1] = '\0';

        delete[] str;
        str = newStr;
        length++;

        return temp;
    }
    // Метод для виведення рядка
    void show() const
    {
        if (str)
        {
            cout << str << endl;
        } else {
            cout << "Empty string" << endl;
        }
    }
};

int main()
{
    MyString s1("Hello");
    s1.show();

    // Оператор []
    cout << "Third symbol: " << s1[2] << endl;

    // Оператор ()
    s1();
    s1.show();

    // Операторы + для символів
    MyString s2 = s1 + 'A';
    s2.show();

    MyString s3 = s1.addToStart('A');
    s3.show();

    // Операторы + для чисел
    MyString s4 = s1 + 10;
    s4.show();

    MyString s5 = s1.addToStart(10);
    s5.show();

    // Префиксный інкремент
    ++s1;
    s1.show();

    // Постфиксный інкремент
    s1++;
    s1.show();

    return 0;
}
