void Read_Display(Text*& text, int& n) {
    ifstream read("..\\Bai05\\input05.bin", ios::binary);
    read.seekg(0, ios::end);
    int size = read.tellg();
    read.seekg(0, ios::beg);
    int local = 0;
    n = 0;
    while (!read.eof()) {
        char* tmp = new char[size];
        read.read(tmp, (size - local));// doc cac phan tu tiep theo, tru di so luong phan tu da doc
        text[n].data = new char[strlen(tmp) + 1];
        strcpy_s(text[n].data, strlen(tmp) + 1, tmp);
        n++;
        local += strlen(tmp) + 1;// vi tri bat dau phan tu tiep theo
        read.seekg(local); // day con tro den vi tri bat dau phan tu tiep theo
        if (local >= size)
            break;
    }
    read.close();
}
