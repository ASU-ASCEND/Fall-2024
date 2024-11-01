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
  "Header","Millis",
  "BMETemp(C),BMEPress(hPa),BMEHum(%),BMEGas(KOhms),BMEAlt(m),",    
  "GeigerSensor(CPS),", 
  "INACurr(mA),INAVolt(mV),INAPow(mW),",                   
  "LSM9DS1 AccX, LSM9DS1 AccY, LSM9DS1 AccZ, LSM9DS1 GyroX, LSM9DS1 GyroY, LSM9DS1 GyroZ, LSM9DS1 MagX, LSM9DS1 MagY, LSM9DS1 MagZ,", 
  "SHTHum(%), SHTTemp(C),",  
  "PicoTemp(C),",
  "WindADC,TempADC,", 
  "SGPTVOC(ppb),SGPeCO2(ppm),SGPTVOCBase(ppb),SGPeCO2Base(ppb),SGPH2,SGPEtha",
  "BME280RelHum %,BME280Pres Pa,BME280Alt m,BME280TempC,DewPointC,",  
  "ENSAQI,ENSTVOC ppb,ENSECO2 ppm,",
  " "  # final space for matching fsw
]

root = tk.Tk()
root.title("ASU ASCEND Ground Station")

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
 
HIST_SIZE = 6
data_line = ["empty," for i in range(HIST_SIZE)]
time_line = ["none" for i in range(HIST_SIZE)]
header = "Receive time,header,"

def update():
  with open(fileName, "a", newline = '\n') as f:
    # last_line = data_line
    data_line.insert(0, str(ser.readline()))
    data_line.pop() 

    now = datetime.now()
    current_time = now.strftime("%H:%M:%S")
    time_line.insert(0, current_time)
    time_line.pop()

    if(header == "header"):
      header = "Receive time, "
      header_field = int(data_line[0].split(",")[0], 16) # read header field, convert from hex 
      header_bin = bin(header_field)[2:]
      header_bin = header_bin[header_bin.find("1"):] # trim to first 1
      for i in range(len(header_bin)): # add each from full header if 1
        if header_bin[i] == "1": header += full_no_fail_header[i]
      print(",".join(header))
      f.write(",".join(header) + "\n")

    print(f"{time_line[0]}, {data_line[0]}")
    f.write(f"{time_line[0]}, {data_line[0]}\n")

  Title = tk.Label(root, font = ("Helvetica", "20", "bold"))
  Title.grid(row=0,column=0,padx=(0, 0), pady=(0,0))
  Title.config(text=('RFD-900x Data'))

  # Data1 = tk.Label(root, font = ("Helvetica", "10"))
  # Data1.grid(row=1,column=0,padx=(0, 5), pady=(0,0))
  # Data1.config(text=f"{header}")
  header_arr = header.split(",")
  for i in range(len(header_arr)):
    header_label = tk.Label(root, font = ("Helvetica", "10", "bold"))
    header_label.grid(row=1, column=i, padx=5, pady=0)
    header_label.config(text=header_arr[i])

  for i in range(len(data_line)):
    combined_arr = f"{time_line[i]},{data_line[i]}".split(",")

    for j in range(len(combined_arr)):
      Data = tk.Label(root, font = ("Helvetica", "10"))
      Data.grid(row=i+2, column=j, padx=5, pady=0)
      Data.config(text=combined_arr[j])

  root.after(500, update) 

root.after(0, update)

root.mainloop()
