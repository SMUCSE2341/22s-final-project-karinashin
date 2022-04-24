//
// Created by Karina Shin on 4/19/2022.
//

#ifndef INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
#define INC_22S_FINAL_PROJ_QUERYPROCESSOR_H

#include <string>
#include <vector>
#include <algorithm>
#include "Document.h"
#include "DSAVLTree.h"
#include "Word.h"
#include "StopWord.h"

class QueryProcessor {
private:
//    string query;
    vector<Document> finalIndex;
    DSAVLTree<Word> words;
    DSAVLTree<Word> orgs;
    DSAVLTree<Word> people;

public:
    QueryProcessor();
    QueryProcessor(DSAVLTree<Word>& w, DSAVLTree<Word>& o, DSAVLTree<Word>& p);
    void parseQuery(string& query, StopWord& stop);//parse query
    void setUnion(vector<Document>& a, vector<Document>& b);//OR keyword
    void intersection(vector<Document>& a, vector<Document>&b);//AND keyword
    void complement(vector<Document>& a);//set subtraction
    void addPersonOrg(vector<Document>& a);//remove any docs that don't include the given person or org
};


#endif //INC_22S_FINAL_PROJ_QUERYPROCESSOR_H
