echo off
rem ******************
rem Copy dataImage.dat to student repos
rem ******************
cls
echo starting 'data file Copy' phase
cd ..
for /d %%i in (csse373devenv202430-*) do (
   echo copying to %%i\PM1
   copy /Y PM1-Grading\dataSixForSpell.dat  %%i\PM1
   copy /Y PM1-Grading\dictionaryJustEWords.dat  %%i\PM1
   echo .
)
cd PM1-Grading
echo "Done with 'data file Copy' phase"
pause
