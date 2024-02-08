import csv
import uuid
from datetime import datetime
import pandas as pd
import ast
import matplotlib.pyplot as plt
from collections import defaultdict
import seaborn as sns
from dateutil.relativedelta import relativedelta


print("Welcome to  SOME BANK of SOME BRANCH ")
class customer:
  def load_info_data(self):
    account = []
    with open("info.csv", "r") as csvfile:
      reader = csv.DictReader(csvfile)# object is created and it is an instance of the csv.DictReader class.
      for row in reader:
        account.append(row)
    return account
  def check_info_data(self):
    info=[]
    field=input("Enter field name (cif_no or adhar_no or phone_no ) to check:")
    print("Enter the",field,end=":")
    criteria=input()
    for index in cust_info:
        if(index[field]==criteria):
          info.append(index)
    return info
  def add_info():
    with open("info.csv", "a", newline="") as csvfile:
      fieldnames = cust_info[0].keys()
      writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
      print("Enter the details to create:")
      #generating a UUID using the version 4 algorithm (uuid.uuid4().int), 
      #converting it to an integer, converting that integer to a string,
      # and then taking the first 11 characters of that string.
      unique_no=str(uuid.uuid4().int)[:11] 
      new_cust={
        "cif_no": unique_no,
        "adhar_no":input("ADHAR NO:"),
        "name":input("NAME:"),
        "dob":input("DOB:"),
        "street":input("STREET:"),
        "city":input("CITY:"),
        "state":input("STATE:"),
        "pin_code":input("PINCODE:"),
        "email_id":input("EMAIL ID:"),
        "phone_no":input("PHONE NUMBER:")
              }
      writer.writerow(new_cust)
      return unique_no


class account:
  def load_acc_data():
    account = []
    with open("acc.csv", "r") as csvfile:
      reader = csv.DictReader(csvfile)
      for row in reader:
        account.append(row)
    return account
  
  def check_acc_data(acc_no):
    for row in acc_info:
        if(row["acc_no"]==acc_no):
          return row
    return 0

  def create_acc():
    print("You have CIF number")
    cif=input("YES or NO")
    if cif.upper()=='YES':
      info=cust.check_info_data()
      #print(info)
      if info==[]:
        print("cif number not found")
      elif (len(info)>1):  # if customer has different cif numbers for unique phone or adhar numbers
          # Asking which CIF number should used
          case=0
          while(case==0):
            for index in info:
              print("Enter",info.index(index),"to select:",index['cif_no'])
            n=int(input())
            if(n>len(cif)):
              print("wrong number")
            else:
              case=1
              return info[n]['cif_no']
      
      else:
        return info[0]['cif_no']
    elif cif.upper()=='NO':
      cif_no=customer.add_info()
      return cif_no
    else:print("INVALID ENTRY")

  def add_acc():
    print("Enter the details")
    with open("acc.csv", "+a", newline="") as csvfile:
      fieldnames =acc_info[0].keys()
      writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
      unique_no=str(uuid.uuid4().int)[:12]
      new_acc={
        "cif_no":account.create_acc(),
        "acc_no":unique_no,
        "acc_type":input("ACCOUN TYPE:"),
        "adhar":input("ADHAR"),
        "acc_status":"active",
        "acc_activation_date":datetime.now().date(),
        "total_bal":"0",

        
      }
      writer.writerow(new_acc)
      print("CIF number is:",new_acc["cif_no"])
      print("Account number is:",unique_no)
      transaction.create_trans(new_acc["cif_no"],unique_no)

