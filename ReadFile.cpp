#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fp;
    string fileName;
    char ch;
    int arr[128];
    cout << "Enter filename: ";
    cin >> fileName;
    fp.open(fileName, ios::in);
    if (!fp)
    {
        cout << "No file";
        exit(0);
    }

    for (int i = 0; i < 128; i++)
        arr[i] = 0;

    while (fp)
    {
        fp.get(ch);
        arr[ch]++;
    }
}