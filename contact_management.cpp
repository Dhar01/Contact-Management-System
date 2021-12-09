#include <iostream>	// for input output.
#include <fstream>	// for file management.
#include <string>   // for taking string-type value

std::fstream fp;

// the contact book class
class contact
{
    long phone{}; // for phone number
    std::string name{}; // for contact name
    std::string email{};    // for contact email

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

// to save contact information on the phonebook
void save_contact()
{

}

// to display contact on the command line
void display_contact(int phone)
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
    for(;;) {
        std::cout << "\n\t ~~~~~~~~ Contact Management System (Command Line) ~~~~~~~~";

        /* not sure how should I organize this section, 
            I wrote so many print functions for code readability. */
        std::cout << "\n\n\t Main Menu:";
        std::cout << "\n[1] Add new contact";
        std::cout << "\n[2] List all contacts";
        std::cout << "\n[3] Search for contact";
        std::cout << "\n[4] Edit a contact";
        std::cout << "\n[5] Delete a contact";
        std::cout << "\n[0] Exit";
        std::cout << "\n\n";

        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch(choice) {
            case 0: {
                    std::cout << "Thank you for using my project. \n\nRegards,\nLoknath Dhar";
                    break;
            }
            case 1: {
                    save_contact();
                    break;
            }
            case 2: {
                    show_all_contacts();
                    break;
            }
            case 3: {
                    long num{};
                    std::cout << "\nPhone: ";
                    std::cin >> num;
                    display_contact(num);
                    break;
            }
            case 4: {
                    edit_contact();
                    break;
            }
            case 5: {
                    delete_contact();
                    break;
            }
            default:
                    break;
        }

        std::cout << "\n\nEnter your choice: \n[1] Main Menu\t[0] Exit\n";
        int option{};
        std::cin >> option;

        switch(option) {
            case 1:
                    continue;
            case 0:
                    break;
        }
    }

    return 0;
}