echo off
SETLOCAL EnableDelayedExpansion
rem ***************************************
rem This Windows batch does its work in the student's repo
rem Preconditions: The student's L1.exe must exist 
rem                in the student's repo in the folder:
rem                csse373devenv202430-*\L1\x64\Release
rem                where '*' (above) is a wildcard representing the specific
rem                student's repo name
rem This Windows batch script will run each student's
rem L1.exe (compiled in Release config) on each of the 
rem test scripts found in GradeScripts\ folder, sending the output
rem to a file named yourL1Output.txt 
rem storing it in the folder csse373devenv202430-*\L1\x64\Release\
rem ***************************************
IF EXIST FailureNoL1ExeFound.txt (
   del FailureNoL1ExeFound.txt
)
cd ..
for /d %%i in (csse373devenv202430-*) do (
   IF EXIST "%%i\L1\x64\Release\L1.exe" (
	cd %%i\L1\x64\Release
        echo Running Test Scripts > yourL1Output.txt
        for /r %%i in (GradeScripts\*.txt) do (
          echo run script: %%i
	  echo ### >> yourL1Output.txt
	  echo run script: %%i >> yourL1Output.txt
	  echo *** >> yourL1Output.txt
	  L1.exe g < %%i >> yourL1Output.txt
        )
        cd ..\..\..\..
   ) else (
       echo %%i\L1.exe non-existent >> L1-Grading\FailureNoL1ExeFound.txt
   )
)
cd L1-Grading
echo "Done with running script phase"
echo See list of build failures in L1-Grading\FailureNoL1ExeFound.txt
pause
 




