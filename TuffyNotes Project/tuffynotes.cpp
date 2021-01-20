#include "notebook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  char choice = 'a';
  std::string file_name;
  std::cout << "Welcome to TuffyNotes!\n";

  // this array is where all the notes will be stored
  Notebook tuffynotes;
  Note *temp;

  // will keep asking user these options until they exit
  do {
    std::cout << "[C] Create a note\n";
    std::cout << "[N] Create an encrypted note\n";
    std::cout << "[L] List notes\n";
    std::cout << "[V] View note\n";
    std::cout << "[S] Save notes\n";
    std::cout << "[O] Load notes\n";
    std::cout << "[E] Exit\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();
    std::cout << "\n";

    switch (choice) {
    // will go to this option if user chooses to create a note
    case 'c':
    case 'C':
      temp = create_note();
      tuffynotes.add(temp);
      break;
    case 'n':
    case 'N':
      temp = create_encrypted_note();
      tuffynotes.add(temp);
    // will go to this option if user chooses to list notes
    case 'l':
    case 'L':
      tuffynotes.list();
      break;
    // will go to this option if usr chooses to view the notes
    case 'v':
    case 'V':
      tuffynotes.view();
      break;
    // will go to this option if the user chooses to save their notes
    case 's':
    case 'S':
      std::cout << "\nPlease enter filename: ";
      std::getline(std::cin, file_name);
      tuffynotes.save(file_name);
      break;
    // will go to this option if the user chooses to load their notes
    case 'o':
    case 'O':
      std::cout << "\nPlease enter filename: ";
      std::getline(std::cin, file_name);
      tuffynotes.load(file_name);
      break;
    // will go to this option if the user chooses to exit
    case 'e':
    case 'E':
      std::cout << "\nThank you for using TuffyNotes!\n";
      break;
    default:
      std::cout << "\nInvalid choice. Please try again.\n\n";
    }
  } while (choice != 'E' && choice != 'e');

  return 0;
}
