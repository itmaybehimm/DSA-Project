#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    int weight;
    char character;
    node *next;
};

void print_list(node *start)
{
    node *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->character << " = " << ptr->weight << ' ' << endl;
        ptr = ptr->next;
    }
}

node *create_node(int weight, char character)
{
    node *new_node = new node;
    if (!new_node)
    {
        cout << "Node cannot be created";
        exit(0);
    }
    new_node->weight = weight;
    new_node->character = character;
    new_node->next = NULL;
    return new_node;
}

void create_list(int *arr, int &count, node *start)
{
    start = NULL;
    node *ptr, *preptr;
    for (int i = 0; i < 127; i++)
    {
        if (arr[i] != 0)
        {
            count++;
            node *new_node = create_node(arr[i], i);
            if (start == NULL)
            {
                start = new_node;
                continue;
            }
            ptr = start;
            preptr = start;
            while (arr[i] > ptr->weight)
            {
                preptr = ptr;
                ptr = ptr->next;
                if (ptr == NULL)
                    break;
            }
            if (preptr == start && ptr == start)
            {
                new_node->next = start;
                start = new_node;
            }
            else if (ptr == NULL)
            {
                preptr->next = new_node;
            }
            else
            {
                preptr->next = new_node;
                new_node->next = ptr;
            }
        }
    }
    print_list(start);
    cout << endl;
}

int main()
{
    fstream fp;
    string fileName;
    node *start;
    char ch;
    int arr[128], count;
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

    while (1)
    {
        fp.get(ch);
        if (!fp)
            break;
        arr[ch]++;
    }

    create_list(arr, count, start); // To be replaced by a min heap
    cout << "PUGYO";
    print_list(start);
    return 0;
}