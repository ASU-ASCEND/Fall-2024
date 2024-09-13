"""
Generate issues for improving sensors
"""
import os

milestone = "FSWv2"
label = "fsw"

sensors = """
BME680
Geiger
INA260
LSM9DS1
MTK3339
SGP30
SHT31
ZOPT220
""".split()

for s in sensors:
    title = f"Research and Improve the {s} Sensor"
    body = f"Update /Testing/README.md with information on the {s} sensor, identify which communication protocols it supports and how to calibrate it.\n Use that new information to modify the .cpp code for the {s} to make it sample faster and if necessary create calibration code in /Testing."
    command = f"gh issue create --title \"{title}\" --body \"{body}\" --label \"{label}\" --milestone \"{milestone}\""
    print(command)
    os.system(command)
