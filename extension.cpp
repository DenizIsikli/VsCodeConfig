#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    fstream file;
    
    file.open("extensions.txt", ios::out);

    if (!file.is_open()) {
        cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Run PowerShell to execute the 'code' CLI command
    const char* command = "powershell.exe -ExecutionPolicy Bypass -NoLogo -NonInteractive -NoProfile -Command \"code --list-extensions\"";

    FILE *pipe = _popen(command, "r");
    if (!pipe) {
        cerr << "Error opening pipe." << std::endl;
        return 1;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        char *dotPosition = strchr(buffer, '.');
        if (dotPosition) {
            file << (dotPosition + 1);  // Write the text after the dot (excluding the dot)
        } else {
            file << buffer;  // Write the entire line if no dot is found
        }
    }

    _pclose(pipe);

    file.close();

    cout << "List of VSCode extensions saved to extensions.txt" << endl;

    return 0;
}
