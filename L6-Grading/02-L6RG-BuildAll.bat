echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Build L6RG project
rem ******************
cls
echo starting build phase

IF EXIST buildFailures.txt (
   rem delete record of previous build failures
   del buildFailures.txt
)
cd ..
for /d %%i in (csse373devenv202430-*) do (

   echo ===============================
   Find "name" %%i\README.md

   IF NOT EXIST %%i\components\include\Queue\InjectCapability1.hpp (
      echo InjectCapability1.hpp  not found
      echo %%i >> L6-Grading\buildFailures.txt
      echo    InjectCapability1.hpp not found >> L6-Grading\buildFailures.txt
   ) 
   IF NOT EXIST %%i\components\include\Queue\FindLocOfXCapability1.hpp (
      echo FindLocOfXCapability1.hpp  not found
      echo %%i >> L6-Grading\buildFailures.txt
      echo    FindLocOfXCapability1.hpp not found >> L6-Grading\buildFailures.txt
   ) 
   IF NOT EXIST %%i\components\include\Queue\QueueEqCapability1.hpp (
      echo QueueEqCapability1.hpp  not found
      echo %%i >> L6-Grading\buildFailures.txt
      echo    QueueEqCapability1.hpp not found >> L6-Grading\buildFailures.txt
   )


   rem ----------------------------------------------------------------
   rem Build L6RG project 
   rem ----------------------------------------------------------------

   echo Release mode compiling
   cd %%i\L6RG 
   "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" L6RG.sln /ProjectConfig "Release|x64" /Project L6RG  /Build "Release|x64" /Out L6RG-BuildOutput.txt
   cd ..\..


   rem ----------------------------------------------------------------
   rem Check to see L6RG built and generated a .dll
   rem ----------------------------------------------------------------

   IF NOT EXIST "%%i\L6RG\x64\Release\L6RG.dll" (
      echo L6RG FAILED build in Release Mode

      echo %%i >> L6-Grading\buildFailures.txt
      echo    FAILED build in Release Mode >> L6-Grading\buildFailures.txt
   ) 


  echo ===============================
  echo.
)
cd L6-Grading
echo "Done with building' phase"
echo "Check file buildFailures.txt for list of projects that did not build"
pause
