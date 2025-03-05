echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Build PM1 project
rem ******************
cls
echo Starting with build phase
IF EXIST BuildFailures.txt (
   del BuildFailures.txt
)
cd ..
for /d %%i in (csse373devenv202430-*) do (
   set earnZero=false
   echo ===============================
   Find "name" %%i\README.md

   rem ----------------------------------------------------------------
   rem Build the PM1
   rem ----------------------------------------------------------------

   IF EXIST %%i\PM1\ (
      echo Release mode compiling
      cd %%i\PM1
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" PM1.sln /ProjectConfig "Release|x64" /Project PM1  /Build "Release|x64" /Out PM1-BuildOutput.txt
      cd ..\..
   ) else (
      echo PM1 folder doesn't exist
   )

   rem ----------------------------------------------------------------
   rem Check to see that the PM1 built and generated a .dll
   rem ----------------------------------------------------------------

   IF NOT EXIST "%%i\PM1\x64\Release\PM1.exe" (
      set earnZero=true
      echo FAILED build in Release Mode
      echo %%i\PM1 project failed to build > PM1-Grading\BuildFailures.txt
   ) else (
      echo SUCCESSFUL build for PM1
   )

  echo.
)
cd PM1-Grading
echo "Done with building phase"
echo "Check file buildFailures.txt for list of projects that did not build"
pause
