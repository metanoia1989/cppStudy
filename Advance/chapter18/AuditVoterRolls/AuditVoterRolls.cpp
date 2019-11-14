#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <set>

using namespace std;

// 选民登记审核问题
  
using VotersMap = map<string, vector<string>>;
using DistrictPair = pair<const string, vector<string>>;


// 找到所有出现多个选民登记vector中的姓名
set<string> getDuplicates(const VotersMap& votersByDistrict)
{
    vector<string> allNames;
    for (auto& district : votersByDistrict) {
        allNames.insert(end(allNames), begin(district.second), end(district.second));
    }

    sort(begin(allNames), end(allNames));

    set<string> duplicates;
    for (auto lit = cbegin(allNames); lit != cend(allNames); ++lit) {
        lit = adjacent_find(lit, cend(allNames));
        if (lit == cend(allNames)) {
            break;
        }
        duplicates.insert(*lit);
    }

    return duplicates;
}

// 调用 getDuplicates 获得所有登记vector中的重复名字
// 将重复姓名 set 和 罪犯 set 合并
// 在每个选民 vector 中删除重复姓名 set 和 罪犯 vector 合并结果中的所有姓名
void auditVoterRolls(VotersMap& votersByDistrict, const vector<string>& convictedFelons)
{
    set<string> toRemove = getDuplicates(votersByDistrict);

    toRemove.insert(cbegin(convictedFelons), cend(convictedFelons));

    for_each(begin(votersByDistrict), end(votersByDistrict),
        [&toRemove](DistrictPair& district){
            auto it = remove_if(begin(district.second), end(district.second), 
                [&toRemove](const string& name){ 
                    return (toRemove.count(name) > 0);  
                }
            );
            district.second.erase(it, end(district.second));
        }
    );
}

int main(int argc, char const *argv[])
{
    VotersMap voters = {
        { "Orange", { "Amy Aardvark", "Bob Buffalo", "Charles Cat", "Dwayne Dog" } },
        { "Los Angeles", { "Elizabeth Elephant", "Fred Flamingo", "Amy Aardvark" } },
        { "San Diego", { "Georage Goose", "Heidi Hen", "Fred Flamingo" } }
    };

    vector<string> felons = { "Bob Buffalo", "Charles Cat" };

    auto printDistrict = [](const DistrictPair& district) {
        cout << district.first << ":";
        for (auto& str : district.second) {
            cout << " {" << str << "}";
        }
        cout << endl;
    };

    cout << "Before Audit: " << endl;
    for (const auto& district : voters) { printDistrict(district); }
    cout << endl;

    auditVoterRolls(voters, felons);

    cout << "After Audit:" << endl;
    for (const auto& district : voters) { printDistrict(district); }
    cout << endl;

    return 0;
}
