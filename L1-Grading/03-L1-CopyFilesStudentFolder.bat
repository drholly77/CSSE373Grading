echo off
rem ******************
rem Copy Gradescript Files to student repos
rem ******************
cls
echo starting 'Gradescript Files Copy' phase
cd ..
for /d %%i in (csse373devenv202430-*) do (
   echo copying to %%i
   mkdir %%i\L1\x64\Release\GradeScripts
   copy /Y L1-Grading\GradeScripts\*.*  %%i\L1\x64\Release\GradeScripts
   copy L1-Grading\L1Sol.exe %%i\L1\x64\Release
   echo .
)
cd L1-Grading
echo "Done with 'Gradescript Files Copy' phase"
pause
