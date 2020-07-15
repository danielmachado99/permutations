#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>
#include <omp.h>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
using namespace std;

void reverseStr(string &str)
{
  int n = str.length();

  // Swap character starting from two
  // corners
  for (int i = 0; i < n / 2; i++)
    swap(str[i], str[n - i - 1]);
}

int writeFile(int thread, string toappend)
{
  ofstream outfile;
  string temp = to_string(thread) + ".txt";
  outfile.open(temp, ios_base::app); // append instead of overwrite
  outfile << (toappend);
  return 0;
}
int clearFile(int thread)
{
  ofstream outfile;
  string temp = to_string(thread) + ".txt";
  outfile.open(temp); // append instead of overwrite
  outfile << ("");
  return 0;
}

int val(char c)

{
  if (c >= '0' && c <= '9')
    return (int)c - '0';
  else
    return (int)c - 'A' + 10;
}
// Function to convert a number from given base 'b'
// to decimal
int toDeci(char *str, int base)
{
  int len = strlen(str);
  int power = 1; // Initialize power of base
  int num = 0;   // Initialize result
  int i;

  // Decimal equivalent is str[len-1]*1 +
  // str[len-2]*base + str[len-3]*(base^2) + ...
  for (i = len - 1; i >= 0; i--)
  {
    // A digit in input number must be
    // less than number's base
    if (val(str[i]) >= base)
    {
      printf("Invalid Number");
      return -1;
    }

    num += val(str[i]) * power;
    power = power * base;
  }

  return num;
}
// Driver code
// To return char for a value. For example '2'
// is returned for 2. 'A' is returned for 10. 'B'
// for 11
char reVal(int num)
{
  if (num >= 0 && num <= 9)
    return (char)(num + '0');
  else
    return (char)(num - 10 + 'A');
}
// Utility function to reverse a string
void strev(char *str)
{
  int len = strlen(str);
  int i;
  for (i = 0; i < len / 2; i++)
  {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}
// Function to convert a given decimal number
// to a base 'base' and
char *fromDeci(char res[], int base, long long inputNum)
{
  int index = 0; // Initialize index of result

  // Convert input number is given base by repeatedly
  // dividing it by base and taking remainder
  while (inputNum > 0)
  {
    res[index++] = reVal(inputNum % base);
    inputNum /= base;
  }
  res[index] = '\0';

  // Reverse the result
  strev(res);

  return res;
}

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

int addpointshome(int status)
{
  if (status == 0)
  {
    return (0);
  }
  if (status == 1)
  {
    return (1);
  }
  if (status == 0)
  {
    return (3);
  }
  return (-1);
}
int addpointsaway(int status)
{
  if (status == 0)
  {
    return (3);
  }
  if (status == 1)
  {
    return (1);
  }
  if (status == 0)
  {
    return (0);
  }
  return (-1);
}

void othermain(long long start, long long end, int maxthreads, int thread)
{
  cout << thread << endl;
  clearFile(thread);
  //string teams[] = {"Liverpool", "Man City", "Chelsea", "Leicester", "Man Utd", "Wolves", "Sheffield Utd", "Spurs", "Arsenal", "Burnley", "Everton", "Southampton", "Newcastle", "Crystal Palace", "Brighton", "West Ham", "Watford", "Bournemouth", "Aston Villa", "Norwich"};
  // string homegame[] = {"Chelsea", "Burnley", "Man City", "Newcastle", "Arsenal", "Everton", "Leicester", "Crystal Palace", "Southampton", "West Ham", "Norwich", "Bournemouth", "Spurs", "Brighton", "Sheffield Utd", "Wolves", "Watford", "Aston Villa", "Man Utd", "Liverpool", "Arsenal", "Burnley", "Chelsea", "Crystal Palace", "Everton", "Leicester", "Man City", "Newcastle", "Southampton", "West Ham"};
  //string awaygame[] = {"Norwich", "Wolves", "Bournemouth", "Spurs", "Liverpool", "Aston Villa", "Sheffield Utd", "Man Utd", "Brighton", "Watford", "Burnley", "Southampton", "Leicester", "Newcastle", "Everton", "Crystal Palace", "Man City", "Arsenal", "West Ham", "Chelsea", "Watford", "Brighton", "Wolves", "Spurs", "Bournemouth", "Man Utd", "Norwich", "Liverpool", "Sheffield Utd", "Aston Villa"};
  string teams[7] = {"Chelsea", "Leicester", "Man Utd", "Wolves", "Sheffield Utd", "Spurs", "Arsenal"};
  string homegame[] = {"Burnley", "Newcastle", "Arsenal", "Leicester", "Crystal Palace", "Spurs", "Sheffield Utd", "Wolves", "Aston Villa", "Man Utd", "Liverpool", "Arsenal", "Chelsea", "Crystal Palace", "Leicester", "Southampton"};
  string awaygame[] = {"Wolves", "Spurs", "Liverpool", "Sheffield Utd", "Man Utd", "Leicester", "Everton", "Crystal Palace", "Arsenal", "West Ham", "Chelsea", "Watford", "Wolves", "Spurs", "Man Utd", "Sheffield Utd"};
  int status[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  //int points[] = {93, 72, 60, 59, 59, 55, 54, 52, 50, 50, 45, 45, 43, 42, 36, 34, 34, 31, 30, 21};
  int points[] = {63, 59, 59, 55, 54, 52, 50};
  map<string, int> teamspoints;

  for (int i = 0; i < sizeof(teams) / sizeof(teams[0]); i++) //initialise starting points for each team
  {
    teamspoints[teams[i]] = points[i];
    // cout << teamspoints[teams[i]] << endl;
  }

  long long counter = start + thread;
  map<string, map<int, int>> teamendpositions;
  bool exit = false;
  char res[100];

  //long long begin = 0;
  // long long end = pow(3, (sizeof(homegame) / sizeof(homegame[0]))) - 1;

  string stringtemp = fromDeci(res, 3, counter); //fromDeci(res, 3, 0);
  reverse(stringtemp.begin(), stringtemp.end());
  int lengthstring = (sizeof(homegame) / sizeof(homegame[0])) - stringtemp.length();
  for (int i = 0; i < lengthstring; i++)
  {
    stringtemp = stringtemp + "0";
  }
  for (int i = 0; i < sizeof(status) / sizeof(status[0]); i++)
  {
    status[i] = stringtemp[i] - 48;
    // cout << status[i] << " ";
  }
  //cout << endl;
  //system("pause");
  //cout << "NUMBER OF GAMES = " << sizeof(homegame) / sizeof(homegame[0]) << endl;
  // cout << counter << "           " << start << endl;
  while (exit == false && counter < end)
  {
    int statuscounter = 0;                                           //used to check if the status arrray is full of 2s.
    for (int i = 0; i < sizeof(homegame) / sizeof(homegame[0]); i++) //add points to teams for the current permutation
    {
      if (status[i] == 2)
      {
        statuscounter = statuscounter + 1;
      }
      if (std::find(std::begin(teams), std::end(teams), homegame[i]) != std::end(teams))
      {
        // cout << homegame[i] << teamspoints[homegame[i]] << endl;
        teamspoints[homegame[i]] = teamspoints[homegame[i]] + addpointshome(status[i]);
      }
      else
      {
        // cout << "not in teams " << homegame[i] << endl;
        ;
      }
      if (std::find(std::begin(teams), std::end(teams), awaygame[i]) != std::end(teams))
      {
        teamspoints[awaygame[i]] = teamspoints[awaygame[i]] + addpointsaway(status[i]);
        // cout << awaygame[i] << teamspoints[awaygame[i]] << endl;
      }
      else
      {
        //cout << "not in teams " << awaygame[i] << endl;
        ;
      }
    }

    if (statuscounter == sizeof(homegame) / sizeof(homegame[0])) //exit while loop since permutations have been completed
    {
      exit = true;
    }

    //following code to sort teampoints to sort teams position.
    map<string, int> M;
    // Given Map
    M = teamspoints;
    std::vector<std::string> data;
    // Function Call
    data = sort(M);
    for (int i = 0; i < data.size(); i++)
    {
      //  cout << data[i] << endl;
    }
    for (int i = data.size() - 1; i >= 0; i--)
    {
      //teamsendpositions {team:{1:500, 2:400}}, used to count the number of times a team has finished in a position
      teamendpositions[data[i]][sizeof(teams) / sizeof(teams[0]) - i] = teamendpositions[data[i]][sizeof(teams) / sizeof(teams[0]) - i] + 1;
      // cout << data[i] << " " << teamendpositions[data[i]][sizeof(teams) / sizeof(teams[0]) - i] << endl;
    }

    if (counter % 100000 == 0) //to print the frequency of positions every 100,000 permutations
    {
      clearFile(thread);
      for (int i = 0; i < sizeof(teams) / sizeof(teams[0]); i++)
      {
        cout << teams[i];
        writeFile(thread, teams[i]);
        for (int x = 1; x < sizeof(teams) / sizeof(teams[0]) + 1; x++)
        {

          writeFile(thread, " " + to_string(x) + ":" + to_string(teamendpositions[teams[i]][x]));
          cout << " " << x << ":" << teamendpositions[teams[i]][x] << " ";
        }
        writeFile(thread, "\n");
        cout << endl;
      }
    }

    //following is to iterate to the next permutation

    // if (status[0] == 2)
    // {
    //   for (int i = 0; i < sizeof(status) / sizeof(status[0]); i++)
    //   {
    //     if (status[i] < 2)
    //     {
    //       status[i] = status[i] + 1;
    //       break;
    //     }
    //     else
    //     {
    //       status[i] = 0;
    //     }
    //   }
    // }
    // else
    // {
    //   status[0] = status[0] + 1;
    // }

    string stringtemp = fromDeci(res, 3, counter); //fromDeci(res, 3, 0);
    reverse(stringtemp.begin(), stringtemp.end());
    int lengthstring = (sizeof(homegame) / sizeof(homegame[0])) - stringtemp.length();
    for (int i = 0; i < lengthstring; i++)
    {
      stringtemp = stringtemp + "0";
    }
    for (int i = 0; i < sizeof(status) / sizeof(status[0]); i++)
    {
      status[i] = stringtemp[i] - 48;
      //cout << status[i] << " ";
    }
    //cout << "                                     " << thread << endl;
    // system("pause");

    //following is for setting the points of each team to their starting points , for the next permutation
    for (int i = 0; i < sizeof(teams) / sizeof(teams[0]); i++)
    {
      teamspoints[teams[i]] = points[i];
      ;
    }

    counter = counter + maxthreads;
  }
  cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
  clearFile(thread);
  for (int i = 0; i < sizeof(teams) / sizeof(teams[0]); i++)
  {
    // cout << teams[i];
    writeFile(thread, "{\"" + teams[i] + "\"" + ":{");
    for (int x = 1; x < sizeof(teams) / sizeof(teams[0]) + 1; x++)
    {

      writeFile(thread, "" + to_string(x) + ":" + to_string(teamendpositions[teams[i]][x]) + ",");
      cout << " " << x << ":" << teamendpositions[teams[i]][x] << " ";
    }
    //writeFile(thread, "          counter  " + to_string(counter) + "      thread " + to_string(thread) + "\n");
    writeFile(thread, "}}\n");

    //cout << endl;
  }
}

int main()
{

  // cout << endl;
  //othermain(0, 20, 8, 7);
  omp_set_num_threads(8);
#pragma omp parallel num_threads(8)
  {
    cout << "started" << omp_get_thread_num() << endl;

    cout << omp_get_thread_num() << endl;
    othermain(0, pow(3, 17), omp_get_max_threads(), omp_get_thread_num());
  }
}
