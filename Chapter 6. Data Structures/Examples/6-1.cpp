// 题目 UVA 210 ：https://cn.vjudge.net/problem/UVA-210

/**
 * TODO
 * 输出正确，但超时了
 */

#include <cstdio>
#include <iostream>
#include <deque>
#include <queue>
#include <map>
using namespace std;

int n, Q; // 程序数量、一次程序可运行的时间
// 五种操作的别名
const string ASSIGN = "=";
const string PRINT = "print";
const string LOCK = "lock";
const string UNLOCK = "unlock";
const string END = "end";

bool isLock = false; // 是否存在程序正在独占变量访问（即调用lock，但为调用unlock）

// 语句
class Statement
{
  private:
    string operation, variable, value; // 操作、变量、值
    int remainingTime;                 // 剩余执行时间
  public:
    Statement(string operation, string variable, string value, int remainingTime) : operation(operation), variable(variable), value(value), remainingTime(remainingTime) {}

    // 获取操作
    string getOperation()
    {
        return operation;
    }
    // 获取变量
    string getVariable()
    {
        return variable;
    }
    // 获取值
    string getValue()
    {
        return value;
    }
    // 获取剩余执行时间
    int getTime()
    {
        return remainingTime;
    }
    // 设置剩余执行时间
    void setTime(int time)
    {
        remainingTime = time;
    }
};

typedef queue<Statement> Program; // 程序的数据类型
vector<Program> programs;         // 程序
deque<int> readyQueue;            // 等待队列，存储程序id
queue<int> blockedQueue;          // 阻止队列，存储程序id
map<string, string> variables;
map<string, int> times; // 5中语句运行所需的时间

/**
 * 将语句转化为Statement对象
 * @param statement 语句
 * @param operation 操作
 * @param variable 变量
 * @param value 值
 */
void readStatement(const string &statement, string &operation, string &variable, string &value)
{
    auto position = statement.find(' ');
    operation = statement.substr(0, position);

    // 没有空格，即lock、unlock、end
    // 有空格，则为赋值语句或者打印语句
    if (position == string::npos)
    {
        variable = value = "";
    }
    else
    {
        // 如果第一个单词为单字母，则为赋值语句
        if (operation.size() == 1)
        {
            variable = operation;
            operation = "=";

            auto rPosition = statement.find_last_of(' ');
            value = statement.substr(rPosition + 1);
        }
        else
        { // 打印语句
            variable = statement.substr(position + 1);
            value = "";
        }
    }
}

/**
 * 复制，储存在 variable map 中
 * @param variable 变量
 * @param value 值
 */
void assign(string variable, string value)
{
    variables[variable] = value;
}

/**
 * 打印
 * @param id 程序id
 * @param variable 变量
 */
void print(int id, string variable)
{
    cout << id << ": " << variables[variable] << endl;
}

/**
 * 加锁
 * @return 是否加锁成功
 */
bool lock()
{
    if (!isLock)
    {
        isLock = true;
        return true;
    }
    return false;
}

/**
 * 解锁
 */
void unlock()
{
    isLock = false;
}

/**
 * 运行程序
 */
void running()
{
    int id = readyQueue.front();
    readyQueue.pop_front(); // 准备执行的程序，出队列
    Program *programPtr = &programs[id - 1];

    int time = Q;
    while (1)
    {
        Statement statement = programPtr->front();
        string operation = statement.getOperation();
        time = time - statement.getTime();

        if (time >= 0)
        {
            if (operation == ASSIGN)
            { // 赋值
                assign(statement.getVariable(), statement.getValue());
            }
            else if (operation == PRINT)
            { // 打印
                print(id, statement.getVariable());
            }
            else if (operation == LOCK)
            { // lock
                if (!lock())
                {
                    // 将程序移动到阻止队列
                    blockedQueue.push(id);
                    break;
                }
            }
            else if (operation == UNLOCK)
            { // unlock
                unlock();
                if (!blockedQueue.empty())
                {
                    // 将阻止队列中的第一个程序移动到等待队列
                    int blockedId = blockedQueue.front();
                    blockedQueue.pop();
                    readyQueue.push_front(blockedId);
                }
            }
            else
            { // 结束
                break;
            }
            programPtr->pop();
        }
        else
        { // 运行时间已经用完，语句未执行完
            // time为负数，负负得正
            statement.setTime(-time);
            // 将程序放到等待队列队尾
            readyQueue.push_back(id);
            break;
        }
    }
}

int main()
{
    cin >> n >> times[ASSIGN] >> times[PRINT] >> times[LOCK] >> times[UNLOCK] >> times[END] >> Q;
    // 处理并存储程序
    for (int i = 1; i <= n; ++i)
    {
        string input;
        Program program;
        while (getline(cin, input) && input != "end")
        {
            if (input == "")
            {
                continue;
            }
            string operation, variable, value; // 操作、变量、值
            readStatement(input, operation, variable, value);
            Statement statement(operation, variable, value, times[operation]);
            program.push(statement);
        }
        Statement s(END, "", "", times[END]);
        program.push(s);
        programs.push_back(program);
        readyQueue.push_back(i);
    }

    // 并发执行程序
    while (!readyQueue.empty())
    {
        running();
    }

    return 0;
}
