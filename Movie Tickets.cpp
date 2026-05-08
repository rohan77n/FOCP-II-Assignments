#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class MovieTicket {
private:
    // movieID -> set of customerIDs
    unordered_map<int, unordered_set<int>> bookings;

public:

    // BOOK X Y
    bool book(int customerID, int movieID) {

        // Already booked
        if (bookings[movieID].count(customerID))
            return false;

        // Movie full
        if (bookings[movieID].size() >= 100)
            return false;

        bookings[movieID].insert(customerID);
        return true;
    }

    // CANCEL X Y
    bool cancel(int customerID, int movieID) {

        // Not booked
        if (!bookings[movieID].count(customerID))
            return false;

        bookings[movieID].erase(customerID);
        return true;
    }

    // IS_BOOKED X Y
    bool isBooked(int customerID, int movieID) {
        return bookings[movieID].count(customerID);
    }

    // AVAILABLE_TICKETS Y
    int availableTickets(int movieID) {
        return 100 - bookings[movieID].size();
    }
};

int main() {

    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {

        string query;
        cin >> query;

        if (query == "BOOK") {

            int X, Y;
            cin >> X >> Y;

            if (mt.book(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "CANCEL") {

            int X, Y;
            cin >> X >> Y;

            if (mt.cancel(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "IS_BOOKED") {

            int X, Y;
            cin >> X >> Y;

            if (mt.isBooked(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "AVAILABLE_TICKETS") {

            int Y;
            cin >> Y;

            cout << mt.availableTickets(Y) << endl;
        }
    }

    return 0;
}