BEGIN PROGRAM

DISPLAY "Electrical Fault Logging and Analysis System"
DISPLAY Main Menu:
    1. Add Fault Record
    2. Display All Faults
    3. Save Report to File
    4. Exit

REPEAT
    PROMPT "Enter your choice:"
    READ choice

    IF choice = 1 THEN
        PROMPT "Enter number of fault records:"
        READ n
        FOR i ← 1 TO n DO
            PROMPT "Enter Fault ID:"
            READ faultID
            PROMPT "Enter Location:"
            READ location
            PROMPT "Enter Fault Type:"
            READ faultType
            PROMPT "Enter Voltage Reading:"
            READ voltage
            PROMPT "Enter Current Reading:"
            READ current
            PROMPT "Enter Action Taken:"
            READ action

            IF voltage < 0 OR current < 0 THEN
                DISPLAY "Error: Invalid readings"
                CONTINUE to next record
            ENDIF

            IF faultType = "short circuit" OR faultType = "burning smell" OR faultType = "electric shock" THEN
                severity ← "Critical"
            ELSE IF voltage < 180 OR voltage > 250 OR current > 15 THEN
                severity ← "Serious"
            ELSE IF faultType = "loose connection" OR faultType = "flickering light" OR faultType = "damaged socket" THEN
                severity ← "Moderate"
            ELSE
                severity ← "Minor"
            ENDIF

            STORE fault record (faultID, location, faultType, voltage, current, action, severity) in FaultList
            DISPLAY fault report
        ENDFOR

    ELSE IF choice = 2 THEN
        DISPLAY all records in FaultList
        DISPLAY "Total Faults:" COUNT(FaultList)
        DISPLAY "Critical Faults:" COUNT(records with severity = "Critical")

    ELSE IF choice = 3 THEN
        OPEN file "electrical_fault_report.txt" FOR writing
        WRITE all records from FaultList into file
        WRITE "Total Faults:" COUNT(FaultList)
        WRITE "Critical Faults:" COUNT(records with severity = "Critical")
        CLOSE file
        DISPLAY "Report saved successfully."

    ELSE IF choice = 4 THEN
        DISPLAY "Thank you for using the system."
        EXIT PROGRAM

    ELSE
        DISPLAY "Invalid choice. Please try again."
    ENDIF

UNTIL choice = 4

END PROGRAM
