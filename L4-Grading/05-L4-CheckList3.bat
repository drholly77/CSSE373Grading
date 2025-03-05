echo off
rem ----------------------------------------------------------------
rem Visual inspection for violation of "Important Restrictions"
rem In particular: 
rem    no cross calling
rem    no making copies of variables of type T
rem    leveraging the full capabilities of Queue 
rem ----------------------------------------------------------------
cd ..
for /d %%i in (csse373devenv202430-*) do (
   cls

   rem ----------------------------------------------------------------
   rem Check that List3.hpp exists, then open up in VSCode
   rem ----------------------------------------------------------------
   IF EXIST %%i\components\include\list\List3.hpp (
       rem Open in VS Code
       "C:\Users\hollings\AppData\Local\Programs\Microsoft VS Code\Code.exe" %%i\components\include\list\List3.hpp
   ) 

)

cd L4-Grading
echo "Done with visual inspection phase"
pause