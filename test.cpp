#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>
#include <omp.h>
#include <unistd.h>
#include <fstream>
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
  clearFile(thread);
  string teams[] = {"Liverpool", "Man City", "Leicester", "Chelsea", "Man Utd", "Wolves", "Sheffield Utd", "Arsenal", "Spurs", "Burnley", "Everton", "Crystal Palace", "Newcastle", "Southampton", "Brighton", "West Ham", "Watford", "Aston Villa", "Bournemouth", "Norwich"};
  string homegame[] = {"Crystal Palace", "Arsenal", "Sheffield Utd", "Bournemouth", "Aston Villa", "Sheffield Utd", "Wolves", "Spurs", "Bournemouth", "Man Utd", "Arsenal", "Burnley", "Chelsea", "Crystal Palace", "Leicester", "Newcastle", "Aston Villa", "Liverpool", "Man Utd", "Sheffield Utd", "Spurs", "Wolves", "Arsenal", "Chelsea", "Crystal Palace", "Leicester", "Southampton"};
  string awaygame[] = {"Chelsea", "Leicester", "Wolves", "Spurs", "Man Utd", "Chelsea", "Everton", "Arsenal", "Leicester", "Southampton", "Liverpool", "Wolves", "Norwich", "Man Utd", "Sheffield Utd", "Spurs", "Arsenal", "Chelsea", "West Ham", "Everton", "Leicester", "Crystal Palace", "Watford", "Wolves", "Spurs", "Man Utd", "Sheffield Utd"};
  int status[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int points[] = {86, 66, 55, 54, 52, 52, 47, 46, 45, 45, 44, 42, 42, 40, 33, 30, 28, 27, 27, 21};

  map<string, int> teamspoints;

  for (int i = 0; i < sizeof(teams) / sizeof(teams[0]); i++) //initialise starting points for each team
  {
    teamspoints[teams[i]] = points[i];
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
    cout << status[i] << " ";
  }
  cout << endl;
  //system("pause");
  //cout << "NUMBER OF GAMES = " << sizeof(homegame) / sizeof(homegame[0]) << endl;
  cout << counter << "           " << start << endl;
  while (exit == false && counter < end)
  {
    int statuscounter = 0;                                           //used to check if the status arrray is full of 2s.
    for (int i = 0; i < sizeof(homegame) / sizeof(homegame[0]); i++) //add points to teams for the current permutation
    {
      if (status[i] == 2)
      {
        statuscounter = statuscounter + 1;
      }
      teamspoints[homegame[i]] = teamspoints[homegame[i]] + addpointshome(status[i]);
      teamspoints[awaygame[i]] = teamspoints[awaygame[i]] + addpointsaway(status[i]);
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
    for (int i = data.size() - 1; i >= 0; i--)
    {
      //teamsendpositions {team:{1:500, 2:400}}, used to count the number of times a team has finished in a position
      teamendpositions[data[i]][20 - i] = teamendpositions[data[i]][20 - i] + 1;
    }

    if (counter % 100000 == 0) //to print the frequency of positions every 100,000 permutations
    {
      clearFile(thread);
      for (int i = 0; i < 20; i++)
      {
        // cout << teams[i];
        writeFile(thread, teams[i]);
        for (int x = 1; x < 21; x++)
        {

          writeFile(thread, " " + to_string(x) + ":" + to_string(teamendpositions[teams[i]][x]));
          // cout << " " << x << ":" << teamendpositions[teams[i]][x] << " ";
        }
        writeFile(thread, "\n");
        //cout << endl;
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
  for (int i = 0; i < 20; i++)
  {
    // cout << teams[i];
    writeFile(thread, teams[i]);
    for (int x = 1; x < 21; x++)
    {

      writeFile(thread, " " + to_string(x) + ":" + to_string(teamendpositions[teams[i]][x]));
      // cout << " " << x << ":" << teamendpositions[teams[i]][x] << " ";
    }
    //writeFile(thread, "          counter  " + to_string(counter) + "      thread " + to_string(thread) + "\n");
    writeFile(thread, "\n");

    //cout << endl;
  }
}

int main()
{
#pragma omp parallel
  {
    // if (omp_get_thread_num() == 0)
    // {
    //   //cout << "asdfgdjiaonrfokwepjnbgerfewokprnjberfewkornjbemr,rlokrfewl,rborkf,reopbkpkgebksomkl" << endl;
    //   othermain(0, 1000000);
    // }
    // if (omp_get_thread_num() == 1)
    // {
    //   sleep(2);
    //   // cout << "asdfgdjiaonrfokwepjnbgerfewokprnjberfewkornjbemr,rlokrfewl,rborkf,reopbkpkgebksomkl" << endl;
    //   othermain(1000001, 2000001);
    // }
    for (int i = 0; i < omp_get_max_threads(); i++)
    {
      if (omp_get_thread_num() == i)
      {
        sleep(2);
        cout << omp_get_thread_num() << endl;
        //cout << omp_get_max_threads() << endl;
        //othermain(omp_get_thread_num() * 10000000, 10000000 / (omp_get_max_threads()- omp_get_thread_num() ), omp_get_thread_num());
        othermain(0, 1000001, omp_get_max_threads(), omp_get_thread_num());
      }
    }

    //cout << omp_get_max_threads() << endl;
    //othermain(omp_get_thread_num() * 10000000, 10000000 / (omp_get_max_threads()- omp_get_thread_num() ), omp_get_thread_num());
  }
}
