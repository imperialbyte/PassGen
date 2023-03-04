#include <iostream>
#include <string>
#include <vector>

// Imperialbyte
// typedef for String because I enjoy Java
typedef std::string String;

// declare variables for stuff.....
const String letter_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const String letter_lower = "abcdefghijklmnopqrstuvwxyz";
const String letter_number = "0123456789";
const String letter_special = "!@#$%^&*()_+-./;<=>?";
String data = letter_upper + letter_lower + letter_number + letter_special;
unsigned int number_of_passwords = 8;
unsigned int length_of_password = 8;
int choice;

// Maybe I will add formats one day
enum PasswordFormats {APPLE};

// just me using namespace
namespace PassGen {
    // more variables to see if a option is enabled or not
    bool upper_enabled = true;
    bool lower_enabled = true;
    bool number_enabled = true;
    bool special_enabled = true;
    bool has_error = false;

    // function prototypes
    void run(String &data, unsigned int &length_of_password, unsigned int &number_of_passwords);
    void print_menu(int &choice, unsigned int &length_of_password, unsigned int &number_of_passwords);
    void print_settings(int &choice, unsigned int &length_of_password);

    // run function that takes all characters String data, length of password and number of passwords and generates passwords
    // and saves them to a vector and prints out vector
    void run(String &data, unsigned int &length_of_password, unsigned int &number_of_passwords) {
        std::vector<String> password(number_of_passwords);
        for(unsigned int a = 0; a < number_of_passwords; a++) {
            String generated_password;
            for(unsigned int i = 1; i <= length_of_password; i++) {
                unsigned int random_index = rand() % data.length();
                generated_password += data[random_index];
            }
            password[a] = generated_password;
        }

        std::cout << "Generated passwords: " << std::endl;
        for(const String& pass : password) {
            std::cout << pass << "\n";
        }
        std::cout << "Successfully generated " << number_of_passwords << " passwords." << std::endl;
        char c;
        std::cout << "Would you like to continue? (y/n): " << std::endl;
        std::cin >> c;
        while(1) {
            if(c == 'y' || c == 'Y') {
                print_menu(choice, length_of_password, number_of_passwords);
                std::cout << std::endl;
            }
            else if(c == 'n' || c == 'N') {
                std::cout << "Goodbye!" << std::endl;
                std::exit(0);
            }
            else {
                std::cout << "Please enter y or n." << std::endl;
            }
            std::cin >> c;
        }
        
    }

    // menu
    void print_menu(int &choice, unsigned int &length_of_password, unsigned int &number_of_passwords) {
        std::cout << "*************************\n";
        std::cout << "Welcome to passgen!\n";
        std::cout << "1> Run\n";
        std::cout << "2> Settings\n";
        std::cout << "3> Exit\n";
        std::cout << "*************************\n";
        std::cout.flush();
        std::cin >> choice;

        if (choice == 3) {
            std::cout << "Exiting...\n";
            std::exit(0);
        } else if (choice == 1) {
            if(number_enabled == false && lower_enabled == false && upper_enabled == false && special_enabled == false) {
                upper_enabled = true;
                data.append(letter_upper);
                print_menu(choice, length_of_password, number_of_passwords);
            } else if(number_enabled == true || lower_enabled == true || upper_enabled == true || special_enabled == true) {
                run(data, length_of_password, number_of_passwords);
            }
        } else if (choice == 2) {
            PassGen::print_settings(choice, length_of_password);
        } else {
            std::cout << "Invalid choice!\n";
        }
    }

    // settings
    void print_settings(int &choice, unsigned int &length_of_password) {
        system("cls");
        std::cout << "*************************\n";
        std::cout << "Passgen Settings\n";
        std::cout << "Include the following settings\n";
        std::cout << "Enabled(1) : Disabled(0)\n";
        std::cout << "1> Upper letters " << upper_enabled << "\n";
        std::cout << "2> Lower letters " << lower_enabled << "\n";
        std::cout << "3> Numbers " << number_enabled << "\n";
        std::cout << "4> Special characters " << special_enabled << "\n";
        std::cout << "5> Length of password(" << length_of_password << ")" << "\n";
        std::cout << "6> Number of passwords(" << number_of_passwords << ")" << "\n";
        std::cout << "7> Run\n";
        std::cout << "8> Back to menu\n";
        std::cout << "9> Exit\n";
        std::cout << "*************************\n";
        std::cout << "Enter a option: \n";
        if(has_error) {
            std::cout << "Invalid option!\n";
        }
        has_error = !has_error;
        std::cin >> choice;
        if(choice == 1) {
            if(upper_enabled == true) {
                upper_enabled = !upper_enabled;
                data.erase(data.find(letter_upper), letter_upper.length());
                print_settings(choice, length_of_password);
            } else {
                data.append(letter_upper);
                upper_enabled = true;
                print_settings(choice, length_of_password);
            }
        } else if(choice == 2) {
            if(lower_enabled == true) {
                lower_enabled = !lower_enabled;
                data.erase(data.find(letter_lower), letter_lower.length());
                print_settings(choice, length_of_password);
            } else {
                data.append(letter_lower);
                lower_enabled = true;
                print_settings(choice, length_of_password);
            }
        } else if(choice == 3) {
            if(number_enabled == true) {
                number_enabled = !number_enabled;
                data.erase(data.find(letter_number), letter_number.length());
                print_settings(choice, length_of_password);
            } else {
                data.append(letter_number);
                number_enabled = true;
                print_settings(choice, length_of_password);
            }
        } else if(choice == 4) {
            if(special_enabled == true) {
                special_enabled = !special_enabled;
                data.erase(data.find(letter_special), letter_special.length());
                print_settings(choice, length_of_password);
            } else {
                data.append(letter_special);
                special_enabled = true;
                print_settings(choice, length_of_password);
            }
        } else if(choice == 5) {
            std::cout << "Enter length of password: " << std::endl;
            std::cin >> length_of_password;
            print_settings(choice, length_of_password);
        } else if(choice == 6) {
            std::cout << "Enter number of passwords: " << std::endl;
            std::cin >> number_of_passwords;
            print_settings(choice, length_of_password);
        } else if(choice == 7) {
            if(number_enabled == false && lower_enabled == false && upper_enabled == false && special_enabled == false) {
                upper_enabled = true;
                data.append(letter_upper);
                print_settings(choice, length_of_password);
            } else if(number_enabled == true || lower_enabled == true || upper_enabled == true || special_enabled == true) {
                run(data, length_of_password, number_of_passwords);
            }
        } else if(choice == 8) {
            system("cls");
            print_menu(choice, length_of_password, number_of_passwords);
        } else if(choice == 9) {
            std::cout << "Goodbye" << std::endl;
            std::exit(0);
        } else {
            has_error = true;
            print_settings(choice, length_of_password);
        }
    }

}

// main function
int main() {
    srand(std::time(nullptr));
    system("cls");
    PassGen::print_menu(choice, length_of_password, number_of_passwords);

    return 0;
}
