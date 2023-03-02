#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class DataLog
{
public:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }

    void printLog()
    {
        for (auto i = logList.begin(); i != logList.end(); i++)
        {
            if (i == currentState)
                cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog()
{
    logList.push_back(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    logList.push_back(data);
    currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
    *currentState += number;
}

void DataLog::subtractCurrentState(int number)
{
    *currentState -= number;
}

void DataLog::save()
{
    if (currentState != --logList.end())
    {
        logList.pop_back();
    }
    logList.push_back(logList.back());
    currentState = --logList.end();
}

void DataLog::undo()
{
    if (currentState != logList.begin())
    {
        --currentState;
    }
}

void DataLog::redo()
{
    if (currentState != --logList.end())
    {
        ++currentState;
    }
}

int main()
{
    DataLog log(10);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.addCurrentState(15);
    log.undo();
    log.printLog();
}