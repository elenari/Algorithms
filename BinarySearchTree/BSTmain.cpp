#include "BinarySearchTree.cpp"
#include <iostream>

using namespace std;

void print_help() {

    cout << endl << "Commands:" << endl;
    cout << "  P    : [P]rint Help (displays this message)" << endl;
    cout << "  +key : Insert (or update) data item (use integers)" << endl;
    cout << "  -key : Delete data item " << endl;
    cout << "  ?key : Search data item " << endl;
    cout << "  C    : Clear the tree" << endl;
    cout << "  E    : Empty tree?" << endl;
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;

}

int main()

{

    BSTree<DataNode, int> testTree;   // Test binary search tree
    DataNode testData;               // Binary search tree data item
    int inputKey = 0;                // User input key
    char cmd;                        // Input command

    print_help();

    do
    {
        testTree.show();                     // Output tree
        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if (cmd == '+' || cmd == '?' || cmd == '-' || cmd == '<')
            cin >> inputKey;

        switch (cmd)
        {

        case 'P': case 'p':
            print_help();  
            break;

        case '+':                                  // insert
            testData.setKey(inputKey);
            cout << "Insert : key = " << testData.getKey() << endl;
            testTree.insert(testData);
            break;

        case '-':                                  //delete
            testData.setKey(inputKey);
            cout << "Remove : key = " << testData.getKey() << endl;
            testTree.remove(inputKey);
            break;

        case '?': testData.setKey(inputKey);
            cout << "Search/find : key = " << testData.getKey() << endl;
            if (testTree.find(inputKey)) cout << "Element '" << testData.getKey() << "' exist." << endl;
            else cout << "Element " << testData.getKey() << " NOT exist.";
            break;

        case 'C': case 'c':                       // clear
            cout << "Clear the tree" << endl;
            testTree.clear();
            break;

        case 'E': case 'e':                       // empty
            if (testTree.isEmpty())
                cout << "Tree is empty" << endl;
            else
                cout << "Tree is NOT empty" << endl;
            break;

        case 'Q': case 'q':                   // Quit test program
            cout << "Exit program... Completed";
            break;

        default:                               // Invalid command
            cout << "Inactive or invalid command. 'P' prints help." << endl;

        }

    }

    while (cin && (cmd != 'Q') && (cmd != 'q'));

    if (!cin)
    {
        cerr << "Error in console input. Exiting." << endl;
    }


    return 0;

}
