echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Build L1 project in Debug configuration
rem ******************
cls
echo Starting with build phase
IF EXIST FailureDebugBuild.txt (
   del FailureDebugBuild.txt
)
cd ..
for /d %%i in (csse373devenv202430-*) do (
   set earnZero=false
   echo ===============================
   Find "name" %%i\README.md

   rem ----------------------------------------------------------------
   rem Check that L1 folder exists 
   rem If it doesn't exist, then do not compile, student earns zero
   rem ----------------------------------------------------------------
   IF NOT EXIST %%i\L1\ (
      set earnZero=true
   ) 

   rem ----------------------------------------------------------------
   rem Build the L1
   rem ----------------------------------------------------------------
   IF !earnZero!==false (
      echo Debug mode compiling
      cd %%i\L1
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" L1.sln /ProjectConfig "Debug|x64" /Project L1  /Build "Debug|x64" /Out L1-BuildV2Output.txt
      cd ..\..
   )

   rem ----------------------------------------------------------------
   rem Check to see that the L1 built and generated a .exe
   rem ----------------------------------------------------------------

   IF NOT EXIST "%%i\L1\x64\Debug\L1.exe" (
      set earnZero=true
      echo FAILED build L1 in Release Mode
      echo %%i\L1 project failed to build >> L1-Grading\FailureDebugBuild.txt 
   ) 

   rem ----------------------------------------------------------------
   rem If .exe does not exist, then student earns zero
   rem ----------------------------------------------------------------
   IF !earnZero!==true (
      echo Enter zero for grade into Moodle
    ) else (
      echo SUCCESSFUL build for L1
   )
  echo.
)
cd L1-Grading
echo "Done with building phase"
echo See list of build failures in L1-Grading\FailureDebugBuild.txt
pause
