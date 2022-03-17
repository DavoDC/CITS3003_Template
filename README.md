# CITS3003_Template

## DESCRIPTION
- A template for CITS3003 students to help them organize their code files
- This repo demonstrates a good organisational system / folder structure
- The labs-examples folder is simply labs-examples.zip extracted
- The Lab folders (Lab1, Lab2.. etc) contain specially configured makefiles that refer back to the labs-examples folder

## BENEFITS
I highly recommend this folder structure as it will allow you to:
- Only have the code you are working on in your current Lab folder
- Abstract away from the lab-examples folder 
- Avoid dealing with so many levels of nested folders.


Text files with instructions have been added


## HOW TO USE:
If you using Mac, please see the note at the bottom first.
 `git clone https://github.com/DavoDC/CITS3003_Template`





How to Use the Folder Template for Labs:
Read the README (Mac users have some extra tasks!)
Use your file explorer to copy files from the LAB_DWL (lab-examples) files into the “Lab1”, “Lab2”... folders, then edit/compile/run them within there.
e.g. For Lab1:
Go into LAB_DWL -> CHAPTER 2 CODE -> Copy example1.cpp
Go back to your Lab1 folder ‘outside’ -> Paste example1.cpp there
Rename it to q1circle.cpp or mylab1.cpp etc.
Edit -> compile/make -> run  (your custom code file)
You can keep a Makefile in each folder (like I did), OR, you may try using a ‘master makefile’ and a symbolic link.
My Makefiles are configured specially to refer back to the ‘master’ LAB_DWL folder
You do not need to edit anything in the labs-examples/LAB_DWL folder. 
With this system, you’ll always have a copy of the originals:
So you don’t need to re-download the examples.
You are free to change the code however you want in your Lab folders.


 as a ZIP by pressing “DOWNLOAD ALL”

If you want to use this directly, it should work on Linux easily

### IMPORTANT NOTE FOR MAC USERS:
Code files in Lab1,2.. folders are for LINUX only
MAC USERS - Code files in Lab1,2.. folders will not work without changes
- The makefiles and code files in the Lab folders (e.g. Lab1 etc.) are based on files from the LINUX_VERSIONS folder.
- So you won’t be able to run these as-is, but the folder structure may still prove useful. 

EDIT THIS = 
You can make changes by finding Mac comments!
OLD See the Mac section for how the code is different.
I would advise just deleting the all the files in Lab1, Lab2 etc. , but keeping the folders only.

A Link back to my Guide:
<https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#> 


## TODO


add mac to makefile too

Make diamond.cpp the simple starting point

FIX makefile

ADD COMMENTS TO MAKE FILE

ADD COMMENTS TO SHADERS


add full comments to diamond.cpp!! - use matrixRot

Mention that comments have been added to diamond file, makefile and shaders!

Download and test on X230!

Add mac change comments to diamond.cpp

e.g. APPLE

explain every part of code, even vec 3 xyz stuff


mentioned this is a simple but fully commented code file

added documentation links

add mac to makefile too


add Mac stuff by using Mac versions folder!

add EXAMPLE FOLDER IMAGES 
