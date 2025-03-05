Below is an explanation of all the files in the folder

// Subfolder
GradeScripts - containing all the test scripts used to test student's L1 submission

// .bat files in this folder
01-L1-BuildRelease.bat - In student's repo, builds students L1 submission in Release configuration
02-L1-BuildDebug.bat - In student's repo, builds students L1 submission in Release configuration
03-L1-CopyFilesStudentFolder.bat - copies GradeScripts folder and L1Sol.exe to student's repo
04-L1-runScriptsUsingL1Sol.bat - Runs L1Sol.exe on all test scripts found in GradeScripts folder
05-L1-runScriptsUsingL1.bat - Runs student's L1.exe on all test scripts found in GradeScripts folder
06-L1-runFC.bat - Runs FC to file compare output of L1.exe against L1Sol.exe
07-L1-CheckFCResults.bat - Displays in VS Code one student at a time the results of the FC

// .exe files in this folder
L1Sol.exe - solution .exe

// .txt files in this folder
FailureReleaseBuild.txt - 01-L1-BuildRelease.bat creates this file, lists all repos where L1 failed to build in Release configuration
FailureDebugBuild.txt - 02-L1-BuildDebug.bat creates this file, lists all repos where L1 failed to build in Debug configuration
FailureNoL1ExeFound.txt - 05-L1-runScriptsUsingL1.bat creates this file, lists repos where L1.exe does not exist
FailureFCNotRunNoL1Exe.txt	 - 06-L1-runFC.bat creates this file, lists repos where L1.exe does not exist
	