echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Check and copy 
rem Check in student's repo for existence of VS2022 project PM2RG, delete if present
rem Copy PM2RG to student's repo
rem ******************
cls
echo starting copy
cd ..
for /d %%i in (csse373devenv202430-*) do (
   echo ===============================
   Find "name" %%i\README.md

   IF EXIST %%i\PM2RG (
      rmdir /S /Q %%i\PM2RG
   ) 

   echo copy PM2RG project to student's repo folder
   xcopy PM2-Grading\PM2RG %%i\PM2RG /I /E

  echo ===============================
  echo.
)
cd PM2-Grading
echo "Done with 'Copy' phase"
pause
