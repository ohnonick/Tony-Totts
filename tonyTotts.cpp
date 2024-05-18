#include "tonyTotts.h"

#include <string>
#include <iostream>
using namespace std;

TonyTotts::TonyTotts(){
    blunders = 0;
    addEvidence("My Badge", "Badge No. 201! I'm a real official detective!");
}

bool TonyTotts::wompWomp(){
    blunders++;
    cout << "(Ouch... You're at " << blunders << " demerits. 3 gets you fired.)" << endl << endl;
    if(blunders > 2){
        return true;
    }
    return false;
}

int TonyTotts::getNumEvidence(){
    return evidenceNames.getLength();
}

int TonyTotts::addEvidence(string title, string description){
    int index = evidenceNames.getLength() + 1;
    evidenceNames.insert(index, title);
    const hash<string> hasher; // From string library
    const auto hashResult = hasher(title);
    evidenceInfo.add(hashResult, description);
    return index;
}

void TonyTotts::viewList(){
    cout << endl << "[ INVENTORY ]" << endl;
    for(int i = 1; i < evidenceNames.getLength() + 1; i++){
        cout << "    " << i << ". " << evidenceNames.getEntry(i) << endl;
    }
}

string TonyTotts::viewEvidence(int index){
    string key;
    try{
        key = evidenceNames.getEntry(index);
    }catch(...){
        return "This is not a listed number... No evidence found.";
    }

    // Remove " (updated!)" from key
    string ignore = " (updated!)";
    size_t found = key.rfind(ignore);
    if(found!=string::npos){
        key = key.substr(0, found);
    }

    const hash<string> hasher; // From string library
    const auto hashResult = hasher(key);
    cout << endl << "[ITEM] " << key << endl << evidenceInfo.getValue(hashResult) << endl << endl;
    return key;
}

void TonyTotts::updateInfo(string oldName, string newDesc){
    string key = oldName;
    int index = findIndex(oldName);
    evidenceNames.replace(index, (evidenceNames.getEntry(index) + " (updated!)"));
    const hash<string> hasher; // From string library
    const auto hashResult = hasher(key);
    evidenceInfo.remove(hashResult);
    evidenceInfo.add(hashResult, newDesc);
}

void TonyTotts::removeEvidence(string name){
    string key = name;
    int index = findIndex(name);
    // Remove " (updated!)" from key
    string ignore = " (updated!)";
    size_t found = key.rfind(ignore);
    if(found!=string::npos){
        key = key.substr(0, found);
    }

    const hash<string> hasher; // From string library
    const auto hashResult = hasher(key);
    evidenceInfo.remove(hashResult);
    evidenceNames.remove(index);
}

string TonyTotts::getNameForCheck(int index){
    string key;
    try{
        key = evidenceNames.getEntry(index);
    }catch(...){
        return "This is not a listed number... No evidence found.";
    }

    // Remove " (updated!)" from key
    string ignore = " (updated!)";
    size_t found = key.rfind(ignore);
    if(found!=string::npos){
        key = key.substr(0, found);
    }

    return key;
}

int TonyTotts::findIndex(string name){
    int index;
    for(int i = 1; i < evidenceNames.getLength() + 1; i++){
        string temp = evidenceNames.getEntry(i);

        // Remove " (updated!)" from key
        string ignore = " (updated!)";
        size_t found = temp.rfind(ignore);
        if(found!=string::npos){
            temp = temp.substr(0, found);
        }

        if(temp == name){
            index = i;
        }
    }
    return index;
}