#include <iostream>
#include "Header.h"
using namespace std;
int userInput;

int main()
{
    cout << "Ahlan ya user ya habibi\n";
    checkFile();
    while (true)
    {
        menuDisplay();
        switch (userInput)
        {
        case 1:
            addText();
            break;
        case 2:
            dispalyContent();
            break;
        case 3:
            emptyFile();
            break;
        case 4:
            encryptFile();
            break;
        case 5:
            decryptFile();
            break;
        case 6:
            Merge();
            break;
        case 7:
            countWords();
            break;
        case 8:
            countChars();
            break;
        case 9:
            countLines();
            break;
        case 10:
            searchWord();
            break;
        case 11:
            countWordExists();
            break;
        case 12:
            upperCase();
            break;
        case 13:
            lowerCase();
            break;
        case 14:
            contentCaps();
            break;
        case 15:
            save();
            exit(0);
            break;
        case 16:
            exit(0);
            break;
        default:
            break;
        }
    }    
}
//_________________________________________
void menuDisplay() {
    while (true) { // Dispaly menu and take user input
        
        cout << "1- Add new text to the end of the file\n";
        cout << "2- Display the content of the file\n";
        cout << "3- Empty the file\n";
        cout << "4- Encrypt the file content\n";
        cout << "5- Decrypt the file content\n";
        cout << "6- Merge another file\n";
        cout << "7- Count the number of words in the file\n";
        cout << "8- Count the number of characters in the file\n";
        cout << "9- Count the number of lines in the file\n";
        cout << "10- Search for a word in the file\n";
        cout << "11- Count the number of times a word exists in the file\n";
        cout << "12- Turn the file content to upper case\n";
        cout << "13- Turn the file content to lower case\n";
        cout << "14- Turn file content to 1st caps(1st char of each word is capital)\n";
        cout << "15- Save\n";
        cout << "16- Exit\n--> ";
        cin >> userInput;
        if (userInput >= 1 && userInput <= 16) {
            break;
        }
        else {
            cout << "Please enter valid input from the menu!!\n\n";
            cin.ignore();
        }
    }
}
