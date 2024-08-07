#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    // std::cout << "Phonebook constructor called" << std::endl;
}

PhoneBook::PhoneBook(const PhoneBook &new_phonebook)
{
    // std::cout << "Copy phonebook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
    // std::cout << "Phonebook destructor called" << std::endl;
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
    contacts[0] = new_contact;
    
}

void PhoneBook::searchContact(std::string fname)
{
    for(int i = 0; i < 8; i++)
    {
        if(contacts[i].getFirstName() == fname)
        {
            printContacts(contacts[i]);
            return ;
        }
    }
    std::cout << "Contact not found" << std::endl;
}

void PhoneBook::printContacts(Contact &contact)
{
    std::cout << "Index | first name | last name | nickname" << std::endl;
    std::cout << contact.getIndex() << " | " << contact.getFirstName().substr(0, 10) << " | " << contact.getLastName().substr(0, 10) << " | " << contact.getNickName().substr(0, 10) << std::endl;
}

