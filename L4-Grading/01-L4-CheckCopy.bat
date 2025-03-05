echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Check and copy 
rem Check in student's components\include\list folder for existence of List3.hpp 
rem Check in student's repo for existence of VS2022 project L4D and L4R
rem Copy grading test scripts to student's L4D and L4R folders
rem ******************
cls
echo starting check and copy
cd ..
for /d %%i in (csse373devenv202430-*) do (
   set earnZero=false
   set List3Exists=true
   set L4DProjExists=true
   set L4RProjExists=true
   echo ===============================
   Find "name" %%i\README.md

   IF NOT EXIST %%i\components\include\list\List3.hpp (
      set List3Exists=false
      set earnZero=true
      echo List3.hpp not found
   ) 

   IF NOT EXIST %%i\L4D ( 
      set L4DProjExists=false
      set earnZero=true
      echo L4D project not found
   )
   IF NOT EXIST %%i\L4R ( 
      set L4RProjExists=false
      set earnZero=true
      echo L4R project not found
   )

   IF !earnZero!==true (
      echo Enter zero for grade into Moodle
   ) else (
      echo copy test scripts to student's L4D and L4R folders/projects
      copy /Y L4-Grading\L4D.cpp %%i\L4D
      copy /Y L4-Grading\L4R.cpp %%i\L4R
   )

  echo ===============================
  echo.
)
cd L4-Grading
echo "Done with 'Check and Copy' phase"
pause
