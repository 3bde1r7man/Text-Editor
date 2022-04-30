void first_char_capital() {
    char text_file;
    string text_file2;
    int counter;
    int counter2;
    counter = 0;
    counter2 = 0;
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        if (counter == 0 || counter2 == counter) {
            text_file2 = text_file2 + char(toupper(text_file));
            counter++;
            continue;
        }

        if (text_file == 32) {
            text_file2 = text_file2 + char(text_file);
            counter2 = counter;
            continue;
        }
        text_file2 = text_file2 + char(text_file);
    }
    myfile2.open(file_name + ".txt", ios::trunc);
    myfile2 << text_file2;
    cout << "Done!!" << endl;
    cout << endl << endl;

}
