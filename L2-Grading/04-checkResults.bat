echo off
rem **************
rem Uses FC to compare test script outputs
rem Compares outputs generated in Debug configuration
rem **************

rem ******************
rem Iterate through all student repos 
rem   if yourOutput-Debug.txt FC compare it against solution version
rem ******************

cd ..
for /d %%i in (csse373devenv202430-*) do (
   cls
   echo grading repo: %%i
   Find "name" %%i\README.md
   IF EXIST %%i\L2\x64\Debug\FCdiffs-Debug.txt (
      rem Find lines with total tests passed
      FIND "Passed:" %%i\L2\x64\Debug\FCdiffs-Debug.txt
   ) else (
      IF EXIST %%i\L2\x64\Debug\L2.dll (
         echo L2 failed tests in Debug mode
      ) else (
         echo L2 failed to build in Debug mode
      )
   )

   echo ====================================================
   echo The 'Passed:' lines should agree in number
   echo Record this student grade now in Moodle
   echo ====================================================
   pause
)
cd L2-Grading
echo "Done"
pause



