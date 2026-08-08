# Hotel Management System (C)

A robust, console-based Hotel Management System built in standard C. Developed collaboratively with fellow students as a university project for a Programming 1 course around two years ago, this application demonstrates foundational concepts in procedural programming, data structures, and file I/O persistence.

## 🛠️ Features & Functionalities
* **User Authentication:** Secure login system with username/password verification and attempt limitation.
* **Room Management:** Track room availability, pricing, and categories ('Seaview', 'Lakeview', 'Gardenview').
* **Reservation Lifecycle:** Create, edit, cancel, and sort reservations by date with dynamically generated unique IDs.
* **Check-In & Check-Out:** Manage guest arrivals, compute stay durations, validate dates against system time, and automatically calculate total bills.
* **Reporting & Search:** Generate daily booking reports and search records by customer name, room number, or status.
* **File I/O Persistence:** Stores and updates user credentials, room statuses, and reservation logs across execution cycles using flat text files.

## 📂 Project Structure
* `main.c` - Entry point handling login verification, system initialization, and menu routing.
* `header.c` - Core implementation of system logic, reservations, check-ins/outs, and file updates.
* `header.h` - Header definitions containing data structures for users, rooms, and reservations.
* Data files (`users.txt`, `room.txt`, `reservations.txt`) - Flat-file databases managed dynamically by the application.
* 
