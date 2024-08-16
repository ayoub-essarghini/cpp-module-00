#include "phonebook.hpp"

Contact::Contact()
{
    
}

// Contact::Contact(const Contact &new_contact)
// {

// }
Contact::~Contact()
{

}

int Contact::getIndex()
{
    return index;
}
std::string Contact::getFirstName()
{
    return first_name;
}

std::string Contact::getLastName()
{
    return last_name;
}

std::string Contact::getNickName()
{
    return nickname;
}

std::string Contact::getPhone()
{
    return phone;
}

std::string Contact::getDarkestSec()
{
    return darkest_sec;
}

void Contact::setIndex(int new_index)
{
    index = new_index;
}
void Contact::setFirstName(std::string new_fname)
{
    first_name = new_fname;
}

void Contact::setLastName(std::string new_lname)
{
    last_name = new_lname;
}

void Contact::setNickname(std::string new_nickname)
{
    nickname = new_nickname;
}

void Contact::setPhone(std::string new_phone)
{
    phone = new_phone;
}

void Contact::setDarkestSec(std::string new_secret)
{
    darkest_sec = new_secret;
}


