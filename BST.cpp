#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    int key;
    cout << "Enter key for root: ";
    cin >> key;
    BST<int> b1(key);
    int opt;

    while (1)
    {
        cout << "\nOPT: ";
        cin >> opt;
        if (opt == 1)
        {
            cout << "Enter data: ";
            cin >> key;
            b1.insert_node(key);
            cout << "Inserted: " << key << endl;
        }
        else if (opt == 2)
            b1.inorder();
        else if (opt == 3)
            b1.preorder();
        else if (opt == 4)
            b1.postorder();
        else if (opt == 5)
            cout << b1.find_max() << endl;
        else if (opt == 6)
            cout << b1.find_min() << endl;
        else if (opt == 8)
            break;
    }
    return 0;
}