/*
EZTechMovie Company customer and movie management software.
This software enables front-line employees to add, search, and delete customer records, and
to add, search, and delete movie records.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct EZTechCustomer {
    string fname; string lname; string accountNumber; string email; string phone; string birth_date; string start_date; string sub_ID; string sub_status;
    string pmt_method; string userID; string password;
} customerEntry[10]; //Dynamic array of strings for movie information;

void outputcustomer(EZTechCustomer customer);

struct EZTechMovie {
    string name; string cast; string rating; string description; string releaseyear; string genre;
} movieListEntry[10]; //Dynamic array of strings for movie information;

void outputmovie(EZTechMovie movies);

int main() {

    ofstream outFile;
    ifstream inFile;
    int size = 0;
    int numMovies = 0;

    int menuOption = 0;

    cout << "--- EZTechMovie database management system --- \n";
    cout << "--- Please select the option from the following menu to proceed. --- \n";
    while (menuOption != 7) {
        cout << "1 - Add Customer" << endl <<
            "2 - Search Customer" << endl <<
            "3 - Delete Customer" << endl <<
            "4 - Add Movie" << endl <<
            "5 - Search Movie" << endl <<
            "6 - Delete Movie" << endl <<
            "7 - Quit" << endl <<
            "Enter the number of the menu item you want to access: ";
        cin >> menuOption; // receive input for menu selection
        cin.ignore(); //ignore trailing whitespace
        if (menuOption == 1 || menuOption == 2 || menuOption == 3 || menuOption == 4 || menuOption == 5 || menuOption == 6 || menuOption == 7) {
            if (menuOption == 1) {
                // create variables for use in customer entry functions

                struct EZTechCustomer;
                bool addCustomer;
                string addMore = "yes";
                int n;
                outFile.open("customerdata.txt", ios_base::app);

                cout << "--- EZTechMovie customer database entry system --- \n";
                addCustomer = true; // assign beginning value
                n = 0; // set counter to limit customer entry to the struct array to 0
                while (addCustomer == true && n < 10) {
                    cout << "\n Enter first name: ";
                    getline(cin, customerEntry[n].fname); // receive variable input for customer first name
                    outFile << customerEntry[n].fname << endl;
                    cout << "\n Enter last name: ";
                    getline(cin, customerEntry[n].lname); // receive variable input for customer last name
                    outFile << customerEntry[n].lname << endl;
                    cout << "\n Enter Account Number: ";
                    getline(cin, customerEntry[n].accountNumber); // receive variable input for customer last name
                    outFile << customerEntry[n].accountNumber << endl;
                    cout << "\n Enter customer email: ";
                    getline(cin, customerEntry[n].email); // receive variable input for customer email
                    outFile << customerEntry[n].email << endl;
                    cout << "\n Enter customer phone number: ";
                    cin >> customerEntry[n].phone; // receive variable input for customer phone
                    outFile << customerEntry[n].phone << endl;
                    cout << "\n Enter customer birth date (MMDDYYYY): ";
                    cin >> customerEntry[n].birth_date; // receive variable input for customer date of birth
                    outFile << customerEntry[n].birth_date << endl;
                    cout << "\n Enter start date (MMDDYYYY): ";
                    cin >> customerEntry[n].start_date; // receive variable input for customer start date
                    outFile << customerEntry[n].start_date << endl;
                    cout << "\n Enter payment method (card/echeck/PayPal): ";
                    cin >> customerEntry[n].pmt_method; // receive input for payment method
                    outFile << customerEntry[n].pmt_method << endl;
                    cout << "\n Enter subscription ID (Stream[1-3]/Ship[1-3]): ";
                    cin >> customerEntry[n].sub_ID; // receive input for payment method
                    outFile << customerEntry[n].sub_ID << endl;
                    cout << "\n Enter suscription status (active/inactive): ";
                    cin >> customerEntry[n].sub_status; // receive input for payment method
                    outFile << customerEntry[n].sub_status << endl;
                    cout << "\n Enter customer user ID: ";
                    cin >> customerEntry[n].userID; // receive input for payment method
                    outFile << customerEntry[n].userID << endl;
                    cout << "\n Enter customer password: ";
                    cin >> customerEntry[n].password; // receive input for password
                    outFile << customerEntry[n].password << endl;
                    ++size;
                    outputcustomer(customerEntry[n]); // output current movie inputs as loaded to struct
                    n++;
                    if (n < 10) { // check that the counter limit is unmet before asking about additional entry
                        cout << "Would you like to store additional customers?" << std::endl;
                        cin >> addMore; // receive input whether to continue
                        cin.ignore(); //ignore trailing whitespace
                        if (addMore == "no" || addMore == "n" || addMore == "NO" || addMore == "No") {
                            addCustomer = false;  //change variable to exit the loop
                        }
                    }
                }
                outFile.close();
            }
            if (menuOption == 2)  //search for customer saved to file
            {
                struct EZTechCustomer customer;
                bool found = false;

                inFile.open("customerdata.txt");
                string searchString;
                cout << "Enter last name to search for: ";
                cin >> searchString;
                string line;
                if (inFile.is_open())
                {
                    while (!inFile.eof()) //reading the file to retrieve customer
                    {
                        getline(inFile, customer.fname);
                        getline(inFile, customer.lname);
                        getline(inFile, customer.accountNumber);
                        getline(inFile, customer.email);
                        getline(inFile, customer.phone);
                        getline(inFile, customer.birth_date);
                        getline(inFile, customer.start_date);
                        getline(inFile, customer.pmt_method);
                        getline(inFile, customer.sub_ID);
                        getline(inFile, customer.sub_status);
                        getline(inFile, customer.userID);
                        getline(inFile, customer.password);
                        if (searchString == customer.lname)
                        {
                            found = true;
                            cout << "Customer found!";
                            outputcustomer(customer);
                            break;
                        }
                    }
                    if (found == false)
                    {
                        cout << "Customer not found!" << endl;
                    }
                }
                inFile.close(); //closing the file
            }
            if (menuOption == 3)  //deleting the customer information
            {
                inFile.open("customerdata.txt");
                int i = 0;
                int deletionIndex = -1;
                string fname, lname;
                cout << "Enter the customer first name and last name in order: ";
                cin >> fname >> lname;
                while (!inFile.eof()) //traversing the file and storing data in array excluding customer to be deleted
                {
                    getline(inFile, customerEntry[i].fname);
                    getline(inFile, customerEntry[i].lname);
                    getline(inFile, customerEntry[i].accountNumber);
                    getline(inFile, customerEntry[i].email);
                    getline(inFile, customerEntry[i].phone);
                    getline(inFile, customerEntry[i].birth_date);
                    getline(inFile, customerEntry[i].start_date);
                    getline(inFile, customerEntry[i].pmt_method);
                    getline(inFile, customerEntry[i].sub_ID);
                    getline(inFile, customerEntry[i].sub_status);
                    getline(inFile, customerEntry[i].userID);
                    getline(inFile, customerEntry[i].password);
                    if (fname == customerEntry[i].fname && lname == customerEntry[i].lname)
                    {
                        deletionIndex = i;
                        --size;
                        --i;
                    }
                    ++i;
                }

                inFile.close();

                if (deletionIndex != -1)
                {
                    outFile.open("customerdata.txt");
                    for (i = 0; i < size; ++i) //writing the customer array data to file
                    {
                        outFile << customerEntry[i].fname << endl;
                        outFile << customerEntry[i].lname << endl;
                        outFile << customerEntry[i].accountNumber << endl;
                        outFile << customerEntry[i].email << endl;
                        outFile << customerEntry[i].phone << endl;
                        outFile << customerEntry[i].birth_date << endl;
                        outFile << customerEntry[i].start_date << endl;
                        outFile << customerEntry[i].pmt_method << endl;
                        outFile << customerEntry[i].sub_ID << endl;
                        outFile << customerEntry[i].sub_status << endl;
                        outFile << customerEntry[i].userID << endl;
                        outFile << customerEntry[i].password << endl;
                    }
                    outFile.close();
                    cout << "Record deleted" << endl;
                }
                else
                {
                    cout << "Customer not found." << endl;
                }

            }


            if (menuOption == 4) //adding movie to database
            {

                struct EZTechMovie;
                bool addMovies;
                bool addCast;
                string addMore = "yes";
                string addMoreCast = "yes";
                string castMember;
                int j;
                int n;
                // int i;

                outFile.open("moviedata.txt", ios_base::app);

                cout << "--- EZTechMovie movies database entry system --- \n";
                addMovies = true;
                addCast = true;
                n = 0; // set counter to limit movie entry to the struct array to 0
                while (addMovies == true && n < 10) {
                    cout << "\n Enter title: ";
                    getline(cin, movieListEntry[n].name); // receive variable input for movie name
                    outFile << movieListEntry[n].name << endl;
                    cout << "\n Enter up to four main cast members";
                    j = 0; // set counter for limiting cast member entry to 0
                    while (j < 4 && addCast == true) { // while loop to add up to four cast members
                        cout << "\n Enter cast member first and last name : ";
                        getline(cin, castMember); // receive variable input for movie cast
                        if (j == 0) {
                            movieListEntry[n].cast = castMember;
                        }
                        else {
                            movieListEntry[n].cast = movieListEntry[n].cast + ", " + castMember;
                        }
                        j++;
                        if (j < 4) { // check that the counter limit is unmet before asking about additional entry
                            cout << "\n Enter another cast member? ";
                            cin >> addMoreCast; // receive input whether to continue
                            cin.ignore(); //ignore trailing whitespace
                            if (addMoreCast == "no" || addMoreCast == "n" || addMoreCast == "NO" || addMoreCast == "No") {
                                addCast = false;  //change variable to exit the loop
                            }
                        }
                    }
                    outFile << movieListEntry[n].cast << endl;
                    cout << "\n Enter description: ";
                    getline(cin, movieListEntry[n].description); // receive variable input for movie description
                    outFile << movieListEntry[n].description << endl;
                    cout << "\n Enter rating: ";
                    getline(cin, movieListEntry[n].rating); // receive variable input for movie rating
                    outFile << movieListEntry[n].rating << endl;
                    cout << "\n Enter release year: ";
                    cin >> movieListEntry[n].releaseyear; // receive input whether to continue
                    cin.ignore(); //ignore trailing whitespace
                    outFile << movieListEntry[n].releaseyear << endl;
                    cout << "\n Enter genre: ";
                    cin >> movieListEntry[n].genre; // receive input whether to continue
                    outFile << movieListEntry[n].genre << endl;
                    cin.ignore(); //ignore trailing whitespace
                    ++numMovies;
                    outputmovie(movieListEntry[n]); // output current movie inputs as loaded to struct
                    n++;
                    if (n < 10) { // check that the counter limit is unmet before asking about additional entry
                        cout << "Would you like to store additional movies?" << std::endl;
                        cin >> addMore; // receive input whether to continue
                        cin.ignore(); //ignore trailing whitespace
                        if (addMore == "no" || addMore == "n" || addMore == "NO" || addMore == "No") {
                            addMovies = false;  //change variable to exit the loop
                        }
                    }
                }
                outFile.close();
            }
            if (menuOption == 5) //search for movie in database
            {
                struct EZTechMovie movie;
                bool found = false;

                inFile.open("moviedata.txt");
                string searchString;
                cout << "Enter movie name to search for: ";
                cin >> searchString;
                string line;
                if (inFile.is_open())
                {
                    while (!inFile.eof()) //traversing the file to search the given movie name
                    {
                        getline(inFile, movie.name);
                        getline(inFile, movie.cast);
                        getline(inFile, movie.description);
                        getline(inFile, movie.rating);
                        getline(inFile, movie.releaseyear);
                        getline(inFile, movie.genre);

                        if (searchString == movie.name)
                        {
                            found = true;
                            cout << "Movie found!";
                            outputmovie(movie);
                            break;
                        }
                    }
                    if (found == false)
                    {
                        cout << "Movie not found!" << endl;
                    }
                }
                inFile.close();
            }

            if (menuOption == 6)  //deleting the movie from database
            {
                inFile.open("moviedata.txt");
                int i = 0;
                int deletionIndex = -1;
                string name;
                cout << "Enter movie name: ";
                cin >> name;

                while (!inFile.eof())   //traversing the file and 
                                        //storing the data in array excluding the movie to be deleted
                {
                    getline(inFile, movieListEntry[i].name);
                    getline(inFile, movieListEntry[i].cast);
                    getline(inFile, movieListEntry[i].description);
                    getline(inFile, movieListEntry[i].rating);
                    getline(inFile, movieListEntry[i].releaseyear);
                    getline(inFile, movieListEntry[i].genre);
                    if (name == movieListEntry[i].name)
                    {
                        deletionIndex = i;
                        --numMovies;
                        --i;
                    }
                    ++i;
                }

                inFile.close();

                if (deletionIndex != -1)
                {
                    outFile.open("moviedata.txt");
                    for (i = 0; i < numMovies; ++i)  //storing the movie array data back into file
                    {
                        outFile << movieListEntry[i].name << endl;
                        outFile << movieListEntry[i].cast << endl;
                        outFile << movieListEntry[i].description << endl;
                        outFile << movieListEntry[i].rating << endl;
                        outFile << movieListEntry[i].releaseyear << endl;
                        outFile << movieListEntry[i].genre << endl;
                    }
                    outFile.close();
                    cout << "Record deleted" << endl;
                }
                else
                {
                    cout << "Movie not found." << endl;
                }
            }

            if (menuOption == 7)
            {
                cout << "Bye Bye!!!";
                return 0;
            }

        }
        else {
            cout << endl << "You have not entered a valid option." << endl;
            cout << "Enter the number of the menu item you want to access:\n 1 - Add Customer \n  2 - Search Customer \n  3 - Delete Customer \n  4 - Add Movie \n   5 - Search Movie \n   6 - Delete Movie \n   7 - Quit \n ";
            cin >> menuOption; // receive input for menu selection
        }

    }
    return 0;
}

void outputcustomer(EZTechCustomer customer) {  //displaying the customer information
    cout << "\n ---- " << endl << " You entered " << endl;
    cout << "Customer Name: " + customer.fname + " " + customer.lname << endl;
    cout << "Account Number: " + customer.accountNumber << endl;
    cout << "Email:" + customer.email << endl;
    cout << "Phone: " + customer.phone << endl;
    cout << "Date of Birth: " + customer.birth_date << endl;
    cout << "Start Date: " + customer.start_date << endl;
    cout << "Payment Method: " + customer.pmt_method << endl;
    cout << "Subscription type: " + customer.sub_ID << endl << " ----" << endl;
    cout << "Subscription status: " + customer.sub_status << endl << " ----" << endl;
    cout << "User ID: " + customer.userID << endl << " ----" << endl;
    cout << "Password: " + customer.password << endl << " ----" << endl;
}

void outputmovie(EZTechMovie movies) {   // displaying the movie information
    cout << "\n ---- " << endl << " You entered " << endl;
    cout << "Movie title: " + movies.name << endl;
    cout << "Main Cast:" << endl << " Cast members: " + movies.cast << endl;
    cout << "Description: " + movies.description << endl;
    cout << "Rating: " + movies.rating << endl;
    cout << "Year Released: " + movies.releaseyear << endl;
    cout << "Genre: " + movies.genre << endl << " ----" << endl;
}