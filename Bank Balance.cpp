#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Bank {
private:
    // userID -> balance
    unordered_map<int, int> users;

public:

    // CREATE X Y
    bool create(int userID, int amount) {

        // User already exists
        if (users.count(userID)) {
            users[userID] += amount;
            return false;
        }

        // Create new user
        users[userID] = amount;
        return true;
    }

    // DEBIT X Y
    bool debit(int userID, int amount) {

        // User not present OR insufficient balance
        if (!users.count(userID) || users[userID] < amount)
            return false;

        users[userID] -= amount;
        return true;
    }

    // CREDIT X Y
    bool credit(int userID, int amount) {

        // User not present
        if (!users.count(userID))
            return false;

        users[userID] += amount;
        return true;
    }

    // BALANCE X
    int balance(int userID) {

        // User not present
        if (!users.count(userID))
            return -1;

        return users[userID];
    }
};

int main() {

    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {

        string query;
        cin >> query;

        if (query == "CREATE") {

            int X, Y;
            cin >> X >> Y;

            if (bank.create(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "DEBIT") {

            int X, Y;
            cin >> X >> Y;

            if (bank.debit(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "CREDIT") {

            int X, Y;
            cin >> X >> Y;

            if (bank.credit(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "BALANCE") {

            int X;
            cin >> X;

            cout << bank.balance(X) << endl;
        }
    }

    return 0;
}