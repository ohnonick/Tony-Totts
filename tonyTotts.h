#ifndef TONY_TOTTS
#define TONY_TOTTS

#include "linkedlist.h"
#include "arrayDictionary.h"

#include <string>
using namespace std;

class TonyTotts{
    private:
        int blunders;
        LinkedList<string> evidenceNames;
        ArrayDictionary<int, string> evidenceInfo;

    public:
        TonyTotts();
        bool wompWomp();
        int getNumEvidence();
        int addEvidence(string title, string description);
        void viewList();
        string viewEvidence(int index);
        void updateInfo(string oldName, string newDesc);
        void removeEvidence(string name);
        string getNameForCheck(int index);
        int findIndex(string name);
};

#endif