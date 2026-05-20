#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Convert to lowercase
string toLowerCase(string str) {
    for (char &c : str) c = tolower(c);
    return str;
}

// Check blank input
bool isBlank(const string &str) {
    for (char c : str) {
        if (!isspace(c)) return false;
    }
    return true;
}

int main() {
    srand(time(0));

    // Welcome
    cout << "Welcome to the AI Excuse Generator 2.0 \n";
    cout << " Warning: Use these excuses at your own risk!\n";

    // Joke
    cout << "\n Joke: Why didn't the student bring homework?\n";
    cout << "Because the dog installed Windows updates \n";

    while (true) {
        string name;

        cout << "\n Enter your name (or type 'exit'): ";
        getline(cin,name);

        if (isBlank(name)) {
            cout << " Please enter a valid name!\n";
            continue;
        }

        if (toLowerCase(name) == "exit") {
            cout << "\nGoodbye! Hope your excuses work \n";
            break;
        }

        // Excuse templates
        vector<string> excuses = {
            "{name} couldnt finish the assignment because the laptop updated for 6 hours.",
            "{name} was about to complete homework when Wi-Fi vanished mysteriously.",
            "{name} tried finishing the assignment, but the keyboard stopped working.",
            "{name}'s file disappeared right before submission.",
            "{name} completed everything but forgot to save the file.",
            "{name}'s system crashed at the last moment.",
            "{name} lost the file due to a sudden power cut.",
            "{name} was attacked by too many notifications.",
            "{name}'s dog accidentally deleted {name}'s homework.",
            "{name} opened the file and it was completely blank."
        };

        // Random excuse
        string excuse = excuses[rand() % excuses.size()];

        // INTENTIONAL BUG: only replaces first occurrence
        size_t pos = 0;
        while ((pos = excuse.find("{name}", pos)) != string::npos) {
        excuse.replace(pos, 6, name);
         pos += name.length(); 
        }

        cout << "\n GENERATED EXCUSE:\n";
        cout << excuse << endl;

        cout << "\n-------------------------\n";
    }

    return 0;
}