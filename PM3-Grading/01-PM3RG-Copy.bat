echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Check and copy 
rem Check in student's repo for existence of VS2022 project PM3RG, delete if present
rem Copy PM3RG to student's repo
rem ******************
cls
echo starting copy
cd ..
for /d %%i in (csse373devenv202430-*) do (
   echo ===============================
   Find "name" %%i\README.md

   IF EXIST %%i\PM3RG (
      rmdir /S /Q %%i\PM3RG
   ) 

   echo copy PM3RG project to student's repo folder
   xcopy PM3-Grading\PM3RG %%i\PM3RG /I /E

  echo ===============================
  echo.
)
cd PM3-Grading
echo "Done with 'Copy' phase"
pause
