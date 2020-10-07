#include <list>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    list<string> dictionary{ "dict-frist", "dict-second" };
    list<string> bWords{ "bWords-first", "bWords-second" };

    dictionary.push_back("dict-third");
    dictionary.push_back("dict-four");

    if (!bWords.empty()) {
        auto iterLastB = --(cend(bWords));
        auto it = cbegin(dictionary);
        for (; it != cend(dictionary); ++it) {
            if (*it > *iterLastB) 
                break;
        }
        dictionary.splice(it, bWords);
    }

    for (const auto& word : dictionary) {
        cout << word << endl;
    }    

    return 0;
}
