#include <iomanip>
#include <iostream>
#include <string>

class Note {
private:
  std::string title_;
  std::string body_;

public:
  Note() : Note("Untitled", "") {}
  Note(const std::string &title, const std::string &body)
      : title_(title), body_(body) {}

  void set_title(const std::string title) { title_ = title; }
  void set_body(const std::string body) { body_ = body; }
  std::string title() { return title_; }
  std::string body() { return body_; }

  virtual void display() const {
    std::cout << "[" << title_ << "]\n" << body_ << "\n\n";
  }

  virtual std::string serialize() {
    std::string serialize_one;
    serialize_one = "[Note]" + "\n" + title_ + "\n" << body_ + "\n";
    return serialize_one;
  }
};

class EncryptedNote : public Note {
private:
  std::string password_;

public:
  EncryptedNote() : password_("") {}
  EncryptedNote(const std::string &title, const std::string &body,
                const std::string &password)
      : Note(title, body), password_(password) {}

  std::string password() const { return password_; }
  void set_password(const std::string &password) { password_ = password; }

  void display() const override;
  std::string serialize() override {
    std::string serialize_one;
    serialize_one =
        "[EncNote]\n" + title() + "\n" + body() + "\n" + password_ + "\n";
    return serialize_one;
  }
};

class Notebook {
private:
  int capacity_, size_;
  Note **notes_;

public:
  Notebook() : Notebook(100) {}
  Notebook(int capacity)
      : capacity_(capacity), size_(0), notes_(new Note *[capacity]) {}

  // deconstructor and deletes the Note array from memory
  ~Notebook() {
    delete[] notes_;
    notes_ = nullptr;
  }

  int capacity() const { return capacity_; }
  int size() const { return size_; }

  void add(Note *new_note) { notes_[size_++] = new_note; }
  Note *get(int index) const { return notes_[index]; };
  void list() const;
  void view() const;
  void save(const std::string &filename) const;
  void load(const std::string &filename);
};

Note *create_note();
EncryptedNote *create_encrypted_note();
