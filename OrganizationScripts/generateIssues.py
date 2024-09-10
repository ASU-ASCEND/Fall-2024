import os

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
    title = f"Migrate code for {s} from last semester"
    body = f"Create new .cpp and .h files for a {s}Sensor class based off of last semester's code but with the new inheritence scheme. (see https://github.com/ASU-ASCEND/AcademicYear-2023-24/blob/main/root/src/{s}Sensor.cpp and https://github.com/ASU-ASCEND/AcademicYear-2023-24/blob/main/root/include/{s}Sensor.h"
    label = "fsw"
    milestone = "FSWv1"
    command = f"gh issue create --title \"{title}\" --body \"{body}\" --label \"{label}\" --milestone \"{milestone}\""
    print(command)
    os.system(command)
