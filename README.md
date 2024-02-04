# VSCode Configuration

## Overview
This repository contains my extensions and configurations for Visual Studio Code.

### Extensions
Import Extentions: `https://vscode.dev/profile/github/ac3603d859d0d974316dfaaf8fe40779`

### Background
Background Configs with Katsute.code-background extension:
- Setup Background
    - Command Palette: "Background: Configuration" (Setup IDE Backgrund)
- Change Background
    - Command Palette: "Open User Settings (JSON)" and then navigate to
        ``` json
        "background.windowBackgrounds": ["c:/Users/image_path"]
        ```
    - Change the image path, save, and use Command Palette: "Background: Install"

### ~~VsCodeConfiguration.md~~
- This .md workbench configuration is not in use

### Extra
Don't forget to add `**/*.exe` `VsCodeFileExclude.png` to the file exclude settings in VS Code. This helps avoid generating executables when using GCC/G++.
