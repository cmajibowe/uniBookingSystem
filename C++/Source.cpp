// Student id: 16013340
// 12/01/17
// Purpose of program is to allow a client to book sessions
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Customer
{
  // Struct made to sort the current customers data
  // Store the customers name
  string name = " ";
  // Store the type of package the customer has
  string custPack = " ";
  // Session limit is set upon package being assigned
  int sessionLimit = 0;
};

string getName() {
  // getName function used to get the clients name
  // Variable to hold name
  string name = " ";
  // Used to get users input
  char checkBit = ' ';
  // Bool to make sure a name has been entered and is correct
  bool cust = false;

  // Do loop used to loop if the client enters an incorrect name
  do
  {
    // General information to help the client
    cout << "Please enter a customers surname." << endl;
    cout << "Enter exit to quit the program" << endl;
    cin >> name;

    // Allows client to check name entered and change it
    cout << "You entered " << name << ". Is this correct? (y|n)" << endl;
    cin >> checkBit;
    // Simple if statement to get client input on if the name is correct
    if (checkBit == 'y' || checkBit == 'Y')
    {
      cust = true;
    }

  } while (cust == false);

  return name;
}

char getPack() {
  // getPack function used to get the pack type the customer has
  // Variable to get user input
  char pack = ' ';
  // Bool to make sure it is a valid input
  bool checkBit = false;

  // Do loop to go through the selection and make sure the user enters
  // a correct value
  do
  {
    // General information to user
    cout << "Please enter the package that the customer " << endl;
    cout << "has purchased." << endl;
    cout << "Either input g for Gold or s for Standard." << endl;
    cin >> pack;

    // If statement to check that the appropriate input has been entered
    // if inappropriate then feed back given to client
    if (pack == 'g' || pack == 's')
    {
      checkBit = true;
    }
    else
    {
      cout << "Please enter a valid input." << endl;
    }

  } while (checkBit == false);

  return pack;
}

void dupRemover(string array[], string sessionName[])
{
  // Function created to remove any duplicate session names
  //for easy viewing of the client
  // Array to hold all the names
  string a[30];
  // Int variables to hold and sort
  int i, j, k, n, q;
  // Assigned to the amount of array entities
  n = 30;
  q = 0;

  // Removes welcome from the list manually because it is automatically
  // added depending on a clients package
  for (int i = 0; i < 30; i++)
  {
    if (array[i] != "Welcome")
    {
      a[q] = array[i];
      q++;
    }
  }

  // This is the main sorting loops
  for (i = 0; i < n; ++i)
  {
    for (j = i + 1; j < n;)
    {
      if (a[i] == a[j])
      {
        for (k = j; k < n - 1; ++k)
        {
          a[k] = a[k + 1];
        }
        --n;
      }
      else
      {
        ++j;
      }
    }
  }

  // This displayed all the sessions in the new set
  cout << "\n";
  for (i = 0; i<n; ++i)
    cout << a[i] << endl;
}

string validSession(string sessionName[], int count, string names[],
  Customer currentCustomer) {
  // Function used to make sure the session selected is valid and isn't
  // already being attended
  // Two bool variables to make sure the entered value is allowed
  bool check = false;
  bool checkBit = false;

    do
    {
      int t = 0;
      // Reassigning checkBit incase it was set to true further in the loop
      checkBit = false;

      cin >> sessionName[count];
      // Loops through to see if any of the sessionNames are not equal to
      // the set of session names in the names[] array
      for (int i = 0; i < 30; i++)
      {
        if (sessionName[count] != names[i])
        {
          t++;
        }
      }
      // Gives feedback to the client
      if (t == 30)
      {
        cout << "Invalid input, please enter a sessions name." << endl;
      }
      else
      {
        check = true;
      }

      // Checks to see if the user is already attending this session
      for (int i = 0; i < count; i++)
      {
        if (sessionName[count] == sessionName[i])
        {
          checkBit = true;
        }
      }

      // If they are already attending a session then this their instruction
      if (checkBit == true)
      {
        cout << "Invalid input. You are already attending that session.\n";
        check = false;
      }

      // Checks to see if a client with a standard package is trying to get
      // onto the welcome session and stops them
      if (currentCustomer.custPack == "Standard")
      {
        if (sessionName[count] == "Welcome")
        {
          check = false;
          cout << "You are not allowed to attend this session." << endl;
        }
      }

    } while (check == false);

  return sessionName[count];
}

