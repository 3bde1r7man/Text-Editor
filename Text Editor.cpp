#include <iostream>
#include <fstream>

using namespace std;
int userInput;

void Merge();
void menuDisplay();

int main()
{
    cout << "Ahlan ya user ya habibi\n";
    menuDisplay();
    switch (userInput)
    {
    case 6:
        Merge();
        break;
    default:
        break;
    }
    
}
//_________________________________________
void menuDisplay() {
    while (true) {
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
        if (userInput >= 1 && userInput <= 16)
            break;
        else {
            cout << "Please enter valid input from the menu!!\n\n";
            cin.ignore();
        }
    }
}
//_________________________________________
void Merge() {
    fstream firstFile, secFile;
    char name1[100], name2[100];
    cout << "Please enter the first file name to append to(e.g. file1.txt): ";
    cin >> name1;
    cout << "Please enter the second file name(e.g. file2.txt): ";
    cin >> name2;
    firstFile.open(name1, ios::app);
    secFile.open(name2, ios::in);
    if (firstFile.fail() || secFile.fail()) {
        cout << "please enter valid file name";
    }
    else {
        firstFile << "\n" << secFile.rdbuf();
        cout << "Please go check " << name1;
    }
    firstFile.close();
    secFile.close();

}