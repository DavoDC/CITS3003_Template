# CITS3003_Template

## Description
- A template for CITS3003 students to help them organize their code files
- This repo demonstrates a good organisational system / folder structure
- The `labs-examples` folder is simply `labs-examples.zip` extracted
- The Lab folders (Lab1, Lab2.. etc) contain specially configured makefiles that refer back to the labs-examples folder
  - The same makefile is used for Lab1, 2 and 3
  - Lab4 and Lab5 will need a slightly different makefile, because the folder is one level lower

## Benefits
I highly recommend this folder structure as it will allow you to:
- Only have the code you are working on in your current Lab folder.
- Abstract away from the lab-examples folder. 
- Avoid dealing with so many levels of nested folders.
- Less code duplication (e.g. fshader in Lab 4 and 5)

## Initial Setup Instructions
1. Open your terminal to where you want your CITS3003 folder to be (See [here for advice](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.42yr22ji4ygg)).
2. Copy, paste and execute the command: `git clone https://github.com/DavoDC/CITS3003_Template` (You only have to do this once).
3. This repo will now be in a folder called `CITS3003_Template` in the current directory.
4. Rename that folder to `CITS3003`.

## Lab Usage Instructions
1. Open your CITS3003 folder in the file manager GUI.
2. Enter the `labs-examples` folder and copy the needed base files for the Lab you are on (e.g. For Lab1 on Linux, go into `CITS3003\labs-examples\CHAPTER02_CODE\LINUX_VERSIONS` and copy example1.cpp).
3. Paste them into the relevant Lab folder (e.g. Paste `example1.cpp` into `CITS3003\Lab1`).
4. Rename/edit/compile/execute your code within that Lab folder (e.g. Rename `example1.cpp` so you get: `CITS3003\Lab1\q1circle.cpp`).

## General Usage Instructions
- There are text files throughout the folder structure to guide you.
- I have included only one Makefile to make editing it for me easier - you'll have to copy it to where you need it
- You can copy this Makefile in each folder (like I did), OR, you may try using a ‘master makefile’ and a symbolic link.
- You do not need to edit anything in the `labs-examples` folder. 
- With this system, you’ll always have a copy of the originals:
 - So you don’t need to re-download the examples.
 - You are free to change the code however you want in your Lab folders.





### IMPORTANT NOTE FOR MAC USERS:
Folder structure will work fine for you

BUT makefile, shaders and code will required a bit of editing before they can work

If you want to use this directly, it should work on Linux easily
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
