@echo off

set /a curr_year = %date:~-4%
::set: Creates or modifies a variable.
::/a: Enables arithmetic operations.
::%date:~-4% is used for Extract the last four digits from the %date% system variable 
 
set /p birth_year = Enter your birth year: 
:: /p: For get the user input.

set /a age = %curr_year% - %birth_year%

echo Your age is: %age% years
::Displays the calculated age.

pause