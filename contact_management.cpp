#include <iostream>	// for input output.
#include <fstream>	// for file management.
#include <string>   // for taking string-type value

std::fstream fp;

// the contact book class
class Contact
{
    long phone{}; // for phone number
    std::string name{}; // for contact name
    std::string email{};    // for contact email

    public:

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

Contact contact;

// to save contact information on the phonebook
void save_contact()
{
    // opening file to read and append -> saving the information
    fp.open("contactList.txt", std::ios::out | std::ios::app);
    contact.create_contact();

    fp.write((char*)&contact,std::size(contact));
    fp.close();

    std::cout << std::endl << std::endl << "Contact has been successfully created." << "\n";

}

// to display contact on the command line
void display_contact(long phone)
{
    bool found{false};
    int ch{};

    fp.open("contactList.txt", std::ios::in);

    while(fp.read((char*) &contact, std::size(contact))) {
        if (contact.getPhone() == phone) {
            contact.show_contact();
            found = true;
        }
    }

    fp.close();

    if (found == false) {
        std::cout << "\n\nNo record found!";
    }
}

// to delete preferred contact
void delete_contact()
{
    int number{};
    std::cout << std::endl << "Please, enter the contact #: ";
    std::cin >> number;

    fp.open("contactList.txt", std::ios::in | std::ios::out);
    std::fstream fp2;
    fp2.open("Temp.txt", std::ios::out);
    fp.seekg(0, std::ios::beg);

    while (fp.read((char*)&contact, std::size(contact))) {
        if (contact.getPhone() != number) {
            fp2.write((char*)&contact, std::size(contact));
        }
    }

    fp2.close();
    fp.close();

    remove("contactList.txt");
    rename("Temp.txt", "contactList.txt");
    std::cout << std::endl << "Contact deleted." << "\n";

}

// to edit and update the existing contact
void edit_contact()
{
    int number{};
    bool found{false};

    std::cout << "Edit contact\n---------------\nEnter the number of contact to edit:";
    std::cin >> number;

    fp.open("contactList.txt", std::ios::in | std::ios::out);

    while(fp.read((char*)&contact, std::size(contact)) && found == false) {
        if (contact.getPhone() == number) {
            contact.show_contact();
            std::cout << "\nPlease enter the new Details of contact: " << std::endl;
            contact.create_contact();
            int pos=-1*std::size(contact);
            fp.seekp(pos, std::ios::cur);
            fp.write((char*)&contact, std::size(contact));
            
            std::cout << std::endl << "Contact successfully update!";
            found = true;
        }
    }

    fp.close();

    if (found == false) {
        std::cout << std::endl << "Contact not found.";
    }

}

// to show the list of contacts
void show_all_contacts()
{
    std::cout << "\n\n # List of Contacts # \n\n";
    fp.open("contactList.txt", std::ios::in);

    while(fp.read((char*)&contact, std::size(contact))) {
        contact.show_contact();
        std::cout << std::endl;
    }

    fp.close();
}

// the main program
int main(int argc, char *argv[])
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
            } break;

            case 1: {
                    save_contact();
            } break;

            case 2: {
                    show_all_contacts();
            } break;

            case 3: {
                    long num{};
                    std::cout << "\nPhone: ";
                    std::cin >> num;
                    display_contact(num);
            } break;

            case 4: {
                    edit_contact();
            } break;

            case 5: {
                    delete_contact();
            } break;

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