import csv
import datetime
def load_data():
  """Loads data from the CSV file into a list of patient dictionaries."""
  patients = []
  with open("hospital_data.csv", "r") as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
      patients.append(row)
  return patients

def save_data(patients):
  """Saves the patient data back to the CSV file."""
  with open("hospital_data.csv", "+a", newline="") as csvfile:
    fieldnames = ["patient_id", "name", "date_of_birth", "address", "phone_number", "email", "insurance_provider", "insurance_id", "appointments", "medical_records", "bills"]
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    #writer.writeheader()
    writer.writerow(patients)

def register_patient():
  """Registers a new patient and adds their data to the CSV file."""
  patient_id =int(input("Enter Id:")) #str(datetime.datetime.now().timestamp())  # Generate unique ID using timestamp
  name = input("Enter patient name: ")
  date_of_birth = input("Enter date of birth (YYYY-MM-DD): ")
  address = input("Enter address: ")
  phone_number = input("Enter phone number: ")
  email = input("Enter email (optional): ")
  insurance_provider = input("Enter insurance provider (optional): ")
  insurance_id = input("Enter insurance ID (optional): ")

  new_patient = {
    "patient_id": patient_id,
    "name": name,
    "date_of_birth": date_of_birth,
    "address": address,
    "phone_number": phone_number,
    "email": email,
    "insurance_provider": insurance_provider,
    "insurance_id": insurance_id,
    "appointments": [],
    "medical_records": [],
    "bills": []
  }

  #patients.append(new_patient)
  save_data(new_patient)

def schedule_appointment():
  """Schedules an appointment for a patient."""
  patient_id = input("Enter patient ID: ")
  patient = next((p for p in patients if p["patient_id"] == patient_id), None)
  if patient_id not in patient["patient_id"]:
    print(patient_id,patient)
    print("Patient not found.")
    return

  doctor_id = input("Enter doctor ID: ")  # Assuming doctor IDs are available
  date = input("Enter appointment date (YYYY-MM-DD): ")
  time = input("Enter appointment time (HH:MM): ")
  purpose = input("Enter appointment purpose: ")

  new_appointment = {
    "appointment_id":int(input("appointment id:")),#str(datetime.datetime.now().timestamp()),  # Generate unique ID
    "doctor_id": doctor_id,
    "date": date,
    "time": time,
    "purpose": purpose
  }
  print(patient)
  
  patient["appointments"]=[]
  patient["appointments"].append(new_appointment)
  save_data(patients)

# Example usage
patients = load_data()
register_patient()  # Add a new patient
#schedule_appointment()  # Schedule an appointment for an existing patient
