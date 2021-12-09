#include <iostream>	// for input output.
#include <fstream>	// for file management.
#include <string>

std::fstream fp;

// the contact book class
class contact
{
    long phone{}; // for phone number
    char name[20], email[30];
    std::string name{};
    std::string email{};

    // creating a new contact
    void create_contact() {
        std::cout << "Phone: ";
        std::cin >> phone;

        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Email: ";
        std::getline(std::cin, email);

        std::cout << "\n";
    }

    // show contact information
    void show_contact() {
        std::cout << "Phone #: " << phone;
        std::cout << "Name  #: " << name;
        std::cout << "Email #: " << email;
    }

    // get the phone number
    long getPhone() {
        return phone;
    }

    // get the contact name
    std::string getName() {
        return name;
    }

    // get email address
    std::string getEmail() {
        return email;
    }
};

// to save contact on the phonebook
void save_contact()
{

}

// to display contact on the command line
void display_contact()
{

}

// to delete preferred contact
void delete_contact()
{

}

// to edit and update the existing contact
void edit_contact()
{

}

// to show the list of contacts
void show_all_contacts()
{

}

// the main program
int main()
{

    return 0;
}