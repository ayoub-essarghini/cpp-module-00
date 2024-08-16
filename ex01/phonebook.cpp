#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
}



PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(Contact &new_contact)
{
    static int next_index = 0;


    new_contact.setIndex(next_index);
    contacts[next_index] = new_contact;

    next_index = (next_index + 1) % 8;
}

void PhoneBook::searchContact(int id)
{

    if (!contacts[id].getFirstName().empty())
    {
        std::cout << std::setw(5) << "Index" << " | "
                  << std::setw(10) << "First name" << " | "
                  << std::setw(10) << "Last name" << " | "
                  << std::setw(10) << "Nickname" << std::endl;

        std::cout << std::setw(5) << contacts[id].getIndex() << " | "
                  << std::setw(10) << formatField(contacts[id].getFirstName()) << " | "
                  << std::setw(10) << formatField(contacts[id].getLastName()) << " | "
                  << std::setw(10) << formatField(contacts[id].getNickName()) << std::endl;
    }
    else
    {
        std::cout << RED << "Contact not found" << RESET << std::endl;
    }
}

void PhoneBook::printContacts()
{
    std::cout << std::setw(5) << "Index" << " | "
              << std::setw(10) << "First name" << " | "
              << std::setw(10) << "Last name" << " | "
              << std::setw(10) << "Nickname" << std::endl;
    bool printed = false;
    for (int i = 0; i < 8; i++)
    {
        if (!contacts[i].getFirstName().empty())
        {
            printed = true;
            std::cout << std::setw(5) << contacts[i].getIndex() << " | "
                      << std::setw(10) << formatField(contacts[i].getFirstName()) << " | "
                      << std::setw(10) << formatField(contacts[i].getLastName()) << " | "
                      << std::setw(10) << formatField(contacts[i].getNickName()) << std::endl;
        }
    }
    if (!printed)
    {
        std::cout << std::setw(30) << "No records" << std::endl;
    }
}

std::string PhoneBook::formatField(const std::string &field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return field;
}