void timeDisplay(string names[], int time[], string sessionName[], int z)
{
  // This function displays all avalible times a session is running
  // This for and if loop are used to find out how many different 
  // times are avalible
  int size = 0;
  for (int i = 0; i < 30; i++)
  {
    if (names[i] == sessionName[z])
    {
      size++;
    }
  }

  // This then sorts the times into an array ready to be displayed
  int list[10];
  int count = 0;

  for (int i = 0; i < 30; i++)
  {
    if (names[i] == sessionName[z])
    {
      list[count] = time[i];
      count++;
    }
  }

  // Finally the times are couted out for selection
  for (int i = 0; i < size; i++)
  {
    cout << list[i] << endl;
  }
  cout << "\n";
}

int validTime(int sessionTime[], int count, string sessionName[],
  string names[], int time[])
{
  // This funtion makes sure the user is selecting a valid time and that they
  // aren't already attending another session at the same time
  // Two bool variables to run checks
  bool check = false;
  bool checkBit = false;
  // Bool used to check if a valid time is avalible
  bool correctInput = false;
  // Array used to store all the time avalible for a specific session
  int timeSet[10];
  // Temp number used to add the times to the timeSet[] array
  int tempNum = 1;
  // Allows 0 to be a time so that the client can exit out of a session
  timeSet[0] = 0;

  // Main do loop to exit upon a valid time being inputted
  do
  {
    checkBit = false;
    // Time input
    cin >> sessionTime[count];

    // For loop to get all the times associated with the selected session
    for (int i = 0; i < 30; i++)
    {
      if (sessionName[count] == names[i])
      {
        timeSet[tempNum] = time[i];
        tempNum++;
      }
    }

    // Checks if the inputted time is a valid time for the session
    for (int i = 0; i < 10; i++)
    {
      if (sessionTime[count] == timeSet[i])
      {
        correctInput = true;
      }
    }

    // These loops check that the client isn't already at a session at the
    // same time as the one they are trying to attend
    if (correctInput == true)
    {
      if (count != 0)
      {
        for (int i = 0; i < count; i++)
        {
          if (sessionTime[count] == sessionTime[i])
          {
            checkBit = true;
          }
          else
          {
            check = true;
          }
        }

        // If the user is already attending a session at that time the 
        // program warns them
        if (checkBit == true)
        {
          cout << "You are already attending a session at this time." << endl;
          cout << "Please choose another time from above." << endl;
          check = false;
        }
      }
      else
      {
        check = true;
      }
    }
    else
    {
      cout << "The session is not on at this time. ";
      cout << "Please choose another time." << endl;
    }

  } while (check == false);

  return sessionTime[count];
}

bool isSpace(string sessionName[], int sessionTime[], string names[],
  int time[], int limit[],  int count)
{
  // Function checks to see if there are any spaces left on the course the
  // person is trying to attend
  bool check = true;

  // Loops used to determine whether the client can fit on the course and gives
  // feed back
  for (int i = 0; i < 30; i++)
  {
    if (sessionName[count] == names[i] && sessionTime[count] == time[i])
    {
      if (limit[i] <= 0)
      {
        check = false;
        cout << "There is no space left on this course. Please choose another." << endl;
      }
    }
  }

  return check;
}

int limitCounter(string sessionName[], int sessionTime[], string names[],
  int time[], int count)
{
  // Function used to get the array id's for the selected sessions
  int temp = 0;

  // Loops get all the id's to be able to edit the session limits
  // after the file has been saved
  for (int i = 0; i < 30; i++)
  {
    if (sessionName[count] == names[i] && sessionTime[count] == time[i])
    {
      temp = i;
    }
  }

  return temp;
}

