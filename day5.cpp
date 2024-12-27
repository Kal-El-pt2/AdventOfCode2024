#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to check if there's a rule violation
bool violatesOrder(const set<pair<int, int>> &rules, int a, int b)
{
    return rules.find({b, a}) != rules.end();
}

int main()
{
    string filename = "input.txt";
    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1;
    }

    ll sum = 0;
    string line;
    set<pair<int, int>> rules;
    int lineCount = 1;

    while (getline(inputFile, line))
    {
        if (lineCount < 1177)
        { // First section: read the rules
            stringstream ss(line);
            string xStr, yStr;
            getline(ss, xStr, '|');
            getline(ss, yStr);
            int x = stoi(xStr), y = stoi(yStr);
            rules.insert({x, y});
            lineCount++;
        }
        else
        { // Second section: process the updates
            vector<int> pages;
            stringstream ss(line);
            string token;

            while (getline(ss, token, ','))
            { // Split by commas
                try
                {
                    int number = stoi(token);
                    pages.push_back(number);
                }
                catch (invalid_argument &)
                {
                    continue;
                }
            }

            int n = pages.size();
            bool validOrder = true;

            // Check if the pages are in the correct order
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if (violatesOrder(rules, pages[i], pages[j]))
                    {
                        swap(pages[i], pages[j]);
                        validOrder = false;
                    }
                }
            }

            // If valid, add the middle element to the sum
            if(!validOrder) sum += pages[n / 2];
        }
    }

    inputFile.close();

    // Output the result
    cout << sum << endl;

    return 0;
}
