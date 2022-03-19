# CITS3003 Template Repository

## Description
- This repo demonstrates a good organisational system and folder structure for doing the labs.
- The `LAB_DWL` folder is simply `labs-examples.zip` extracted.
- The Lab folders (Lab1, Lab2.. etc) contain specially configured makefiles that refer back to the `LAB_DWL` folder.
  - The same makefile can be used for Lab1, 2 and 3.
  - Lab4 and Lab5 will need a slightly different makefile, because the working folders are one level lower.


## Benefits
I highly recommend this folder structure as it will allow you to:
- Avoid dealing with so many levels of nested folders (Abstract away from the `labs-examples`/`LAB_DWL` folder).
- Only have the code you are working on in your current Lab folder (and working directory in the terminal).
- Find the code files that you've worked on easier.
- Have less code duplication.


## Initial Setup
1. Open your terminal to where you want your CITS3003 folder to be (See [here for advice](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.42yr22ji4ygg)).
2. Copy, paste and execute the command: `git clone https://github.com/DavoDC/CITS3003_Template CITS3003` 
3. This repo will now be in a folder called `CITS3003` in the current directory.


## General Usage
- There are text files with instructions in their names throughout the folder structure to guide you.
- I have included only one Makefile (in `Lab1`) to make editing it for me easier. You'll have to copy it to where you need it.
- You shouldn't need to edit or compile anything in the `LAB_DWL` folder (including sub-folders). 
- With this system, you’ll always have a copy of the original lab files:
   - So you don’t need to re-download `labs-examples.zip`.
   - You are free to change the code however you want in your Lab folders.
- See `Example_of_Used_Folder_Structure.txt` for an example of a used template.


## Lab Usage
1. **Open your `CITS3003` folder in your file manager/explorer GUI**.
2. **Enter the `LAB_DWL` folder and copy the needed base files for the Lab you are on**.
<br /> (e.g. For Lab1 (on Linux), Go into `CITS3003\LAB_DWL\CHAPTER02_CODE\LINUX_VERSIONS` and copy `example1.cpp`).
3. **Paste them into the relevant Lab folder**.
<br /> (e.g. For Lab 1, Paste `example1.cpp` into `CITS3003\Lab1`).
4. **Rename/edit/compile/execute your code within that Lab folder**.
<br /> (e.g. For Lab 1, Work within the `Lab1` folder, Rename `example1.cpp` so you get: `CITS3003\Lab1\q1circle.cpp`).


## Lab 1 
I have included some extra, simple, fully commented files in the `Lab1` folder to benefit your learning experience:
- `makefile` (for Linux only, Mac users can delete)
- `Mac_makefile` (for Mac only, Linux users can delete)
- `diamond.cpp`
- `shaders/vshaderS.glsl` 
- `shaders/fshaderS.glsl`

<br> See [the Lab 1 Recommendation Section](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.n484gikc90x) for more info.

## Important Note for Mac Users
- You'll need a different makefile, so:
    - Delete `Lab1/makefile` (as it is for Linux only)
    - Rename `Lab1/Mac_makefile` to `makefile`
- You'll need to make some small edits to `diamond.cpp`, `shaders/vshaderS.glsl` and `shaders/fshaderS.glsl`
    1. Open each in a text editor
    2. Search for "`MAC USERS`" and follow the instructions in the comments

## Links Back to My Guide
- **[Default](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ)**
- **[The Lab 1 Recommendation Section](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.n484gikc90x)**
- **[The Organisational Advice Section](https://docs.google.com/document/d/1mu-z7HbcocU0U21qmdsqrVXK6f_btW0oJq6AvEUAMcQ/edit#heading=h.8snhndvjpzls)**