class transaction:
  def load_tranc_data(self):
    account = []
    with open("tranc.csv", "r") as csvfile:
      reader = csv.DictReader(csvfile)
      for row in reader:
        account.append(row)
    return account
  def check_tranc_data(acc_no):
    for index in trans_info:
        if(index["acc_no"]==acc_no):
          return index
    return 0
  def create_trans(cif_no,acc_no):
    with open("tranc.csv", "+a", newline="") as csvfile:
      fieldnames =acc_info[0].keys()
      writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
      new_trans={
          "cif_no":cif_no,
          "acc_no":acc_no,
          "amt_withdraw":{},
          "amt_deposit":{}
      }
      writer.writerow(new_trans)

  def withdraw():
    acc=input("Enter the account number:")
    c=account.check_acc_data(acc)
    if c==0:
      return "Account not found"
    b=transaction.check_tranc_data(acc)
    if b==0:
      print("NO ACCOUNT")
    else:
      amt=int(input("Enter the amount:"))
      bal=int(c["total_bal"])
      if (amt>bal):
        return "No enough balance"
      else:      
        
        with open("acc.csv", "w", newline="") as csvfile:
          acc_info[acc_info.index(c)]["total_bal"]=bal-amt
          fieldnames = acc_info[0].keys()  # Get field names from the first dictionary
          writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
          writer.writeheader()  # Write the header row
          writer.writerows(acc_info)  # Write the data rows

        with open("tranc.csv","w",newline="") as csvfile:
          current_datetime = datetime.now()
          print(current_datetime)
          current_datetime= current_datetime.strftime('%Y-%m-%d %H:%M:%S')
          print(current_datetime)
          trans_info[trans_info.index(b)]['amt_withdraw'] = ast.literal_eval(trans_info[trans_info.index(b)]['amt_withdraw'])

         # Add the key-value pair to the amt_withdraw dictionary
         # Convert string values to dictionaries
          trans_info[trans_info.index(b)]['amt_withdraw'][str(current_datetime)] = str(amt)
          fieldnames = trans_info[0].keys()  # Get field names from the first dictionary
          writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
          writer.writeheader()  # Write the header row
          writer.writerows(trans_info)  # Write the data rows
        return bal-amt
  def deposit():
    acc=input("Enter the account number:")
    c=account.check_acc_data(acc)
    if c==0:
      return "Account not found"
    b=transaction.check_tranc_data(acc)
    if b==0:
      print("NO ACCOUNT")
    else:
      amt=int(input("Enter the amount:"))
      bal=int(c["total_bal"])
      if (amt<0):
        return "Invalid amount"
      else:      
        
        with open("acc.csv", "w", newline="") as csvfile:
          acc_info[acc_info.index(c)]["total_bal"]=bal+amt
          fieldnames = acc_info[0].keys()  # Get field names from the first dictionary
          writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
          writer.writeheader()  # Write the header row
          writer.writerows(acc_info)  # Write the data rows

        with open("tranc.csv","w",newline="") as csvfile:
          current_datetime = datetime.now()
          trans_info[trans_info.index(b)]['amt_deposit'] = ast.literal_eval(trans_info[trans_info.index(b)]['amt_deposit'])

         # Add the key-value pair to the amt_withdraw dictionary
         # Convert string values to dictionaries
          trans_info[trans_info.index(b)]['amt_deposit'][str(current_datetime)] = str(amt)
          fieldnames = trans_info[0].keys()  # Get field names from the first dictionary
          writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
          writer.writeheader()  # Write the header row
          writer.writerows(trans_info)  # Write the data rows
        return bal+amt



cust=customer()
cust_info=cust.load_info_data()
#print(cust_info)

acc=account()
acc_info=account.load_acc_data()
#print(acc_info)

trans=transaction()  
trans_info=trans.load_tranc_data()
#print(trans_info)

while(True):
  print()
  print("""Enter 1-CUSTOMER INFORMATION
        2-ACCOUNT INFORMATION
        3-TRANSACTION INFORMATION
      """)
  choice=int(input("Option:"))

  if choice==1:
    print("""ENTER   1-Check customer details
          2-Create Customer Id""")
    check=int(input("Option:"))
    if check==1:
      check_info=cust.check_info_data()
      if check_info!=[]:
        print(check_info)
        for i in check_info:
          for j in i:
            print(j,":",i[j])
      else:print("There is no such account")
    elif check==2:
      cif_no=customer.add_info()
      print("CiF NUMBER:",cif_no)


  elif choice==2:
    print("""ENTER   1-Check account details
          2-Create Account""")
    check=int(input("Option:"))
    if check==1:
      acc=input("Enter the account number:")
      check_acc=account.check_acc_data(acc)
      if check_acc!=0:
        for i in check_acc:
          print(i,":",check_acc[i])
      else:print("There is no such account")
    elif check==2:
      account.add_acc()

  elif choice==3:
    print("""ENTER   1-Check transaction details
          2-Check deposit details
          3-check withdraw details
          4-Withdraw money
          5-Deposit money""")
    check=int(input("Option:"))
      
    if check==1:
      acc=input("Enter the account number:")  
      check_trans=transaction.check_tranc_data(acc)
      for i in check_trans:
        print(i,":",check_trans[i])

    elif check==2:
      acc=input("Enter the account number:")
      check_trans=transaction.check_tranc_data(acc)
     # amt_withdraw_str = check_trans["amt_withdraw"]
     # b = eval(amt_withdraw_str)
      b=ast.literal_eval(check_trans["amt_deposit"])  # Check amount deposit details
      for i in b:
        print(i,":",b[i])

    elif check==3:
      acc=input("Enter the account number:")
      check_trans=transaction.check_tranc_data(acc)
      b=eval(check_trans["amt_withdraw"])  # Check amount withdraw details
      for i in b:
        print(i,":",b[i])

    elif check==4:
      bal=transaction.withdraw()
      print("Balance:",bal)

    elif check==5:
      bal=transaction.deposit()
      print("Balance:",bal)
  else:break

print("CUSTOMRER INFO")
df = pd.read_csv("info.csv")
print(df)

