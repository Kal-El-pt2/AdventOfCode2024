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

    vector<string> a;
    string input;
    while (getline(inputFile, input))
    {
        a.push_back(input);
    }

    int n = a[0].length(); // number of columns
    int m = a.size();      // number of rows
    long long count = 0;
    /*

    // Horizontal Left-to-Right and Right-to-Left
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - 3; ++j) {
            string t = a[i].substr(j, 4);
            if (t == "XMAS") count++;
            reverse(t.begin(), t.end());
            if (t == "XMAS") count++;
        }
    }

    // Vertical Top-to-Bottom and Bottom-to-Top
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 3; ++j) {
            string t = string(1, a[j][i]) + string(1, a[j + 1][i]) + string(1, a[j + 2][i]) + string(1, a[j + 3][i]);
            if (t == "XMAS") count++;
            reverse(t.begin(), t.end());
            if (t == "XMAS") count++;
        }
    }

    // Diagonal Top-Left to Bottom-Right and Bottom-Right to Top-Left
    for (int i = 0; i < n - 3; ++i) {
        for (int j = 0; j < m - 3; ++j) {
            string t = string(1, a[j][i]) + string(1, a[j + 1][i + 1]) + string(1, a[j + 2][i + 2]) + string(1, a[j + 3][i + 3]);
            if (t == "XMAS") count++;
            reverse(t.begin(), t.end());
            if (t == "XMAS") count++;
        }
    }

    // Diagonal Top-Right to Bottom-Left and Bottom-Left to Top-Right
    for (int i = 3; i < n; ++i) {
        for (int j = 0; j < m - 3; ++j) {
            string t = string(1, a[j][i]) + string(1, a[j + 1][i - 1]) + string(1, a[j + 2][i - 2]) + string(1, a[j + 3][i - 3]);
            if (t == "XMAS") count++;
            reverse(t.begin(), t.end());
            if (t == "XMAS") count++;
        }
    }
    */

    for (int i = 0; i < m-2; ++i)
    {
        for (int j = 0; j < n-2; ++j)
        {
            string s = string(1, a[i][j]) + string(1, a[i + 1][j + 1]) + string(1, a[i + 2][j + 2]);
            string t = string(1, a[i][j+2]) + string(1, a[i + 1][j + 1]) + string(1, a[i + 2][j]);
        
            if( (s == "MAS"|| s== "SAM") && (t =="MAS"|| t== "SAM")){
                count++;
            }
        }
    }

    cout << count << endl;
    inputFile.close();
    return 0;
}
