echo off

cd ..
for /d %%i in (csse373devenv202430-*) do (
   cls

   rem ----------------------------------------------------------------
   rem Check that driver.cpp exists, then open up in VSCode for visual inspection
   rem ----------------------------------------------------------------
   IF EXIST %%i\PM1\driver.cpp (
       rem Open in VS Code
       "C:\Users\hollings\AppData\Local\Programs\Microsoft VS Code\Code.exe" %%i\PM1\driver.cpp
       pause
   ) 

)

cd PM1-Grading
echo "Done with visual inspection phase"
pause