void saveFile(Customer currentCustomer, string sessionName[],
  int sessionTime[])
{
  // This function is responsible for saving a clients file once they have
  // decided on all the sessions they wish to attend
  ofstream out;
  out.open(currentCustomer.name + ".txt");
  if (out.is_open())
  {
    // Used to store the clients name and package type
    out << "Client: " << currentCustomer.name << endl;
    out << "Package: " << currentCustomer.custPack << endl;
    // For loop to show all selected sessions
    for (int i = 0; i < currentCustomer.sessionLimit; i++)
    {
      out << sessionName[i] << "  \t";
      out << sessionTime[i] << endl;
    }
    out.close();
  }
  else
  {
    cout << "Could not open out\n";
  }
}

void saveMainFile(string names[], int time[], int limit[])
{
  // This function saves the main file after all edits have been made to it
  ofstream out;
  out.open("sessions.txt");
  if (out.is_open())
  {
    // These are the titles of the columns
    out << "Name\t\tTime\tLimit" << endl;
    // For loop to print out all the values associated with sessions
    for (int i = 0; i < 30; i++)
    {
      out << names[i] << "  \t";
      out << time[i] << "\t";
      out << limit[i] << endl;
    }
    out.close();
  }
  else
  {
    cout << "Could not open out\n";
  }
}

void timeSort(string sessionName[], int sessionTime[],
  Customer currentCustomer)
{
  // This function is used to sort out the selected sessions into time order
  // This variable is used as a temp int
  int iSwap = 0;
  // This is used as a temp string
  string wSwap = " ";
  // This is used to decide how many times the sort loop should run
  int count = 0;

  do
  {
    // Basic bubble sort algorithm to sort the times into order
    for (int i = 1; i < currentCustomer.sessionLimit; i++)
    {
      for (int j = 0; j < (currentCustomer.sessionLimit - i); j++)
      {
        if (sessionTime[j] > sessionTime[j + 1])
        {
          // This is swapping the times as well as the names so that they are
          // sorted together
          iSwap = sessionTime[j];
          wSwap = sessionName[j];
          sessionTime[j] = sessionTime[j + 1];
          sessionName[j] = sessionName[j + 1];
          sessionTime[j + 1] = iSwap;
          sessionName[j + 1] = wSwap;
        }
      }
      count++;
    }
  } while (count < 6);

  // This prints out the newly sorted session names and times
  for (int i = 0; i < currentCustomer.sessionLimit; i++)
  {
    cout << (i + 1) << ". ";
    cout << sessionName[i] << "\t";
    cout << sessionTime[i] << endl;
  }
  
}

