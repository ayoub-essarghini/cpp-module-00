#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip> 
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class Contact
{
private:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string darkest_sec;

public:
    Contact();
    Contact(const Contact &new_contact);
    ~Contact();
    int getIndex();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhone();
    std::string getDarkestSec();
    void setFirstName(std::string new_fname);
    void setIndex(int new_index);
    void setLastName(std::string new_lname);
    void setNickname(std::string new_nickname);
    void setPhone(std::string new_nickname);
    void setDarkestSec(std::string new_nickname);
};

class PhoneBook
{

private:
    Contact contacts[8];

public:
    PhoneBook();
    PhoneBook(const PhoneBook &new_phonebook);
    ~PhoneBook();
    void addContact(Contact &new_contact);
    void searchContact(int id);
    void printContacts();
    std::string formatField(const std::string &field);
};

#endif