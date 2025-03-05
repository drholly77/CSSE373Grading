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
   echo Running FC in repo: %%i
   Find "name" %%i\README.md
   IF EXIST %%i\L2\x64\Debug\yourOutput-Debug.txt (
      rem FC compare Debug version of solution against students output
      FC L2-Grading\solutionOutput-Debug.txt %%i\L2\x64\Debug\yourOutput-Debug.txt > %%i\L2\x64\Debug\FCdiffs-Debug.txt
   ) 

   echo ===============================
   echo.
)
cd L2-Grading
echo "Done"
pause



