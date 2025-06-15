#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main() {
    string colors[] = {
        "0 - Black", "1 - Blue", "2 - Green", "3 - Aqua",
        "4 - Red", "5 - Purple", "6 - Yellow", "7 - White",
        "8 - Gray", "9 - Light Blue", "A - Light Green", "B - Light Aqua",
        "C - Light Red", "D - Light Purple", "E - Light Yellow", "F - Bright White"
    };

    for (int bg = 0; bg <= 15; ++bg) {
        for (int fg = 0; fg <= 15; ++fg) {
            // Skip if background and foreground are the same
            if (bg == fg) continue;

            // Create color code in hex
            char hexColor[3];
            sprintf(hexColor, "%X%X", bg, fg);
            string command = "color ";
            command += hexColor;

            // Set console color
            system(command.c_str());

            // Show current color setting
            cout << "Background: " << colors[bg] << " | Text: " << colors[fg] << " (code: " << hexColor << ")" << endl;

            // Short delay to allow seeing the color
            Sleep(300);
        }
    }

    // Reset to default color (optional)
    system("color 07");
    return 0;
}
