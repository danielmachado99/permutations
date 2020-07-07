
// C++ program for the above approach
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Function to sort the map according
// to value in a (key-value) pairs
std::vector<std::string> sort(map<string, int> &M)
{

    // Declare a multimap
    multimap<int, string> MM;
    std::vector<std::string> data;
    int counter = 0;
    // Insert every (key-value) pairs from
    // map M to multimap MM as (value-key)
    // pairs
    for (auto &it : M)
    {
        MM.insert({it.second, it.first});
    }

    // Print the multimap
    for (auto &it : MM)
    {
        data.push_back(it.second);
    }

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        //cout << data[i] << endl;
    }

    return (data);
}

int main()
{
    using namespace std;
    map<string, map<int, int>> teamendpositions;
    teamendpositions["spurs"][2] = 234;
    teamendpositions["spurs"][3] = 22354334;

    teamendpositions["arsenal"][3] = 234352;
    // cout << teamendpositions["spurs"][2] << "  " << teamendpositions["spurs"][3];
    string teams[] = {"Liverpool", "Man City", "Leicester", "Chelsea", "Man Utd", "Wolves", "Sheffield Utd", "Arsenal", "Spurs", "Burnley", "Everton", "Crystal Palace", "Newcastle", "Southampton", "Brighton", "West Ham", "Watford", "Aston Villa", "Bournemouth", "Norwich"};

    map<string, int> teamspoints;
    //string teamspointssorted[];

    for (int i = 0; i < sizeof(teams) / sizeof(teams[0]); i++)
    {
        teamspoints[teams[i]] = 20 - i;
        // cout << teamspoints[teams[i]] << endl;
    }

    // Declare Map
    map<string, int> M;

    // Given Map
    M = teamspoints;
    std::vector<std::string> data;
    // Function Call
    data = sort(M);
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
    system("pause");
    return 0;
}