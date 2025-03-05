echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Check and copy 
rem Check in student's components\include\list folder for existence of List6.hpp 
rem Check in student's repo for existence of VS2022 project E1P3D 
rem Copy grading test scripts to student's E1P3D folder
rem ******************
cls
echo starting check and copy
IF EXIST missingFiles.txt (
   rem delete record of previous build failures
   del missingFiles.txt 
)
cd ..
for /d %%i in (csse373devenv202430-*) do (
   set earnZero=false
   set List6Exists=true
   set E1P3DProjExists=true
   echo ===============================
   Find "name" %%i\README.md

   IF NOT EXIST %%i\components\include\list\List6.hpp (
      set List6Exists=false
      set earnZero=true

      echo %%i >> E1P3D-Grading\missingFiles.txt
      echo    Missing List6.hpp >> E1P3D-Grading\missingFiles.txt
   ) 

   IF NOT EXIST %%i\E1P3D ( 
      set E1P3DProjExists=false
      set earnZero=true

      echo %%i >> E1P3D-Grading\missingFiles.txt
      echo    Missing E1P3D project >> E1P3D-Grading\missingFiles.txt
   )

   IF !earnZero!==false (
      echo copy test scripts to student's E1P3D folder/project
      copy /Y E1P3D-Grading\E1P3D.cpp %%i\E1P3D
   )

  echo ===============================
  echo.
)
cd E1P3D-Grading
echo "Done with 'Check and Copy' phase"
pause
