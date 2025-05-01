@echo off

echo Fulldate:%date%
::Displays the complete system date in the default format

echo Year is : %date:~-4%
::Extracts the last four characters, which represent the year 

echo Month is : %date:~4,2%
::Extracts two characters starting at position 4, representing the month

echo Date is : %date:~7,2%
::Extracts two characters starting at position 7, representing the day of the month 

echo Day of the week is : %date:~0,3% 
::Extracts the first three characters, representing the day of the week

pause

