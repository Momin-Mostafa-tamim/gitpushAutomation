#include <iostream>
#include <fstream>
#include <vector>
#define dataInDatafile 3
#define fileName "data.txt"

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

    /*
        inputFromDataFile[0] = username
        inputFromDatafile[1] = password
        inputFromDatafile[3] = github Path
    */
    int lenOffinalCommand = finalCommandStr.size();
    char finalCommand[lenOffinalCommand - 3];

    for (int i = 0; i < lenOffinalCommand; i++)
    {
        finalCommand[i] = finalCommandStr[i];
    }

    // string To Char ------end

    system(finalCommand);
}
int main()
{
    Push();
    return 0;
}