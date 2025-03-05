echo off
rem ******************
rem Runs your L2.dll test scripts
rem ******************

rem ******************
rem First check to see if the MS executable vstest.console.exe can be found
rem   if not echo a message and exit
rem   if yes then proceed to run test scripts
rem ******************
IF NOT EXIST "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" (
   echo This batch file needs to run: vstest.console.exe
   echo Use Windows File Explorer to find it on your machine
   echo Once you find it, note down its pathname
   echo Then edit this batch file by fixing the pathname to vstest.console.exe
   pause
   exit
)

rem ******************
rem Iterate through all student repos 
rem   if L2.dll exists in debug mode, then run it, save output to L2\Debug folder
rem ******************

cd ..
for /d %%i in (csse373devenv202430-*) do (
   echo Running L2.dll in repo: %%i
   Find "name" %%i\README.md

   IF EXIST %%i\L2\x64\Debug\L2.dll (
      rem Run Debug mode L2.dll
      echo run %%i's Debug L2.dll
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" %%i\L2\x64\Debug\L2.dll > %%i\L2\x64\Debug\yourOutput-Debug.txt
   ) else (
      echo Debug L2.dll not found
   )

echo ===============================
echo.
)
cd L2-Grading
echo "Done"
pause



