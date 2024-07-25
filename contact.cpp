#include "phonebook.hpp"

Contact::Contact()
{
    
}

Contact::Contact(const Contact &new_contact)
{

}
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

