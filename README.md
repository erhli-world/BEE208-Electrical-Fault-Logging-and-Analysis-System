# BEE208-Electrical-Fault-Logging-and-Analysis-System
This project is a C++-based system developed as part of the BEE208 course to log, analyze, and classify electrical faults in power systems. It provides a structured framework for recording fault data, applying control statements for decision-making, and generating meaningful outputs for diagnostics and reporting.

ANUM EMMANUEL ELIKPLIM - 01244738B (Project lead and final coordination)

Stephen Attigah - 01242739B (Testing and input validation lead)

Obeng Kissi Jedediah Siisi - 01243581B (Flowchart designer)

Enock Ansah Ardey - 01242780B (C++ programmer)

Armah Bruce Nii - 01243733B (C++ programmer)

Benedict Bissah - 01240038B (Pseudocode writer)

Narter - Olaga Daniel Tetteh - 01243250B (Algorithm writer)

Basing Joseph N-Sinbeh - 01240234B (Documentation and README lead)

⁠Israel Avabey Awomnab - 01244814B (Presentation and defence lead)

Dzirasi Samuel Arthur - 01246159B (GitHub repository manager)

##  Project Background
Electrical installations in labs, workshops, hostels, and small buildings often face faults such as overload, short circuit, earth leakage, low voltage, loose connections, and equipment failure. Proper fault recording helps technicians identify recurring issues, take corrective action, and plan maintenance.  

This project involves building a **C++ program** that records fault reports, classifies severity, and generates a simple fault analysis report.

##  Problem Statement
Faults in electrical systems are common but often poorly documented. Without proper records, repeated issues go unnoticed, leading to safety risks and equipment damage. A simple tool is needed to log faults, assess severity, and provide analysis.

## Aims and Objectives
- Record electrical fault reports  
- Classify faults by severity  
- Generate a basic fault analysis report  
- Reinforce programming skills in data handling and control structures

# Fault Severity Rules
The system classifies faults into **three severity levels** based on their impact:
- **Minor Faults** → Low voltage, loose connections (non-critical, but require attention).  
- **Moderate Faults** → Overload, equipment failure (can cause interruptions if ignored).  
- **Severe Faults** → Short circuit, earth leakage (pose safety hazards and require immediate action).  

Severity rules are implemented using **conditional statements (`if...else`, `switch`)** to ensure accurate categorization.


## Applied C++ Concepts
This project reinforces key programming concepts:
- **Control Structures** → `if...else`, `switch` for fault classification.  
- **Loops** → `for`, `while`, `do...while` for iterative fault analysis.  
- **Data Handling** → Arrays and structures for storing fault records.  
- **Functions** → Modular design for logging, classification, and reporting.  
- **User Interaction** → Menu-driven interface for input and output.  

## Challenges and Solutions

- **Challenge:** Handling multiple fault entries efficiently  
  **Solution:** Implemented arrays and loops to store and process multiple records  

- **Challenge:** Designing clear severity classification rules  
  **Solution:** Used structured conditional logic (`switch` statements) to ensure consistency  

- **Challenge:** User input errors (e.g., invalid fault type)  
  **Solution:** Added input validation and error-handling routines  




