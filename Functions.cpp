#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include "Header.h"

using namespace std;
char fileName[100];
fstream myFile;

void checkFile() {
    cout << "Please Enter Your File Name: ";
    cin >> fileName;
    myFile.open(fileName, ios::in);  
    if (myFile.fail()) {
        cout << "File " << fileName << " does not exist. I created it for you.\n";
        fstream (fileName);
    }
    else {
        cout << "File is opened successful.\n";
    } 
    myFile.close();
}
//_________________________________________
void addText() {
    int i;
    char ch;
    string text = "";
    myFile.open(fileName, ios::app);
    cout << "Please enter the text that you want to add : ";
    for (i = 0; (ch = _getche()) != '\032';) {
        if (ch != '\b') {
            if (ch == '\r') {
                cout << "\n";
                text += "\n";
                i++;
            }
            else {
                text += ch;
                i++;
            }
        }
        else {
            i--;
            if (i < 0) {
                i++;
            }
            else {
                cout << "\b";
            }
        }
        if (ch == 26) {
            return;
        }
    }
    text[i] = '\0';
    myFile << text;
    cout << "\n\nText added successfully.\n";
    myFile.close();
}
//_________________________________________
void dispalyContent() {
    myFile.open(fileName, ios::in);
    cout << myFile.rdbuf() << "\n"; // reading the buffer and print it
    myFile.close();
}
//_________________________________________
void emptyFile() {   
    myFile.open(fileName, ios::in);
    myFile.clear(); // Clearing the file content
    cout << "\nFile content cleared successfully.\n";      
    myFile.close();
}
//_________________________________________
void encryptFile() {    
    string buffer = "";    
    myFile.open(fileName, ios::in);// Opening file to take the buffer      
    while (!myFile.eof())
    {
        if (myFile.peek() == EOF) { // To avoid printing EOF char
            break;
        }
        buffer += char(myFile.get()); // Add each char to the buffer
    }
    myFile.close(); // Close the file
    for (int i = 0; i < buffer.size(); i++) { // Encrypt the file content
        buffer[i]++;
    }
    myFile.open(fileName, ios::out); // Open the file for writing
    myFile << buffer; // Add the content encrypted to the file
    cout << "\nFile content encrypted successfully.\n";    
    myFile.close();
}
//_________________________________________
void decryptFile() {
    string buffer = "";        
    myFile.open(fileName, ios::in);
    while (!myFile.eof())
    {
        if (myFile.peek() == EOF) { // To avoid printing EOF char
            break;
        }
        buffer += char(myFile.get()); // Add each char to the buffer
    }
    myFile.close();
    for (int i = 0; i < buffer.size(); i++) { // Decrypt the file content
        buffer[i]--;
    }
    myFile.open(fileName, ios::out); // Open the file for writing
    myFile << buffer; // Add the content decrypted to the file
    cout << "\nFile content decrypted successfully.\n"; 
    myFile.close();
}
//_________________________________________
void Merge() {
    fstream secFile;
    string name2;
    myFile.open(fileName, ios::app);
    while (true)
    {
        cout << "Please enter the second file name: ";
        cin >> name2;
        secFile.open(name2 , ios::in);
        if (secFile.fail()) {
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            myFile << "\n" << secFile.rdbuf();
            cout << "The content of File " << name2 << " successfully added to " << fileName << endl;
            break;
        }
    }
    myFile.close();
    secFile.close();

}
//_________________________________________
void countWords() {
    char name[100];
    int count = 0;            
    myFile.open(fileName, ios::in);// Opening file        
    while (!myFile.eof())
    {
        myFile >> name;
        if (name != NULL) { // Count words
            count++;
        }
    }
    cout << "There is " << count << " words in this file.\n";    
    myFile.close();
}
//_________________________________________
void countChars() {    
    int count = 0;     
    myFile.open(fileName, ios::in);// Opening file        
    while (!myFile.eof())
    {
        /*if (isalnum(file.get())) { // will count if alpha or digit not else
            count++;
        }*/
        if (isascii(myFile.get())) { // If the char is in ascii will count even spaces
            count++;
        }
    }
    cout << "There is " << count << " characters in this file.\n"; 
    myFile.close();
}
//_________________________________________
void countLines() {   
    char name[256];
    int count = 0;
    myFile.open(fileName , ios::in);// Opening file
    while (!myFile.eof())
    {
        if (myFile.getline(name, 256, '\n')) { // Count lines
            count++;
        }
    }
    cout << "There is " << count << " lines in this file.\n";       
    myFile.close();
}
//_________________________________________
void searchWord() {
    
    int check = 0;
    string word, data;    
    myFile.open(fileName , ios::in);// Opening file   
    cout << "Please enter the word to search for: ";
    cin >> word;
    for (int i = 0; i < word.size(); i++) { // to ignore the case 
        word[i] = toupper(word[i]);
    }
    while (!myFile.eof()) {
        myFile >> data;
        for (int i = 0; i < data.size(); i++) {
            data[i] = toupper(data[i]);
        }
        if (data == word) {
            check = 1;
            break;
        }
    }
    if (check == 1) {
        cout << "Word was found in the file.\n";              
    }
    else {
        cout << "Word was not found in the file.\n";
    }      
    myFile.close();
}
//_________________________________________
void countWordExists() {   
    int count = 0;
    string buffer = "", word, temp;
    istringstream content("");        
    myFile.open(fileName, ios::in);// Opening file    
    cout << "Please enter the word to count it: ";
    cin >> word;
    for (int i = 0; i < word.size(); i++) { // To ignore the case 
        word[i] = toupper(word[i]);
    }
    while (!myFile.eof())
    {
        if (myFile.peek() == EOF) { // To avoid taking EOF char
            break;
        }
        buffer += char(myFile.get()); // Add each char to the buffer
    }
    content.str(buffer); 
    content >> temp; // Put the first word to check it
    while (content)
    {
        for (int i = 0; i < temp.size(); i++) { // To ignore the case
            temp[i] = toupper(temp[i]);
        }
        if (word == temp) {
            count++;
        }
        content >> temp; // To put the next word to check it
    }
    cout << "The word \"" << word << "\" was found " << count << " times in the file.\n";
    myFile.close();
}
//_________________________________________
void upperCase() {
    string buffer = "";      
    myFile.open(fileName, ios::in);// Opening file     
    while (!myFile.eof())
    {
        if (myFile.peek() == EOF) { // To avoid taking EOF char
            break;
        }
        buffer += char(myFile.get()); // Add each char to the buffer
    }
    myFile.close();
    for (int i = 0; i < buffer.size(); i++) { // Content to upper case
        buffer[i] = toupper(buffer[i]);
    }
    myFile.open(fileName, ios::out); // Open the file for writing
    myFile << buffer; // Add the content to the file
    cout << "Done.\n";           
    myFile.close();
 }
