echo off

cd ..
for /d %%i in (csse373devenv202430-*) do (
   cls

   rem ----------------------------------------------------------------
   rem Check that List6.hpp exists, then open up in VSCode
   rem ----------------------------------------------------------------
   IF EXIST %%i\components\include\list\List6.hpp (
       rem Open in VS Code
       "C:\Users\hollings\AppData\Local\Programs\Microsoft VS Code\Code.exe" %%i\components\include\list\List6.hpp
   ) 

)

cd L4-Grading
echo "Done with visual inspection phase"
pause