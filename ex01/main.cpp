
#include "phonebook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command, fname, lname, nickName, phone, darkest;
    int index;
    Contact contact;
    while (true)
    {
        std::cout << YELLOW << "Enter command (ADD/SEARCH/EXIT):" << RESET;
        std::getline(std::cin, command);
        if (!std::cin)
            break;

        if (command == "ADD")
        {
            std::cout << BLUE << "Enter first name:" << RESET;
            std::getline(std::cin, fname);
            if (!std::cin)
                break;
            if (fname.empty())
            {
                std::cout << RED << "First name cannot be empty.\n"
                          << RESET;
                continue;
            }
            contact.setFirstName(fname);

            std::cout << BLUE << "Enter last name: " << RESET;
            std::getline(std::cin, lname);
            if (!std::cin)
                break;
            if (lname.empty())
            {
                std::cout << "Last name cannot be empty.\n"
                          << RESET;
                continue;
            }
            contact.setLastName(lname);

            std::cout << BLUE << "Enter nickname: " << RESET;
            std::getline(std::cin, nickName);
            if (!std::cin)
                break;
            if (nickName.empty())
            {
                std::cout << "Nickname cannot be empty. \n"
                          << RESET;
                continue;
            }
            contact.setNickname(nickName);

            std::cout << BLUE << "Enter phone number:" << RESET;
            std::getline(std::cin, phone);
            if (!std::cin)
                break;
            if (phone.empty())
            {
                std::cout << "Phone number cannot be empty. \n"
                          << RESET;
                continue;
            }
            contact.setPhone(phone);

            std::cout << BLUE << "Enter darkest secret:" << RESET;
            std::getline(std::cin, darkest);
            if (!std::cin)
                break;
            if (darkest.empty())
            {
                std::cout << "Darkest secret cannot be empty. \n"
                          << RESET;
                continue;
            }
            contact.setDarkestSec(darkest);

            phoneBook.addContact(contact);
        }
        else if (command == "SEARCH")
        {

            phoneBook.printContacts();
            std::cout << "Enter index : ";
            std::string input;
            std::getline(std::cin, input);
            if (!std::cin)
                break;
            if (input.empty())
            {
                std::cout << "Index cannot be empty. \n";
                continue;
            }
            try
            {

                std::stringstream ss(input);
                ss >> index;
                if (index < 8 && index >= 0)
                    phoneBook.searchContact(index);
                else
                    std::cout << RED << "please enter number between 0 and 7" << RESET << '\n';
            }
            catch (const std::exception &e)
            {
                std::cerr << "Invalid input" << '\n';
            }
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT.\n";
        }
    }
}