echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Build PM2RG project
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

   IF NOT EXIST %%i\components\include\UnlabeledUndirectedGraph\UnlabeledUndirectedGraph2.hpp (
      echo UnlabeledUndirectedGraph2.hpp  not found
      echo %%i >> PM2-Grading\buildFailures.txt
      echo    UnlabeledUndirectedGraph2.hpp not found >> PM2-Grading\buildFailures.txt
   ) 

   rem ----------------------------------------------------------------
   rem Build PM2RG project 
   rem ----------------------------------------------------------------

   echo Release mode compiling
   cd %%i\PM2RG 
   "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" PM2RG.sln /ProjectConfig "Release|x64" /Project PM2RG  /Build "Release|x64" /Out PM2RG-BuildOutput.txt
   cd ..\..


   rem ----------------------------------------------------------------
   rem Check to see PM2RG built and generated a .dll
   rem ----------------------------------------------------------------

   IF NOT EXIST "%%i\PM2RG\x64\Release\PM2RG.dll" (
      echo PM2RG FAILED build in Release Mode

      echo %%i >> PM2-Grading\buildFailures.txt
      echo    FAILED build in Release Mode >> PM2-Grading\buildFailures.txt
   ) 


  echo ===============================
  echo.
)
cd PM2-Grading
echo "Done with building' phase"
echo "Check file buildFailures.txt for list of projects that did not build"
pause
