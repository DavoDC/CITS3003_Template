# CITS3003_Template

## Description
- This repo demonstrates a good organisational system / folder structure for doing the labs.
- The `labs-examples` folder is simply `labs-examples.zip` extracted
- The Lab folders (Lab1, Lab2.. etc) contain specially configured makefiles that refer back to the `labs-examples` folder
  - The same makefile is used for Lab1, 2 and 3
  - Lab4 and Lab5 will need a slightly different makefile, because the folder is one level lower

## Benefits
I highly recommend this folder structure as it will allow you to:
- Only have the code you are working on in your current Lab folder.
- Abstract away from the lab-examples folder. 
- Avoid dealing with so many levels of nested folders.
- Have less code duplication
- Find your code files easier

## Initial Setup Instructions
1. Open your terminal to where you want your CITS3003 folder to be (See [here for advice](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.42yr22ji4ygg)).
2. Copy, paste and execute the command: `git clone https://github.com/DavoDC/CITS3003_Template` (You only have to do this once).
3. This repo will now be in a folder called `CITS3003_Template` in the current directory.
4. Rename that folder to `CITS3003`.

## Lab Usage Instructions
1. **Open your CITS3003 folder in the file manager GUI**.
2. **Enter the `labs-examples` folder and copy the needed base files for the Lab you are on**
<br /> (e.g. For Lab1 on Linux, go into `CITS3003\labs-examples\CHAPTER02_CODE\LINUX_VERSIONS` and copy example1.cpp).
3. **Paste them into the relevant Lab folder** 
<br /> (e.g. Paste `example1.cpp` into `CITS3003\Lab1`).
4. **Rename/edit/compile/execute your code within that Lab folder** 
<br /> (e.g. Work within the `Lab1` folder, Rename `example1.cpp` so you get: `CITS3003\Lab1\q1circle.cpp`).

## General Usage Instructions
- There are text files throughout the folder structure to guide you.
- I have included only one Makefile to make editing it for me easier - you'll have to copy it to where you need it
- You can copy this Makefile to each folder (like I did), OR, you may try using a ‘master makefile’ and a [symbolic link](https://linuxize.com/post/how-to-create-symbolic-links-in-linux-using-the-ln-command/).
- You shouldn't need to edit or compile anything in the `labs-examples` folder. 
- With this system, you’ll always have a copy of the original lab files:
 - So you don’t need to re-download `lab-examples.zip`.
 - You are free to change the code however you want in your Lab folders.

### Important Note for Mac Users:
- The folder structure will work fine for you.
- The but the files in Lab1 (makefile, CPP, shaders) will require a bit of editing before they can work.
- I have added comments mentioning 'Mac' where these changes to need to occur.
- So to make the changes, just search for 'Mac' and follow the instructions.


## A Link Back to My Guide
<https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#> 


## TODO
Fully comment all files in Lab1
- diamond.cpp  (use matrixRot thing)
  - explain every part of code, even vec 3 xyz stuff
  - add shader paths, show they can be anything
  - add vec3/vec2 info!! 
- Makefile
- vshader
- fshader

Add 'Mac changes' comments by comparing code to MAC VERSIONS Code

Fix makefile, test on Linux
On Linux = Add example folder structure to this README by using output of TREE on actual CITS3003 folder
Get a Mac user to test it out


GUIDE:

ORGANISATION:
Add repo link

ADD TO LAB 1 SECTION:
Make diamond.cpp the simple starting point in Lab1 section
Mention that comments have been added to diamond file, makefile and shaders!
added documentation links
mentioned this is a simple but fully commented code file
Good to help you understand OpenGL programs
Add warning for Mac
