#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <cctype>

using namespace std;

// Convert string to lowercase (for exit handling)
string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

// Check if input is empty or only spaces
bool isBlank(const string &str) {
    for (char c : str) {
        if (!isspace(c)) return false;
    }
    return true;
}

// AI thinking animation
void thinkingEffect() {
    cout << "\n AI is analyzing your personality";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "\n";
}

int main() {
    srand(time(0));

    // Welcome messages
    vector<string> welcomes = {
        " Welcome to the Roast Machine 3000!",
        " Enter at your own risk... feelings may be hurt!",
        " AI Activated: Sarcasm Mode ON!",
        " Welcome! Today, we destroy egos professionally."
    };

    // Random welcome
    cout << welcomes[rand() % welcomes.size()] << endl;

    // Random joke
    vector<string> jokes = {
        "Why do programmers prefer dark mode? Because light attracts bugs ",
        "Why did the developer go broke? Because he used up all his cache ",
        "Why do Java developers wear glasses? Because they don't C# ",
        "Debugging: Removing bugs from code. Programming: Adding them "
    };

    cout << "\n Joke: " << jokes[rand() % jokes.size()] << endl;

    while (true) {
        string name;

        cout << "\n Enter your name (or type 'exit' to quit): ";
        getline(cin, name);

        //  Check empty / blank input
        if (isBlank(name)) {
            cout << " Hey! Even AI needs a name to roast  Try again.\n";
            continue;
        }

        //  Exit condition (case-insensitive)
        if (toLowerCase(name) == "exit") {
            cout << "\nAI shutting down... Stay roasted!\n";
            break;
        }

        // Roast templates
        vector<string> roasts = {
            "{name} writes code so slow that even a turtle switched careers.",
            "If procrastination were an Olympic sport, {name} would win gold.",
            "{name}'s debugging strategy: stare at screen until bug resigns.",
            "{name}'s code has more drama than a daily soap.",
            "Even AI refuses to review {name}'s code.",
            "{name} once fixed a bug... by deleting the project.",
            "If laziness had a CEO, it would be {name}.",
            "{name} doesn't write code, they summon chaos.",
            "{name}'s code runs so slow, snails are filing complaints.",
            "{name} and bugs have a long-term relationship."
        };

        // Thinking effect
        thinkingEffect();

        // Random roast
        string roast = roasts[rand() % roasts.size()];

        //  Replace ALL occurrences of {name}
        size_t pos = roast.find("{name}");
        while (pos != string::npos) {
            roast.replace(pos, 6, name);
            pos = roast.find("{name}");
        }

        // Display roast
        cout << "\n ROAST RESULT \n";
        cout << roast << endl;

        // Random roast level
        int level = rand() % 3;

        cout << "\n Roast Level: ";
        if (level == 0) cout << "Mild ";
        else if (level == 1) cout << "Savage ";
        else cout << "EMOTIONAL DAMAGE ";

        cout << "\n-----------------------------\n";
    }

    return 0;
}