echo off
rem ***************************************	
rem This Windows batch does its work in the student's repo
rem Preconditions: The files solutionOutput.txt and yourL1Output.txt must exist 
rem                in the student's repo in the folder:
rem                csse373devenv202430-*\L1\x64\Release
rem                where '*' (above) is a wildcard representing the specific
rem                student's repo name

rem This Windows batch script will run FC (File Compare)
rem FC solutionOutput.txt yourL1Output.txt
rem The output FC will be sent to: FC-Differences.txt
rem storing it in the folder csse373devenv202430-*\L1\x64\Release\
rem ***************************************

IF EXIST FailureFCNotRunNoL1Exe.txt (
   del FailureFCNotRunNoL1Exe.txt
)
cd ..
for /d %%i in (csse373devenv202430-*) do (
   IF EXIST "%%i\L1\x64\Release\L1.exe" (
        Find "name" %%i\README.md
	cd %%i\L1\x64\Release
        echo Running FC solutionOutput.txt yourL1Output.txt
        FC /N solutionOutput.txt yourL1Output.txt > FC-Differences.txt
        echo Running Test Scripts > yourL1Output.txt
        cd ..\..\..\..
   ) else (
       echo %%i\L1.exe non-existent, so no yourL1Output.txt file exists >> L1-Grading\FailureFCNotRunNoL1Exe.txt
   )
)
cd L1-Grading
echo "Done with running FC phase"
echo See list of build failures in L1-Grading\FailureFCNotRunNoL1Exe.txt
pause





