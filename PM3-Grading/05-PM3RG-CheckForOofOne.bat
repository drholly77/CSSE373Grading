echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Check UnlabeledUndirectedGraph3.hpp for calls to the PartitionableArray operations
rem that will make there Graph3 work in O(1) time
rem These operations are: numberOfInterestingEntries, giveIndexOfInterestingEntry
rem ******************
cls
echo starting build phase

cd ..
for /d %%i in (csse373devenv202430-*) do (

   echo ===============================
   Find "name" %%i\README.md

   IF NOT EXIST %%i\components\include\UnlabeledUndirectedGraph\UnlabeledUndirectedGraph3.hpp (
      echo UnlabeledUndirectedGraph3.hpp  not found
      echo %%i >> PM3-Grading\buildFailures.txt
      echo    UnlabeledUndirectedGraph2.hpp not found >> PM3-Grading\buildFailures.txt
   ) else (
  
      echo *********************************
      echo Below you should see multiple calls two PartitionableArray operations:
      echo     numberOfInterestingEntries
      echo     giveIndexOfInterestingEntry
      echo *********************************
      Find "InterestingEntr" %%i\components\include\UnlabeledUndirectedGraph\UnlabeledUndirectedGraph3.hpp
      pause
      cls
   )

  echo ===============================
  echo.
)
cd PM3-Grading
echo "Done with building' phase"
echo "Check file buildFailures.txt for list of projects that did not build"
pause
