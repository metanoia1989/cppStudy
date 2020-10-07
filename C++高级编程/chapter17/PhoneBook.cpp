#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

template<class T>
void printMap(const T& m)
{
    for (auto& [key, value] : m) {
        cout << key << "（Phone: " << value << "）" << endl;
    }

    cout << "--------------" << endl;
}

int main(int argc, char const *argv[])
{
    // 创建哈希表
    unordered_map<string, string> phoneBook = {
        { "Marc G.", "123-456789" },
        { "Scott K.", "654-987321" },
    };
    printMap(phoneBook);

    // 添加和移除一些电话号码
    phoneBook.insert(make_pair("John D.", "321-987654"));
    phoneBook["Johan G."] = "963-258147";
    phoneBook["Freddy K."] = "999-256256";
    phoneBook.erase("Freddy K.");
    printMap(phoneBook);

    // 根据指定查找桶索引
    const size_t bucket = phoneBook.bucket("Marc G.");
    cout << "Marc G. is in bucket " << bucket
        << " which contains the following "
        << phoneBook.bucket_size(bucket) << " elements: " << endl;

    auto localBegin = phoneBook.cbegin(bucket);
    auto localEnd = phoneBook.cend(bucket);
    for (auto iter = localBegin; iter != localEnd; ++iter) {
        cout << "\t" << iter->first << " (Phone："
            << iter->second << ")" << endl;
    }
    cout << "--------------" << endl;

    cout << "There are " << phoneBook.bucket_count() << " buckets." << endl;
    cout << "Average number of elements in a bucket is " << phoneBook.load_factor() << endl;

    return 0;
}

