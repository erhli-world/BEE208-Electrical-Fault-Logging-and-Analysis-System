#  Electrical Fault Logging and Analysis System

## Algorithm Steps

1. **START** the program.  
2. **DISPLAY** the project title and main menu with options:  
   - Add Fault Record  
   - Display All Faults  
   - Save Report to File  
   - Exit  
3. **PROMPT** the user to enter a choice from the menu.  

---

### Case 1: Add Fault Record
4. If the user selects **Add Fault Record**:  
   - Ask how many fault records they want to enter.  
   - For each fault record:  
     a. Collect details: *Fault ID, Location, Fault Type, Voltage Reading, Current Reading, Action Taken*.  
     b. Validate voltage and current readings (**must not be negative**).  
     c. Classify fault severity using decision rules:  
        - **Critical**: short circuit, burning smell, electric shock  
        - **Serious**: voltage < 180 V or > 250 V, or current > 15 A  
        - **Moderate**: loose connection, flickering light, damaged socket  
        - **Minor**: all other cases  
     d. Store the record in a list/vector.  
     e. Display the fault report immediately.  

---

### Case 2: Display All Faults
5. If the user selects **Display All Faults**:  
   - Show all recorded fault reports.  
   - Count and display the **total number of faults**.  
   - Count and display the **number of Critical faults**.  

---

### Case 3: Save Report to File
6. If the user selects **Save Report to File**:  
   - Open a text file named `electrical_fault_report.txt`.  
   - Write all fault reports into the file.  
   - Include summary: *total faults and number of critical faults*.  
   - Close the file and confirm successful saving.  

---

### Case 4: Exit
7. If the user selects **Exit**:  
   - Display a **thank-you message**.  
   - Terminate the program.  

---

### Case 5: Invalid Choice
8. If the user enters an **invalid choice**:  
   - Display an error message.  
   - Return to the main menu.  

---

9. **REPEAT** steps 3–8 until the user chooses Exit.  
10. **END** the program.  
