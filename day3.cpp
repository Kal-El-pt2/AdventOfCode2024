#include <bits/stdc++.h>
using namespace std;

int main()
{
    string filename = "input.txt";

    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1;
    }

    regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))"); 
    regex dont(R"(don't\(\))");               
    regex doit(R"(do\(\))");                 

    bool doing = true; 
    long long totalSum = 0;
    string line;

    while (getline(inputFile, line)) 
    {
        auto it = line.cbegin();
        auto end = line.cend();
        smatch match;

        while (it != end)
        {
            if (regex_search(it, end, match, dont))
            {
                doing = false;           
                it = match[0].second;        
                continue;
            }

            if (regex_search(it, end, match, doit))
            {
                doing = true;           
                it = match[0].second;        
                continue;
            }

            if (regex_search(it, end, match, mulPattern))
            {
                if (doing)
                {
                    int x = stoi(match[1]);  
                    int y = stoi(match[2]);  
                    totalSum += x * y;       
                }
                it = match[0].second;       
                continue;
            }
            ++it;
        }
    }

    inputFile.close();
    cout << totalSum << endl;
    return 0;
}
