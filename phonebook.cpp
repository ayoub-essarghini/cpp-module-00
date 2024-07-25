#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Phonebook constructor called" << std::endl;
}

PhoneBook::PhoneBook(const PhoneBook &new_phonebook)
{
    std::cout << "Copy phonebook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Phonebook destructor called" << std::endl;
}

void PhoneBook::addContact(Contact &new_contact)
{
    for(int i = 0; i < 8; i++)
    {
      if(contacts[i].getFirstName().empty())
      {
        new_contact.setIndex(i);
        contacts[i] = new_contact;
        return ;
      }
    }
}

void PhoneBook::searchContact(std::string fname)
{
    std::cout << "Search function called" << std::endl;
}

void PhoneBook::printContacts()
{
    std::cout << "Index | first name | last name | nickname" << std::endl;
    for(int i = 0; i < 8; i++)
    {
        if (!contacts[i].getFirstName().empty())
        {
        std::cout << contacts[i].getIndex() << " " \
        << contacts[i].getFirstName() << " " << contacts[i].getLastName() \
        << " " << contacts[i].getNickName() << std::endl; 

        }

    }
}

