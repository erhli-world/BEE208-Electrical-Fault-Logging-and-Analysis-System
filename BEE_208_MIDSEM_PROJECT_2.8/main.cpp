#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class FaultRecord
{
private:
    string faultID;
    string location;
    string faultType;
    double voltageReading;
    double currentReading;
    string actionTaken;
    string severity;

public:

    void setFaultDetails()
    {
        cout << "\nEnter Fault ID: ";
        cin >> faultID;

        cin.ignore();

        cout << "Enter Location: ";
        getline(cin, location);

        cout << "Enter Fault Type: ";
        getline(cin, faultType);

        do
        {
            cout << "Enter Voltage Reading (V): ";
            cin >> voltageReading;

            if(voltageReading < 0)
                cout << "Voltage cannot be negative.\n";

        }while(voltageReading < 0);

        do
        {
            cout << "Enter Current Reading (A): ";
            cin >> currentReading;

            if(currentReading < 0)
                cout << "Current cannot be negative.\n";

        }while(currentReading < 0);

        cin.ignore();

        cout << "Enter Action Taken: ";
        getline(cin, actionTaken);
    }

    bool validateReadings()
    {
        if(voltageReading < 0 || currentReading < 0)
            return false;

        return true;
    }

    void classifyFault()
    {
        string type = faultType;

        transform(type.begin(), type.end(), type.begin(), ::tolower);

        if(type == "short circuit" ||
           type == "burning smell" ||
           type == "electric shock")
        {
            severity = "Critical";
        }

        else if(voltageReading < 180 || voltageReading > 250 ||
                currentReading > 15)
        {
            severity = "Serious";
        }

        else if(type == "loose connection" ||
                type == "flickering light" ||
                type == "damaged socket")
        {
            severity = "Moderate";
        }

        else
        {
            severity = "Minor";
        }
    }

    void displayFaultReport()
    {
        cout << "\n------------------------------------\n";

        cout << "Fault ID : " << faultID << endl;
        cout << "Location : " << location << endl;
        cout << "Fault Type : " << faultType << endl;
        cout << "Voltage : " << voltageReading << " V" << endl;
        cout << "Current : " << currentReading << " A" << endl;
        cout << "Action Taken : " << actionTaken << endl;
        cout << "Severity : " << severity << endl;

        cout << "------------------------------------\n";
    }

    void saveFaultReport(ofstream &file)
    {
        file << "Fault ID: " << faultID << endl;
        file << "Location: " << location << endl;
        file << "Fault Type: " << faultType << endl;
        file << "Voltage: " << voltageReading << " V" << endl;
        file << "Current: " << currentReading << " A" << endl;
        file << "Action Taken: " << actionTaken << endl;
        file << "Severity: " << severity << endl;
        file << "---------------------------------\n";
    }

    string getSeverity()
    {
        return severity;
    }
};

int main()
{
    vector<FaultRecord> faults;

    int choice;

    do
    {
        cout << "\n=============================================\n";
        cout << " ELECTRICAL FAULT LOGGING AND ANALYSIS SYSTEM\n";
        cout << "=============================================\n";

        cout << "1. Add Fault Record\n";
        cout << "2. Display All Faults\n";
        cout << "3. Save Report to File\n";
        cout << "4. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int number;

                cout << "\nHow many faults do you want to record? ";
                cin >> number;

                for(int i = 0; i < number; i++)
                {
                    cout << "\nFault " << i + 1 << endl;

                    FaultRecord record;

                    record.setFaultDetails();

                    if(record.validateReadings())
                    {
                        record.classifyFault();

                        record.displayFaultReport();

                        faults.push_back(record);
                    }

                    else
                    {
                        cout << "Invalid readings.\n";
                    }
                }

                break;
            }

            case 2:
            {
                int critical = 0;

                cout << "\n========== FAULT REPORT ==========\n";

                for(int i = 0; i < faults.size(); i++)
                {
                    faults[i].displayFaultReport();

                    if(faults[i].getSeverity() == "Critical")
                        critical++;
                }

                cout << "\nTotal Faults Recorded: "
                     << faults.size() << endl;

                cout << "Critical Faults: "
                     << critical << endl;

                break;
            }

            case 3:
            {
                ofstream file("electrical_fault_report.txt");

                int critical = 0;

                file << "ELECTRICAL FAULT REPORT\n\n";

                for(int i = 0; i < faults.size(); i++)
                {
                    faults[i].saveFaultReport(file);

                    if(faults[i].getSeverity() == "Critical")
                        critical++;
                }

                file << "\nTotal Faults: "
                     << faults.size() << endl;

                file << "Critical Faults: "
                     << critical << endl;

                file.close();

                cout << "\nReport saved successfully as ";
                cout << "electrical_fault_report.txt\n";

                break;
            }

            case 4:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    }while(choice != 4);

    return 0;
}
