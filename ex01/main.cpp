
#include "phonebook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command, fname, lname, nickName, phone, darkest;
    Contact contact;
   while (true) {
        std::cout << "\033[1;34mEnter command (ADD/SEARCH/EXIT): \033[0m";
        std::getline(std::cin, command);

        if (command == "ADD") {
            std::cout << "\033[1;34mEnter first name: \033[0m";
            std::getline(std::cin, fname);
            if (fname.empty()) {
                std::cout << "First name cannot be empty. Starting over...\n";
                continue;
            }
            contact.setFirstName(fname);

            std::cout << "\033[1;35mEnter last name: \033[0m";
            std::getline(std::cin, lname);
            if (lname.empty()) {
                std::cout << "Last name cannot be empty. Starting over...\n";
                continue;
            }
            contact.setLastName(lname);

            std::cout << "\033[1;36mEnter nickname: \033[0m";
            std::getline(std::cin, nickName);
            if (nickName.empty()) {
                std::cout << "Nickname cannot be empty. Starting over...\n";
                continue;
            }
            contact.setNickname(nickName);

            std::cout << "\033[1;33mEnter phone number: \033[0m";
            std::getline(std::cin, phone);
            if (phone.empty()) {
                std::cout << "Phone number cannot be empty. Starting over...\n";
                continue;
            }
            contact.setPhone(phone);

            std::cout << "\033[1;31mEnter darkest secret: \033[0m";
            std::getline(std::cin, darkest);
            if (darkest.empty()) {
                std::cout << "Darkest secret cannot be empty. Starting over...\n";
                continue;
            }
            contact.setDarkestSec(darkest);

            phoneBook.addContact(contact);

        } else if (command == "SEARCH") {
            std::cout << "\033[1;34mEnter first name: \033[0m";
            std::getline(std::cin, fname);
            if (fname.empty()) {
                std::cout << "First name cannot be empty. Starting over...\n";
                continue;
            }
            phoneBook.searchContact(fname);

        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT.\n";
        }
    }
}