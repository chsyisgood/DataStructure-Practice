#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;
#define PRIMEA 39751
#define PRIMEB 895932
#define SEED 97
#define CAPACITY 26*26

/*
 *  Author: Siyu (Max) Chen
 *  CWID: 10424481
 *  Complete HashMap using linear chaining
 *  Cite: I copied a hash function from online website, thanks a lot for people's sharing !!!
 */

// HashMap using linear chaining
class HashMap{
public:
    class HashMapNode {
    public:
        string key;
        int val;
        bool present;
        HashMapNode* nextNode;
        HashMapNode(const string& key, int val, HashMapNode* nextNode): key(key),val(val),present(true),nextNode(nextNode){};
        HashMapNode(const string& key, int val): key(key),val(val),present(true),nextNode(nullptr){};
        HashMapNode(const string& key):key(key),present(true),nextNode(nullptr){};
        HashMapNode():present(false){};
    };
    //
    vector<HashMapNode*> Lists;
    uint32_t size; uint32_t used;
    bool isInitialized;  // Used to judge whether this HashMap is Initialized
    // if not, the size will be ZERO; Otherwise, it will be AT LEAST 5000(Of course it may GROW)

    // Hash function
    // Cite: I copied a hash function from online website, thanks a lot for people's sharing !!!
    uint32_t hash(const string& key) {
        uint32_t ret = SEED;
        size_t len = key.length();
        for(size_t i = 0; i < len; i++)
            ret = ((ret * PRIMEA) ^ (key[i] * PRIMEB)) >> 13;
        return ret % size;
    }

    // Constructor of class HashMap
    HashMap(uint32_t size = 5000, bool isInitialized = false):isInitialized(isInitialized),size((isInitialized)? size: 0), used(0){
        Lists = * new vector<HashMapNode*>(size);
    }
    // Destructor of class HashMap
    ~HashMap(){
        Lists.clear(); Lists.shrink_to_fit();
    }

    void grow(){
        //cout << " Grow Start!!! " << endl;
        vector<HashMapNode*> temp = Lists;
        Lists = * new vector<HashMapNode*>(2 * size);
        for(uint32_t i = 0; i < size; i++){
            HashMapNode* tempNode = temp[i]; // the first Node of prev i th List
            while(tempNode != nullptr){
                uint32_t newKey = hash(tempNode->key);
                HashMapNode* newHead = new HashMapNode(tempNode->key,tempNode->val,Lists[newKey]);
                Lists[newKey] = newHead;
                tempNode = tempNode->nextNode;
            }
        }
        //cout << " Grow End!!! " << endl;
        // Release the memory of prev Lists
        temp.clear();
        temp.shrink_to_fit();
        size *= 2;
    }

    void add(const string& str){
        if(size < used * 1.35)
            grow();
        uint32_t key = hash(str);
        //cout << str << "  " << key << endl;
        HashMapNode* newHead = new HashMapNode(str, 0, Lists[key]);
        Lists[key] = newHead;
        used++;
    }

    bool find(const string& str){
        uint32_t key = hash(str);
        HashMapNode* temp = Lists[key];
        while(temp != nullptr){
            if(temp->key == str)
                return true;
            else
                temp = temp->nextNode;
        }
        return false;
    }
};

int getIndex(char a, char b){
    return (a - 'a') * 26 + b - 'a';
}

// Calculate the collisions and print out
void printHist(HashMap* Map){
    int arr[60] = {0}; int initializedNum = 0;
    for(int j = 0; j < CAPACITY; ++j){
        // if Map[j] is not Initialized, its size will be zero, which means we dont need to check!!!
        if(!Map[j].isInitialized)
            continue;
        ++ initializedNum;
        for(uint32_t i = 0; i < Map[j].size; i++){
            int len = 0; HashMap::HashMapNode* temp = Map[j].Lists[i];
            while(temp != nullptr){
                ++len;
                temp = temp->nextNode;
            }
            arr[len]++;
        }
    }
    cout << "Num of ALL index : " << CAPACITY << endl;
    cout << "Num of INITIALIZED index : " << initializedNum << endl;
    cout << "Num of NOT initialized index : " << CAPACITY - initializedNum << endl;
    for(int i = 0; i <= 50; i++)
        cout << "Numbers of bins with " << i << " collisions : " << arr[i] << endl;
}

int main() {
    //HashMap index[26][26];
    HashMap* Map = new HashMap[CAPACITY];
    ifstream dictFile("dict.txt");
    string line;
    if(!dictFile){
        cout << "dict.txt not found!";
        return 0;
    }
    while(!dictFile.eof()){
        getline(dictFile, line);
        if(line != ""){
            int index = getIndex(line[0],line[1]); int len = line.length();
            // if the Map[index] is not Initialized, then we initialized it and set size as 5000
            if(!Map[index].isInitialized)
                Map[index] = * new HashMap(5000, true);
            // if the length of word is less or equal to 2, then put "" to the HashMap
            string postfix = (len < 3)? "": line.substr(2,len - 1);
            Map[index].add(postfix);
        }
    }
    dictFile.close();
    printHist(Map);

    ifstream spellFile("spell.txt");
    if(!spellFile){
        cout << "spell.txt not found!";
        return 0;
    }

    cout << "------------ALL the words NOT in the DICT:---------------" << endl;
    while(!spellFile.eof()){
        getline(spellFile, line);
        int index = getIndex(line[0],line[1]); int len = line.length();
        if(!Map[index].isInitialized)
            cout << line << " not found! " << endl;
        else{
            string postfix = (len < 3)? "": line.substr(2,len - 1);
            //cout << postfix << endl;
            if(!Map[index].find(postfix))
                cout << line << " not found! " << endl;
            //else
                //cout << line << " found! " << endl;
        }
    }
    spellFile.close();
    return 0;
}