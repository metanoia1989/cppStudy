#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

list<string> getTotalEnrollment(const vector<list<string>>& courseStudents, 
    const list<string>& droppedStudents)
{
    list<string> allStudents;
    for (auto& lst : courseStudents) {
        allStudents.insert(cend(allStudents), cbegin(lst), cend(lst));
    }

    allStudents.sort();
    allStudents.unique();

    for (auto& str : droppedStudents) {
        allStudents.remove(str);
    }

    return allStudents;
}

list<string> readStudentList(ifstream& istr)
{
    list<string> students;
    string name;
    while (getline(istr, name)) {
        cout << "Read name " << name << endl;
        students.push_back(name);
    }
    return students;
}

vector<list<string>> readCourseLists()
{
    vector<list<string>> lists;
    for (int i=1; i<=3; i++) {
        ostringstream ostr;
        ostr << "course" << i << ".txt";

        ifstream istr(ostr.str().c_str());
        if (!istr) {
            cout << "Failed to open " << ostr.str() << endl;
            break;
        }
        lists.push_back(readStudentList(istr));
    }
    return lists;
}

list<string> readDroppedStudents()
{
    ifstream istr("dropped.txt");
    return readStudentList(istr);
}

int main(int argc, char const *argv[])
{
    vector<list<string>> courseStudents = readCourseLists();
    list<string> droppedStudents = readDroppedStudents();

    list<string> finalList = getTotalEnrollment(courseStudents, droppedStudents);

    for (const auto& name : finalList) {
        cout << name << endl;
    }

    return 0;
}
