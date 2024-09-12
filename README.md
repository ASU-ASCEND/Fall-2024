# Fall-2024
Flight software for the ASU Fall 2024 ASCEND Payload

## Subfolders

[Testing](/Testing/):
Test and callibration information for sensor and storage modules

[ascendfsw](/ascendfsw/):
Payload flight software

[Watchdog](/Watchdog/):
Watchdog program to restart microcontroller if it crashes 

## Schedule
[//]: # (&#x2611; is checked box, &#x2610; is unchecked box)

| Week  | Task                                    | Complete   |
|-------|-----------------------------------------|------------|
| 9/19  | Github, Arduino, Platform.io and FSWv1  | &#x2610;   |
| 9/26  | Colibration and optimization            | &#x2610;   |
| 10/3  | FSWv2                                   | &#x2610;   |
| 10/10 | Testing FSWv2                           | &#x2610;   |
| 10/17 | Science Mission review                  | &#x2610;   |
| 10/24 | DP:Tv1, DP:3Dv1                         | &#x2610;   |
| 10/31 | DP:Tv2                                  | &#x2610;   |
| 11/7  | FSWv3, DP:3Dv2                          | &#x2610;   |
| 11/14 | Testing FSWv3, DP:3Dv3                  | &#x2610;   |
| 11/22 | Launch                                  | &#x2610;   |

# Milestones 

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
* Visualization for each sensor with explaining section and what is expected
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
* integrate into radio reception
