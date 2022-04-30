void Add_new_text() {
    char text[1000];
    int i;
    char ch;
    ofstream myfile;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    cout << "please enter the text that you want to add : ";
    cin.ignore();
    for (i = 0; (ch = _getche()) != '\r';) {

        if (ch != '\b') {
            text[i] = ch;
            i++;
        }

        else {
            i--;

            if (i < 0) {
                i++;
            }
            else {
                cout << " \b";
            }
        }
        if (ch == 26) {
            system("cls");
            return;
        }
    }
    text[i] = '\0';
    myfile << text;
    cout << endl;
    cout << "Done!!";
    cout << endl << endl;
    myfile.close();

}
