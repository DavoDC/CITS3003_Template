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


## Initial Setup
1. Open your terminal to where you want your CITS3003 folder to be (See [here for advice](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.42yr22ji4ygg)).
2. Copy, paste and execute the command: `git clone https://github.com/DavoDC/CITS3003_Template` 
<br /> (You only have to do this once).
3. This repo will now be in a folder called `CITS3003_Template` in the current directory.
4. Rename that folder to `CITS3003`.


## General Usage
- There are text files throughout the folder structure to guide you.
- I have included only one Makefile (in `Lab1`) to make editing it for me easier. You'll have to copy it to where you need it.
- You shouldn't need to edit or compile anything in the `LAB_DWL` folder (including sub-folders). 
- With this system, you’ll always have a copy of the original lab files:
   - So you don’t need to re-download `labs-examples.zip`.
   - You are free to change the code however you want in your Lab folders.
- See `Example_of_Used_Folder_Structure.txt` for an example of a used template.


## Lab Usage
1. **Open your CITS3003 folder in the file manager GUI**.
2. **Enter the `LAB_DWL` folder and copy the needed base files for the Lab you are on**
<br /> (e.g. For Lab1 (on Linux), Go into `CITS3003\LAB_DWL\CHAPTER02_CODE\LINUX_VERSIONS` and copy `example1.cpp`).
3. **Paste them into the relevant Lab folder** 
<br /> (e.g. For Lab 1, Paste `example1.cpp` into `CITS3003\Lab1`).
4. **Rename/edit/compile/execute your code within that Lab folder** 
<br /> (e.g. For Lab 1, Work within the `Lab1` folder, Rename `example1.cpp` so you get: `CITS3003\Lab1\q1circle.cpp`).


## Important Note for Mac Users
- The folder structure will work just fine for you.
- But you will need a different makefile, so:
    - Delete `Lab1/makefile` (as it for Linux only)
    - Rename `Lab1/Mac_makefile` to `makefile`
- If you wish to run `diamond.cpp`:
    - Open it in a text editor
    - Search for "`# Create VAO on Mac`"
    - Follow the instructions there for Mac users

## Links Back to My Guide
- [Default](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ)
- [The Lab 1 Recommendation Section](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.n484gikc90x)
- [The Organisational Advice Section](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.8snhndvjpzls)


## TODO
- Get a Mac user to test it out, Jasper?

- When done, update guide and  UNDER CONSTRUCTION parts
- Put diamond over one in UWA repo and give link to other 
- Let discord know ive revamped lab1 / organisational advice / template archive with better GitHub repo system
