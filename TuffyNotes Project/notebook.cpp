#include "notebook.hpp"
#include <fstream>
#include <iostream>

Note *create_note() {
  std::string note_title, note_body;

  std::cout << "Please enter the note's title: ";
  getline(std::cin, note_title);

  std::cout << "Please enter the note: ";
  getline(std::cin, note_body);

  std::cout << "\n";
  Note *new_note = new Note(note_title, note_body);
  std::cout << "Note added!\n\n";
  return new_note;
}

EncryptedNote *create_encrypted_note() {
  std::string title, body, password;

  std::cout << "\nPlease enter the note's title: ";
  std::getline(std::cin, title);

  std::cout << "Please enter the note: ";
  std::getline(std::cin, body);

  std::cout << "Please enter the password: ";
  std::getline(std::cin, password);
  std::cout << "\n";

  EncryptedNote *new_note = new EncryptedNote(title, body, password);
  std::cout << "Note added!\n\n";

  return new_note;
}

void EncryptedNote::display() const {
  std::string password_new;

  std::cout << "Please enter the password to view the note: ";
  std::getline(std::cin, password_new);

  if (password_new == password()) {
    display();
  } else {
    std::cout << "Sorry, you do not have the permission to view note.\n\n";
  }
}


// function to display the list of different notes the user created
void Notebook::list() const {
  if (size_ == 0) {
    std::cout << "\nNo notes have been added.\n\n";
  } else {
    std::cout << "\nNotes\n";
    for (unsigned int i = 0; i < size(); i++) {
      std::cout << i + 1 << ". " << (*notes_ + i)->title() << "\n";
    }
    std::cout << "\n";
  }
}
// function to display the notes body according to the index the user inputs
void Notebook::view() const {
  list();

  if (size_ > 0) {
    int index = 0;
    std::cout << "Please input note index: ";
    std::cin >> index;
    std::cin.ignore();

    if (index - 1 >= size_) {
      std::cout << "\nInvalid note index.\n\n";
    } else {
      std::cout << "\n";
      notes_[index - 1]->display();
    }
  }
}

// function that saves notes
void Notebook::save(const std::string &filename) const {
  std::ofstream save_file;
  save_file.open(filename);
  save_file << size_ << "\n";

  for (int i = 0; i < size_; i++) {
    save_file << notes_[i]->serialize();
  }
  save_file.close();
  std::cout << "Notes saved!\n\n";
}

// function that loads notes
void Notebook::load(const std::string &filename) {
  size_ = 0;
  std::ifstream load_file;
  load_file.open(filename);
  load_file >> size_;
  load_file.ignore();

  std::string temp;
  for (int i = 0; i < size_; i++) {
    std::getline(load_file, temp);

    if (temp == "[Note]") {
      Note *temp_note = new Note();
      getline(load_file, temp);
      temp_note->set_title(temp);
      getline(load_file, temp);
      temp_note->set_body(temp);
    } else if (temp == "[EncNote]") {
      EncryptedNote *temp_note = new EncryptedNote();
      getline(load_file, temp);
      temp_note->set_title(temp);
      getline(load_file, temp);
      temp_note->set_body(temp);
      getline(load_file, temp);
      temp_note->set_password(temp);
    }
    load_file.close();
    std::cout << "Notes loaded!\n\n";
  }
}
