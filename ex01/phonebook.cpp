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
    bool added = false;
    for (int i = 0; i < 8; i++)
    {
        if (contacts[i].getFirstName().empty())
        {
            new_contact.setIndex(i);
            contacts[i] = new_contact;
            added = true;
            break;
        }
    }

    if (!added)
    {

        for (int i = 0; i < 7; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        new_contact.setIndex(7);
        contacts[7] = new_contact;
    }
}

void PhoneBook::searchContact(int id)
{
    // if (id < 0 || id > 7 || contacts[id].getFirstName().empty())
    // {
    //     std::cout << "Contact not found" << std::endl;
    //     return;
    // }
    printContacts(contacts[id]);
}


void PhoneBook::printContacts(Contact &contact)
{
    std::cout << std::setw(5) << "Index" << " | "
              << std::setw(10) << "First name" << " | "
              << std::setw(10) << "Last name" << " | "
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < 8; i++)
    {
          std::cout << std::setw(5) << contacts[i].getIndex() << " | "
              << std::setw(10) << formatField(contacts[i].getFirstName()) << " | "
              << std::setw(10) << formatField(contacts[i].getLastName()) << " | "
              << std::setw(10) << formatField(contacts[i].getNickName()) << std::endl;
    }
  
}

std::string PhoneBook::formatField(const std::string &field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return field;
}
