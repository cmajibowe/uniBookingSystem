#University Booking System

This is a program I created during my first year of university. I was used for an assessment and submitted 12/01/17. The breif for the project was as follows.

You should create a C++ program that performs the task described below. Your program code should adhere to the code policy which can be found on Blackboard. Your code should also be safe, reliable, easy to maintain and well documented. The program should use standard C++ which can be compiled using Visual Studio and/or G++.

The program
The program is a booking system that allows users to books spaces at conference sessions. There is a text file called “sessions.txt” which contains a list of available sessions, the time of the session and the number of spaces remaining. An example would be:

	Welcome	9	42
Metallurgy	10	12
	Linguistics	10	6
	Robotics	11	0	
Robotics	12	5	
	Psychology	13	3
	Tradecraft	11	5

In the example, a session on Metallurgy will happen at 10am, and there are 12 places remaining. Times use the 24 hour clock (so 13 means 1pm). Note that some sessions have no places remaining.
You may assume:
•	the session names are always a single word
•	all sessions last for one hour
•	the earliest session is 9am and the last session starts at 4pm
•	there will be exactly 30 available sessions.

An example file is available on Blackboard, named “sessionlist.txt”.

People attending the conference can choose either a “standard” package or a “gold” package. People with a standard package must choose exactly four sessions to attend. They cannot attend the session called “Welcome” at 9am.
People with a gold package must choose exactly six sessions to attend. This must include the session called “Welcome” at 9am.
A person cannot attend two sessions that are held at the same time.
A person cannot attend two sessions with the same name.
A person cannot attend a session if there is no space left.

Your program will be used by a booking clerk who is talking to customers on the phone. The clerk will deal with several customers, one after the other.

It should do the following:

When the program starts, it will read the file containing the list of sessions. The information should be stored into three lists – a list of session names, a list of times and a list of how many spaces are left.

The program will then allow the clerk to deal with a customer. First, the clerk will enter the customer’s name, and indicate whether the customer has a “standard” or “gold” package. It is up to you how the clerk inputs this. Make it easy to use, and make it clear which option the clerk has chosen.
Next the program will give the clerk a choice of sessions. Again, it is up to you how to do this. Perhaps the clerk enters the name and the time. Or maybe each session has a number, which the clerk can enter. Either way, the clerk should be able to see which sessions are available.

If the clerk chooses a session that is not possible (such as booking two sessions at the same time), the system should let the clerk know this is not possible, and why.

Once the clerk has selected the right number of bookings, the program will display the final list of sessions, in order of time. The clerk can then accept or reject this plan. If the clerk rejects the plan, no changes are made, and the program returns to the point where the clerk enters a customer name.

If the clerk accepts the plan, the program will do three things:
1.	The program will save the details of the booking into a text file. This will be the customer’s ticket. It contains the customer’s name and the list of sessions (in time order). The file name will be the customer’s surname. For example, a customer named Fred Bloggs will get a file named bloggs.txt.
2.	The program will update the places left on each session.
3.	The program will then allow the clerk to deal with another customer.

The clerk can exit the program by entering “exit” for the customer name. (Or by some other method, if you prefer.) When this happens, the list of sessions should be written back into the sessionlist.txt file. (This is because the places available will have changed due to the bookings that have been made.) 
