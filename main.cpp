#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "include/rapidjson/document.h"
#include "DocParser.h"
#include "DSAVLTree.h"
#include "Word.h"
#include "QueryProcessor.h"
#include "UserInterface.h"

using namespace std;
int main(int argc, char** argv) {
    //TODO find out where to put stop words list so that it can be used in all classes
    //just have the avl tree indexes in the user interface class and then pass it everywhere else?
    //can't have multiple avl trees in each class (doc parser and query), should just have one set
    
    UserInterface parse;
    cout << "parsing..." << endl;
    parse.parseDocs(argv[2]);//absolute path
    cout << "done!" << endl;
    Word w(argv[1]);//search term
    w.stemming();
    parse.getDocParser().getWordTree().find(parse.getDocParser().getWordTree().getRoot(), w).printDocs();
//    parse.getWordTree().find(parse.getWordTree().getRoot(), w)->getData().printDocs();

//    vector<int> finalIndex;
//    finalIndex.push_back(4);
//    finalIndex.push_back(10);
//    finalIndex.push_back(1);
//
//    vector<int> a;
//    a.push_back(5);
//    a.push_back(2);
//    a.push_back(3);
//
//    vector<int> b;
//    b.push_back(10);
//    b.push_back(25);
//    b.push_back(32);
//
//    vector<int> temp;
//    for (int i = 0; i < finalIndex.size(); i++)
//    {
//        cout << "loop running" << endl;
//        vector<int>::iterator it = find(a.begin(), a.end(), finalIndex.at(i));
//        if (it != a.end())//doc of a exists in final
//            temp.push_back(finalIndex.at(i));
//    }
//    finalIndex = temp;
//
//    for (int j = 0; j < finalIndex.size(); j++)
//        cout << finalIndex.at(j) << endl;
//    if (finalIndex.size() == 0)
//        cout << "final is empty" <<endl;
}
