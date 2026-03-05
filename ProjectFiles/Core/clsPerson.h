#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
private:
    string _firstName;

    string _secondName;

    string _thirdName;

    string _fourthName;

    string _phone;

public:
    clsPerson() {}
    clsPerson(string firstName, string secondName, string thirdName,
              string fourthName, string phone)
    {

        _firstName = firstName;
        _secondName = secondName;
        _thirdName = thirdName;
        _fourthName = fourthName;
        _phone = phone;
    }

    void SetFirstName(string firstName)
    {
        _firstName = firstName;
    }

    string GetFirstName() const
    {
        return _firstName;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    void SetSecondName(string lastName)
    {
        _secondName = lastName;
    }

    string GetSecondName() const
    {
        return _secondName;
    }

    __declspec(property(get = GetSecondName, put = SetSecondName)) string SecondNeme;

    void SetThirdName(string thirdName)
    {
        _thirdName = thirdName;
    }

    string GetThirdName() const
    {
        return _thirdName;
    }

    __declspec(property(get = GetThirdName, put = SetThirdName)) string ThirdName;

    void SetFourthName(string fourthName)
    {
        _fourthName = fourthName;
    }

    string GetFourthName() const
    {
        return _fourthName;
    }

    __declspec(property(get = GetFourthName, put = SetFourthName)) string FourthName;

    string GetFullName() const
    {
        return this->_firstName + " " + this->_secondName + " " + this->_thirdName + " " + this->_fourthName;
    }
    __declspec(property(get = GetFullName)) string FullName;

    void SetPhone(string Phone)
    {
        _phone = Phone;
    }

    string GetPhone() const
    {
        return _phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;
};
