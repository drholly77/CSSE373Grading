echo off
rem
rem This is a minimal check of submission for using 
rem assignment statement only when implementing List2's operator =
rem
cd ..
for /d %%i in (csse373devenv202430-*) do (
   cls

   rem ----------------------------------------------------------------
   rem Check that List2.hpp exists, then open up in VSCode
   rem ----------------------------------------------------------------
   IF EXIST %%i\components\include\list\List2.hpp (
       Find "name" %%i\README.md
       Find " = rhs" %%i\components\include\list\List2.hpp 
       echo.
       echo VERIFY: 2 lines above with assignment 
       pause
   ) 

)

cd L3-Grading
echo "Done with visual inspection phase"
pause