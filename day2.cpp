#include <bits/stdc++.h>

using namespace std;

bool isSafe(const vector<int>& a) {
    int n = a.size();
    if (n < 2) return false; // Not enough levels to evaluate
    bool inc = true;
    if(a[0] > a[1]){
        inc = false;
    }
    
    for(int i=1;i<n;++i){
        if(inc){
            int diff = a[i] - a[i-1];

            if(diff<=0 || diff >3) return false;
        }
        else{
            int diff = a[i-1] - a[i];
            if(diff<=0 || diff>3) return false;
        }
    }
    return true;   
}

int main() {
    string filename = "input.txt";
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1;
    }

    int safeCount = 0;
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<int> levels;
        int level;

        while (ss >> level) {
            levels.push_back(level);
        }

        if (isSafe(levels)) {
            ++safeCount;
        }
    }

    inputFile.close();

    cout << safeCount << endl;

    return 0;
}
