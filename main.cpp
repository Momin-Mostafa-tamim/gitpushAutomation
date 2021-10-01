#include <iostream>
#include <fstream>
#include <string>

#define dataInDatafile 3
#define fileName "data.txt"

void Push()
{
    std::string inputFromDataFile[3];
    std::ifstream input;
    std::string finalCommandStr = "";
    input.open(fileName);
    for (int i = 0; i < dataInDatafile; i++)
    {
        getline(input, inputFromDataFile[i]); /*
                                                inputFromDataFile[0] = username
                                                inputFromDatafile[1] = password
                                                inputFromDatafile[3] = github Path
                                                */
    }
    // string To Char -------start

    finalCommandStr += "git push https://" + inputFromDataFile[0] + ":" + inputFromDataFile[1] + "@" + inputFromDataFile[2];

    int lenOfFinalCommand = finalCommandStr.size();
    char finalCommand[lenOfFinalCommand - 3];

    for (int i = 0; i < lenOfFinalCommand; i++)
    {
        finalCommand[i] = finalCommandStr[i];
    }

    // string To Char ------end

    system(finalCommand);

    input.close();
}
void init()
{
    std::ofstream generate;

    std::string UserName;
    std::string Key;
    std::string ProjectName;
    std::string finalFormat;

    std::cout << "Username : ";
    std::cin >> UserName;
    std::cout << "Key : ";
    std::cin >> Key;
    std::cout << "Project Name : ";
    std::cin >> ProjectName;

    finalFormat = UserName + "\n" + Key + "\n" + "github.com/" + UserName + "/" + ProjectName;

    generate.open("data.txt");

    generate << finalFormat;

    generate.close();
}
//TODO : add git add and git commit .
int main(int argc, char *argv[])
{

    if (argc == 1)
        Push();

    if (argc > 1)
    {
        std::string argument = argv[1];
        if (argument == "init")
            init();
    }
    return 0;
}