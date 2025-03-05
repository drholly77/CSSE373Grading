echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Check and copy 
rem Check in student's components\include\list folder for existence of List2.hpp 
rem Check in student's repo for existence of VS2022 project L3D and L3R
rem Copy grading test scripts to student's L3D and L3R folders
rem ******************
cls
echo starting copy
cd ..
for /d %%i in (csse373devenv202430-*) do (
   echo ===============================
   Find "name" %%i\README.md

   IF EXIST %%i\L6RG (
      rmdir /S /Q %%i\L6RG
   ) 

   echo copy L6RG project to student's repo folder
   xcopy L6-Grading\L6RG %%i\L6RG /I /E

  echo ===============================
  echo.
)
cd L6-Grading
echo "Done with 'Copy' phase"
pause
