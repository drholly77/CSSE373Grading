echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Runs student's L6RG.dll test scripts
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

   IF EXIST "%%i\L6RG\L6RG-Output.txt" (
      echo Deleting previous run's L6RG-Output.txt
      del %%i\L6RG\L6RG-Output.txt
   )

   rem ******************
   rem First check to see L4R.dll and L4D.dll exist 
   rem ******************

   IF NOT EXIST "%%i\L6RG\x64\Release\L6RG.dll" (
      set dllExists=false
   )

   rem ******************
   rem If .dll's exist, then run both their scripts
   rem ******************
   IF !dllExists!==true (
     "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" %%i\L6RG\x64\Release\L6RG.dll > %%i\L6RG\L6RG-Output.txt

      rem ******************
      rem If .dll's exist, then run both their scripts
      rem ******************

      type %%i\L6RG\L6RG-Output.txt
      echo *********************************
      echo 12 Test L6RG scripts should have passed
      echo *********************************
      echo %%i
      pause
   )
   echo.
   echo ===============================
   echo.
)
cd L6-Grading
echo "Done with running test scripts phase"
pause



