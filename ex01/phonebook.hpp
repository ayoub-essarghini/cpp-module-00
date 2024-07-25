#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>


class Contact
{
    private:
        int index;
        std::string first_name;
        std::string last_name;
        std::string nickname;

    public:
        Contact();
        Contact(const Contact &new_contact);
        ~Contact();
        int getIndex();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        void setFirstName(std::string new_fname);
        void setIndex(int new_index);
        void setLastName(std::string new_lname);
        void setNickname(std::string new_nickname);
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
        void searchContact(std::string fname);
        void printContacts();


};

#endif