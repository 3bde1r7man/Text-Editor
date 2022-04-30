void save() {
    string new_name;
    char content;
    string content2;
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    cout << "please enter the new name of the file : ";
    cin.ignore();
    getline(cin, new_name);
    while (!myfile.eof()) {
        myfile.get(content);
        content2 = content2 + char(content);
    }
    myfile2.open(new_name + ".txt", ios::out | ios::app);
    myfile2 << content2;
    cout << "Done!!"<<endl;
    cout << endl << endl;


}
