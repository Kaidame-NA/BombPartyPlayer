#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::unordered_set;
using std::vector;
using std::string;
using std::ifstream;
using std::binary_search;

void getAllWords(vector<string> &allWords, const string &PATH);
void executeCommand(const string &command, const vector<string> &allWords, unordered_set<string> &usedWords);

int main()
{
    vector<string> allWords;
    unordered_set<string> usedWords;
    const string PATH = "wlist_match12.txt";
    getAllWords(allWords, PATH);

    string command;
    do
    {
        cin >> command;
        executeCommand(command, allWords, usedWords);
    } while (command != "quit");
    

    return 0;
}

void getAllWords(vector<string> &allWords, const string &PATH)
{
    ifstream inputFilestream(PATH);
    string word;
    while(inputFilestream >> word)
    {
        allWords.push_back(word);
    }
}

void executeCommand(const string &command, const vector<string> &allWords, unordered_set<string> &usedWords)
{
    if(command == "clear")
        usedWords.clear();
    else if(command == "quit")
        return;
    else
    {
        if(binary_search(allWords.cbegin(), allWords.cend(), command) && usedWords.find(command) == usedWords.end())
        {
            usedWords.insert(command);
            cout << command << endl;
            return;
        }
        for(vector<string>::const_iterator it = allWords.cbegin(); it != allWords.cend(); ++it)
        {
            if(usedWords.find(*it) == usedWords.end() && (*it).find(command) != string::npos)
            {
                usedWords.insert(*it);
                cout << *it << endl;
                return;
            }
        }
        cout << "No words found" << endl;
    }
}