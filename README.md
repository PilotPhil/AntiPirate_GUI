# AntiPirateGUI

#### Description
the GUI for antipirate project

#### Software Architecture
- QWidget based GUI
- Yolo based object detection
- Deploy object detection with opencv DNN module
- Capture video with ZED camera


#### Installation
```shell
cd ./AntiPirateGUI
mkdir build
cd ./build
cmake ..
make -j12
./AntiPirateGUI
```

#### Instructions
- config net: default net or cunstom net
- set img path or video path or config zed camera
- click start detect button
- you will see view in the center of the widget, and object detected will show


