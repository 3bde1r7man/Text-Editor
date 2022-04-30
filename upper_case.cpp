void upper_case() {
    char text_file;
    string text_file2;
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        text_file2 = text_file2 + char(toupper(text_file));
    }
    myfile2.open(file_name + ".txt", ios::trunc);
    myfile2 << text_file2;
    cout << "Done!!" << endl;
    cout << endl << endl;

}
