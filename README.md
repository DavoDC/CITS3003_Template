# CITS3003 Template Repository
# (WORK IN PROGRESS, NOT FINISHED!)

## Description
- This repo demonstrates a good organisational system and folder structure for doing the labs.
- The `LAB_DWL` folder is simply `labs-examples.zip` extracted
- The Lab folders (Lab1, Lab2.. etc) contain specially configured makefiles that refer back to the `LAB_DWL` folder
  - The same makefile can be used for Lab1, 2 and 3
  - Lab4 and Lab5 will need a slightly different makefile, because the working folders are one level lower

## Benefits
I highly recommend this folder structure as it will allow you to:
- Avoid dealing with so many levels of nested folders (Abstract away from the `labs-examples`/`LAB_DWL` folder)
- Only have the code you need / are working on in your current Lab folder and working directory in the terminal.
- Find the code files that you've worked on easier
- Have less code duplication

## Initial Setup Instructions
1. Open your terminal to where you want your CITS3003 folder to be (See [here for advice](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.42yr22ji4ygg)).
2. Copy, paste and execute the command: `git clone https://github.com/DavoDC/CITS3003_Template` 
<br /> (You only have to do this once).
3. This repo will now be in a folder called `CITS3003_Template` in the current directory.
4. Rename that folder to `CITS3003`.

## Lab Usage Instructions
1. **Open your CITS3003 folder in the file manager GUI**.
2. **Enter the `LAB_DWL` folder and copy the needed base files for the Lab you are on**
<br /> (e.g. For Lab1 (on Linux), Go into `CITS3003\LAB_DWL\CHAPTER02_CODE\LINUX_VERSIONS` and copy `example1.cpp`).
3. **Paste them into the relevant Lab folder** 
<br /> (e.g. For Lab 1, Paste `example1.cpp` into `CITS3003\Lab1`).
4. **Rename/edit/compile/execute your code within that Lab folder** 
<br /> (e.g. For Lab 1, Work within the `Lab1` folder, Rename `example1.cpp` so you get: `CITS3003\Lab1\q1circle.cpp`).

## General Usage Instructions
- There are text files throughout the folder structure to guide you.
- I have included only one Makefile (in `Lab1`) to make editing it for me easier. You'll have to copy it to where you need it.
- You shouldn't need to edit or compile anything in the `LAB_DWL` folder (including sub-folders). 
- With this system, you’ll always have a copy of the original lab files:
   - So you don’t need to re-download `labs-examples.zip`.
   - You are free to change the code however you want in your Lab folders.
- See `Example_of_Used_Folder_Structure.txt` for an example of a used template.

## Important Note for Mac Users
- The folder structure will work just fine for you.
- But the files in `Lab1` (CPP file, makefile, shaders) will require a bit of editing before they can work.
- I have added comments mentioning 'Mac' where these changes to need to occur.
- So to make these changes: 
<br /> For the CPP file, makefile and shaders:
<br /> - Search for 'Mac' in a text editor in each of these files.
<br /> - Follow the instructions in the comments.


## Links Back to My Guide
- [Default](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ)
- [The Lab 1 Recommendation Section](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.n484gikc90x)
- [The Organisational Advice Section](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.8snhndvjpzls)

## TODO
- Fully comment all files in Lab1
  - Makefile
  - vshader
  - fshader
- Merge update readme commits in GitHub desktop
- Add 'Mac changes' comments by comparing code to MAC VERSIONS Code
- Get a Mac user to test it out
- When done, update guide and  UNDER CONSTRUCTION parts
