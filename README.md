# Fall-2024
Flight software for the ASU Fall 2024 ASCEND Payload

## Subfolders

[DataProcessing](https://github.com/ASU-ASCEND/Fall-2024/tree/main/DataProcessing): Scripts and programs for processing and visualizing flight data.

[Testing](https://github.com/ASU-ASCEND/Fall-2024/tree/main/Testing): Test and calibration information for sensor and storage modules.

[Watchdog](https://github.com/ASU-ASCEND/Fall-2024/tree/main/Watchdog): Software for watchdog Attiny85 chip.

[ascendfsw](https://github.com/ASU-ASCEND/Fall-2024/tree/main/ascendfsw): Payload flight software.

[docs](https://github.com/ASU-ASCEND/Fall-2024/tree/main/docs): Doxygen auto-generated documentation site for GitHub pages. 

[scripts](https://github.com/ASU-ASCEND/Fall-2024/tree/main/scripts) Various organizational and automation scripts. 


## Meeting Schedule

| Week  | Task                                                | Status   |
|-------|-----------------------------------------------------|----------|
| 9/18  | Reviewing last semester, Github Org.                | Done.    |
| 9/25  | Github, Arduino, Platform.io and FSWv1              | Done.    |
| 10/2  | Merging, Datasheets, and Calibration                | Done.    |
| 10/9  | Starting FSWv2 Improvements                         | Done.    |
| 10/16 | FSWv2 More Improvements and New Sensors             | Done.    |
| 10/23 | FSWv2 (cont.)                                       | Done.    |
| 10/30 | Testing and more FSWv2                              | Done.    |
| 11/6  | Finish FSWv2, start integrating FSWv3, start DP:Tv1 |          |
| 11/13 | Testing FSWv3, DP:Tv2                               |          |
| 11/21 | Launch                                              |          |

# Potential Milestones 

## FSW Versions
#### v1 (Minimum Viable Product)
* Reimplement old code into new system
#### v2 (New & Improved)
* Update sensors with fastest comm protocol
* Add this year’s new sensors
* Add watchdog
#### v3 (Multi Core)
* Migrate storage code to core 1
* Implement safe transfer queue

## Data Processing
### Traditional
#### v1 (Minimum Viable Product)
* Visualization for each sensor with explaining the section and what is expected
#### v2 (Reusable Toolset)
* Generalized format and add customization for different CSV input 
* Create consistently styled reusable visualization template 
### 3D Visualization 
#### v1 (Real Time Updating) 
* Using serial connection
* Live gimbaling box
#### v2 (Polishing and Saving)
* Relevant data overlays 
* Payload accurate model
* Output savable as video
#### v3 (Real World Use)
* Integrate into radio reception
