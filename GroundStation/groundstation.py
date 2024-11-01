import serial
import time 
from datetime import datetime
import serial.tools.list_ports as sp
import tkinter as tk

print("Starting Ground Station...")
now = datetime.now()
current_time = now.strftime("%H:%M:%S")
print(f"Time: {current_time}\n")

# potential full header, based on sensors in flight software main, used to build header
# avoids trouble from missing transmit header 
full_no_fail_header = [
   "header1","header2",
  " "  # final space for matching fsw
]

# root = tk.Tk()
# root.title("MSGC RFD900x")

# User enter serial port
ports = list(sp.comports())
for i in ports:
    print(i)
print("Enter the COM Port (COM4, COM5, COM9, COM12, etc.) ")
comport = str(input())
print()

# Open Serial Port, 
ser = serial.Serial(
  port = comport,
  baudrate = 57600,
  parity = serial.PARITY_NONE,
  stopbits = serial.STOPBITS_ONE,
  bytesize = serial.EIGHTBITS,
  timeout = None
  )

fileName = "RFD900x_Data.csv"
file = open(fileName, "a")
file.close()
print(fileName + " created to hold data. If file exists, data will be appended\n")
 
while True:
  with open(fileName, "a", newline = '\n') as f:
    data_line = ser.readline()

    print(data_line)
    f.write(data_line + "\n")

# data_line = ""
# last_line = ""
# def update():
  # with open(fileName, "a", newline = '\n') as f:
  #   last_line = data_line
  #   data_line = "asdfasdfads" #ser.readline()

  #   print(data_line)
  #   f.write(data_line + "\n")

#   Title = tk.Label(root, font = ("Helvetica", "20"))
#   Title.grid(row=0,column=0,padx=(0, 0), pady=(0,0))
#   Title.config(text=('RFD-900x Data'))

#   now = datetime.datetime

#   Data1 = tk.Label(root, font = ("Helvetica", "10"))
#   Data1.grid(row=1,column=0,padx=(0, 5), pady=(0,0))
#   Data1.config(text=f"{last_line}")

#   Data2 = tk.Label(root, font = ("Helvetica", "10"))
#   Data2.grid(row=1,column=1,padx=(5, 0), pady=(0,0))
#   Data2.config(text=f"{data_line}")

#   root.after(500, update) 

# root.after(0, update)

# root.mainloop()
