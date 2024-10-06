from tkinter import *
from tkinter import ttk
import random
import time
import datetime
from tkinter import messagebox
from tkinter import Tk, Button
import mysql.connector


class Hospital:
    def __init__(self, root):
        self.root = root
        self.root.title("Hospital Management System")
        self.root.geometry("1540x800+0+0")
        
        self.Nameoftablets = StringVar()
        self.ref = StringVar()
        self.Dose = StringVar()
        self.NumberofTblets = StringVar()
        self.Lot = StringVar()
        self.Issuedate = StringVar()
        self.ExpDate = StringVar()
        self.DailyDose = StringVar()
        self.sideEfect = StringVar()
        self.FutherInformation = StringVar()
        self.StorageAdvice = StringVar()
        self.DrivingUsingMachine = StringVar()
        self.HowToUsingMachine = StringVar()
        self.PatientId = StringVar()
        self.nhsNumber = StringVar()
        self.PatientName = StringVar()
        self.DateOfBirth = StringVar()
        self.PatientAddress = StringVar()

        lbltitle = Label(self.root, bd=20, relief=RIDGE, text="HOSPITAL MANAGEMENT SYSTEM", fg="red", bg="white", font=("times new roman", 50, "bold"))
        lbltitle.pack(side=TOP, fill=X)

        # ===============================Dataframe==========================================
        Dataframe = Frame(self.root, bd=20, relief=RIDGE)
        Dataframe.place(x=0, y=130, width=1530, height=400)

        DataFrameLeft = LabelFrame(Dataframe, bd=10, padx=20, relief=RIDGE, font=("Times new roman", 12, "bold"), text="Patient Information")
        DataFrameLeft.place(x=0, y=5, width=980, height=350)

        DataframeRight = LabelFrame(Dataframe, bd=10, relief=RIDGE, padx=20, font=("Times new roman", 12, "bold"), text="Prescription")
        DataframeRight.place(x=990, y=5, width=460, height=350)
        
        # ===============================buttons frame ======================================
        Buttonframe = Frame(self.root, bd=20, relief=RIDGE)
        Buttonframe.place(x=0, y=530, width=1530, height=60)

        # ============================== details frame=======================================
        Detailsframe = Frame(self.root, bd=20, relief=RIDGE)
        Detailsframe.place(x=0, y=600, width=1530, height=150)

        #===============================Dataframeleft========================================
        lblnametablet = Label(DataFrameLeft, text="Name of Tablet", font=("times new roman", 12, "bold"), padx=2, pady=6)
        lblnametablet.grid(row=0, column=0, sticky=W)

        comnametablet = ttk.Combobox(DataFrameLeft, textvariable=self.Nameoftablets, state="readonly", font=("times new roman", 12, "bold"), width=33)
        comnametablet["values"] = ("Nice", "Corona Vaccine", "Acetaminophen", "Adderall", "Amlodipine", "Ativan")
        comnametablet.current(0)
        comnametablet.grid(row=0, column=1)

        lblref = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Reference No:", padx=2)
        lblref.grid(row=1, column=0, sticky=W)
        txtref = Entry(DataFrameLeft, font=("arial", 13, "bold"), textvariable=self.ref, width=35)
        txtref.grid(row=1, column=1)

        lblDose = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Dose:", padx=2, pady=4)
        lblDose.grid(row=2, column=0, sticky=W)
        txtDose = Entry(DataFrameLeft, font=("arial", 13, "bold"), textvariable=self.Dose, width=35)
        txtDose.grid(row=2, column=1)

        lblNoOftablets = Label(DataFrameLeft, font=("arial", 12, "bold"), text="No of Tablets:", padx=2, pady=6)
        lblNoOftablets.grid(row=3, column=0, sticky=W)
        txtNoOftablets = Entry(DataFrameLeft, font=("arial", 13, "bold"), textvariable=self.NumberofTblets, width=35)
        txtNoOftablets.grid(row=3, column=1)

        lbllot = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Lot:", padx=2, pady=6)
        lbllot.grid(row=4, column=0, sticky=W)
        txtlot = Entry(DataFrameLeft, font=("arial", 13, "bold"), textvariable=self.Lot, width=35)
        txtlot.grid(row=4, column=1)

        lblissuedate = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Issue Date:", padx=2, pady=6)
        lblissuedate.grid(row=5, column=0, sticky=W)
        txtissuedate = Entry(DataFrameLeft, font=("arial", 13, "bold"), textvariable=self.Issuedate, width=35)
        txtissuedate.grid(row=5, column=1)

        lblExpdate = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Exp Date:", padx=2, pady=6)
        lblExpdate.grid(row=6, column=0, sticky=W)
        txtexpdate = Entry(DataFrameLeft, font=("arial", 13, "bold"), textvariable=self.ExpDate, width=35)
        txtexpdate.grid(row=6, column=1)

        lblDailydose = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Daily Dose:", padx=2, pady=4)
        lblDailydose.grid(row=7, column=0, sticky=W)
        txtDailydose = Entry(DataFrameLeft, font=("arial", 13, "bold"), textvariable=self.DailyDose, width=35)
        txtDailydose.grid(row=7, column=1)

        lblSideEffect = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Side Effect:", padx=6)
        lblSideEffect.grid(row=8, column=0, sticky=W)
        txtsideeffect = Entry(DataFrameLeft, font=("arial", 13, "bold"), textvariable=self.sideEfect, width=35)
        txtsideeffect.grid(row=8, column=1)

        lblFutherinfo = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Further Information:", padx=2)
        lblFutherinfo.grid(row=0, column=2, sticky=W)
        txtFutherinfo = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.FutherInformation, width=35)
        txtFutherinfo.grid(row=0, column=3)

        lblBloodpressure = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Blood Pressure:", padx=2, pady=6)
        lblBloodpressure.grid(row=1, column=2, sticky=W)
        txtbloodpressure = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.DrivingUsingMachine, width=35)
        txtbloodpressure.grid(row=1, column=3)

        lblStorage = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Storage Advice:", padx=2, pady=6)
        lblStorage.grid(row=2, column=2, sticky=W)
        txtstorage = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.StorageAdvice, width=35)
        txtstorage.grid(row=2, column=3)

        lblmedicine = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Medication:", padx=2, pady=6)
        lblmedicine.grid(row=3, column=2, sticky=W)
        txtmedicine = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.HowToUsingMachine, width=35)
        txtmedicine.grid(row=3, column=3, sticky=W)

        lblpatientid = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Patient ID:", padx=2, pady=6)
        lblpatientid.grid(row=4, column=2, sticky=W)
        txtpatientid = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.PatientId, width=35)
        txtpatientid.grid(row=4, column=3)

        lblnhsnumber = Label(DataFrameLeft, font=("arial", 12, "bold"), text="NHS Number:", padx=2, pady=6)
        lblnhsnumber.grid(row=5, column=2, sticky=W)
        txtnhsnumber = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.nhsNumber, width=35)
        txtnhsnumber.grid(row=5, column=3)

        lblpatientname = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Patient Name:", padx=2, pady=6)
        lblpatientname.grid(row=6, column=2, sticky=W)
        txtpatientname = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.PatientName, width=35)
        txtpatientname.grid(row=6, column=3)

        lbldateofbirth = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Date of Birth:", padx=2, pady=6)
        lbldateofbirth.grid(row=7, column=2, sticky=W)
        txtdateofbirth = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.DateOfBirth, width=35)
        txtdateofbirth.grid(row=7, column=3)

        lblpatientaddress = Label(DataFrameLeft, font=("arial", 12, "bold"), text="Patient Address:", padx=2, pady=6)
        lblpatientaddress.grid(row=8, column=2, sticky=W)
        txtpatientaddress = Entry(DataFrameLeft, font=("arial", 12, "bold"), textvariable=self.PatientAddress, width=35)
        txtpatientaddress.grid(row=8, column=3)

        #==============================Dataframeright===============================================
        self.txtPrescription = Text(DataframeRight, font=("arial", 12, "bold"), width=40, height=16, padx=2, pady=6)
        self.txtPrescription.grid(row=0, column=0)

        #=======================================buttons==============================================
        btnPrescription = Button(Buttonframe, text="Prescription", font=("arial", 12, "bold"), width=15, padx=2, pady=6, command=self.iPrescriptionData)
        btnPrescription.grid(row=0, column=0)

        btnPrescriptionData = Button(Buttonframe, text="Prescription Data", font=("arial", 12, "bold"), width=15, padx=2, pady=6)
        btnPrescriptionData.grid(row=0, column=1)

        btnUpdate = Button(Buttonframe, text="Update", font=("arial", 12, "bold"), width=15, padx=2, pady=6)
        btnUpdate.grid(row=0, column=2)

        btnDelete = Button(Buttonframe, text="Delete", font=("arial", 12, "bold"), width=15, padx=2, pady=6)
        btnDelete.grid(row=0, column=3)

        btnClear = Button(Buttonframe, text="Clear", font=("arial", 12, "bold"), width=15, padx=2, pady=6)
        btnClear.grid(row=0, column=4)

        btnExit = Button(Buttonframe, text="Exit", font=("arial", 12, "bold"), width=15, padx=2, pady=6, command=root.quit)
        btnExit.grid(row=0, column=5)

        #=======================================table===============================================
        #======================================scrollbar===========================================
        scroll_x = ttk.Scrollbar(Detailsframe, orient=HORIZONTAL)
        scroll_y = ttk.Scrollbar(Detailsframe, orient=VERTICAL)
        self.hospital_table = ttk.Treeview(Detailsframe, column=("nameoftable", "ref", "dose", "nooftablets", "lot", "issuedate", "expdate", "dailydose", "storage", "nhsnumber", "pname", "dob", "address"), xscrollcommand=scroll_x.set, yscrollcommand=scroll_y.set)
        scroll_x.pack(side=BOTTOM, fill=X)
        scroll_y.pack(side=RIGHT, fill=Y)

        scroll_x.config(command=self.hospital_table.xview)
        scroll_y.config(command=self.hospital_table.yview)

        self.hospital_table.heading("nameoftable", text="Name of Tablet")
        self.hospital_table.heading("ref", text="Reference No")
        self.hospital_table.heading("dose", text="Dose")
        self.hospital_table.heading("nooftablets", text="No of Tablets")
        self.hospital_table.heading("lot", text="Lot")
        self.hospital_table.heading("issuedate", text="Issue Date")
        self.hospital_table.heading("expdate", text="Exp Date")
        self.hospital_table.heading("dailydose", text="Daily Dose")
        self.hospital_table.heading("storage", text="Storage")
        self.hospital_table.heading("nhsnumber", text="NHS Number")
        self.hospital_table.heading("pname", text="Patient Name")
        self.hospital_table.heading("dob", text="DOB")
        self.hospital_table.heading("address", text="Address")
        self.hospital_table["show"] = "headings"

        self.hospital_table.column("nameoftable", width=100)
        self.hospital_table.column("ref", width=100)
        self.hospital_table.column("dose", width=100)
        self.hospital_table.column("nooftablets", width=100)
        self.hospital_table.column("lot", width=100)
        self.hospital_table.column("issuedate", width=100)
        self.hospital_table.column("expdate", width=100)
        self.hospital_table.column("dailydose", width=100)
        self.hospital_table.column("storage", width=100)
        self.hospital_table.column("nhsnumber", width=100)
        self.hospital_table.column("pname", width=100)
        self.hospital_table.column("dob", width=100)
        self.hospital_table.column("address", width=100)
        self.hospital_table.pack(fill=BOTH, expand=1)

    def iPrescriptionData(self):
        if self.Nameoftablets.get() == "" or self.ref.get() == "":
            messagebox.showerror("Error", "All fields are required")
        else:
            conn = mysql.connector.connect(host="localhost", username="root", password="reddy@12345", database="Myshopdb")
            my_cursor = conn.cursor()
            my_cursor.execute("INSERT INTO hospital VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)",
                              (self.Nameoftablets.get(),
                               self.ref.get(),
                               self.Dose.get(),
                               self.NumberofTblets.get(),
                               self.Lot.get(),
                               self.Issuedate.get(),
                               self.ExpDate.get(),
                               self.DailyDose.get(),
                               self.StorageAdvice.get(),
                               self.nhsNumber.get(),
                               self.PatientName.get(),
                               self.DateOfBirth.get(),
                               self.PatientAddress.get()))
            conn.commit()
            conn.close()


root = Tk()
ob = Hospital(root)
root.mainloop()
print("COMPLETED")
