#include <iostream>
#include <fstream>
#include <vector>
#define dataInDatafile 3
#define fileName "data.txt"

void init(std::string username, std::string password)
{
    std::string path = fileName;
    std::ofstream out;
    out.open(path);
    out << username << '\n'
        << password;
    out.close();
}

void Push()
{
    std::string inputFromDataFile[3];
    std::ifstream input;
    input.open(fileName);
    for (int i = 0; i < dataInDatafile; i++)
    {
        getline(input, inputFromDataFile[i]);
    }
    // string To Char -------start
    std::string finalCommandStr = "";
    finalCommandStr += "git push https://" + inputFromDataFile[0] + ":" + inputFromDataFile[1] + "@" + inputFromDataFile[2];
    int lenOffinalCommand = finalCommandStr.size();
    char finalCommand[lenOffinalCommand - 3];

    for (int i = 0; i < lenOffinalCommand; i++)
    {
        finalCommand[i] = finalCommandStr[i];
    }

    // string To Char ------end

    // std::cout << finalCommand << std::endl;

    // git push https://user:pass@yourrepo.com/path HEAD

    system(finalCommand);
}
int main()
{
    Push();
    return 0;
}