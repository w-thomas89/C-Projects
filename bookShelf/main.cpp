/*  ~UPDATES PERFORMED~
 *  W.Thomas - added constructors to struct 10.1.2021
 *  W.Thomas - changed add book output/input to use getline to prevent overlapping 10.1.2021
 *
 *
 *
 *  ~UPDATES REQUESTED~
 *  Use .at() for vector referencing. .at() is a vector library function and will automatically throw exceptions if out_of_bounds
 *  Use constant string array for output information. Vectors are dynamic and hold higher memory value than a declare array. *editBook*
 *
 */

#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Book { //Bobby
public:
    string title;
    string author;
    string publisher;
    string genre;
    string description;
    //no-arg constructor W.Thomas

    Book() {
        string title, author, publisher, genre, description;
    }
    //arg passed constructor - W.Thomas
    Book(string title, string author, string publisher, string genre, string description) {
        this->title = title;
        this->author = author;
        this->publisher = publisher;
        this->genre = genre;
        this->description = description;
    }

};

class Bookshelf {
public:
    void addBook(vector<Book> &books) { //William
        //constants
        const string askTitle = "Please enter the Title for the book: ";
        const string askAuthor = "Please enter the Author for the book: ";
        const string askPub = "Please enter the publisher of the book: ";
        const string askGenre = "Please enter the genre of your book: ";
        const string askDesc = "Please enter a simple description of the book: ";
        //variables
        string title, author, publisher, genre, description;
        char correct, more;
        bool add = true;
        //program
        while (add) {
            do {
                printf(askTitle.data());
                cin.ignore();
                getline(cin, title);
                printf(askAuthor.data());
                cin.ignore(-1);
                getline(cin, author);
                printf(askPub.data());
                cin.ignore(-1);
                getline(cin, publisher);
                printf(askGenre.data());
                cin.ignore(-1);
                getline(cin, genre);
                printf(askDesc.data());
                cin.ignore(-1);
                getline(cin, description);
                cin.clear();
                //trying to create a validation loop that compares the input var title to an object.title from the vector to prevent double inputs.
                /*
                 * for (size_t i = 0; i < books.size(); i++) {
                 *  cout << title.compare(books.at(i).title) << endl;
                 * }
                */
                cout << title << " by " << author << "\nPublished by: " << publisher //W.Thomas changed vector index reference to use .at() for testing
                     << "\nGenre: " << genre << "\nDescription: " << description << endl << endl;
                cout << "Is this correct? (y for yes)" << endl;
                cin >> correct;
                if (tolower(correct) == 'y') {
                    Book b = Book(title, author, publisher, genre, description);
                    books.push_back(b);
                }
            } while (tolower(correct) != 'y');
            cout << "More books to add? (n for no)" << endl;
            cin >> more;
            if (tolower(more) == 'n')
            {
                add = false;
            }
        }



        /*
        cout << askTitle << endl;
        cin >> title;
        cout << askAuthor << endl;
        cin >> author;
        cout << askPub << endl;
        cin >> publisher;
        cout << askGenre << endl;
        cin >> genre;
        cout << askDesc << endl;
        cin >> description;
        */
    }

    void remove(vector<Book> &books){ //Josiah
        unsigned int bookRemove;
        list(books);
        if(!books.empty()){

            // Prompt the user to select a book
            cout << "Select a book to remove" << endl;
            cout << endl << "Enter a number: ";

            // Receive input
            cin >> bookRemove;

            // Input Validation
            while (cin.fail() || bookRemove <= 0 || bookRemove > books.size()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Sorry not an available book to remove" << endl << "Enter a number" << endl;
                cin >> bookRemove;
            }
            // Display to the user the book that has been removed
            cout << books.at(bookRemove - 1).title << " has been removed" << endl << endl;
            // Remove the book
            books.erase(books.begin()+ (bookRemove - 1));

            list(books);
        }
        else{
            cout << "There are no books on the bookshelf" << endl;
        }
    }

