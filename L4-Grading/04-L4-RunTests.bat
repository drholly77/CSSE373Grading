echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Runs student's L4R.dll and L4D.dll test scripts
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
   IF EXIST "%%i\L4D\L4D-Output.txt" (
      echo Deleting previous run's L4D-Output.txt
      del %%i\L4D\L4D-Output.txt
   )
   IF EXIST "%%i\L4R\L4R-Output.txt" (
      echo Deleting previous run's L4R-Output.txt
      del %%i\L4R\L4R-Output.txt
   )

   rem ******************
   rem First check to see L4R.dll and L4D.dll exist 
   rem ******************
   IF NOT EXIST "%%i\L4D\x64\Debug\L4D.dll" (
      set dllExists=false
   )   
   IF NOT EXIST "%%i\L4R\x64\Release\L4R.dll" (
      set dllExists=false
   )

   rem ******************
   rem If .dll's exist, then run both their scripts
   rem ******************
   IF !dllExists!==true (
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" %%i\L4D\x64\Debug\L4D.dll > %%i\L4D\L4D-Output.txt
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" %%i\L4R\x64\Release\L4R.dll > %%i\L4R\L4R-Output.txt

      rem ******************
      rem If .dll's exist, then run both their scripts
      rem ******************

      type %%i\L4D\L4D-Output.txt
      echo *********************************
      echo 35 Test L4D scripts should have passed
      echo *********************************
      echo %%i
      pause

      type %%i\L4R\L4R-Output.txt
      echo *********************************
      echo 18 Test L4R scripts should have passed
      echo *********************************
      echo %%i
      pause
   )
   echo.
   echo ===============================
   echo.
)
cd L4-Grading
echo "Done with running test scripts phase"
pause



