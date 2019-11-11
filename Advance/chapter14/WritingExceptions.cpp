#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <sstream>
#include <cstddef>

using namespace std;

class FileError : public exception
{
public:
    FileError(string_view fileName) : mFileName(fileName) {}
    virtual const char* what() const noexcept override { return mMessage.c_str(); }
    string_view getFileName() const noexcept { return mFileName; }

protected:
    void setMessage(string message) { mMessage = message; }

private:
    string mFileName;
    string mMessage;
};

class FileOpenError : public FileError
{
public:
    FileOpenError(string_view fileName)
        : FileError(fileName)
    {
        setMessage("Unable to open "s + fileName.data());
    }
};

class FileReadError : public FileError
{
public:
    FileReadError(string_view fileName, size_t lineNumber)
        : FileError(fileName), mLineNumber(lineNumber)
    {
        ostringstream ostr;
        ostr << "Error reading " << fileName << " at line " << lineNumber;
        setMessage(ostr.str());
    }

    size_t getLineNumber() const noexcept { return mLineNumber; }

private:
    size_t mLineNumber;
};

vector<int> readIntegerFile(string_view fileName)
{
    ifstream inputStream(fileName.data());
    if (inputStream.fail()) {
        throw FileOpenError(fileName);
    }

    vector<int> integers;
    size_t lineNumber = 0;
    while(!inputStream.eof()) {
        // 从文件中读取一行
        string line;
        getline(inputStream, line);
        ++lineNumber;

        // 从一行字符中创建字符串流;
        istringstream lineStream(line);

        // 读取整数，一个个添加到 vector 中
        int temp;
        while (lineStream >> temp) {
            integers.push_back(temp);
        }

        if (!lineStream.eof()) {
            throw FileReadError(fileName, lineNumber);
        }
    }
    return integers;
}

int main()
{
    const string fileName = "IntegerFile.txt";
    vector<int> myInts;

    try {
        myInts = readIntegerFile(fileName);
    } catch(const FileError& e) {
        cerr << e.what() << endl;
        return 1;
    }

    for (const auto& element : myInts) {
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}