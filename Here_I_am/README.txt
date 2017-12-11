Here I am

The Use Case that has been developed is Set Reminder.
The software starts with a basic Login Page as the reminder database is stored for each user differently.
A list of username ("users.txt") was already made for testing the software (as the use case concerned did not include Account Management, registration is ignored here).
User can only login if the username and password entered belongs to the "users.txt".
Once the user is logged in, the profile frame is opened with his username as the heading.
The only thing contained in his profile is Set Reminder.
The New Reminder contains all the functional properties of the reminder (example name,description,volume etc).
The Select Reminder contains a table of all the reminders of the user.
Any row of the table can be selected to modify the reminder (the name doesnt change because of obvious reasons).
At the given time in the reminder a new frame appears containing the reminder info.

Sl.No.     Input               Expected Output        Actual Ouput       Testing Okay
1          invalid username    ask to login again     ask to login again OK
2          invalid name        ask to enter again     ask to enter again OK
           of reminder  
3          reading empty       show message           show message       OK
	   reminder list
4          time and date       show error             reminder popup     Not OK
	   before current                             comes right next 
           time entered