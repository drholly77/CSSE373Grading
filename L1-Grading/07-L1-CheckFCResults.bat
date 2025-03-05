echo off
rem ----------------------------------------------------------------
rem Visual inspection for FC "No Differences Found"
rem ----------------------------------------------------------------
cd ..
for /d %%i in (csse373devenv202430-*) do (
   cls

   rem ----------------------------------------------------------------
   rem Check that List3.hpp exists, then open up in VSCode
   rem ----------------------------------------------------------------
   IF EXIST %%i\L1\x64\Release\FC-Differences.txt (
       rem Open in VS Code
       "C:\Users\hollings\AppData\Local\Programs\Microsoft VS Code\Code.exe" %%i\L1\x64\Release\FC-Differences.txt
   ) 

)

cd L1-Grading
echo "Done with visual inspection phase"
pause