#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int userInput;

// define each function are used
void menuDisplay();
void addText();
void dispalyContent();
void emptyFile();
void encryptFile();
void decryptFile();
void Merge();
void countWords();
void countChars();
void countLines();
void searchWord();

int main()
{
    cout << "Ahlan ya user ya habibi\n";
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
    default:
        break;
    }
    
}
//_______________
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
//_______________
void addText() {
    fstream file;
    char name[100];
    string Text;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            file.close();
            file.open(name, ios::app);
            cout << "Please enter the Text to append: ";
            cin.ignore();
            getline(cin, Text);
            file<< " " << Text;
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_______________
void dispalyContent() {
    fstream file;
    char name[100];
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            cout << file.rdbuf();
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_______________
void emptyFile() {
    fstream file;
    char name[100];
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::out);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            file.clear();
            break;
        }
    }
    file.close();
}
//_______________
void encryptFile() {
    fstream file;
    char name[100];
    string buffer = "";

    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.peek() == EOF) {
                    break;
                }
                buffer += char(file.get());
            }
            file.close();
            for (int i = 0; i < buffer.size(); i++) {
                buffer[i]++;
            }
            file.open(name, ios::out);
            file << buffer;
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_______________
void decryptFile() {
    fstream file;
    char name[100];
    string buffer = "";

    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.peek() == EOF) {
                    break;
                }
                buffer += char(file.get());
            }
            file.close();
            for (int i = 0; i < buffer.size(); i++) {
                buffer[i]--;
            }
            file.open(name, ios::out);
            file << buffer;
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_______________
void Merge() {
    fstream firstFile, secFile;
    char name1[100], name2[100];
    while (true)
    {
        cout << "Please enter the first file name to append to(e.g. file1.txt): ";
        cin >> name1;
        cout << "Please enter the second file name(e.g. file2.txt): ";
        cin >> name2;
        firstFile.open(name1, ios::app);
        secFile.open(name2, ios::in);
        if (firstFile.fail() || secFile.fail()) {
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            firstFile << "\n" << secFile.rdbuf();
            cout << "Please go check " << name1 << "\n";
            break;
        }
    }
    firstFile.close();
    secFile.close();

}
//_______________
void countWords() {
    fstream file;
    char name[100];
    int count = 0;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                file >> name;
                if (name != NULL) { // Count words
                    count++;
                }
            }
            cout << "There is " << count << " words in this file.";
            break;
        }
    }
    file.close();
}
//_______________
void countChars() {
    fstream file;
    char name[100];
    int count = 0;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {   
                /*if (isalnum(file.get())) { // will count if alpha or digit not else 
                    count++;
                }*/
                if (isascii(file.get())) { // If the char is in ascii will count even spaces
                    count++;
                }
            }
            cout << "There is " << count << " characters in this file.";
            break;
        }
    }
    file.close();
}
//_______________
void countLines() {
    fstream file;
    char name[256];
    int count = 0;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.getline(name, 256, '\n')) { // Count lines
                    count++;
                }
            }
            cout << "There is " << count << " lines in this file.";
            break;
        }
    }
    file.close();
}
//_______________
void searchWord() {
    fstream file;
    int check = 0;
    char fileName[100];
    string word, name;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> fileName;
        file.open(fileName, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            cout << "Please enter the word to search for: ";
            cin >> word;
            for (int i = 0; i < word.size(); i++) { // to ignore the case 
                word[i] = toupper(word[i]);
            }
            while (!file.eof()) {
                file >> name;
                for (int i = 0; i < name.size(); i++) {
                    name[i] = toupper(name[i]);
                }
                if (name == word) {
                    check = 1;
                    break;
                }    
            }
            if (check == 1) {
                cout << "Word was found in the file.";
                break;
            }
            else {
                cout << "Word was not found in the file.";
            }
        }
    }
    file.close();
}
//_______________