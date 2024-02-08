import json

# Specify the path to your JSON file
json_file_path = r'C:\Users\Administrator\Desktop\codes\JSON\test.json'

# Open and read the JSON file
with open(json_file_path, 'r') as file:
    # Load the JSON data into a Python dictionary
    data = json.load(file)

# Access information from the loaded dictionary
print("First Name:", data["firstName"])
print("Last Name:", data["lastName"])
print("Age:", data["age"])
print("Address:", data["address"]["street"], data["address"]["city"], data["address"]["state"], data["address"]["zipCode"])
print("Is Student:", data["isStudent"])
print("Hobbies:", ", ".join(data["hobbies"]))

print()
print(json.dumps(data))
print()
print(json.dumps(data,indent=2))