# Binary File Management in C (SFSD - Practical Work)

This repository contains a C programming project for managing a binary file that stores information about university professors in Algeria. The project follows the **LObarreF** method (Unordered List with Fixed-Size Records) and includes various functionalities for creating, managing, and optimizing the file.

---

## Project Overview

The goal is to create and manipulate a binary file (`ENSEIGNANT-MESRS.bin`) containing professor records, each with **12 attributes**:

- Matricule
- Name & Surname
- Date & Wilaya of Birth
- Gender
- Blood Group
- Recruitment Date
- Grade
- Specialty
- Last Diploma
- University

---

## Implemented Features

- ✔ **File Creation & Initial Loading** (Randomly generated data)
- ✔ **File Purging** (Removing duplicate records)
- ✔ **Adding a New Professor**
- ✔ **Updating a Professor’s University** (Transfer management)
- ✔ **Deleting Records** (By ID or specialty)
- ✔ **Querying Professors**
  - By university with an experience filter
  - By geographical region (West, Center, East)
- ✔ **File Encoding & Decoding**
- ✔ **File Header & Structure Visualization**

---

## Technical Details

- Uses binary file handling in C
- Implements indexing for faster lookups
- Provides a menu-based user interface
- Includes graphical representation of file structure

---
