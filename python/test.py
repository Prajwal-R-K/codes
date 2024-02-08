""""a=int(input("enter a"))
b=int(input("enter b"))
c=int(input("enter c"))
d=input("Enter the operation")
if(a>b and a>c):
    print("a is greater")
elif(b>c):
    print("b is greater")
else:
    print("c is greater")
if(d=='+'):
    print(a+b+c)
elif(d=='-'):
    print(a-b-c)
elif(d=='*'):
    print(a*b*c)
elif(d=='/'):
    print(a*b/c)
else:
    print("Invalid")"""

"""def while1():
    print("Enter the elements")
    sum=0
    i=0
    while(i<5):
        sum=sum+int(input())
        i=i+1
    print(sum)
while1()"""

""""
a=(2,32,45,5)#a=[2,32,45,5]
sum=0
for i in a:
    sum=sum+i
print(sum)"""

"""d={1:"hdfs",2:"sdkhj"}  
print(d)
print(type(d))
for i in d:
    print(i)
for i in d.keys():
    print(i)
for j in d:
    print(d[j])
for i in d.values():
    print(i)

    """


import matplotlib.pyplot as plt
from collections import defaultdict
from datetime import datetime

def withdrawals_by_year(account_number, trans_info):
    withdrawals_by_year = defaultdict(int)

    for entry in trans_info:
        if entry['acc_no'] == account_number:
            amt_withdraw = eval(entry['amt_withdraw'])
            for date, amount in amt_withdraw.items():
                try:
                    datetime_obj = datetime.strptime(date, '%Y-%m-%d %H:%M:%S.%f')
                except ValueError:
                    datetime_obj = datetime.strptime(date, '%Y-%m-%d')
                year = datetime_obj.year
                withdrawals_by_year[year] += int(amount)

    return withdrawals_by_year

def plot_withdrawals_by_year(account_number, trans_info):
    withdrawals_data = withdrawals_by_year(account_number, trans_info)

    if not withdrawals_data:
        print(f"No withdrawal data found for account number {account_number}")
        return

    years, amounts = zip(*sorted(withdrawals_data.items()))

    plt.figure(figsize=(10, 6))
    plt.bar(years, amounts, color='red')
    plt.title(f'Withdrawals Over Years - Account {account_number}')
    plt.xlabel('Year')
    plt.ylabel('Total Withdrawal Amount')
    plt.show()

# Example: Plot withdrawals for account number '39233895656'
account_number_to_plot = input("Enter the account number:")
plot_withdrawals_by_year(account_number_to_plot, trans_info)

import matplotlib.pyplot as plt
from collections import defaultdict
from datetime import datetime

def withdrawals_by_date(account_number, trans_info):
    withdrawals_by_date = defaultdict(int)

    for entry in trans_info:
        if entry['acc_no'] == account_number:
            amt_withdraw = eval(entry['amt_withdraw'])
            for date, amount in amt_withdraw.items():
                try:
                    datetime_obj = datetime.strptime(date, '%Y-%m-%d %H:%M:%S.%f')
                except ValueError:
                    datetime_obj = datetime.strptime(date, '%Y-%m-%d')
                withdrawals_by_date[datetime_obj.year] += int(amount)

    return withdrawals_by_date

def plot_withdrawals_over_time(account_number, trans_info):
    withdrawals_data = withdrawals_by_date(account_number, trans_info)

    if not withdrawals_data:
        print(f"No withdrawal data found for account number {account_number}")
        return

    years, amounts = zip(*sorted(withdrawals_data.items()))

    plt.figure(figsize=(10, 6))
    plt.plot(list(map(int, years)), amounts, marker='o', linestyle='-', color='green')
    plt.title(f'Withdrawals Over Time - Account {account_number}')
    plt.xlabel('Year')
    plt.ylabel('Withdrawal Amount')
    plt.show()

# Example: Plot withdrawals over time for account number '39233895656'
account_number_to_plot = '39233895656'
plot_withdrawals_over_time(account_number_to_plot, trans_info)