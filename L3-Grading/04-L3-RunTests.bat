echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Runs student's L3RG.dll test scripts
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
   IF EXIST "%%i\L3D\L3D-Output.txt" (
      echo Deleting previous run's L3D-Output.txt
      del %%i\L3D\L3D-Output.txt
   )
   IF EXIST "%%i\L3R\L3R-Output.txt" (
      echo Deleting previous run's L3R-Output.txt
      del %%i\L3R\L3R-Output.txt
   )

   rem ******************
   rem First check to see L3R.dll and L3D.dll exist 
   rem ******************
   IF NOT EXIST "%%i\L3D\x64\Debug\L3D.dll" (
      set dllExists=false
   )   
   IF NOT EXIST "%%i\L3R\x64\Release\L3R.dll" (
      set dllExists=false
   )

   rem ******************
   rem If .dll's exist, then run both their scripts
   rem ******************
   IF !dllExists!==true (
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" %%i\L3D\x64\Debug\L3D.dll > %%i\L3D\L3D-Output.txt
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" %%i\L3R\x64\Release\L3R.dll > %%i\L3R\L3R-Output.txt

      rem ******************
      rem If .dll's exist, then run both their scripts
      rem ******************

      type %%i\L3D\L3D-Output.txt
      echo *********************************
      echo 34 Test L3D scripts should have passed
      echo *********************************
      echo %%i
      pause

      type %%i\L3R\L3R-Output.txt
      echo *********************************
      echo 18 Test L3R scripts should have passed
      echo *********************************
      echo %%i
      pause
   )
   echo.
   echo ===============================
   echo.
)
cd L3-Grading
echo "Done with running test scripts phase"
pause



