void word_times() {
    char text_file;
    char text_file3;
    string text_file2;
    string word;
    int counter = 0;
    int counter2 = 0;
    ifstream myfile;
    ifstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    cout << "please enter the word : ";
    cin >> word;
    while (!myfile.eof()) {
        myfile.get(text_file3);
        counter++;
    }
    myfile2.open(file_name + ".txt", ios::out | ios::app);
    while (!myfile2.eof()) {
        myfile2.get(text_file);
        if (text_file != 32) {
            text_file2 = text_file2 + char(text_file);
        }
        if (text_file == 32) {
            text_file2 = "";
        }
        if (text_file2 == word) {
            counter2++;
        }
    }

    cout << "the number of times a word is : " << counter2 << endl << endl;
}
