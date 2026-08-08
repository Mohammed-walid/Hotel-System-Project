# Hotel Management System (C)

A robust, console-based Hotel Management System built in standard C. Developed collaboratively with fellow students as a university project for a Programming 1 course around two years ago, this application demonstrates foundational concepts in procedural programming, data structures, and file I/O persistence.

## 🛠️ Features & Functionalities
* **User Authentication:** Secure login system with username/password verification and attempt limitation[cite: 2].
* **Room Management:** Track room availability, pricing, and categories ('Seaview', 'Lakeview', 'Gardenview').
* **Reservation Lifecycle:** Create, edit, cancel, and sort reservations by date with dynamically generated unique IDs[cite: 1].
* **Check-In & Check-Out:** Manage guest arrivals, compute stay durations, validate dates against system time, and automatically calculate total bills[cite: 1].
* **Reporting & Search:** Generate daily booking reports and search records by customer name, room number, or status[cite: 1].
* **File I/O Persistence:** Stores and updates user credentials, room statuses, and reservation logs across execution cycles using flat text files[cite: 1, 2].

## 📂 Project Structure
* `main.c` - Entry point handling login verification, system initialization, and menu routing[cite: 2].
* `header.c` - Core implementation of system logic, reservations, check-ins/outs, and file updates[cite: 1].
* `header.h` - Header definitions containing data structures for users, rooms, and reservations[cite: 1, 2].
* Data files (`users.txt`, `room.txt`, `reservations.txt`) - Flat-file databases managed dynamically by the application[cite: 1, 2].

## 🚀 Getting Started

To compile and run this project locally using Code::Blocks or any standard C compiler:

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/Mohammed-walid/Hotel-System-Project.git](https://github.com/Mohammed-walid/Hotel-System-Project.git)
