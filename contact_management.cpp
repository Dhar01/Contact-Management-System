#include <iostream>	// for input output.
#include <fstream>	// for file management.
#include <string>   // for taking string-type value
#include <cstdlib>  // for std::exit(0), terminating the program instantly

std::fstream fp;

// forward declaration of functions
void save_contact();
void search_contact(long phone);
void delete_contact();
void edit_contact();
void show_all_contacts();

// the contact book class
class Contact
{
    // using member variable with "m_" prefix
    long m_phone {}; // for phone number
    char m_name[20] {};    // for name
    char m_email[30] {};    // for contact email

    public:

    // creating a new contact
    void create_contact() {
        std::cout << "Phone: ";
        std::cin >> m_phone;

        std::cout << "Name: ";
        std::cin.ignore();
        std::cin >> m_name;

        std::cout << "Email: ";
        std::cin.ignore();
        std::cin >> m_email;

        std::cout << "\n";
    }

    // show contact information
    void show_contact() {
        std::cout << "Phone #: " << m_phone << std::endl;
        std::cout << "Name  #: " << m_name << std::endl;
        std::cout << "Email #: " << m_email << std::endl;
    }

    // get the phone number
    long getPhone() {
        return m_phone;
    }

    // get the contact name
    char* getName() {
        return m_name;
    }

    // get email address
    char* getEmail() {
        return m_email;
    }
};

// creating an object in order to call the class function
Contact contact;

// to save contact information on the phonebook
void save_contact()
{
    // opening file to read and append -> saving the information
    fp.open("contactList.txt", std::ios::out | std::ios::app);
    contact.create_contact();

    fp.write((char*)&contact,sizeof(contact));
    fp.close();

    std::cout << std::endl << std::endl << "Contact has been successfully created." << "\n";
}

// to display contact on the command line
void search_contact(long phone)
{
    bool found{false};

    fp.open("contactList.txt", std::ios::in);

    while(fp.read((char*)&contact,sizeof(contact))) {
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
    std::cout << std::endl << "Please, enter the contact #: ";
    int number{};
    std::cin >> number;

    fp.open("contactList.txt", std::ios::in | std::ios::out);
    std::fstream fp2;
    fp2.open("Temp.txt", std::ios::out);
    fp.seekg(0, std::ios::beg);

    while (fp.read((char*)&contact, sizeof(contact))) {
        if (contact.getPhone() != number) {
            fp2.write((char*)&contact, sizeof(contact));
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

    while(fp.read((char*)&contact, sizeof(contact)) && found == false) {
        if (contact.getPhone() == number) {
            contact.show_contact();
            std::cout << "\nPlease enter the new Details of contact: " << std::endl;
            contact.create_contact();
            int pos=-1*sizeof(contact);
            fp.seekp(pos, std::ios::cur);
            fp.write((char*)&contact, sizeof(contact));
            
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

    while(fp.read((char*)&contact, sizeof(contact))) {
        contact.show_contact();
        std::cout << std::endl;
    }

    fp.close();
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
                    std::cout << "\n\nThank you for using my project. \n\nRegards,\nLoknath Dhar\n";
                    std::exit(0);
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
                    search_contact(num);
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
            case 0:
                    std::cout << "\n\nThank you for using my project. \n\nRegards,\nLoknath Dhar\n";
                    std::exit(0);
            case 1:
                    continue;
        }
    }
    return 0;
}
