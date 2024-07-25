
#include "phonebook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::string fname;
    std::string lname;
    std::string nickName;

    int i = 0;
    while (1)
    {
        std::cout << "Enter command" << "\n";
        std::cin >> command;
        if (command == "ADD")
        {
            std::cout << "Enter first name ";
            std::cin >> fname;
            std::cout << "Enter last name ";
            std::cin >> lname;
            std::cout << "Enter nickname ";
            std::cin >> nickName;
            Contact contact;
            contact.setFirstName(fname);
            contact.setLastName(lname);
            contact.setNickname(nickName);
            phoneBook.addContact(contact);
        }
        else if (command == "SHOW")
        {
            phoneBook.printContacts();
        }
    }
}