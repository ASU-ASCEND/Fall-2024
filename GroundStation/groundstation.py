import serial
from datetime import datetime
import serial.tools.list_ports as sp

print("Starting Ground Station...")
print(f"Time: {datetime.now().strftime("%H:%M:%S")}\n")

# potential full header, based on sensors in flight software main, used to build header
# avoids trouble from missing transmit header 
full_no_fail_header = [
  " "  # final space for matching fsw
]

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

with open(fileName, "a", newline = '\n') as f:
  input = ser.readline()

  print(input)
  f.write(input + "\n")