int main()
{
  // Main function
  // Customer variable created to use as the current customers data point
  Customer currentCustomer;
  // Names array to hold session names
  string names[30];
  // Session names array to hold the selected session for the customer
  string sessionName[6];
  // Time array to hold the times of the sessions
  int time[30];
  // Limit array to hold the remaining spaces for the sessions
  int limit[30];
  // Session time holds the selected times the client wishes to
  // attend the sessions
  int sessionTime[6];
  // Session limit holds the limit id's for the main limit
  // array for ease of access
  int sessionLimit[6];
  // Basic int holder
  int count = 0;
  // Used for user ease of use
  int total = 0;
  // Boolean to dictate whether the secondary do loop should be exited 
  bool check = true;
  // Bool used to exit the main program
  bool exit = false;
  // Answer for accepting or rejecting the final clients plan
  char answer = ' ';

  // Read sessions file
  // Code here used to read the sessions file and compile all the data into
  // there own arrays
  ifstream sessions;
  sessions.open("sessions.txt");

  string temp;
  getline(sessions, temp);

  for (int i = 0; i < 30; i++)
  {
    sessions >> names[i];
    sessions >> time[i];
    sessions >> limit[i];
  }

  sessions.close();


  // Main code
  // Main do loop to continue to loop until the user sets the clients name
  // to exit
  do
  {
    cout << "Booking program initalise..." << endl;

    // Function to get clients name
    currentCustomer.name = getName();
    // If statement to check if the program should be exited or not
    if (currentCustomer.name == "exit")
    {
      exit = true;
    }
    else
    {
      // Function to get the customers package type
      currentCustomer.custPack = getPack();
      // This if statement assigns the appropriate data to the Customer 
      // variable depending on the package type
      if (currentCustomer.custPack == "g")
      {
        cout << "Gold package selected." << endl;
        currentCustomer.custPack = "Gold";
        currentCustomer.sessionLimit = 6;
      }
      else
      {
        cout << "Standard package selected." << endl;
        currentCustomer.custPack = "Standard";
        currentCustomer.sessionLimit = 4;
      }

      // Session section
      // User feed back to begin session section
      cout << "Please enter the sessions that the customer "; 
      cout << "wishes to attend." << endl;
      count = 0;
      total = currentCustomer.sessionLimit;

      // This if statement is used to automatically add the Welcome session
      // to a gold package members time table
      if (currentCustomer.custPack == "Gold")
      {
        sessionName[count] = "Welcome";
        sessionTime[count] = 9;
        count++;
        total--;
        cout << "\n";
        cout << "Welcome session at 9am has been automatically added to";
        cout << " your sessions list due to your gold member status." << endl;
      }

      // Main do loop to begin the session addion
      do
      {
        // Do loop to make sure the session info that is entered is allowed
        // into the main session name and time array
        do
        {
          check = true;
          // Displays all avalible sessions but removes duplicates
          dupRemover(names, sessionName);
          cout << "Input a sessions name below. Names are case ";
          cout << "sensitive." << endl;
          // Shows user how many sessions they have left to choose
          cout << total << " sessions left to choose." << endl;
          // This function makes sure that the user has inputted an
          // appropriate session
          sessionName[count] = validSession(sessionName, count, names,
            currentCustomer);

          // Displays all the selected sessions avalible times
          cout << "\nNow select a time you wish to attend the ";
          cout << "session." << endl;
          cout << "Enter 0 as the time to go back.\n" << endl;
          // Function displays all avalible times for the selected session
          timeDisplay(names, time, sessionName, count);
          // Function makes sure that the time entered is avalible for the
          // selected session and that the client isn't already attending
          // a session at the same time
          sessionTime[count] = validTime(sessionTime, count, sessionName,
            names, time);

          // Function used to check if there is any space remaining in the
          // session and time selected
          check = isSpace(sessionName, sessionTime, names, time, limit,
            count);

          // If this is assigned to 0 then it will not input the selected
          // session info and allow the user to re-enter that session
          if (sessionTime[count] == 0)
          {
            check = false;
          }
          
          // If there is no space this cancels out the session info
          // so that it is not added to the main array
          if (check == false)
          {
            sessionName[count] = "";
            sessionTime[count] = 0;
          }
        } while (check == false);

        // Shows which session at what time has been selected
        cout << sessionName[count] << " at " << sessionTime[count];
        cout << " has been selected." << endl;
        count++;
        total--;
      } while (count != currentCustomer.sessionLimit);
      
      // Used to tidy up the console for the user
      cout << string(100, '\n');
      // Displayed all the information for the customers plan
      cout << "Customer: " << currentCustomer.name << endl;
      cout << "Customer Package: " << currentCustomer.custPack << endl;
      // Function shows all the selected sessions in time order
      timeSort(sessionName, sessionTime, currentCustomer);
      // Allows client to accept or reject session plan
      cout << "Do you want to accept or reject this plan? (y|n)" << endl;

      // Used to get users answer
      cin >> answer;
      // If statement to decide if plan is saved or rejected
      if (answer == 'y')
      {
        // Function used to save the clients session file
        saveFile(currentCustomer, sessionName, sessionTime);
        // For loop used to update the limit array to remove a 
        // seat from the sessions that have been selected
        for (int i = 0; i < currentCustomer.sessionLimit; i++)
        {
          sessionLimit[i] = limitCounter(sessionName, sessionTime, names,
            time, i);
          limit[sessionLimit[i]] = limit[sessionLimit[i]] - 1;
        }
      }
      // Used to clear up the console
      cout << string(100, '\n');
    }

  } while (exit == false);

  // Function to save the main file with all changes
  saveMainFile(names, time, limit);
}