    void edit(vector<Book> &books){ //Dylan
            int bookToEdit, detailToEdit, shelfSize = books.size();
            const string details[5] = {"1) Title: ", "2) Author: ", "3) Publisher: ", "4) Genre: ", "5) Description: "};

            // Display menu of books in bookshelf
            cout << "Books\n--------------------" << endl;
            for (int i=0; i < shelfSize; i++){
                cout << i+1 << ") " << books.at(i).title << endl;
            }

            // Get input for which book to edit
            cout << "\nSelect a book to edit: ";

            // Input validation
            while (!(cin >> bookToEdit) || bookToEdit <= 0 || bookToEdit > shelfSize){
                cout << "\nInvalid entry, please select a book to edit: ";
                cin.clear();
                cin.ignore(100, '\n');
            }

            // Account for indexing
            bookToEdit -=1;

            // Create array of chosen book details for easy menu display
            const string choiceDetails[5] = {books.at(bookToEdit).title, books.at(bookToEdit).author, books.at(bookToEdit).publisher, books.at(bookToEdit).genre, books.at(bookToEdit).description};

            // Display menu of edit options with the current values
            cout << "\nBook details\n--------------------" << endl;
            for (int i=0; i < 5; i++){
                cout << details[i] << choiceDetails[i]<< endl;
            }

            // Get input for which value to edit
            cout << "\nSelect a detail to edit: ";

            // Input validation
            while (!(cin >> detailToEdit) || detailToEdit <= 0 || detailToEdit > 5){
                cout << "\nInvalid entry, please select a detail to edit: ";
                cin.clear();
                cin.ignore(100, '\n');
            }

            // Get input for the new value and use it to change the original value
            cout << "\nEnter the new value: ";
            if (detailToEdit == 1){
                cin.ignore();
                getline(cin, books.at(bookToEdit).title);
                cout << "Title changed to: " << books.at(bookToEdit).title << endl << endl;
            }
            else if (detailToEdit == 2){
                cin.ignore();
                getline(cin, books.at(bookToEdit).author);
                cout << "Author changed to: " << books.at(bookToEdit).author << endl << endl;
            }
            else if (detailToEdit == 3){
                cin.ignore();
                getline(cin, books.at(bookToEdit).publisher);
                cout << "Publisher changed to: " << books.at(bookToEdit).publisher << endl << endl;
            }
            else if (detailToEdit == 4){
                cin.ignore();
                getline(cin, books.at(bookToEdit).genre);
                cout << "Genre changed to: " << books.at(bookToEdit).genre << endl << endl;
            }
            else if (detailToEdit == 5){
                cin.ignore();
                getline(cin, books.at(bookToEdit).description);
                cout << "Description changed to: " << books.at(bookToEdit).description << endl << endl;
            }
        }

    void search(vector<Book> &books) { //Chris
            int category;             // search category with 3 choices -author, title, genre
            bool found = false;
            string tempAuthor;
            string tempTitle;
            string tempGenre;
            size_t partialFound;

            cout << "Please enter 1 to search by author, 2 to search by book title, or 3 to search by genre: ";
            cin >> category;

            if (category == 1) {
                string authorName;

                cin.ignore();
                getline(cin, authorName);
                transform(authorName.begin(), authorName.end(), authorName.begin(), ::toupper);  //capitalize name

                // searching by author. tempAuthor is author in that vector. If it matches info is outputed. Same formula for other cats.
                for (unsigned int i = 0; i < books.size(); i++) {
                    tempAuthor = books[i].author;
                    transform(tempAuthor.begin(), tempAuthor.end(), tempAuthor.begin(), ::toupper);

                    partialFound = tempAuthor.find(authorName);

                    if (tempAuthor == authorName) {
                        cout << "-" << books.at(i).title << " by " << books.at(i).author << "\nPublished by: " << books.at(i).publisher
                             << "\nGenre: " << books.at(i).genre << "\nDescription: " << books.at(i).description << endl << endl;
                        found = true;
                    }
                    // Look for partial match
                    else if(partialFound != string::npos){
                        // Print book
                        cout << "-" << books.at(i).title << " by " << books.at(i).author << "\nPublished by: " << books.at(i).publisher
                             << "\nGenre: " << books.at(i).genre << "\nDescription: " << books.at(i).description << endl << endl;
                        found = true;
                    }

                }
            } else if (category == 2) {
                string bookName;

                cout << "Please enter book title: ";
                cin.ignore();
                getline(cin, bookName);
                transform(bookName.begin(), bookName.end(), bookName.begin(), ::toupper);

                for (unsigned int i = 0; i < books.size(); i++) {
                    tempTitle = books[i].title;
                    transform(tempTitle.begin(), tempTitle.end(), tempTitle.begin(), ::toupper);

                    partialFound = tempTitle.find(bookName);

                    if (tempTitle == bookName) {
                        cout << "-" << books.at(i).title << " by " << books.at(i).author << "\nPublished by: " << books.at(i).publisher
                             << "\nGenre: " << books.at(i).genre << "\nDescription: " << books.at(i).description << endl << endl;
                        found = true;
                    }
                    // Look for partial match
                    else if(partialFound != string::npos){
                        // Print book
                        cout << "-" << books.at(i).title << " by " << books.at(i).author << "\nPublished by: " << books.at(i).publisher
                             << "\nGenre: " << books.at(i).genre << "\nDescription: " << books.at(i).description << endl << endl;
                        found = true;
                    }
                }
            } else if (category == 3) {
                string genreName;

                cout << "Please enter book genre: ";
                cin.ignore();
                getline(cin, genreName);
                transform(genreName.begin(), genreName.end(), genreName.begin(), ::toupper);

                for (unsigned int i = 0; i < books.size(); i++) {
                    tempGenre = books[i].genre;
                    transform(tempGenre.begin(), tempGenre.end(), tempGenre.begin(), ::toupper);

                    partialFound = tempGenre.find(genreName);

                    if (tempGenre == genreName) {
                        cout << "-" << books.at(i).title << " by " << books.at(i).author << "\nPublished by: " << books.at(i).publisher
                             << "\nGenre: " << books.at(i).genre << "\nDescription: " << books.at(i).description << endl << endl;
                        found = true;
                    }
                    // Look for partial match
                    else if(partialFound != string::npos){
                        cout << "-" << books.at(i).title << " by " << books.at(i).author << "\nPublished by: " << books.at(i).publisher
                             << "\nGenre: " << books.at(i).genre << "\nDescription: " << books.at(i).description << endl << endl;
                        found = true;
                    }
                }
            } else {
                cout << "Invalid input." << endl;  // message for invalid input i.e. any input not 1 -3
            }

            if (found == false) {
                cout << "Term not found in bookshelf." << endl;  //message for book not found
            }
        }

