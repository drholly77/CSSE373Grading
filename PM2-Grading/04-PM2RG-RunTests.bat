echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Runs student's PM2RG.dll test scripts
rem ******************

cd ..
for /d %%i in (csse373devenv202430-*) do (
   cls
   set dllExists=true
   echo ===============================
   Find "name" %%i\README.md

   rem ******************
   rem Delete test output from previous runs 
   rem ******************

   IF EXIST "%%i\PM2RG\PM2RG-Output.txt" (
      echo Deleting previous run's PM2RG-Output.txt
      del %%i\PM2RG\PM2RG-Output.txt
   )

   rem ******************
   rem First check to see PM2RG.dll
   rem ******************

   IF NOT EXIST "%%i\PM2RG\x64\Release\PM2RG.dll" (
      set dllExists=false
   )

   rem ******************
   rem If .dll's exist, then run both their scripts
   rem ******************
   IF !dllExists!==true (
     "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" %%i\PM2RG\x64\Release\PM2RG.dll > %%i\PM2RG\PM2RG-Output.txt

      rem ******************
      rem If .dll's exist, then run both their scripts
      rem ******************

      type %%i\PM2RG\PM2RG-Output.txt
      echo *********************************
      echo 27 Test PM2RG scripts should have passed
      echo *********************************
      echo %%i
      pause
   )
   echo.
   echo ===============================
   echo.
)
cd PM2-Grading
echo "Done with running test scripts phase"
pause



