# TuffyNotes Project Milestone 6

This is milestone 6 of the [TuffyNotes Project](https://docs.google.com/document/d/14qiyhHtXpZOkVqHdUmLjLu1OWcBhQijvqybHtgsEWhI/edit?usp=sharing).

# Requirements
Create a new type of `Note` called the `EncryptedNote` that functions exactly like a `Note`, but requires the user to provide a password to view it. This should be implemented using inheritance. Moreover, you need to refactor the code from Milestone 5 to use `Note` pointers instead of objects to implement polymorphism. The features from Milestone 5 should work the same way in this version of the software.

## Note class modifications
### Data members
no changes

### Constructors
no changes

### Member functions
- `display()` - there are no significant changes to this function, but a specific keyword needs to be used to allow polymorphism
- `std::string serialize()` - This new method should return a string that represents the object. It will be used for saving the object. Specifically, it should use the following format:

   ```"[Note]\n" + title + "\n" + body + "\n"```

   A specific keyword also needs to be used to allow polymorphism

## EncryptedNote class
This class should derive from the `Note` class so it will inherit its data members and methods

### Data members
- `password_` - password that will be used to view the note

### Constructors
- `EncryptedNote()` - initializes the `EncryptedNote` by setting its password to an empty string (`""`)
- `EncryptedNote(const std::string &title, const std::string &body, const std::string &password)` - initializes the `EncryptedNote` by calling its base class' constructor (`Note`) and setting its password to the given parameter

### Member functions
- `display()` - displays the title and body only if the correct password is provided. Specifically, it should ask the user to enter a password first using the text: `Please enter password to view note: `. The note's title and body will be shown the same way that the `Note` class' `display()` method works. If an incorrect password is provided, then it should display: `Sorry, you do not have the permission to view note.\n\n`. Kindly see the sample output for more details. This method overrides `Notes`' implementation. Make sure to use the keyword that will allow polymorphism
- `std::string serialize()` - return a string that represents the object. It will be used for saving the object. Specifically, it should use the following format:

   ```"[EncNote]\n" + title + "\n" + body + "\n" + password + "\n"```

   A specific keyword also needs to be used to allow polymorphism

## Notebook class modifications
### Data members
- `notes_` - this should now be a pointer to an array of `Note*` objects

### Constructors
- `Notebook()` - this should be updated so that it dynamically creates an array of `Note*`
- `Notebook(int capacity)` - this should be updated so that it dynamically creates an array of `Note*`

### Destructor
The previously mentioned changes make `notes_` an array of `Note*`. Therefore each of those pointers need to be deleted. Then, delete the `Note` array from memory and set `notes_` to `nullptr` to avoid *dangling pointers*

### Member functions
- `void add(Note* new_note)` - this method should now receive a `Note*` that will be added to the `Notebook`
- `Note* get(int index) const` - this method should now return a pointer to a `Note` object in the `notes_` array.
- `void list() const` - update to use pointers instead of objects
- `void view() const` - update to use pointers instead of objects
- `void save(const std::string &filename) const` - update to use pointers instead of objects. *Hint: you can now use the `serialize()` method to generate the text that will be saved in the text file*
- `void load(const std::string &filename)` - update to use pointers instead of objects. Make sure that you delete all `Note*` in the `notes_` array and delete the array from the heap before loading a file. Also dynamically create an entirely new array of `Note*` using the same `capacity_` used when the `Notebook` was created. Finally, take note that there are now 2 types of objects. The method should create a `Note` object when it sees `[Note]` and an `EncryptedNote` object when it sees `[EncNote]`

## Global functions
- `Note* create_note()` - this function should now dynamically allocate a Note object in the heap, assign it the values from user input, then return the **address** of that object
- `EncryptedNote* create_encrypted_note()` - this function should dynamically allocate an EncryptedNote object, assign it the values from user input, then return the **address** of that object. The values it asks from the user are its title, body, and password. Kindly follow the text below (see the sample output for more details)

   ```
   \nPlease enter the note's title:
   Please enter the note:
   Please enter the password:
   \nEncrypted Note added!\n\n
   ```

# Driver (tuffynotes.cpp)
The driver file that contains the menu should be updated so that it uses `Notebook`, `Note`, and `EncryptedNote` objects. The menu must call the appropriate methods from the updated code.

All previously created functionalities from Milestones 1 to 5s should still work as expected. Kindly refer to the sample output below and follow it as closely as possible.
```
Welcome to TuffyNotes!

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: c

Please enter the note's title: Grocery list
Please enter the note: milk, banana, water, turkey sandwich

Note added!

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: c

Please enter the note's title: Band mates
Please enter the note: Geddy Lee, Alex Lifeson, Neil Peart

Note added!

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: n

Please enter the note's title: Passwords
Please enter the note: Facebook - zucky; Twitter - dorsi
Please enter the password: secret

Encrypted Note added!

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: l

Notes
1. Grocery list
2. Band mates
3. Passwords

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: v

Notes
1. Grocery list
2. Band mates
3. Passwords

Please input note index: 2

[Band mates]
Geddy Lee, Alex Lifeson, Neil Peart

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: v

Notes
1. Grocery list
2. Band mates
3. Passwords

Please input note index: 3

Please enter password to view note: sec
Sorry, you do not have the permission to view note.

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: v

Notes
1. Grocery list
2. Band mates
3. Passwords

Please input note index: 3

Please enter password to view note: secret
[Passwords]
Facebook - zucky; Twitter - dorsi

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: s

Please enter filename: my_notes.txt
Notes saved!

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: c

Please enter the note's title: Enrolled courses
Please enter the note: CPSC 121, CPSC 481

Note added!

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: l

Notes
1. Grocery list
2. Band mates
3. Passwords
4. Enrolled courses

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: o

Please enter filename: my_notes.txt
Notes loaded!

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: l

Notes
1. Grocery list
2. Band mates
3. Passwords

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: j

Invalid choice. Please try again.

[C] Create a note
[N] Create an encrypted note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: e

Thank you for using TuffyNotes!
```

Place the function/method prototypes and classes in `notebook.hpp`, the function and method implementations in `notebook.cpp`, and the main function in `tuffynotes.cpp`. Take note that in the case of classes, any method whose body is over 5 lines or uses advanced constructs (e.g., if, switch, for) should have its implementation in `notebook.cpp`.

# Submission checklist
1. Created function prototype
1. Created function implementation
1. Called function in the driver
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

# Documentation
See [google's style guide](https://google.github.io/styleguide/cppguide.html#Comments) for more details.

## File comments
Describe the contents of the file on the first line. For example:

```cpp
// This file implements a simple calculator
```

## Function comments
Describe the use of the function and how it is implemented if it is non-obvious. For example:

```cpp
// Displays a greeting based on the time of day on the command line using the name parameter.
void show_greeting(std::string name) {
  ...
}
```

## Implementation comments
Provide comments in tricky, non-obvious, interesting, or important parts of your code.

```cpp
// Compute the distance between two points using the Manhattan distance formula
double dist = sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
```

# Code evaluation
Open the terminal and navigate to the folder that contains this milestone. Assuming you have pulled the code inside of `/home/student/project02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd project02-tuffy
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample commands below shows how you would compile code saved in `tuffynotes.cpp` and `notebook.cpp` and into the executable file `tuffynotes`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 tuffynotes.cpp notebook.cpp -o tuffynotes
./tuffynotes
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add .
    ```

1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```

1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```

    When you're done, make sure you type `git commit` again.   

1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.

1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```

1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the project milestone page. Provide a short message in the text area such as "finished milestone" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
