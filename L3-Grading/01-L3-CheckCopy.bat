echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Check and copy 
rem Check in student's components\include\list folder for existence of List2.hpp 
rem Check in student's repo for existence of VS2022 project L3D and L3R
rem Copy grading test scripts to student's L3D and L3R folders
rem ******************
cls
echo starting check and copy
cd ..
for /d %%i in (csse373devenv202430-*) do (
   set earnZero=false
   set list2Exists=true
   set l3dProjExists=true
   set l3rProjExists=true
   echo ===============================
   Find "name" %%i\README.md

   IF NOT EXIST %%i\components\include\list\List2.hpp (
      set list2Exists=false
      set earnZero=true
   ) 

   IF NOT EXIST %%i\L3D ( 
      set l3dProjExists=false
      set earnZero=true
   )
   IF NOT EXIST %%i\L3R ( 
      set l3rProjExists=false
      set earnZero=true
   )

   IF !earnZero!==true (
      echo Enter zero for grade into Moodle
      pause
   ) else (
      echo copy test scripts to student's L3D and L3R folders/projects
      copy /Y L3-Grading\L3D.cpp %%i\L3D
      copy /Y L3-Grading\L3R.cpp %%i\L3R
      rem Also copy IntegerList.h which creates instance of List2.hpp
      rem A later lab might already be making changes to IntegerList.h
      copy /Y L3-Grading\IntegerList.h %%i\L3D
      copy /Y L3-Grading\IntegerList.h %%i\L3R
   )

  echo ===============================
  echo.
)
cd L3-Grading
echo "Done with 'Check and Copy' phase"
pause
