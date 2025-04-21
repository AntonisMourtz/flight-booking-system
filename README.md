# Flight Booking System

This project is a simple flight ticket booking application consisting of two main parts:
- **Server**: Responsible for managing flights and processing booking requests.
- **Client**: The user who sends booking requests to the server.

---

## How to Run the Project

To run the project, follow these steps:

### 1. Open Two Terminal Windows
   - The **first terminal** will be used for the **server**.
   - The **second terminal** will be used for the **client**.

### 2. Compile the Server and Client
   - In the **first terminal** (for the server), run:
     ```bash
     gcc server.c -o server
     ```
   - In the **second terminal** (for the client), run:
     ```bash
     gcc client.c -o client
     ```

### 3. Run the Server
   - In the **first terminal**, run the server:
     ```bash
     ./server
     ```
   - The server will start and wait for requests from the client.

### 4. Run the Client
   - In the **second terminal**, run the client:
     ```bash
     ./client
     ```
   - The client will send booking requests to the server and display the response.
   - You can run the client **multiple times** until all tickets are sold.
   - To stop the program, press **Ctrl+C** in the **server terminal**.

---

## Functionality Description

- **Server**:
  - The server manages a list of flights, which include:
    - **Flight ID**
    - **From City**
    - **To City**
    - **Available Seats**
    - **Price**
  - When the client sends a booking request, the server checks if there are available seats and responds with the price or a failure message.
  - The server continues to run until **Ctrl+C** is pressed in its terminal.

- **Client**:
  - The client generates random booking requests for flights and sends them to the server.
  - It displays the server's response (success or failure of the booking).
  - The client can be run **multiple times** until all tickets are sold.

---

## Example Execution

1. **Server Terminal**:
   ```bash
   $ ./server
   [+]TCP server socket created.
   [+]Bind to the port number: 5566
   Listening...
-------------------------------------------------------------------------------------------------------------------------------------------------------
### **Ελληνικά (Greek)**

Αποθήκευσέ το σε ένα αρχείο `README_GR.txt`:


# Σύστημα Κράτησης Εισιτηρίων Αεροπλάνων

Αυτό το project είναι μια απλή εφαρμογή κράτησης εισιτηρίων αεροπλάνων, η οποία αποτελείται από δύο βασικά μέρη:
- **Server**: Υπεύθυνος για τη διαχείριση των πτήσεων και την επεξεργασία των αιτημάτων κράτησης.
- **Client**: Ο χρήστης που στέλνει αιτήματα κράτησης στον server.

---

## Πώς να Τρέξεις το Project

Για να τρέξεις το project, ακολούθησε τα παρακάτω βήματα:

### 1. Άνοιξε Δύο Παράθυρα Terminal
   - Το **πρώτο terminal** θα χρησιμοποιηθεί για τον **server**.
   - Το **δεύτερο terminal** θα χρησιμοποιηθεί για τον **client**.

### 2. Μεταγλώττιση του Server και του Client
   - Στο **πρώτο terminal** (για τον server), εκτέλεσε:
     ```bash
     gcc server.c -o server
     ```
   - Στο **δεύτερο terminal** (για τον client), εκτέλεσε:
     ```bash
     gcc client.c -o client
     ```

### 3. Εκτέλεση του Server
   - Στο **πρώτο terminal**, εκτέλεσε τον server:
     ```bash
     ./server
     ```
   - Ο server θα ξεκινήσει και θα περιμένει αιτήματα από τον client.

### 4. Εκτέλεση του Client
   - Στο **δεύτερο terminal**, εκτέλεσε τον client:
     ```bash
     ./client
     ```
   - Ο client θα στείλει αιτήματα κράτησης στον server και θα εμφανίζει την απάντηση.
   - Μπορείς να τρέξεις τον client **όσες φορές θέλεις** μέχρι να εξαντληθούν τα εισιτήρια.
   - Για να σταματήσεις το πρόγραμμα, πάτησε **Ctrl+C** στο **terminal του server**.

---

## Περιγραφή Λειτουργίας

- **Server**:
  - Ο server διαχειρίζεται μια λίστα με πτήσεις, οι οποίες έχουν:
    - **Αριθμό πτήσης** (Flight ID)
    - **Από πού** (From City)
    - **Προς πού** (To City)
    - **Διαθέσιμες θέσεις** (Available Seats)
    - **Τιμή** (Price)
  - Όταν ο client στέλνει ένα αίτημα κράτησης, ο server ελέγχει αν υπάρχουν διαθέσιμες θέσεις και απαντά με την τιμή ή με ένα μήνυμα αποτυχίας.
  - Ο server συνεχίζει να τρέχει μέχρι να πατηθεί **Ctrl+C** στο terminal του.

- **Client**:
  - Ο client δημιουργεί τυχαία αιτήματα κράτησης για πτήσεις και τα στέλνει στον server.
  - Εμφανίζει την απάντηση από τον server (επιτυχία ή αποτυχία κράτησης).
  - Μπορείς να τρέξεις τον client **όσες φορές θέλεις** μέχρι να εξαντληθούν τα εισιτήρια.

---

## Παράδειγμα Εκτέλεσης

1. **Server Terminal**:
   ```bash
   $ ./server
   [+]TCP server socket created.
   [+]Bind to the port number: 5566
   Listening...
