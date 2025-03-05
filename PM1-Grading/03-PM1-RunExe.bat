echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Runs student's PM1.exe 
rem ******************

cd ..
for /d %%i in (csse373devenv202430-*) do (
   cls
   set exeExists=true
   echo ===============================
   Find "name" %%i\README.md

   rem ******************
   rem Delete PM1-Output.txt from previous runs 
   rem ******************

   IF EXIST "%%i\PM1\PM1-Output.txt" (
      echo Deleting previous run's PM1-Output.txt
      del %%i\PM1\PM1-Output.txt
   )

   rem ******************
   rem First check to see PM1.exe exist 
   rem ******************
   IF NOT EXIST "%%i\PM1\x64\Release\PM1.exe" (
      set exeExists=false
   )

   rem ******************
   rem If .exe's exist, then run both their scripts
   rem ******************
   IF !exeExists!==true (
      cd %%i\PM1
      rem Run student's .exe
      x64\Release\PM1.exe dictionaryJustEWords.dat dataSixForSpell.dat 4 > PM1-Output.txt

      IF NOT EXIST PM1-Output.txt (
         echo Error: PM1.exe failed to run correctly
      ) else ( 
         type PM1-Output.txt
         echo *********************************
         echo Should see these 11 words: "elod","epop","eadi","edea","edna","edit","eole","erer","ecol","ecod","ecad"
         echo *********************************
      )
      echo %%i
      pause
      cd ..\..
   )
   echo.
   echo ===============================
   echo.
)
cd PM1-Grading
echo "Done with running .exe phase"
pause



