# Clinic Project

A simple C++ console-based clinic management system built as an OOP practice project. The system manages patients, doctors, users, and appointments, while storing data in plain text files.

<a id="table-of-contents"></a>
## Table of Contents

- [Overview](#overview)
- [How to Run](#how-to-run)
- [Demo Login Accounts](#demo-login-accounts)
- [System Description](#system-description)
- [Project Structure](#project-structure)
- [Main Work Completed](#main-work-completed)
- [Function Wrapper, Lambda, and Template Usage](#function-wrapper-lambda-and-template-usage)
- [Data Flow](#data-flow)
- [Development Notes](#development-notes)

<a id="overview"></a>
## Overview

Clinic Project is a console application that provides a structured way to manage clinic data. The project is organized into clear layers: core business classes, screens, helper libraries, global state, and text-file database storage.

The system supports:

- User login.
- Role-based permissions: SuperAdmin, Admin, and Receptionist.
- Patient management: list, update, and search.
- Doctor management: list, add, update, delete, and search.
- User management: list, add, update, delete, and search.
- Appointment management: list, add, update, delete, and search.
- Data persistence using text files.

<a id="how-to-run"></a>
## How to Run

### Run with Visual Studio

1. Open the solution file:

```text
Clinic.sln
```

2. Select a build configuration, for example:

```text
x64 / Debug
```

3. Run the project using:

```text
Ctrl + F5
```

You can also start it from the Visual Studio Start button.

### Run the Executable

After building the project, run the executable from:

```text
x64/Debug/Clinic.exe
```

### Program Entry Point

The program starts from:

```cpp
Clinic.cpp
```

The main function repeatedly opens the login screen:

```cpp
while (true)
    clsLoginScreen::ShowLoginScreen();
```

<a id="demo-login-accounts"></a>
## Demo Login Accounts

Users are stored in:

```text
ProjectFiles/Database/UsersFile.txt
```

Example accounts available in the data file:

| Username | Password | Role |
|---|---:|---|
| Doc.Ah | 1234 | SuperAdmin |
| User1 | 1234 | Receptionist |
| User2 | 1234 | Admin |

<a id="system-description"></a>
## System Description

### Login

The system starts from `clsLoginScreen`. It asks for a username and password, then searches for the matching user in the users file. If the credentials are valid, the user is moved to the main menu. If not, the login screen asks again.

### Main Menu

The main menu is implemented in:

```text
ProjectFiles/Screens/MainMenu/clsMainMenu.h
```

It displays menu options based on the current user's permissions:

- Manage Patients Menu
- Manage Doctors Menu
- Manage Users Menu
- Manage Appointments Menu
- Log out

### Permissions

Permissions are handled by `clsPermissions`. Each permission is represented as a numeric flag, and the system checks permissions using bitwise operations. This allows each role to have a precise set of allowed actions.

Main roles:

- `SuperAdmin`: has full access.
- `Admin`: can manage most system areas with some restrictions.
- `Receptionist`: focuses mainly on patients, appointments, and viewing doctors.

### Data Management

Each main entity has its own class:

- `clsPatient`: patient data.
- `clsDoctor`: doctor data.
- `clsUser`: system user data.
- `clsAppointment`: appointment data.

These classes share the same general save, update, find, and delete behavior through `clsTemplate`.

<a id="project-structure"></a>
## Project Structure

```text
Clinic_Project/
├── Clinic.cpp
├── Clinic.sln
├── Clinic.vcxproj
├── ProjectFiles/
│   ├── Core/
│   │   ├── clsPerson.h
│   │   ├── clsPatient.h
│   │   ├── clsDoctor.h
│   │   ├── clsUser.h
│   │   ├── clsAppointment.h
│   │   ├── clsPermissions.h
│   │   └── clsTemplate.h
│   ├── Database/
│   │   ├── FilesName.h
│   │   ├── PatientsFile.txt
│   │   ├── DoctorsFile.txt
│   │   ├── UsersFile.txt
│   │   └── AppointmentsFile.txt
│   ├── Globlas/
│   │   └── Globals.h
│   ├── Libraries/
│   │   ├── clsDate.h
│   │   ├── clsInputValidate.h
│   │   ├── clsPeriod.h
│   │   ├── clsString.h
│   │   └── clsUtil.h
│   └── Screens/
│       ├── MainMenu/
│       ├── PatientMenu/
│       ├── DoctorMenu/
│       ├── UsersMenu/
│       └── AppointmentMenu/
└── x64/
    └── Debug/
```

### Core Layer

Contains the main business classes and their related logic. For example, `clsDoctor` stores doctor data, converts a doctor object to a text line, loads doctors from file, and saves doctor data.

### Screens Layer

Contains the user interface screens for the console application. Each screen handles a specific workflow, such as adding a doctor, listing patients, updating an appointment, or finding a user.

### Database Layer

Contains text files used as a simple database. Fields are separated using:

```text
#//#
```

### Libraries Layer

Contains general helper classes, including:

- Input validation.
- Date handling.
- String utilities.
- Console formatting utilities.

<a id="main-work-completed"></a>
## Main Work Completed

- Built a complete console-based clinic management system.
- Applied OOP concepts using inheritance between `clsPerson` and `clsPatient`, `clsDoctor`, and `clsUser`.
- Created a role-based permissions system.
- Used text files as a lightweight database.
- Built reusable CRUD behavior through `clsTemplate`.
- Used `std::function` to pass different behaviors into generic operations.
- Used lambda expressions to connect class-specific member functions with generic template functions.
- Used templates to apply the same save, find, update, and delete logic to multiple entity types.
- Organized screens into separate folders based on their domain.
- Added automatic ID generation for users, patients, doctors, and appointments.
- Calculated appointment total price based on a base price and doctor fee rate.
- Linked appointments to patient and doctor objects instead of duplicating all related data.

<a id="function-wrapper-lambda-and-template-usage"></a>
## Function Wrapper, Lambda, and Template Usage

This project uses three important C++ ideas to reduce duplication and make the code more flexible.

### Template

File:

```text
ProjectFiles/Core/clsTemplate.h
```

It defines:

```cpp
template <class T>
class clsTemplate
```

This means `clsTemplate` is not limited to one type. It can work with:

- `clsPatient`
- `clsDoctor`
- `clsUser`
- `clsAppointment`

Instead of writing separate save, find, update, and delete logic for each class, the project defines generic functions such as:

```cpp
LoadObjectsDataFromFiles
SaveObjectsDataToFile
FindObject
UpdateObject
AddObjectToFile
DeleteObject
Save
```

Then each entity chooses the type it needs:

```cpp
clsTemplate<clsDoctor>
clsTemplate<clsPatient>
clsTemplate<clsUser>
clsTemplate<clsAppointment>
```

### Function Wrapper

The project uses:

```cpp
std::function
```

`std::function` is a function wrapper. It can store or receive any callable object, such as:

- A normal function.
- A static function.
- A lambda expression.
- A function object.

Example from `clsTemplate`:

```cpp
static map<string, T> LoadObjectsDataFromFiles(
    string &fileName,
    function<T(string, string)> convertDateLineToObject,
    function<string(const T&)> getID
)
```

This function does not know how to convert a text line into a patient, doctor, user, or appointment. Instead, it receives a conversion function from the caller. That makes the loading logic reusable for all entity types.

Another example:

```cpp
static bool Save(
    enMode& mode,
    function<void()> UpdateObject,
    function<void()> AddNewObject,
    enIsSave &objectIsSave
)
```

`Save` does not know the details of updating a doctor, user, patient, or appointment. It only knows when to call the update operation and when to call the add operation.

### Lambda

Lambda expressions are used to pass small functions directly into `clsTemplate`, especially when the function needs access to the current object through `this`.

Example from `clsDoctor`:

```cpp
clsTemplate<clsDoctor>::Save(
    _mode,
    [this]() { _UpdateDoctor(); },
    [this]() { _AddDoctorToFile(); },
    _ObjectIsSaved
);
```

Meaning:

- If the object is in update mode, `_UpdateDoctor` is called.
- If the object is new, `_AddDoctorToFile` is called.
- `[this]` allows the lambda to access the current object's private data and member functions.

Another example from doctor saving:

```cpp
[this](clsDoctor& tempDoctor, string sperator = "#//#") -> string {
    return _ConvertDoctorToDataLine(tempDoctor, sperator);
}
```

This lambda converts a doctor object into a text line, then passes that behavior into the generic save function.

### Why These Ideas Were Used

Using `template`, `std::function`, and lambda expressions turns `clsTemplate` into a reusable CRUD layer. Instead of repeating the same file loading and saving logic in every class, each class only provides its custom behavior:

- How to convert a line into an object.
- How to convert an object into a line.
- How to read the object's ID.
- How to generate a new ID.
- How to check the object's mode.

This reduces duplication and makes it easier to add new entity types later.

<a id="data-flow"></a>
## Data Flow

Example: adding a new doctor.

1. The user opens the doctors menu.
2. `clsAddDoctorScreen` reads the doctor's data.
3. A new `clsDoctor` object is created in `eAddNewMode`.
4. When `Save` is called, `clsDoctor` passes its own functions to `clsTemplate`.
5. `clsTemplate` decides whether the operation is an add or update.
6. A new doctor ID is generated.
7. The doctor object is converted into a text line.
8. The line is saved into `DoctorsFile.txt`.

Example database line:

```text
Doc001#//#First#//#Second#//#Third#//#Fourth#//#male#//#1/1/1990#//#Dentistry#//#777777777#//#20
```

<a id="screenshots"></a>


<a id="development-notes"></a>
## Development Notes

- The project is useful for practicing OOP, file handling, permissions, and advanced C++ concepts.
- The current database is text-file based, which is good for learning. It can later be replaced with a database such as SQLite.
- Future improvements could include tests, password hashing, and operation logs.
- The project uses `__declspec(property)`, which is mainly supported by Microsoft Visual C++, so Visual Studio on Windows is the easiest environment for running it.

