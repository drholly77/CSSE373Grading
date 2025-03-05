echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Runs student's E1P3D.dll test scripts
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
   IF EXIST "%%i\E1P3D\E1P3D-Output.txt" (
      echo Deleting previous run's E1P3D-Output.txt
      del %%i\E1P3D\E1P3D-Output.txt
   )

   rem ******************
   rem First check to see that E1P3D.dll exists
   rem ******************
   IF NOT EXIST "%%i\E1P3D\x64\Debug\E1P3D.dll" (
      set dllExists=false
   )   

   rem ******************
   rem If the .dll's exists, then run the scripts
   rem ******************
   IF !dllExists!==true (
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" %%i\E1P3D\x64\Debug\E1P3D.dll > %%i\E1P3D\E1P3D-Output.txt
 
      rem ******************
      rem If .dll exists, then run the scripts
      rem ******************

      type %%i\E1P3D\E1P3D-Output.txt
      echo *********************************
      echo 36 Test E1P3D scripts should have passed
      echo *********************************
      echo %%i
      pause
   )
   echo.
   echo ===============================
   echo.
)
cd E1P3D-Grading
echo "Done with running test scripts phase"
pause