print("ACCOUNT INFO")
df = pd.read_csv("acc.csv")
print(df)

print("TRANSACTION INFO")
df = pd.read_csv("tranc.csv")
print(df)




# 1)In cif, number of accounts in each city
city_counts = {}
for account in cust_info:
    city = account["city"]
    if city in city_counts:
        city_counts[city] += 1
    else:
        city_counts[city] = 1
# Plotting the data
cities = list(city_counts.keys())
counts = list(city_counts.values())
plt.bar(cities, counts, color='lightgreen')
plt.xlabel('City')
plt.ylabel('Number of Accounts')
plt.title('Number of Accounts for Each City')
plt.xticks(rotation=45, ha='right')
plt.show()


# 2)Number of Saving and Current accounts
df = pd.DataFrame(acc_info)
# Bar chart for acc_type distribution
acc_type_counts = df['acc_type'].value_counts()
acc_type_counts.plot(kind='bar', rot=0, color='skyblue')
plt.title('Account Type Distribution')
plt.xlabel('Account Type')
plt.ylabel('Count')
plt.show()

acc_type_counts = df['acc_status'].value_counts()
acc_type_counts.plot(kind='bar', rot=0, color='skyblue')
plt.title('Account Status Distribution')
plt.xlabel('Account Status')
plt.ylabel('Count')
plt.show()

def get_year_from_activation_date(date):
    return date.split('-')[-1]
def get_account_count_by_year(data):
    year_counts = defaultdict(int)
    for account in data:
        year = get_year_from_activation_date(account['acc_activation_date'])
        year_counts[year] += 1
    return year_counts



# 3)number of accounts activated for the users range of years
def get_year_from_activation_date(date):
    return date.split('-')[-1]

activation_years = [get_year_from_activation_date(account['acc_activation_date']) for account in acc_info]

# Ask user for the range of years
#start_year, end_year = map(int, input("Enter the start and end years (space-separated): ").split())
print("NUMBER OF ACCOUNTS CREATE")
start_year = int(input("Enter the start year: "))
end_year = int(input("Enter the end year: "))
# Filter activation_years based on user input
filtered_years = [year for year in activation_years if start_year <= int(year) <= end_year]

# Count the number of accounts activated per year in the specified range
year_counts = defaultdict(int)
for year in filtered_years:
    year_counts[year] += 1

# Plotting a bar chart
plt.bar(year_counts.keys(), year_counts.values())
plt.xlabel('Activation Year')
plt.ylabel('Number of Accounts')
plt.title(f'Number of Accounts Activated from {start_year} to {end_year}')
plt.show()

# Plotting a line graph
plt.plot(list(year_counts.keys()), list(year_counts.values()), marker='o')
plt.xlabel('Activation Year')
plt.ylabel('Number of Accounts')
plt.title(f'Number of Accounts Activated(Created) from {start_year} to {end_year}')
plt.show()



# 4) Using or merging the files and ploting the graphs
df_cust = pd.DataFrame(cust_info)
df_acc = pd.DataFrame(acc_info)
df_trans = pd.DataFrame(trans_info)

# Merge dataframes to link information
df_merged = pd.merge(df_cust, df_acc, on='cif_no')
# Bar Chart: Number of Accounts by City
plt.figure(figsize=(10, 6))
sns.countplot(x='city', data=df_merged, hue='acc_type')
plt.title('Number of Accounts by City and Account Type')
plt.xlabel('City')
plt.ylabel('Number of Accounts')
plt.xticks(rotation=45)
plt.legend(title='Account Type')
plt.show()


#from dateutil.relativedelta import relativedelta
# Calculate age using relativedelta
df_merged['dob'] = pd.to_datetime(df_merged['dob'], format='%d-%m-%Y')
df_merged['age'] = df_merged['dob'].apply(lambda x: relativedelta(pd.to_datetime('now'), x).years)

# Define age bins
age_bins = [0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
# Create a new column 'age_group' based on age bins
df_merged['age_group'] = pd.cut(df_merged['age'], bins=age_bins, right=False)
# Bar Plot: Total Accounts vs. Age Groups
plt.figure(figsize=(10, 6))
sns.countplot(x='age_group', data=df_merged, palette='viridis')
plt.title('Total Accounts vs. Age Groups')
plt.xlabel('Age Group')
plt.ylabel('Total Accounts')
plt.show()


# 5)pie chart how many savings and current accounts are there
account_types = [account['acc_type'] for account in acc_info]

# Counting the distribution of account types
account_type_counts = defaultdict(int)
for acc_type in account_types:
    account_type_counts[acc_type] += 1

# Plotting a pie chart
plt.pie(account_type_counts.values(), labels=account_type_counts.keys(), autopct='%1.1f%%', startangle=140)
plt.axis('equal')  # Equal aspect ratio ensures that pie is drawn as a circle.
plt.title('Distribution of Account Types')
plt.show()