    void list(vector<Book> &books) { //Matthew

        //we put them in alphabetical order
        sort(books.begin(), books.end(), [](Book a, Book b) {
            return a.title < b.title;
        });

        //output all the books
        for(unsigned int i = 0; i < books.size(); i++) {
            cout << i + 1 << ". " << books.at(i).title << " by " << books.at(i).author << "\nPublished by: " << books.at(i).publisher //W.Thomas changed vector index reference to use .at() for testing
                 << "\nGenre: " << books.at(i).genre << "\nDescription: " << books.at(i).description << endl << endl;
        }
    }
};

int main()
{
    //Ryan & Leia
    const string menuSelection[6] = {"Add a book", "Delete a book", "Edit a book", "Search for a book", "List bookshelf", "Exit program"};
    char selection = 0;
    string input = "";
    vector<Book> books;
    Bookshelf shelf;

    //Creating default books
    Book defBook1 = Book("Frankenstein", "Mary Shelley", "Simon & Schuster", "Gothic Fiction", "A scientist challenges the morality of science and creates life itself, only to be horrored by what he's created.");
    Book defBook2 = Book("The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Tragedy", "The tragedy of a flawed millionaire who built himself up from rock bottom to win the heart back of his long lost love.");
    Book defBook3 = Book("The Lion, the Witch and the Wardrobe", "C. S. Lewis", "Geoffrey Bles", "Fantasy", "Four siblings find a wardrobe that leads to a magical land full of adventure, heartbreak, and friendship.");
    Book defBook4 = Book("The Fellowship of the Ring", "J. R. R. Tolkien", "Allen & Unwin", "High Fantasy", "The beginning journey of Frodo Baggins, a Hobbit from a little village in the Shire, to destroy the One Ring that will dismantle all of Middle Earth if put into the wrong hands.");

    //Adding default books to vector
    books.push_back(defBook1);
    books.push_back(defBook2);
    books.push_back(defBook3);
    books.push_back(defBook4);

    cout << "Welcome to the Bookshelf\n--------------------" << endl << endl;
    while(selection != '6'){ //Displaying the menu
        for(int i = 0; i < 6; i++){
            cout << i + 1 << ") " << menuSelection[i] << endl;
        }
        cout << "Please select an option: ";
        cin >> input;
        cout << endl;
        selection = input[0];
        while(selection < '1' || selection > '6'){ //Checking for invalid input
            cout << "Invalid Entry, Please select an option: ";
            cin >> input;
            selection = input[0];
        }
        if(selection == '1'){
            shelf.addBook(books);
        }
        else if(selection == '2'){
            shelf.remove(books);
        }
        else if(selection == '3'){
            shelf.edit(books);
        }
        else if(selection == '4'){
            shelf.search(books);
        }
        else if(selection == '5'){
            shelf.list(books);
        } else if(selection == '6'){
            return -1;
        }

        //Getch allows user to look at results of their action before moving on to reprinting the menu
        cout << "Press anything to return to the menu" << endl;
        getch();
        cout << endl;
    }

    return 0;
}
