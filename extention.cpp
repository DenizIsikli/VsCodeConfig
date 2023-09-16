#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Run PowerShell to execute the 'code' CLI command
    const char* command = "powershell.exe -ExecutionPolicy Bypass -NoLogo -NonInteractive -NoProfile -Command \"code --list-extensions\" > vscode_extensions.txt";

    // Execute the command
    int result = system(command);

    if (result == 0) {
        cout << "List of VSCode extensions saved to vscode_extensions.txt" << std::endl;
    } else {
        cerr << "Error executing the command." << std::endl;
    }

    return 0;
}