//_________________________________________
void lowerCase() {
    string buffer = "";
    myFile.open(fileName, ios::in);// Opening file      
    while (!myFile.eof())
    {
        if (myFile.peek() == EOF) { // To avoid taking EOF char
            break;
        }
        buffer += char(myFile.get()); // Add each char to the buffer
    }
    myFile.close();
    for (int i = 0; i < buffer.size(); i++) { // Content to lower case
        buffer[i] = tolower(buffer[i]);
    }
    myFile.open(fileName, ios::out); // Open the file for writing
    myFile << buffer; // Add the content to the file
    cout << "Done.\n";    
    myFile.close();
}
//_________________________________________
void contentCaps() {    
    char firstChar;
    string text = "";
    int counter = 0, counter2 = 0;    
    myFile.open(fileName , ios::in);
    while (!myFile.eof()) {
        myFile.get(firstChar);
        if (counter == 0 || counter2 == counter) {
            text += char(toupper(firstChar));
            counter++;
            continue;
        }
        if (firstChar == ' ' || firstChar == '\n') {
            text += char(firstChar);
            counter2 = counter;
            continue;
        }
        text +=  char(firstChar);
    }
    myFile.close();
    myFile.open(fileName, ios::out);
    myFile << text;
    cout << "Done.\n";
    myFile.close();
}
//_________________________________________
void save() {
    fstream  file2;
    
    char  name2[80];
    int choice;
    while (true)
    {
        cout << "1- Save in new File\n2- Save in the same file\n--> ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            break;
        }
        else {
            cin.ignore();
            cout << "Please enter a valid choice. \n";
        }
    }
    if (choice == 1) {    
        cout << "Please enter the file name to save to: ";
        cin >> name2;
        file2.open(name2, ios::app);
        file2 << myFile.rdbuf();    
        myFile.close();
        remove(fileName);
        file2.close();
    }
    else { 
        exit(0); 
    }
}