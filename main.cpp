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
using std::find;
using std::sort;
using std::random_shuffle;

void getAllWords(vector<string> &allWords, const string &PATH);
void executeCommand(const string &command, vector<string> &allWords, unordered_set<string> &usedWords);
bool compareLen(string str1, string str2);

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

void executeCommand(const string &command, vector<string> &allWords, unordered_set<string> &usedWords)
{
    if(command == "clear")
        usedWords.clear();
    else if(command == "rand")
    {
        random_shuffle(allWords.begin(), allWords.end());
    }
    else if(command == "len")
    {
        sort(allWords.begin(), allWords.end(), compareLen);
    }
    else if(command == "quit")
        return;
    else
    {
        if(find(allWords.cbegin(), allWords.cend(), command) == allWords.cend() && usedWords.find(command) == usedWords.end())
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

bool compareLen(string str1, string str2)
{
    return str1.size() < str2.size();
}